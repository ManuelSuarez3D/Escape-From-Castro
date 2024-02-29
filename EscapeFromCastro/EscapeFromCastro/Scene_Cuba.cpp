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

namespace {
    std::random_device rd;
    std::mt19937 rng(rd());
}

Scene_Cuba::Scene_Cuba(GameEngine* gameEngine, const std::string& levelPath)
    : Scene(gameEngine),
    m_worldView(gameEngine->window().getDefaultView()) {

    registerActions();
    loadLevel(levelPath);

    sf::Vector2f spawnPos{ m_worldView.getSize().x / 2.f, m_worldBounds.height - m_worldView.getSize().y / 2.f };
    spawnPlayer(spawnPos);

    MusicPlayer::getInstance().play("gameTheme");
    MusicPlayer::getInstance().setVolume(50);
}
void Scene_Cuba::mapMovement() {
    auto worldViewBounds = getViewBounds();

    for (auto e : m_entityManager.getEntities("lvl1")) {

        auto& sprite = e->getComponent<CSprite>().sprite;

        sf::Vector2f spritePosition = sprite.getPosition();
        sf::FloatRect spriteBounds = sprite.getLocalBounds();

        // Calculate the position of the right side edge of the sprite
        float rightEdgeX = spritePosition.x + spriteBounds.width;

        if (worldViewBounds.contains(rightEdgeX, 0.f)) {
            m_config.scrollSpeed = 0;
            m_hasEnd = true;

            auto& pVel = m_player->getComponent<CTransform>().pos;
            m_player->removeComponent<CBoundingBox>();
            pVel.x += 3.f;
        }
    }
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
    registerAction(sf::Keyboard::Q, "QUIT");
    registerAction(sf::Keyboard::A, "LEFT");
    registerAction(sf::Keyboard::Left, "LEFT");
    registerAction(sf::Keyboard::D, "RIGHT");
    registerAction(sf::Keyboard::Right, "RIGHT");
    registerAction(sf::Keyboard::W, "UP");
    registerAction(sf::Keyboard::Up, "UP");
    registerAction(sf::Keyboard::S, "DOWN");
    registerAction(sf::Keyboard::Down, "DOWN");
}
void Scene_Cuba::onEnd() {
    m_game->changeScene("MENU", nullptr, false);
}
void Scene_Cuba::update(sf::Time dt) {
    sUpdate(dt);
}
void Scene_Cuba::entityMovement() {

}
void Scene_Cuba::playerMovement() {

    if (!m_hasEnd) {
        auto& pPos = m_player->getComponent<CTransform>().pos;
        sf::Vector2f pv{ 0.f,0.f };
        auto& pInput = m_player->getComponent<CInput>();
        if (pInput.LEFT) pv.x -= 1;
        if (pInput.RIGHT) pv.x += 1;
        if (pInput.UP) pv.y -= 1;
        if (pInput.DOWN) pv.y += 1;
        pv = normalize(pv);

        m_player->getComponent<CTransform>().vel = m_config.playerSpeed * pv;
    }

}
void Scene_Cuba::sRender() {

    m_game->window().setView(m_worldView);

    sf::RenderWindow& window = m_game->window();

    for (auto& e : m_entityManager.getEntities("lvl1")) {

        if (e->getComponent<CSprite>().has) {

            auto& sprite = e->getComponent<CSprite>().sprite;
            m_game->window().draw(sprite);
        }
    }
    for (auto& e : m_entityManager.getEntities("player")) {

        if (!e->hasComponent<CSprite>())
            continue;

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
        auto& sprite = e->getComponent<CSprite>().sprite;
        if (e->hasComponent<CTransform>()) {
            auto& tfm = e->getComponent<CTransform>();
            sprite.setPosition(tfm.pos);
            sprite.setRotation(tfm.angle);
        }
        m_game->window().draw(sprite);
    }
    for (auto& e : m_entityManager.getEntities("enemy")) {

        if (!e->hasComponent<CSprite>())
            continue;

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
        auto& sprite = e->getComponent<CSprite>().sprite;
        if (e->hasComponent<CTransform>()) {
            auto& anim = e->getComponent<CAnimation>().animation;
            auto& tfm = e->getComponent<CTransform>();
            anim.getSprite().setPosition(tfm.pos);
            anim.getSprite().setRotation(tfm.angle);

            m_game->window().draw(anim.getSprite());
        }

    }

    sf::View view1;
    view1.reset(sf::FloatRect(0.f, 0.f, 900.f, 512.f));
    m_game->window().setView(view1);

    sf::View view = window.getView();
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f viewCenter = view.getCenter();
    sf::Vector2f viewMousePos = window.mapPixelToCoords(mousePos, view);
    const float maxTime = 6.0f;

    if (m_elapsedTime < maxTime) {
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
                auto overlap = Physics::getOverlap(viewMousePos, e1);
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
                auto overlap = Physics::getOverlap(viewMousePos, e1);
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

            auto overlap = Physics::getOverlap(viewMousePos, e);
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

            auto overlap = Physics::getOverlap(viewMousePos, e);
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

            auto overlap = Physics::getOverlap(viewMousePos, e);
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

    m_score_text.setString(std::to_string(m_score));
    m_score_text.setFillColor(sf::Color::Yellow);

    m_game->window().draw(m_score_text);

    m_game->window().setView(m_worldView);

}
sf::FloatRect Scene_Cuba::getViewBounds() {
    auto view = m_game->window().getView();
    return sf::FloatRect(
        (view.getCenter().x - view.getSize().x / 2.f), (view.getCenter().y - view.getSize().y / 2.f),
        view.getSize().x, view.getSize().y);
}
sf::FloatRect Scene_Cuba::getPlayBounds() const {
    auto center = m_worldView.getCenter();
    auto size = m_worldView.getSize();
    auto rightTop = center + sf::Vector2f(size.x / 2.f, -size.y / 2.f);

    rightTop.x += size.x / 2.f;
    size.x += size.x;

    return sf::FloatRect(rightTop, size);
}
void Scene_Cuba::sDestroyOutsideBounds() {
    auto playBounds = getViewBounds();
    for (auto e : m_entityManager.getEntities()) {
        auto pos = e->getComponent<CTransform>().pos;
        if (!playBounds.contains(pos)) {
            e->destroy();
        }
    }
}
void Scene_Cuba::sDoAction(const Command& action) {

    auto& pPos = m_player->getComponent<CTransform>().pos;


    if (action.type() == "START") {
        if (action.name() == "PAUSE") { setPaused(!m_isPaused); }
        else if (action.name() == "QUIT") { m_game->quitLevel(); }
        else if (action.name() == "BACK") { m_game->backLevel(); }
        else if (action.name() == "LEFT") { m_player->getComponent<CInput>().LEFT = true; }
        else if (action.name() == "RIGHT") { m_player->getComponent<CInput>().RIGHT = true; }
        else if (action.name() == "UP") { m_player->getComponent<CInput>().UP = true; }
        else if (action.name() == "DOWN") { m_player->getComponent<CInput>().DOWN = true; }
        else if (action.name() == "TOGGLE_COLLISION") { m_drawAABB = !m_drawAABB; }
    }

    else if (action.type() == "END") {
        if (action.name() == "LEFT") { m_player->getComponent<CInput>().LEFT = false; }
        else if (action.name() == "RIGHT") { m_player->getComponent<CInput>().RIGHT = false; }
        else if (action.name() == "UP") { m_player->getComponent<CInput>().UP = false; }
        else if (action.name() == "DOWN") { m_player->getComponent<CInput>().DOWN = false; }
    }
}
void Scene_Cuba::sMovement(sf::Time dt) {

    playerMovement();

    for (auto& e : m_entityManager.getEntities("player")) {
        if (e->hasComponent<CTransform>()) {
            auto& tfm = e->getComponent<CTransform>();

            tfm.pos += tfm.vel * dt.asSeconds();
        }
    }
    for (auto& e : m_entityManager.getEntities("enemy")) {
        if (e->hasComponent<CTransform>()) {
            auto& tfm = e->getComponent<CTransform>();

            tfm.pos -= tfm.vel * dt.asSeconds();
        }
    }
    /* for (auto& e : m_entityManager.getEntities("ui")) {
         if (e->hasComponent<CTransform>()) {
             auto& tfm = e->getComponent<CTransform>();

             tfm.pos += sf::Vector2f{ m_config.scrollSpeed, 0.f } *dt.asSeconds();
         }
     }*/
     //for (auto& e : m_entityManager.getEntities("chapter1")) {
     //    if (e->hasComponent<CTransform>()) {
     //        auto& tfm = e->getComponent<CTransform>();

     //        tfm.pos += sf::Vector2f{ m_config.scrollSpeed, 0.f } *dt.asSeconds();
     //    }
     //}
     //for (auto& e : m_entityManager.getEntities("pause_button")) {
     //    if (e->hasComponent<CTransform>()) {
     //        auto& tfm = e->getComponent<CTransform>();

     //        tfm.pos += sf::Vector2f{ m_config.scrollSpeed, 0.f } *dt.asSeconds();
     //    }
     //}
     //for (auto& e : m_entityManager.getEntities("play_button")) {
     //    if (e->hasComponent<CTransform>()) {
     //        auto& tfm = e->getComponent<CTransform>();

     //        tfm.pos += sf::Vector2f{ m_config.scrollSpeed, 0.f } *dt.asSeconds();
     //    }
     //}
     //for (auto& e : m_entityManager.getEntities("exit_button")) {
     //    if (e->hasComponent<CTransform>()) {
     //        auto& tfm = e->getComponent<CTransform>();

     //        tfm.pos += sf::Vector2f{ m_config.scrollSpeed, 0.f } *dt.asSeconds();
     //    }
     //}
     //for (auto& e : m_entityManager.getEntities("uihp3")) {
     //    if (e->hasComponent<CTransform>()) {
     //        auto& tfm = e->getComponent<CTransform>();
     //        tfm.pos += sf::Vector2f{ m_config.scrollSpeed, 0.f } *dt.asSeconds();
     //    }
     //    for (auto& e : m_entityManager.getEntities("uihp2")) {
     //        if (e->hasComponent<CTransform>()) {
     //            auto& tfm = e->getComponent<CTransform>();
     //            tfm.pos += sf::Vector2f{ m_config.scrollSpeed, 0.f } *dt.asSeconds();
     //        }
     //        for (auto& e : m_entityManager.getEntities("uihp1")) {
     //            if (e->hasComponent<CTransform>()) {
     //                auto& tfm = e->getComponent<CTransform>();
     //                tfm.pos += sf::Vector2f{ m_config.scrollSpeed, 0.f } *dt.asSeconds();
     //            }

     //        }
     //    }
     //}
     //for (auto& e : m_entityManager.getEntities("uispecial3")) {
     //    if (e->hasComponent<CTransform>()) {
     //        auto& tfm = e->getComponent<CTransform>();
     //        tfm.pos += sf::Vector2f{ m_config.scrollSpeed, 0.f } *dt.asSeconds();
     //    }
     //    for (auto& e : m_entityManager.getEntities("uispecial2")) {
     //        if (e->hasComponent<CTransform>()) {
     //            auto& tfm = e->getComponent<CTransform>();
     //            tfm.pos += sf::Vector2f{ m_config.scrollSpeed, 0.f } *dt.asSeconds();
     //        }
     //        for (auto& e : m_entityManager.getEntities("uispecial1")) {
     //            if (e->hasComponent<CTransform>()) {
     //                auto& tfm = e->getComponent<CTransform>();
     //                tfm.pos += sf::Vector2f{ m_config.scrollSpeed, 0.f } *dt.asSeconds();
     //            }

     //        }
     //    }
     //}
}
void Scene_Cuba::sCollisions() {

}
void Scene_Cuba::sUpdate(sf::Time dt) {
    auto& pST = m_player->getComponent<CState>().state;
    SoundPlayer::getInstance().removeStoppedSounds();


    if (m_isPaused)
        return;

    m_elapsedTime += dt.asSeconds();
    m_worldView.move(m_config.scrollSpeed * dt.asSeconds() * 1, 0.f);
    m_entityManager.update();
    adjustPlayerPosition();
    mapMovement();


    //float scrollSpeed = m_config.scrollSpeed * dt.asSeconds() * 1;
    //sf::Vector2f textPosition = m_score_text.getPosition();
    //textPosition.x += scrollSpeed;
    //m_score_text.setPosition(textPosition);
    sAnimation(dt);
    sEnemySpawner(dt);
    checkCollisions();
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
void Scene_Cuba::resetEntities() {

}
void Scene_Cuba::initLife() {

}
void Scene_Cuba::spawnPlayer(sf::Vector2f pos) {

    m_player = m_entityManager.addEntity("player");
    m_player->addComponent<CTransform>(pos);

    m_player->addComponent<CBoundingBox>(sf::Vector2f(48.f, 64.f));
    m_player->addComponent<CInput>();

    auto& sprite = m_player->addComponent<CSprite>().sprite;
    auto& spriteName = m_player->addComponent<CSprite>(Assets::getInstance().getTexture("Start01")).sprite;
    sprite.setTexture(Assets::getInstance().getTexture("Start01"));
    auto spriteSize = sprite.getLocalBounds().getSize();

    m_player->addComponent<CBoundingBox>(spriteSize);
    sf::Vector2f spriteOrigin = sprite.getOrigin();
    std::cout << "spawn called";
    centerOrigin(sprite);

}
void Scene_Cuba::spawnEnemy(sf::Vector2f pos) {

    auto raceCarL = m_entityManager.addEntity("enemy");

    raceCarL->addComponent<CTransform>(pos, sf::Vector2f{ m_config.enemySpeed, 0.f });
    raceCarL->addComponent<CBoundingBox>(sf::Vector2f(48.f, 64.f));
    auto& sprite = raceCarL->addComponent<CSprite>().sprite;
    auto& spriteName = raceCarL->addComponent<CSprite>(Assets::getInstance().getTexture("Start02")).sprite;
    raceCarL->addComponent<CAnimation>(Assets::getInstance().getAnimation("Military_Left"));
    sprite.setTexture(Assets::getInstance().getTexture("Start02"));
    auto spriteSize = sprite.getLocalBounds().getSize();

    raceCarL->addComponent<CBoundingBox>(spriteSize);
    sf::Vector2f spriteOrigin = sprite.getOrigin();

    centerOrigin(sprite);

}
void Scene_Cuba::spawnBoat(sf::Vector2f pos){

    //auto raceCarL = m_entityManager.addEntity("enemy");

    //raceCarL->addComponent<CTransform>(pos, sf::Vector2f{ m_config.enemySpeed, 0.f });
    //raceCarL->addComponent<CBoundingBox>(sf::Vector2f(48.f, 64.f));
    //auto& sprite = raceCarL->addComponent<CSprite>().sprite;
    //auto& spriteName = raceCarL->addComponent<CSprite>(Assets::getInstance().getTexture("Start02")).sprite;
    //raceCarL->addComponent<CAnimation>(Assets::getInstance().getAnimation("Military_Left"));
    //sprite.setTexture(Assets::getInstance().getTexture("Start02"));
    //auto spriteSize = sprite.getLocalBounds().getSize();

    //raceCarL->addComponent<CBoundingBox>(spriteSize);
    //sf::Vector2f spriteOrigin = sprite.getOrigin();

    //centerOrigin(sprite);
}
void Scene_Cuba::spawnCoral(sf::Vector2f pos){

    //auto raceCarL = m_entityManager.addEntity("enemy");

    //raceCarL->addComponent<CTransform>(pos, sf::Vector2f{ m_config.enemySpeed, 0.f });
    //raceCarL->addComponent<CBoundingBox>(sf::Vector2f(48.f, 64.f));
    //auto& sprite = raceCarL->addComponent<CSprite>().sprite;
    //auto& spriteName = raceCarL->addComponent<CSprite>(Assets::getInstance().getTexture("Start02")).sprite;
    //raceCarL->addComponent<CAnimation>(Assets::getInstance().getAnimation("Military_Left"));
    //sprite.setTexture(Assets::getInstance().getTexture("Start02"));
    //auto spriteSize = sprite.getLocalBounds().getSize();

    //raceCarL->addComponent<CBoundingBox>(spriteSize);
    //sf::Vector2f spriteOrigin = sprite.getOrigin();

    //centerOrigin(sprite);
}
void Scene_Cuba::spawnIsland(sf::Vector2f pos){

    //auto raceCarL = m_entityManager.addEntity("enemy");

    //raceCarL->addComponent<CTransform>(pos, sf::Vector2f{ m_config.enemySpeed, 0.f });
    //raceCarL->addComponent<CBoundingBox>(sf::Vector2f(48.f, 64.f));
    //auto& sprite = raceCarL->addComponent<CSprite>().sprite;
    //auto& spriteName = raceCarL->addComponent<CSprite>(Assets::getInstance().getTexture("Start02")).sprite;
    //raceCarL->addComponent<CAnimation>(Assets::getInstance().getAnimation("Military_Left"));
    //sprite.setTexture(Assets::getInstance().getTexture("Start02"));
    //auto spriteSize = sprite.getLocalBounds().getSize();

    //raceCarL->addComponent<CBoundingBox>(spriteSize);
    //sf::Vector2f spriteOrigin = sprite.getOrigin();

    //centerOrigin(sprite);
}
void Scene_Cuba::spawnShark(sf::Vector2f pos) {

    //auto raceCarL = m_entityManager.addEntity("enemy");

    //raceCarL->addComponent<CTransform>(pos, sf::Vector2f{ m_config.enemySpeed, 0.f });
    //raceCarL->addComponent<CBoundingBox>(sf::Vector2f(48.f, 64.f));
    //auto& sprite = raceCarL->addComponent<CSprite>().sprite;
    //auto& spriteName = raceCarL->addComponent<CSprite>(Assets::getInstance().getTexture("Start02")).sprite;
    //raceCarL->addComponent<CAnimation>(Assets::getInstance().getAnimation("Military_Left"));
    //sprite.setTexture(Assets::getInstance().getTexture("Start02"));
    //auto spriteSize = sprite.getLocalBounds().getSize();

    //raceCarL->addComponent<CBoundingBox>(spriteSize);
    //sf::Vector2f spriteOrigin = sprite.getOrigin();

    //centerOrigin(sprite);

}
void Scene_Cuba::sEnemySpawner(sf::Time dt) {

    sf::FloatRect field = getPlayBounds();

    std::exponential_distribution<float> exp(1.f / 2);
    std::uniform_real_distribution<float> xDis(field.left, field.left + field.width);
    std::uniform_real_distribution<float> yDis(field.top + 143, field.top + field.height);

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
void Scene_Cuba::adjustPlayerPosition() {

    auto center = m_worldView.getCenter();
    sf::Vector2f viewHalfSize = m_worldView.getSize() / 2.f;


    auto left = center.x - viewHalfSize.x;
    auto right = center.x + viewHalfSize.x;
    auto top = center.y - viewHalfSize.y + 143;
    auto bot = center.y + viewHalfSize.y;

    auto& player_pos = m_player->getComponent<CTransform>().pos;
    auto halfSize = m_player->getComponent<CBoundingBox>().halfSize;

    if (m_hasEnd == false) {
        player_pos.x = std::max(player_pos.x, left + halfSize.x);
        player_pos.x = std::min(player_pos.x, right - halfSize.x);
        player_pos.y = std::max(player_pos.y, top + halfSize.y);
        player_pos.y = std::min(player_pos.y, bot - halfSize.y);
    }
}
void Scene_Cuba::checkCollisions() {
    for (auto e : m_entityManager.getEntities("enemy")) {
        auto overlap = Physics::getOverlap(m_player, e);
        if (overlap.x > 0 and overlap.y > 0) {
            m_player->addComponent<CState>().state = "dead";
            e->destroy();

            checkPlayerState();
        }
    }

}
void Scene_Cuba::checkPlayerState() {
    auto& pST = m_player->getComponent<CState>().state;
    sf::Vector2f spawnPos{ m_worldView.getSize().x / 2.f, m_worldView.getSize().y / 2.f };

    if (pST == "dead") {

        m_player->destroy();
        m_player->removeComponent<CBoundingBox>();
        m_life -= 1;

        std::cout << m_life;
        if (m_life != 0) {
            spawnPlayer(spawnPos);
        }
    }


}