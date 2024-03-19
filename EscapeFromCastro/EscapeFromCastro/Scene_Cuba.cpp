#include <fstream>
#include <iostream>

#include "Scene_Cuba.h"
#include "Components.h"
#include "Physics.h"
#include "Scene_Menu.h"
#include "Utilities.h"
#include "MusicPlayer.h"
#include "Assets.h"
#include "SoundPlayer.h"
#include <random>
#include <unordered_set>

namespace {
    std::random_device rd;
    std::mt19937 rng(rd());
}

#pragma region SceneLoad
Scene_Cuba::Scene_Cuba(GameEngine* gameEngine, const std::string& levelPath)
    : Scene(gameEngine),
    m_worldView(gameEngine->window().getDefaultView()) {

    registerActions();
    loadLevel(levelPath);
    sInit();

    sf::FloatRect field = getPlayerSpawnBounds();
    sf::Vector2f spawnPos{ field.left - field.width, (field.top + field.height) - 173.f};
    spawnPlayer(spawnPos);

    MusicPlayer::getInstance().play("gameTheme");
    MusicPlayer::getInstance().setVolume(50);
}
void Scene_Cuba::loadLevel(const std::string& path) {

    std::ifstream config(path);
    if (config.fail()) {
        std::cerr << "Open file " << path << " failed\n";
        config.close();
        exit(1);
    }

    std::string token{ "" };
    config >> token;
    while (!config.eof()) {
        if (token == "Lvl1") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("lvl1");

            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
            sprite.setOrigin(0.f, 0.f);
            sprite.setPosition(pos);
        }
        //else if (token == "Coral") {
        //    std::string name;
        //    sf::Vector2f pos;

        //    config >> name >> pos.x >> pos.y;
        //    auto e = m_entityManager.addEntity("coral");
        //    e->addComponent<CTransform>(pos);
        //    auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;

        //    sprite.setOrigin(0.f, 0.f);
        //    sprite.setPosition(pos);
        //}
        //else if (token == "Island") {
        //    std::string name;
        //    sf::Vector2f pos;

        //    config >> name >> pos.x >> pos.y;
        //    auto e = m_entityManager.addEntity("Island");
        //    e->addComponent<CTransform>(pos);
        //    auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;

        //    sprite.setOrigin(0.f, 0.f);
        //    sprite.setPosition(pos);
        //}
        else if (token == "Special") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("ui");
            e->addComponent<CTransform>(pos);
            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;

            sprite.setOrigin(0.f, 0.f);
            sprite.setPosition(pos);
        }
        else if (token == "Score") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("ui");
            e->addComponent<CTransform>(pos);
            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
            sprite.setOrigin(0.f, 0.f);
            sprite.setPosition(pos);
        }
        else if (token == "Pause") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("pause_button");

            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
            auto spriteSize = sprite.getLocalBounds().getSize();

            e->addComponent<CBoundingBox>(spriteSize);
            sf::Vector2f spriteOrigin = sprite.getOrigin();

            sf::Vector2f boundingBoxPosition = pos + spriteOrigin;

            e->addComponent<CTransform>(boundingBoxPosition);

        }
        else if (token == "Play") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("play_button");

            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
            auto spriteSize = sprite.getLocalBounds().getSize();

            e->addComponent<CBoundingBox>(spriteSize);
            sf::Vector2f spriteOrigin = sprite.getOrigin();

            sf::Vector2f boundingBoxPosition = pos + spriteOrigin;

            e->addComponent<CTransform>(boundingBoxPosition);
        }
        else if (token == "Exit") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("exit_button");

            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
            auto spriteSize = sprite.getLocalBounds().getSize();

            e->addComponent<CBoundingBox>(spriteSize);
            sf::Vector2f spriteOrigin = sprite.getOrigin();

            sf::Vector2f boundingBoxPosition = pos + spriteOrigin;

            e->addComponent<CTransform>(boundingBoxPosition);
        }
        else if (token == "Restart1") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("restart1");

            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
            auto spriteSize = sprite.getLocalBounds().getSize();

            e->addComponent<CBoundingBox>(spriteSize);
            sf::Vector2f spriteOrigin = sprite.getOrigin();

            sf::Vector2f boundingBoxPosition = pos + spriteOrigin;

            e->addComponent<CTransform>(boundingBoxPosition);
        }
        else if (token == "Restart2") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("restart2");

            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
            auto spriteSize = sprite.getLocalBounds().getSize();

            e->addComponent<CBoundingBox>(spriteSize);
            sf::Vector2f spriteOrigin = sprite.getOrigin();

            sf::Vector2f boundingBoxPosition = pos + spriteOrigin;

            e->addComponent<CTransform>(boundingBoxPosition);
        }
        else if (token == "Back3") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("back3");

            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
            auto spriteSize = sprite.getLocalBounds().getSize();

            e->addComponent<CBoundingBox>(spriteSize);
            sf::Vector2f spriteOrigin = sprite.getOrigin();

            sf::Vector2f boundingBoxPosition = pos + spriteOrigin;

            e->addComponent<CTransform>(boundingBoxPosition);

        }
        else if (token == "Back4") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("back4");

            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
            auto spriteSize = sprite.getLocalBounds().getSize();

            e->addComponent<CBoundingBox>(spriteSize);
            sf::Vector2f spriteOrigin = sprite.getOrigin();

            sf::Vector2f boundingBoxPosition = pos + spriteOrigin;

            e->addComponent<CTransform>(boundingBoxPosition);
        }
        else if (token == "Hp1") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("uihp1");
            e->addComponent<CTransform>(pos);
            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;

            sprite.setOrigin(0.f, 0.f);
            sprite.setPosition(pos);

        }
        else if (token == "Hp2") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("uihp2");
            e->addComponent<CTransform>(pos);
            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;

            sprite.setOrigin(0.f, 0.f);
            sprite.setPosition(pos);

        }
        else if (token == "Hp3") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("uihp3");
            e->addComponent<CTransform>(pos);
            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;

            sprite.setOrigin(0.f, 0.f);
            sprite.setPosition(pos);

        }
        else if (token == "GameOver") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("gameover");
            e->addComponent<CTransform>(pos);
            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;

            sprite.setOrigin(0.f, 0.f);
            sprite.setPosition(pos);

        }
        else if (token == "Special1") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("uispecial1");
            e->addComponent<CTransform>(pos);
            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;

            sprite.setOrigin(0.f, 0.f);
            sprite.setPosition(pos);

        }
        else if (token == "Special2") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("uispecial2");
            e->addComponent<CTransform>(pos);
            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;

            sprite.setOrigin(0.f, 0.f);
            sprite.setPosition(pos);

        }
        else if (token == "Special3") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("uispecial3");
            e->addComponent<CTransform>(pos);
            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;

            sprite.setOrigin(0.f, 0.f);
            sprite.setPosition(pos);

        }
        else if (token == "Chapter1") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("chapter1");
            e->addComponent<CTransform>(pos);
            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;

            sprite.setOrigin(0.f, 0.f);
            sprite.setPosition(pos);

        }
        else if (token == "CurtainTop") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("curtaintop");
            e->addComponent<CTransform>(pos);
            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;

            sprite.setOrigin(0.f, 0.f);
            sprite.setPosition(pos);

            }
        else if (token == "Curtain") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("curtain");
            e->addComponent<CTransform>(pos);
            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;

            sprite.setOrigin(0.f, 0.f);
            sprite.setPosition(pos);

        }
        else if (token == "Frame") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("frame");
            e->addComponent<CTransform>(pos);
            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;

            sprite.setOrigin(0.f, 0.f);
            sprite.setPosition(pos);

            }
        else if (token == "World") {
            config >> m_worldBounds.width >> m_worldBounds.height;
        }
        else if (token == "ScrollSpeed") {
            config >> m_config.scrollSpeed;
        }
        else if (token == "PlayerSpeed") {
            config >> m_config.playerSpeed;
        }
        else if (token == "EnemySpeed") {
            config >> m_config.enemySpeed;
        }
        else if (token[0] == '#') {
            std::cout << token;
        }

        config >> token;
    }

    config.close();
}
void Scene_Cuba::registerActions() {
    registerAction(sf::Keyboard::P, "PAUSE");
    registerAction(sf::Keyboard::C, "TOGGLE_COLLISION");
    registerAction(sf::Keyboard::Escape, "BACK");
    registerAction(sf::Keyboard::Q, "SPECIAL");
    registerAction(sf::Keyboard::Space, "SHOOT");
    registerAction(sf::Keyboard::A, "LEFT");
    registerAction(sf::Keyboard::Left, "LEFT");
    registerAction(sf::Keyboard::D, "RIGHT");
    registerAction(sf::Keyboard::Right, "RIGHT");
    registerAction(sf::Keyboard::W, "UP");
    registerAction(sf::Keyboard::Up, "UP");
    registerAction(sf::Keyboard::S, "DOWN");
    registerAction(sf::Keyboard::Down, "DOWN");
}
void Scene_Cuba::spawnPlayer(sf::Vector2f pos) {

    m_player = m_entityManager.addEntity("player");
    m_player->addComponent<CTransform>(pos);
    std::cout << "player pos " << pos;
    m_player->addComponent<CInput>();

    auto& sprite = m_player->addComponent<CSprite>(Assets::getInstance().getTexture("Tony_Idle")).sprite;
    m_player->addComponent<CAnimation>(Assets::getInstance().getAnimation("Tony_Idle_Right"));


    auto spriteSize = sprite.getLocalBounds().getSize();

    m_player->addComponent<CBoundingBox>(spriteSize);
}
#pragma endregion

#pragma region sMovement
void Scene_Cuba::mapMovement() {
    auto worldViewBounds = getViewBounds();

    for (auto e : m_entityManager.getEntities("lvl1")) {

        auto& sprite = e->getComponent<CSprite>().sprite;

        sf::Vector2f spritePosition = sprite.getPosition();
        sf::FloatRect spriteBounds = sprite.getLocalBounds();

        float rightEdgeX = spritePosition.x + spriteBounds.width;

        if (worldViewBounds.contains(rightEdgeX, 0.f)) {
            m_config.scrollSpeed = 0;
            m_isEnd = true;
        }
    }
}
void Scene_Cuba::entityMovement() {
    auto worldViewBounds = getViewBounds();
    sf::Vector2f spawnPos;

    for (auto e : m_entityManager.getEntities()) {
        if (e->hasComponent<CTransform>() && e->hasComponent<CBoundingBox>()) {
            auto& transform = e->getComponent<CTransform>();
            auto& boundingBox = e->getComponent<CBoundingBox>();

            sf::FloatRect entityBounds(
                transform.pos.x - boundingBox.size.x / 2.0f,
                transform.pos.y - boundingBox.size.y / 2.0f,
                boundingBox.size.x,
                boundingBox.size.y
            );
            if (e->hasComponent<CType>()) {
                if (!worldViewBounds.intersects(entityBounds)) {
                    if (transform.pos.x < worldViewBounds.left) {
                       /* spawnPos = sf::Vector2f(worldViewBounds.left + worldViewBounds.width + boundingBox.size.x / 2.0f,
                            randomSpawn(worldViewBounds.top + 150.f, worldViewBounds.top + worldViewBounds.height - 20.f))*/;
                       //transform.pos = spawnPos;
                       e->destroy();
                    }
                    else if (transform.pos.x > worldViewBounds.left + worldViewBounds.width) {
                       // transform.pos.x = worldViewBounds.left - boundingBox.size.x / 2.0f;

                    }

                    if (transform.pos.y < worldViewBounds.top) {
                       // transform.pos.y = worldViewBounds.top + worldViewBounds.height + boundingBox.size.y / 2.0f;
                    }
                    else if (transform.pos.y > worldViewBounds.top + worldViewBounds.height) {
                        //transform.pos.y = worldViewBounds.top - boundingBox.size.y / 2.0f;
                    }
                }
            }
        }
    }
}
void Scene_Cuba::playerMovement() {
    auto worldViewBounds = getViewBounds();
    bool test = sf::Keyboard::isKeyPressed(sf::Keyboard::Q);

    auto& transform = m_player->getComponent<CTransform>();
    auto& boundingBox = m_player->getComponent<CBoundingBox>();

    sf::FloatRect entityBounds(
        transform.pos.x - boundingBox.size.x / 2.0f,
        transform.pos.y - boundingBox.size.y / 2.0f,
        boundingBox.size.x,
        boundingBox.size.y
    );

    if (!m_isEnd && !m_isIntro) {
        auto& pPos = m_player->getComponent<CTransform>().pos;
        sf::Vector2f pv{ 0.f,0.f };
        auto& pInput = m_player->getComponent<CInput>();
        if (pInput.LEFT) pv.x -= 1;
        if (pInput.RIGHT) pv.x += 1;
        if (pInput.UP) pv.y -= 1;
        if (pInput.DOWN) pv.y += 1;
        pv = normalize(pv);

        if(pv.x == 0 && pv.y == 0){
            m_player->getComponent<CTransform>().vel = m_config.scrollSpeed * sf::Vector2f(1.f, 0.f);
        }
        else {
            m_player->getComponent<CTransform>().vel = m_config.playerSpeed * pv;
        }

    }
    else if (!worldViewBounds.intersects(entityBounds) && m_isIntro){
        if (transform.pos.x < worldViewBounds.left) {
            m_player->getComponent<CTransform>().vel.y = 0.0f;
            m_player->getComponent<CTransform>().vel.x = m_config.playerSpeed / 2;
        }
    }
    else if (m_isEnd){
        m_player->removeComponent<CBoundingBox>();
        m_player->getComponent<CTransform>().vel.y = 0.0f;
        m_player->getComponent<CTransform>().vel.x = m_config.playerSpeed * 1.5f;
    }

}
#pragma endregion

#pragma region System
void Scene_Cuba::sInit() {
    resetEntities();
}
void Scene_Cuba::sRender() {

    m_game->window().setView(m_worldView);

    sf::RenderWindow& window = m_game->window();

    std::vector<std::pair<std::shared_ptr<Entity>, float>> entitiesY;

    for (auto& e : m_entityManager.getEntities("lvl1")) {

        if (e->getComponent<CSprite>().has) {

            auto& sprite = e->getComponent<CSprite>().sprite;
            m_game->window().draw(sprite);
        }

    }

    for (auto& e : m_entityManager.getEntities("player")) {
        float bottomY = e->getComponent<CTransform>().pos.y + e->getComponent<CBoundingBox>().halfSize.y;
        entitiesY.push_back(std::make_pair(e, bottomY));
    }
    for (auto& e : m_entityManager.getEntities("enemyBoat")) {
        float bottomY = e->getComponent<CTransform>().pos.y + e->getComponent<CBoundingBox>().halfSize.y;
        entitiesY.push_back(std::make_pair(e, bottomY));
    }
    for (auto& e : m_entityManager.getEntities("enemyIsland")) {
        float bottomY = e->getComponent<CTransform>().pos.y + e->getComponent<CBoundingBox>().halfSize.y;
        entitiesY.push_back(std::make_pair(e, bottomY));
    }
    for (auto& e : m_entityManager.getEntities("enemyShark")) {
        float bottomY = e->getComponent<CTransform>().pos.y + e->getComponent<CBoundingBox>().halfSize.y;
        entitiesY.push_back(std::make_pair(e, bottomY));
    }
    for (auto& e : m_entityManager.getEntities("enemyCoral")) {
        float bottomY = e->getComponent<CTransform>().pos.y + e->getComponent<CBoundingBox>().halfSize.y;
        entitiesY.push_back(std::make_pair(e, bottomY));
    }
    for (auto& e : m_entityManager.getEntities("coca")) {
        float bottomY = e->getComponent<CTransform>().pos.y + e->getComponent<CBoundingBox>().halfSize.y;
        entitiesY.push_back(std::make_pair(e, bottomY));
    }

    std::sort(entitiesY.begin(), entitiesY.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
        });


    for (const auto& pair : entitiesY) {
        auto& e = pair.first;
        if (e->hasComponent<CSprite>()) {
            auto& sprite = e->getComponent<CSprite>().sprite;
            if (m_drawAABB) {
                if (e->hasComponent<CBoundingBox>()) {
                    auto box = e->getComponent<CBoundingBox>();
                    sf::RectangleShape rect;
                    rect.setSize(sf::Vector2f{ box.size.x, box.size.y });
                    centerOrigin(rect);
                    rect.setPosition(e->getComponent<CTransform>().pos);
                    rect.setFillColor(sf::Color(0, 0, 0, 0));
                    rect.setOutlineColor(sf::Color{ 0, 255, 0 });
                    rect.setOutlineThickness(2.f);
                    m_game->window().draw(rect);
                }
            }
            if (e->hasComponent<CAnimation>()) {
                auto& anim = e->getComponent<CAnimation>().animation;
                auto& tfm = e->getComponent<CTransform>();
                anim.getSprite().setPosition(tfm.pos);
                anim.getSprite().setRotation(tfm.angle);
                m_game->window().draw(anim.getSprite());
            }
            else {
                auto& tfm = e->getComponent<CTransform>();
                sprite.setPosition(tfm.pos);
                sprite.setRotation(tfm.angle);
                m_game->window().draw(sprite);
            }

        }
    }

#pragma region Temp
    //for (auto& e : m_entityManager.getEntities("player")) {

//    if (!e->hasComponent<CSprite>())
//        continue;

//    if (m_drawAABB) {
//        if (e->hasComponent<CBoundingBox>()) {
//            auto abb = e->getComponent<CBoundingBox>();
//            auto atx = e->getComponent<CTransform>();
//            float bottom = atx.pos.y + abb.halfSize.y;
//            float left = atx.pos.x - abb.halfSize.x;
//            float right = atx.pos.x + abb.halfSize.x;

//            // Calculate the bottom section of the bounding box
//            float bottomSectionHeight = 5.f;
//            float bottomSectionWidth = 133.f;
//            float bottomSectionLeft = std::max(left + 45.f, left); // Ensure the left edge is at least 45 units from the original left edge
//            float bottomSectionRight = std::min(left + 45.f + bottomSectionWidth, right); // Ensure the right edge is within the original bounds

//            // Draw the bottom section of the bounding box
//            sf::RectangleShape rect;
//            rect.setSize(sf::Vector2f{ bottomSectionRight - bottomSectionLeft, bottomSectionHeight });
//            centerOrigin(rect);
//            rect.setPosition(bottomSectionLeft + (bottomSectionRight - bottomSectionLeft) / 2.f, bottom - bottomSectionHeight / 2.f);
//            rect.setFillColor(sf::Color(0, 0, 0, 0));
//            rect.setOutlineColor(sf::Color{ 0, 255, 0 });
//            rect.setOutlineThickness(2.f);
//            m_game->window().draw(rect);
//        }
//    }
//    auto& sprite = e->getComponent<CSprite>().sprite;
//    if (e->hasComponent<CTransform>()) {
//        auto& anim = e->getComponent<CAnimation>().animation;
//        auto& tfm = e->getComponent<CTransform>();
//        anim.getSprite().setPosition(tfm.pos);
//        anim.getSprite().setRotation(tfm.angle);

//        m_game->window().draw(anim.getSprite());
//    }
//}

//for (auto& e : m_entityManager.getEntities("enemyBoat")) {

//    if (!e->hasComponent<CSprite>())
//        continue;

//    if (m_drawAABB) {
//        if (e->hasComponent<CBoundingBox>()) {
//            auto box = e->getComponent<CBoundingBox>();
//            sf::RectangleShape rect;
//            rect.setSize(sf::Vector2f{ box.size.x, box.size.y });
//            centerOrigin(rect);
//            rect.setPosition(e->getComponent<CTransform>().pos);
//            rect.setFillColor(sf::Color(0, 0, 0, 0));
//            rect.setOutlineColor(sf::Color{ 0, 255, 0 });
//            rect.setOutlineThickness(2.f);
//            m_game->window().draw(rect);
//        }
//    }
//    auto& sprite = e->getComponent<CSprite>().sprite;
//    if (e->hasComponent<CTransform>()) {
//        auto& anim = e->getComponent<CAnimation>().animation;
//        auto& tfm = e->getComponent<CTransform>();
//        anim.getSprite().setPosition(tfm.pos);
//        anim.getSprite().setRotation(tfm.angle);

//        m_game->window().draw(anim.getSprite());
//    }

//}
//for (auto& e : m_entityManager.getEntities("enemyCoral")) {

//    if (!e->hasComponent<CSprite>())
//        continue;

//    if (m_drawAABB) {
//        if (e->hasComponent<CBoundingBox>()) {
//            auto box = e->getComponent<CBoundingBox>();
//            sf::RectangleShape rect;
//            rect.setSize(sf::Vector2f{ box.size.x, box.size.y });
//            centerOrigin(rect);
//            rect.setPosition(e->getComponent<CTransform>().pos);
//            rect.setFillColor(sf::Color(0, 0, 0, 0));
//            rect.setOutlineColor(sf::Color{ 0, 255, 0 });
//            rect.setOutlineThickness(2.f);
//            m_game->window().draw(rect);
//        }
//    }
//    auto& sprite = e->getComponent<CSprite>().sprite;
//    if (e->hasComponent<CTransform>()) {
//        auto& tfm = e->getComponent<CTransform>();
//        sprite.setPosition(tfm.pos);
//        sprite.setRotation(tfm.angle);

//        m_game->window().draw(sprite);
//    }

//}
//for (auto& e : m_entityManager.getEntities("enemyShark")) {

//    if (!e->hasComponent<CSprite>())
//        continue;

//    if (m_drawAABB) {
//        if (e->hasComponent<CBoundingBox>()) {
//            auto box = e->getComponent<CBoundingBox>();
//            sf::RectangleShape rect;
//            rect.setSize(sf::Vector2f{ box.size.x, box.size.y });
//            centerOrigin(rect);
//            rect.setPosition(e->getComponent<CTransform>().pos);
//            rect.setFillColor(sf::Color(0, 0, 0, 0));
//            rect.setOutlineColor(sf::Color{ 0, 255, 0 });
//            rect.setOutlineThickness(2.f);
//            m_game->window().draw(rect);

//            //auto abb = e->getComponent<CBoundingBox>();
//            //auto atx = e->getComponent<CTransform>();
//            //float bottom = atx.pos.y + abb.halfSize.y;
//            //float left = atx.pos.x - abb.halfSize.x;
//            //float right = atx.pos.x + abb.halfSize.x;

//            //// Calculate the bottom section of the bounding box
//            //float bottomSectionHeight = 5.f;
//            //float bottomSectionWidth = 133.f;
//            //float bottomSectionLeft = std::max(left + 45.f, left); // Ensure the left edge is at least 45 units from the original left edge
//            //float bottomSectionRight = std::min(left + 45.f + bottomSectionWidth, right); // Ensure the right edge is within the original bounds

//            //// Draw the bottom section of the bounding box
//            //sf::RectangleShape rect;
//            //rect.setSize(sf::Vector2f{ bottomSectionRight - bottomSectionLeft, bottomSectionHeight });
//            //centerOrigin(rect);
//            //rect.setPosition(bottomSectionLeft + (bottomSectionRight - bottomSectionLeft) / 2.f, bottom - bottomSectionHeight / 2.f);
//            //rect.setFillColor(sf::Color(0, 0, 0, 0));
//            //rect.setOutlineColor(sf::Color{ 0, 255, 0 });
//            //rect.setOutlineThickness(2.f);
//            //m_game->window().draw(rect);
//        }
//    }
//    
//    auto& sprite = e->getComponent<CSprite>().sprite;
//    if (e->hasComponent<CTransform>()) {
//        auto& anim = e->getComponent<CAnimation>().animation;
//        auto& tfm = e->getComponent<CTransform>();
//        anim.getSprite().setPosition(tfm.pos);
//        anim.getSprite().setRotation(tfm.angle);

//        m_game->window().draw(anim.getSprite());
//    }

//}
//for (auto& e : m_entityManager.getEntities("enemyIsland")) {

//    if (!e->hasComponent<CSprite>())
//        continue;

//    if (m_drawAABB) {
//        if (e->hasComponent<CBoundingBox>()) {
//            auto box = e->getComponent<CBoundingBox>();
//            sf::RectangleShape rect;
//            rect.setSize(sf::Vector2f{ box.size.x, box.size.y });
//            centerOrigin(rect);
//            rect.setPosition(e->getComponent<CTransform>().pos);
//            rect.setFillColor(sf::Color(0, 0, 0, 0));
//            rect.setOutlineColor(sf::Color{ 0, 255, 0 });
//            rect.setOutlineThickness(2.f);
//            m_game->window().draw(rect);
//        }
//    }
//    auto& sprite = e->getComponent<CSprite>().sprite;
//    if (e->hasComponent<CTransform>()) {
//        auto& tfm = e->getComponent<CTransform>();
//        sprite.setPosition(tfm.pos);
//        sprite.setRotation(tfm.angle);

//        m_game->window().draw(sprite);
//    }

//}
#pragma endregion

    sf::View view1;
    view1.reset(sf::FloatRect(0.f, 0.f, 900.f, 512.f));
    m_game->window().setView(view1);

    sf::View view = window.getView();
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f viewCenter = view.getCenter();
    sf::Vector2f viewMousePos = window.mapPixelToCoords(mousePos, view);

    //for (auto& e : m_entityManager.getEntities("frame")) {
    //
    //    if (e->getComponent<CSprite>().has) {
    //        auto& sprite = e->getComponent<CSprite>().sprite;
    //        if (e->hasComponent<CTransform>()) {
    //            auto& tfm = e->getComponent<CTransform>();
    //            sprite.setPosition(tfm.pos);
    //            sprite.setRotation(tfm.angle);
    //        }
    //        m_game->window().draw(sprite);
    //    }
    //}

    if (m_isIntro) {


        for (auto& e : m_entityManager.getEntities("curtain")) {

            if (e->getComponent<CSprite>().has) {
                auto& sprite = e->getComponent<CSprite>().sprite;
                if (e->hasComponent<CTransform>()) {
                    auto& tfm = e->getComponent<CTransform>();
                    sprite.setPosition(tfm.pos);
                    sprite.setRotation(tfm.angle);
                }
                m_game->window().draw(sprite);
            }
        }

        for (auto& e : m_entityManager.getEntities("chapter1")) {

            if (e->getComponent<CSprite>().has) {
                auto& sprite = e->getComponent<CSprite>().sprite;
                if (e->hasComponent<CTransform>()) {
                    auto& tfm = e->getComponent<CTransform>();
                    sprite.setPosition(tfm.pos);
                    sprite.setRotation(tfm.angle);
                }
                m_game->window().draw(sprite);
            }
        }


    }

    for (auto& e : m_entityManager.getEntities("curtaintop")) {

        if (e->getComponent<CSprite>().has) {
            auto& sprite = e->getComponent<CSprite>().sprite;
            if (e->hasComponent<CTransform>()) {
                auto& tfm = e->getComponent<CTransform>();
                sprite.setPosition(tfm.pos);
                sprite.setRotation(tfm.angle);
            }
            m_game->window().draw(sprite);
        }
    }

    if (m_life == 0) {

        m_config.scrollSpeed = 0;
        for (auto& e : m_entityManager.getEntities("gameover")) {
            if (e->getComponent<CSprite>().has) {
                auto& sprite = e->getComponent<CSprite>().sprite;
                auto& tfm = e->getComponent<CTransform>();
                sprite.setPosition(tfm.pos);
                sprite.setRotation(tfm.angle);
                m_game->window().draw(sprite);
            }

        }
        for (auto& e1 : m_entityManager.getEntities("restart1")) {

            if (m_drawAABB) {
                if (e1->hasComponent<CBoundingBox>()) {
                    auto box = e1->getComponent<CBoundingBox>();
                    sf::RectangleShape rect;
                    rect.setSize(sf::Vector2f{ box.size.x, box.size.y });
                    centerOrigin(rect);
                    rect.setPosition(e1->getComponent<CTransform>().pos);
                    rect.setFillColor(sf::Color(0, 0, 0, 0));
                    rect.setOutlineColor(sf::Color{ 0, 255, 0 });
                    rect.setOutlineThickness(2.f);
                    m_game->window().draw(rect);
                }
            }
            if (e1->hasComponent<CSprite>()) {
                auto& sprite1 = e1->getComponent<CSprite>().sprite;
                auto overlap = Physics::getOverlapMouse(viewMousePos, e1);
                auto& tfm = e1->getComponent<CTransform>();
                sprite1.setPosition(tfm.pos);
                sprite1.setRotation(tfm.angle);

                for (auto e2 : m_entityManager.getEntities("restart2")) {
                    if (e2->hasComponent<CSprite>()) {
                        auto& sprite2 = e2->getComponent<CSprite>().sprite;
                        auto& tfm = e2->getComponent<CTransform>();
                        sprite2.setPosition(tfm.pos);
                        sprite2.setRotation(tfm.angle);
                        if (overlap.x > 0 && overlap.y > 0) {
                            m_game->window().draw(sprite2);

                            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                                m_game->quitLevel();
                            }
                        }
                        else {

                            m_game->window().draw(sprite1);
                        }
                    }
                }
            }
        }
        for (auto& e1 : m_entityManager.getEntities("back3")) {

            if (m_drawAABB) {
                if (e1->hasComponent<CBoundingBox>()) {
                    auto box = e1->getComponent<CBoundingBox>();
                    sf::RectangleShape rect;
                    rect.setSize(sf::Vector2f{ box.size.x, box.size.y });
                    centerOrigin(rect);
                    rect.setPosition(e1->getComponent<CTransform>().pos);
                    rect.setFillColor(sf::Color(0, 0, 0, 0));
                    rect.setOutlineColor(sf::Color{ 0, 255, 0 });
                    rect.setOutlineThickness(2.f);
                    m_game->window().draw(rect);
                }
            }
            if (e1->hasComponent<CSprite>()) {
                auto& sprite1 = e1->getComponent<CSprite>().sprite;
                auto overlap = Physics::getOverlapMouse(viewMousePos, e1);
                auto& tfm = e1->getComponent<CTransform>();
                sprite1.setPosition(tfm.pos);
                sprite1.setRotation(tfm.angle);

                for (auto e2 : m_entityManager.getEntities("back4")) {
                    if (e2->hasComponent<CSprite>()) {
                        auto& sprite2 = e2->getComponent<CSprite>().sprite;
                        auto& tfm = e2->getComponent<CTransform>();
                        sprite2.setPosition(tfm.pos);
                        sprite2.setRotation(tfm.angle);
                        if (overlap.x > 0 && overlap.y > 0) {
                            m_game->window().draw(sprite2);

                            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                                MusicPlayer::getInstance().play("menuTheme");
                                MusicPlayer::getInstance().setVolume(50);
                                m_elapsedTime = 0;
                                m_game->quitLevel();
                            }
                        }
                        else {

                            m_game->window().draw(sprite1);
                        }
                    }
                }
            }
        }

    }

    for (auto& e : m_entityManager.getEntities("ui")) {

        if (e->getComponent<CSprite>().has) {
            auto& sprite = e->getComponent<CSprite>().sprite;
            if (e->hasComponent<CTransform>()) {
                auto& tfm = e->getComponent<CTransform>();
                sprite.setPosition(tfm.pos);
                sprite.setRotation(tfm.angle);
            }
            m_game->window().draw(sprite);
        }
    }
    for (auto& e : m_entityManager.getEntities("pause_button")) {
        if (m_drawAABB) {
            if (e->hasComponent<CBoundingBox>()) {
                auto box = e->getComponent<CBoundingBox>();
                sf::RectangleShape rect;
                rect.setSize(sf::Vector2f{ box.size.x, box.size.y });
                centerOrigin(rect);
                rect.setPosition(e->getComponent<CTransform>().pos);
                rect.setFillColor(sf::Color(0, 0, 0, 0));
                rect.setOutlineColor(sf::Color{ 0, 255, 0 });
                rect.setOutlineThickness(2.f);
                m_game->window().draw(rect);
            }
        }
        if (e->getComponent<CSprite>().has) {
            auto& sprite = e->getComponent<CSprite>().sprite;
            auto test = e->getComponent<CTransform>();

            auto overlap = Physics::getOverlapMouse(viewMousePos, e);
            if (e->hasComponent<CTransform>()) {
                auto& tfm = e->getComponent<CTransform>();
                sprite.setPosition(tfm.pos);
                sprite.setRotation(tfm.angle);

                if (overlap.x > 0 && overlap.y > 0) {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        if (!m_isPaused)
                            setPaused(!m_isPaused);
                    }
                }

                m_game->window().draw(sprite);
            }
        }

    }
    for (auto& e : m_entityManager.getEntities("play_button")) {
        if (m_drawAABB) {
            if (e->hasComponent<CBoundingBox>()) {
                auto box = e->getComponent<CBoundingBox>();
                sf::RectangleShape rect;
                rect.setSize(sf::Vector2f{ box.size.x, box.size.y });
                centerOrigin(rect);
                rect.setPosition(e->getComponent<CTransform>().pos);
                rect.setFillColor(sf::Color(0, 0, 0, 0));
                rect.setOutlineColor(sf::Color{ 0, 255, 0 });
                rect.setOutlineThickness(2.f);
                m_game->window().draw(rect);
            }
        }
        if (e->getComponent<CSprite>().has) {
            auto& sprite = e->getComponent<CSprite>().sprite;
            auto test = e->getComponent<CTransform>();

            auto overlap = Physics::getOverlapMouse(viewMousePos, e);
            if (e->hasComponent<CTransform>()) {
                auto& tfm = e->getComponent<CTransform>();
                sprite.setPosition(tfm.pos);
                sprite.setRotation(tfm.angle);

                if (overlap.x > 0 && overlap.y > 0) {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        if (m_isPaused)
                            setPaused(!m_isPaused);

                    }
                }
            }
            m_game->window().draw(sprite);
        }
    }
    for (auto& e : m_entityManager.getEntities("exit_button")) {
        if (m_drawAABB) {
            if (e->hasComponent<CBoundingBox>()) {
                auto box = e->getComponent<CBoundingBox>();
                sf::RectangleShape rect;
                rect.setSize(sf::Vector2f{ box.size.x, box.size.y });
                centerOrigin(rect);
                rect.setPosition(e->getComponent<CTransform>().pos);
                rect.setFillColor(sf::Color(0, 0, 0, 0));
                rect.setOutlineColor(sf::Color{ 0, 255, 0 });
                rect.setOutlineThickness(2.f);
                m_game->window().draw(rect);
            }
        }
        if (e->getComponent<CSprite>().has) {
            auto& sprite = e->getComponent<CSprite>().sprite;
            auto test = e->getComponent<CTransform>();

            auto overlap = Physics::getOverlapMouse(viewMousePos, e);
            if (e->hasComponent<CTransform>()) {
                auto& tfm = e->getComponent<CTransform>();
                sprite.setPosition(tfm.pos);
                sprite.setRotation(tfm.angle);

                if (overlap.x > 0 && overlap.y > 0) {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        MusicPlayer::getInstance().play("menuTheme");
                        MusicPlayer::getInstance().setVolume(50);
                        m_elapsedTime = 0;
                        m_game->quitLevel();
                    }
                }
            }
            m_game->window().draw(sprite);
        }
    }
    for (auto& hp3 : m_entityManager.getEntities("uihp3")) {

        if (hp3->hasComponent<CSprite>()) {
            auto& hp03 = hp3->getComponent<CSprite>().sprite;
            if (hp3->hasComponent<CTransform>()) {
                auto& tfm = hp3->getComponent<CTransform>();
                hp03.setPosition(tfm.pos);
                hp03.setRotation(tfm.angle);
            }
            if (m_life == 3) {
                m_game->window().draw(hp03);
            }
            else if (m_life == 2) {
                for (auto hp2 : m_entityManager.getEntities("uihp2")) {
                    if (hp2->hasComponent<CSprite>()) {
                        auto& hp02 = hp2->getComponent<CSprite>().sprite;
                        if (hp2->hasComponent<CTransform>()) {
                            auto& tfm = hp2->getComponent<CTransform>();
                            hp02.setPosition(tfm.pos);
                            hp02.setRotation(tfm.angle);
                        }
                        m_game->window().draw(hp02);
                    }
                }
            }
            else {
                for (auto hp1 : m_entityManager.getEntities("uihp1")) {
                    if (hp1->hasComponent<CSprite>()) {
                        auto& hp01 = hp1->getComponent<CSprite>().sprite;
                        if (hp1->hasComponent<CTransform>()) {
                            auto& tfm = hp1->getComponent<CTransform>();
                            hp01.setPosition(tfm.pos);
                            hp01.setRotation(tfm.angle);
                        }
                        m_game->window().draw(hp01);
                    }
                }
            }

        }
    }
    for (auto& hp3 : m_entityManager.getEntities("uispecial3")) {

        if (hp3->hasComponent<CSprite>()) {
            auto& hp03 = hp3->getComponent<CSprite>().sprite;
            if (hp3->hasComponent<CTransform>()) {
                auto& tfm = hp3->getComponent<CTransform>();
                hp03.setPosition(tfm.pos);
                hp03.setRotation(tfm.angle);
            }
            if (m_special == 3) {
                m_game->window().draw(hp03);
            }
            else if (m_special == 2) {
                for (auto hp2 : m_entityManager.getEntities("uispecial2")) {
                    if (hp2->hasComponent<CSprite>()) {
                        auto& hp02 = hp2->getComponent<CSprite>().sprite;
                        if (hp2->hasComponent<CTransform>()) {
                            auto& tfm = hp2->getComponent<CTransform>();
                            hp02.setPosition(tfm.pos);
                            hp02.setRotation(tfm.angle);
                        }
                        m_game->window().draw(hp02);
                    }
                }
            }
            else if (m_special == 1) {
                for (auto hp1 : m_entityManager.getEntities("uispecial1")) {
                    if (hp1->hasComponent<CSprite>()) {
                        auto& hp01 = hp1->getComponent<CSprite>().sprite;
                        if (hp1->hasComponent<CTransform>()) {
                            auto& tfm = hp1->getComponent<CTransform>();
                            hp01.setPosition(tfm.pos);
                            hp01.setRotation(tfm.angle);
                        }
                        m_game->window().draw(hp01);
                    }
                }
            }

        }
    }

    m_score_text.setFont(Assets::getInstance().getFont("Arcade"));
    m_score_text.setPosition(730.f, 1.f);
    m_score_text.setCharacterSize(50);

    if (!m_isEnd)
        m_score_text.setString(std::to_string(m_playScore));
    else
        m_score_text.setString(std::to_string(m_finalScore));

    m_score_text.setFillColor(sf::Color::Yellow);
    m_game->window().draw(m_score_text);
    m_game->window().setView(m_worldView);

}
void Scene_Cuba::sDoAction(const Command& action) {

    auto& pPos = m_player->getComponent<CTransform>().pos;

    if (action.type() == "START") {
        if (action.name() == "PAUSE") { setPaused(!m_isPaused); }
        else if (action.name() == "QUIT") { m_game->quitLevel(); }
        else if (action.name() == "SPECIAL") 
        { 
            if (m_special > 0 && !m_isSpecial) 
            { 
                // Make a function?
                m_config.scrollSpeed += 50.f;
                auto& sprite = m_player->addComponent<CSprite>(Assets::getInstance().getTexture("Tontana_Boat")).sprite;
                m_player->addComponent<CAnimation>(Assets::getInstance().getAnimation("Tontana_Idle_Right"));
                auto spriteSize = sprite.getLocalBounds().getSize();
                m_player->addComponent<CBoundingBox>(spriteSize);
                MusicPlayer::getInstance().play("specialTheme");
                MusicPlayer::getInstance().setVolume(50);
                m_isSpecial = true;
                m_special -= 1;
                auto& pFrame = m_player->getComponent<CAnimation>().animation.m_currentFrame;
                std::cout << "Before shooting Frame: " << pFrame << std::endl;
            } 
        }
        else if (action.name() == "SHOOT")
        {
            if (m_isSpecial == true && !m_isFiring)
            {
                m_isFiring = true;
                // Make a function?
                auto& pFrame = m_player->getComponent<CAnimation>().animation.m_currentFrame;
                std::cout << "Current frame: " << pFrame << std::endl;
                m_player->addComponent<CAnimation>(Assets::getInstance().getAnimation("Tontana_Fire_Right")).animation.m_currentFrame += m_player->getComponent<CAnimation>().animation.m_currentFrame;
                std::cout << "After shooting frame: " << pFrame << std::endl;
            }
        }
        else if (action.name() == "LEFT") { m_player->getComponent<CInput>().LEFT = true; }
        else if (action.name() == "RIGHT") { m_player->getComponent<CInput>().RIGHT = true; }
        else if (action.name() == "UP") { m_player->getComponent<CInput>().UP = true; }
        else if (action.name() == "DOWN") { m_player->getComponent<CInput>().DOWN = true; }
        else if (action.name() == "TOGGLE_COLLISION") { m_drawAABB = !m_drawAABB; }
    }

    else if (action.type() == "END") {
        if (action.name() == "LEFT") { m_player->getComponent<CInput>().LEFT = false; }
        else if (action.name() == "SHOOT") { 
            
            if (m_isSpecial == true && m_isFiring)
            {
                m_isFiring = false;
                auto& pFrame = m_player->getComponent<CAnimation>().animation.m_currentFrame;
                std::cout << "Current shooting frame: " << pFrame << std::endl;
                m_player->addComponent<CAnimation>(Assets::getInstance().getAnimation("Tontana_Idle_Right")).animation.m_currentFrame += m_player->getComponent<CAnimation>().animation.m_currentFrame;
                std::cout << "After end shooting frame: " << pFrame << std::endl;
            }
            
        }
        else if (action.name() == "RIGHT") { m_player->getComponent<CInput>().RIGHT = false; }
        else if (action.name() == "UP") { m_player->getComponent<CInput>().UP = false; }
        else if (action.name() == "DOWN") { m_player->getComponent<CInput>().DOWN = false; }
    }
}
void Scene_Cuba::sMovement(sf::Time dt) {
    mapMovement();
    entityMovement();
    playerMovement();

    for (auto& e : m_entityManager.getEntities("player")) {
        if (e->hasComponent<CTransform>()) {
            auto& tfm = e->getComponent<CTransform>();

            tfm.pos += tfm.vel * dt.asSeconds();
        }
    }
    for (auto& e : m_entityManager.getEntities("enemyBoat")) {
        if (e->hasComponent<CTransform>()) {
            auto& tfm = e->getComponent<CTransform>();

            tfm.pos -= tfm.vel * dt.asSeconds();
        }
    }
    for (auto& e : m_entityManager.getEntities("enemyShark")) {
        if (e->hasComponent<CTransform>()) {
            auto& tfm = e->getComponent<CTransform>();

            tfm.pos -= tfm.vel * dt.asSeconds();
        }
    }
    for (auto& e : m_entityManager.getEntities("curtain")) {
        if (e->hasComponent<CTransform>()) {
            auto& tfm = e->getComponent<CTransform>();

            tfm.pos.y -= 100.f * dt.asSeconds();
        }
    }
    if (!m_isIntro) {
        for (auto& e : m_entityManager.getEntities("curtaintop")) {
            if (e->hasComponent<CTransform>()) {
                auto& tfm = e->getComponent<CTransform>();
    
                tfm.pos.y -= 50.f * dt.asSeconds();
            }
        }
    }
}
void Scene_Cuba::sCollisions() {
    adjustPlayerPosition();
    checkCollisions();
    checkPlayerState();
}
void Scene_Cuba::sUpdate(sf::Time dt) {
    auto& pST = m_player->getComponent<CState>().state;
    SoundPlayer::getInstance().removeStoppedSounds();

    if (m_elapsedTime < m_introTime)
        m_isIntro = true;
    else
        m_isIntro = false;

    // Do encapsulation instead of local variables.
    if (m_isPaused)
        return;
    
    if (m_isEnd) {
        static float levelBonus = 100.f;

        m_finalScore = (int)(levelBonus - m_timeScore) + m_playScore;
    }
    else {
        m_timeScore += dt.asSeconds();
        m_elapsedTime += dt.asSeconds();
    }

    m_worldView.move(m_config.scrollSpeed * dt.asSeconds() * 1, 0.f);
    m_entityManager.update();
    //

    sAnimation(dt);
    sEnemySpawner(dt);
    sCollisions();
    sMovement(dt);

    SoundPlayer::getInstance().removeStoppedSounds();
}
void Scene_Cuba::sAnimation(sf::Time dt) {
    for (auto e : m_entityManager.getEntities()) {

        if (e->hasComponent<CAnimation>()) {
            auto& anim = e->getComponent<CAnimation>();
            anim.animation.update(dt);
        }
    }
}
void Scene_Cuba::sEnemySpawner(sf::Time dt) {
    sf::FloatRect field = getEnemySpawnBounds();

    std::exponential_distribution<float> exp(1.f);

    static std::vector<float> spawnLanes{ 478.f };

    while (spawnLanes.size() < 10) {
        float lane = spawnLanes.back() - 34.f;
        std::cout << "Lane: " << lane << std::endl;
        spawnLanes.push_back(lane);
    }

    std::uniform_int_distribution<int> laneDis(0, 9);
    static std::unordered_set<int> occupiedLanes; // Is unordered and has member functions like find.

    if (occupiedLanes.size() == 10) {
        occupiedLanes.clear();
    }

    int laneNumber = laneDis(rng);
    while (occupiedLanes.find(laneNumber) != occupiedLanes.end()) {
        laneNumber = laneDis(rng);
    }
    occupiedLanes.insert(laneNumber);

    std::uniform_real_distribution<float> xDis(field.left + field.width, field.left + field.width);

    std::uniform_real_distribution<float> yDis(spawnLanes[laneNumber], spawnLanes[laneNumber] + 34.f);

    float x = xDis(rng);
    float y = yDis(rng);

    sf::Vector2f spawnPos{ x, y };

    static sf::Time countDownTimer{ sf::Time::Zero };
    countDownTimer -= dt;
    if (countDownTimer < sf::Time::Zero) {
        countDownTimer = sf::seconds(exp(rng));

            spawnEnemy(spawnPos);
    }
}
#pragma endregion

#pragma region Utility
void Scene_Cuba::specialAbility() {

    const float flashDuration = 15.f;
    static sf::Clock flashClock;

    float elapsedTime = flashClock.getElapsedTime().asSeconds();

    if (elapsedTime > flashDuration) {
       auto& sprite = m_player->addComponent<CSprite>(Assets::getInstance().getTexture("Tony_Idle")).sprite;
       m_player->addComponent<CAnimation>(Assets::getInstance().getAnimation("Tony_Idle_Right"));
       auto spriteSize = sprite.getLocalBounds().getSize();
       m_player->addComponent<CBoundingBox>(spriteSize);

       MusicPlayer::getInstance().play("gameTheme");
       MusicPlayer::getInstance().setVolume(50);
       flashClock.restart();

       m_isSpecial = false;
       m_config.scrollSpeed -= 50.f;
    }

}
void Scene_Cuba::onEnd() {
    m_game->changeScene("MENU", nullptr, false);
}
void Scene_Cuba::update(sf::Time dt) {
    sUpdate(dt);
}
sf::FloatRect Scene_Cuba::getViewBounds() {
    auto view = m_game->window().getView();
    return sf::FloatRect(
        (view.getCenter().x - view.getSize().x / 2.f), (view.getCenter().y - view.getSize().y / 2.f),
        view.getSize().x, view.getSize().y);
}
sf::FloatRect Scene_Cuba::getEnemySpawnBounds() {

    auto viewBounds = getViewBounds();
    float spawnWidth = 80.f;
    viewBounds.width += spawnWidth;

    return viewBounds;
}
sf::FloatRect Scene_Cuba::getPlayerSpawnBounds() {

    auto viewBounds = getViewBounds();
    float spawnWidth = 700.f;
    viewBounds.width -= spawnWidth;

    return viewBounds;
}
#pragma endregion

#pragma region sInit
void Scene_Cuba::resetEntities() {

}
#pragma endregion

#pragma region sEnemySpawner
float Scene_Cuba::randomSpawn(float min, float max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(min, max);
    return dis(gen);
}
void Scene_Cuba::spawnEnemy(sf::Vector2f pos) {

    sf::FloatRect field = getEnemySpawnBounds();
    static int prevEntType = 0;
    int newEntType;
    std::uniform_int_distribution<int> intDist(1, 5);

    do {
        newEntType = intDist(rng);
    } while (newEntType == prevEntType);

    prevEntType = newEntType;

    switch (newEntType)
    {
        case 1:
        {
            if (m_entityManager.getEntities("enemyBoat").size() < 3 && m_elapsedTime > m_introTime) {
                float eHalfHeight = 41.f;
                float eHalfWidth = 84.f;
                if ((pos.y + eHalfHeight) > field.top + field.height) {
                    pos.y = field.top + field.height - eHalfHeight;
                }
                else if ((pos.x - eHalfWidth) < field.left + field.width) {
                    pos.x = field.left + field.width + eHalfWidth;
                }
                spawnBoat(pos);
            }
            break;
        }
        case 2:
        {
            if (m_entityManager.getEntities("enemyShark").size() < 3 && m_elapsedTime > m_introTime) {

                float eHalfHeight = 11.5f;

                if ((pos.y + eHalfHeight) > field.top + field.height) {
                    pos.y = field.top + field.height - eHalfHeight;
                }
                spawnShark(pos);
            }
            break;
        }
        case 3: 
        {
            if (m_entityManager.getEntities("enemyIsland").size() < 6) {
                float eFullHeight = 148.f;
                if ((pos.y + eFullHeight) > field.top + field.height) {
                    std::cout << "Island created at too far down: " << pos << std::endl;
                   pos.y = pos.y - eFullHeight;
                }

                spawnIsland(pos);
            }
            break;
        }
        case 4: 
        {
            if (m_entityManager.getEntities("enemyCoral").size() < 6) {

                float eHalfHeight = 26.f;
                if ((pos.y + eHalfHeight) > field.top + field.height) {
                    pos.y = field.top + field.height - eHalfHeight;
                }
                spawnCoral(pos);
            }
            break;
        }
        case 5:
        {
            if (m_entityManager.getEntities("coca").size() < 1 && m_special == 0) {

                float eHalfHeight = 8.f;
                if ((pos.y + eHalfHeight) > field.top + field.height) {
                    pos.y = field.top + field.height - eHalfHeight;
                }
                spawnCoca(pos);
            }
            break;
        }
        default:
        {
            break;
        }
        
    }
}
void Scene_Cuba::spawnBoat(sf::Vector2f pos) {
    auto raceCarL = m_entityManager.addEntity("enemyBoat");

    raceCarL->addComponent<CTransform>(pos, sf::Vector2f{ m_config.enemySpeed, 0.f });
    auto& sprite = raceCarL->addComponent<CSprite>(Assets::getInstance().getTexture("Military")).sprite;
    raceCarL->addComponent<CAnimation>(Assets::getInstance().getAnimation("Military_Left"));
    sprite.setTexture(Assets::getInstance().getTexture("Military"));
    auto spriteSize = sprite.getLocalBounds().getSize();
    raceCarL->addComponent<CBoundingBox>(spriteSize);
    std::cout << "Boat created at: " << pos << std::endl;
    raceCarL->addComponent<CType>().boat += 1;
}
void Scene_Cuba::spawnCoral(sf::Vector2f pos) {
    auto raceCarL = m_entityManager.addEntity("enemyCoral");

    raceCarL->addComponent<CTransform>(pos, sf::Vector2f{ m_config.enemySpeed, 0.f });
    auto& sprite = raceCarL->addComponent<CSprite>().sprite;
    auto& spriteName = raceCarL->addComponent<CSprite>(Assets::getInstance().getTexture("Coral")).sprite;
    sprite.setTexture(Assets::getInstance().getTexture("Coral"));
    auto spriteSize = sprite.getLocalBounds().getSize();
    raceCarL->addComponent<CBoundingBox>(spriteSize);
    std::cout << "Coral created at: " << pos << std::endl;
    raceCarL->addComponent<CType>().coral += 1;

}
void Scene_Cuba::spawnIsland(sf::Vector2f pos) {

    auto raceCarL = m_entityManager.addEntity("enemyIsland");

    raceCarL->addComponent<CTransform>(pos, sf::Vector2f{ m_config.enemySpeed, 0.f });
    auto& sprite = raceCarL->addComponent<CSprite>().sprite;
    auto& spriteName = raceCarL->addComponent<CSprite>(Assets::getInstance().getTexture("Island")).sprite;
    sprite.setTexture(Assets::getInstance().getTexture("Island"));
    auto spriteSize = sprite.getLocalBounds().getSize();

    raceCarL->addComponent<CBoundingBox>(spriteSize);

    std::cout << "Island created at: " << pos << std::endl;
    raceCarL->addComponent<CType>().island += 1;

}
void Scene_Cuba::spawnShark(sf::Vector2f pos) {

    auto raceCarL = m_entityManager.addEntity("enemyShark");

    raceCarL->addComponent<CTransform>(pos, sf::Vector2f{ m_config.enemySpeed, 0.f });
    auto& sprite = raceCarL->addComponent<CSprite>(Assets::getInstance().getTexture("Shark")).sprite;
    raceCarL->addComponent<CAnimation>(Assets::getInstance().getAnimation("Shark_Left"));
    sprite.setTexture(Assets::getInstance().getTexture("Shark"));
    auto spriteSize = sprite.getLocalBounds().getSize();
    raceCarL->addComponent<CBoundingBox>(spriteSize);
    std::cout << "Shark created at: " << pos << std::endl;
    raceCarL->addComponent<CType>().shark += 1;
}
void Scene_Cuba::spawnCoca(sf::Vector2f pos) {

    auto raceCarL = m_entityManager.addEntity("coca");
    raceCarL->addComponent<CTransform>(pos, sf::Vector2f{ m_config.enemySpeed, 0.f });
    auto& sprite = raceCarL->addComponent<CSprite>(Assets::getInstance().getTexture("Coca")).sprite;
    raceCarL->addComponent<CAnimation>(Assets::getInstance().getAnimation("Coca_Left"));
    sprite.setTexture(Assets::getInstance().getTexture("Coca"));
    auto spriteSize = sprite.getLocalBounds().getSize();
    raceCarL->addComponent<CBoundingBox>(spriteSize);
    std::cout << "Coca created at: " << pos << std::endl;
    raceCarL->addComponent<CType>().coca += 1;
}
#pragma endregion

#pragma region sCollisions
void Scene_Cuba::checkCollisions() {
    for (auto e : m_entityManager.getEntities("enemyShark")) {
        auto overlap = Physics::getOverlapEntity(m_player, e, "shark");
        if (overlap.x > 0 and overlap.y > 0) {
            if (m_isSpecial) {
                e->destroy();
                m_playScore += 10.f;
            }
            else {
                m_player->removeComponent<CBoundingBox>();
                m_player->addComponent<CState>().state = "dead";
                e->destroy();
                m_playScore += 10.f;
                if (m_life != 0) {
                    m_life -= 1;
                }
            }
            checkPlayerState();
        }
    }
    for (auto e : m_entityManager.getEntities("enemyBoat")) {
        auto overlap = Physics::getOverlapEntity(m_player, e, "boatMilitary");
        if (overlap.x > 0 and overlap.y > 0) {
            m_player->removeComponent<CBoundingBox>();
            m_player->addComponent<CState>().state = "dead";
            if (m_life != 0) {
                m_life -= 1;
            }
            checkPlayerState();
        }
    }
    for (auto e : m_entityManager.getEntities("enemyCoral")) {
        auto overlap = Physics::getOverlapEntity(m_player, e, "coral");
        if (overlap.x > 0 and overlap.y > 0) {
            if (m_isSpecial) {
                e->destroy();
                if (m_playScore >= 5) {
                    m_playScore -= 5.f;
                }
                else {
                    m_playScore -= m_playScore;
                }
            }
            else {
                m_player->removeComponent<CBoundingBox>();
                m_player->addComponent<CState>().state = "dead";
                e->destroy();
                if (m_playScore >= 5) {
                    m_playScore -= 5.f;
                }
                else {
                    m_playScore -= m_playScore;
                }
                if (m_life != 0) {
                    m_life -= 1;
                }
            }
            checkPlayerState();
        }
    }
    for (auto e : m_entityManager.getEntities("enemyIsland")) {
        auto overlap = Physics::getOverlapEntity(m_player, e, "island");
        if (overlap.x > 0 and overlap.y > 0) {
            m_player->removeComponent<CBoundingBox>();
            m_player->addComponent<CState>().state = "dead";

            if (m_life != 0) {
                m_life -= 1;
            }

            checkPlayerState();
        }
    }
    for (auto e : m_entityManager.getEntities("coca")) {
        auto overlap = Physics::getOverlapEntity(m_player, e, "coca");
        if (overlap.x > 0 and overlap.y > 0) {

            if (m_special != 3) {
                m_special += 1;
                e->destroy();
            }

            checkPlayerState();
        }
    }

}
void Scene_Cuba::checkPlayerState() {
    auto& pST = m_player->getComponent<CState>().state;
    sf::Vector2f spawnPos{ m_worldView.getSize().x / 2.f, m_worldView.getSize().y / 2.f };

    if (pST == "dead") {
        const float flashDuration = 5.0f;
        static sf::Clock flashClock;

        float elapsedTime = flashClock.getElapsedTime().asSeconds();
        auto& anim = m_player->getComponent<CAnimation>();
        m_player->removeComponent<CBoundingBox>();

        if (elapsedTime < flashDuration) {
            if (static_cast<int>(elapsedTime * 5) % 2 == 0) {
                sf::Color color = anim.getColor();
                color.a = 128;
                anim.setColor(color);
            }
            else {
                sf::Color color = anim.getColor();
                color.a = 255;
                anim.setColor(color);
            }
        }
        else {
            sf::Color color = anim.getColor();
            color.a = 255;
            anim.setColor(color);
            flashClock.restart();

            auto& sprite = m_player->getComponent<CSprite>().sprite;
            auto spriteSize = sprite.getLocalBounds().getSize();

            m_player->addComponent<CBoundingBox>(spriteSize);
            m_player->addComponent<CState>().state = "alive";
        }
    }
    if (m_isSpecial) {
        specialAbility();
    }
}
void Scene_Cuba::adjustPlayerPosition() {


    auto center = m_worldView.getCenter();
    sf::Vector2f viewHalfSize = m_worldView.getSize() / 2.f;

    auto left = center.x - viewHalfSize.x;
    auto right = center.x + viewHalfSize.x;
    auto top = center.y - viewHalfSize.y + 150.f;
    auto bot = center.y + viewHalfSize.y;

    auto& player_pos = m_player->getComponent<CTransform>().pos;
    auto halfSize = m_player->getComponent<CBoundingBox>().halfSize;

    if (m_isEnd == false && m_isIntro == false) {
        player_pos.x = std::max(player_pos.x, left + halfSize.x);
        player_pos.x = std::min(player_pos.x, right - halfSize.x);
        player_pos.y = std::max(player_pos.y, top + halfSize.y);
        player_pos.y = std::min(player_pos.y, bot - halfSize.y);
    }

}
#pragma endregion

