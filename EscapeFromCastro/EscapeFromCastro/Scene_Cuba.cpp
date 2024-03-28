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

    loadLevel(levelPath);
<<<<<<< Updated upstream
    sInit();
    sf::Vector2f spawnPos{ m_worldView.getSize().x / 2.f, m_worldBounds.height - m_worldView.getSize().y / 2.f };
    spawnPlayer(spawnPos);

    MusicPlayer::getInstance().play("gameTheme");
    MusicPlayer::getInstance().setVolume(50);
=======
    init();
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
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
=======
        else if (token == "UiSpecial") {
>>>>>>> Stashed changes
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("ui");
            e->addComponent<CTransform>(pos);
            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;

            sprite.setOrigin(0.f, 0.f);
            sprite.setPosition(pos);
        }
        else if (token == "UiScore") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("ui");
            e->addComponent<CTransform>(pos);
            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
            sprite.setOrigin(0.f, 0.f);
            sprite.setPosition(pos);
        }
        else if (token == "UiHp1") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("uihp1");
            e->addComponent<CTransform>(pos);
            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;

            sprite.setOrigin(0.f, 0.f);
            sprite.setPosition(pos);

        }
        else if (token == "UiHp2") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("uihp2");
            e->addComponent<CTransform>(pos);
            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;

            sprite.setOrigin(0.f, 0.f);
            sprite.setPosition(pos);

        }
        else if (token == "UiHp3") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("uihp3");
            e->addComponent<CTransform>(pos);
            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;

            sprite.setOrigin(0.f, 0.f);
            sprite.setPosition(pos);

        }
        else if (token == "UiCocaine1") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("uicocaine1");
            e->addComponent<CTransform>(pos);
            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;

            sprite.setOrigin(0.f, 0.f);
            sprite.setPosition(pos);

        }
        else if (token == "UiCocaine2") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("uicocaine2");
            e->addComponent<CTransform>(pos);
            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;

            sprite.setOrigin(0.f, 0.f);
            sprite.setPosition(pos);

        }
        else if (token == "UiCocaine3") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("uicocaine3");
            e->addComponent<CTransform>(pos);
            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;

            sprite.setOrigin(0.f, 0.f);
            sprite.setPosition(pos);

        }
        else if (token == "Menu1") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("menu1");

            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
            auto spriteSize = sprite.getLocalBounds().getSize();

            e->addComponent<CBoundingBox>(spriteSize);
            sf::Vector2f spriteOrigin = sprite.getOrigin();

            sf::Vector2f boundingBoxPosition = pos + spriteOrigin;

            e->addComponent<CTransform>(boundingBoxPosition);
        }
        else if (token == "Menu2") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("menu2");

            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
            auto spriteSize = sprite.getLocalBounds().getSize();

            e->addComponent<CBoundingBox>(spriteSize);
            sf::Vector2f spriteOrigin = sprite.getOrigin();

            sf::Vector2f boundingBoxPosition = pos + spriteOrigin;

            e->addComponent<CTransform>(boundingBoxPosition);
        }
        else if (token == "MenuT") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("menut");

            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
            auto spriteSize = sprite.getLocalBounds().getSize();

            e->addComponent<CBoundingBox>(spriteSize);
            sf::Vector2f spriteOrigin = sprite.getOrigin();

            sf::Vector2f boundingBoxPosition = pos + spriteOrigin;

            e->addComponent<CTransform>(boundingBoxPosition);

        }
        else if (token == "Restart1M") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("restart1m");

            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
            auto spriteSize = sprite.getLocalBounds().getSize();

            e->addComponent<CBoundingBox>(spriteSize);
            sf::Vector2f spriteOrigin = sprite.getOrigin();

            sf::Vector2f boundingBoxPosition = pos + spriteOrigin;

            e->addComponent<CTransform>(boundingBoxPosition);
        }
        else if (token == "Restart2M") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("restart2m");

            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
            auto spriteSize = sprite.getLocalBounds().getSize();

            e->addComponent<CBoundingBox>(spriteSize);
            sf::Vector2f spriteOrigin = sprite.getOrigin();

            sf::Vector2f boundingBoxPosition = pos + spriteOrigin;

            e->addComponent<CTransform>(boundingBoxPosition);
        }
        else if (token == "Controls1M") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("ctrls1m");

            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
            auto spriteSize = sprite.getLocalBounds().getSize();

            e->addComponent<CBoundingBox>(spriteSize);
            sf::Vector2f spriteOrigin = sprite.getOrigin();

            sf::Vector2f boundingBoxPosition = pos + spriteOrigin;

            e->addComponent<CTransform>(boundingBoxPosition);

        }
        else if (token == "Controls2M") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("ctrls2m");

            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
            auto spriteSize = sprite.getLocalBounds().getSize();

            e->addComponent<CBoundingBox>(spriteSize);
            sf::Vector2f spriteOrigin = sprite.getOrigin();

            sf::Vector2f boundingBoxPosition = pos + spriteOrigin;

            e->addComponent<CTransform>(boundingBoxPosition);

        }
        else if (token == "Quit1M") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("quit1m");

            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
            auto spriteSize = sprite.getLocalBounds().getSize();

            e->addComponent<CBoundingBox>(spriteSize);
            sf::Vector2f spriteOrigin = sprite.getOrigin();

            sf::Vector2f boundingBoxPosition = pos + spriteOrigin;

            e->addComponent<CTransform>(boundingBoxPosition);

        }
        else if (token == "Quit2M") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("quit2m");

            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
            auto spriteSize = sprite.getLocalBounds().getSize();

            e->addComponent<CBoundingBox>(spriteSize);
            sf::Vector2f spriteOrigin = sprite.getOrigin();

            sf::Vector2f boundingBoxPosition = pos + spriteOrigin;

            e->addComponent<CTransform>(boundingBoxPosition);

        }
        else if (token == "InstrcM") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("instrcM");

            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
            auto spriteSize = sprite.getLocalBounds().getSize();

            e->addComponent<CBoundingBox>(spriteSize);
            sf::Vector2f spriteOrigin = sprite.getOrigin();

            sf::Vector2f boundingBoxPosition = pos + spriteOrigin;

            e->addComponent<CTransform>(boundingBoxPosition);

            }
        else if (token == "Back1M") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("back1m");

            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
            auto spriteSize = sprite.getLocalBounds().getSize();

            e->addComponent<CBoundingBox>(spriteSize);
            sf::Vector2f spriteOrigin = sprite.getOrigin();

            sf::Vector2f boundingBoxPosition = pos + spriteOrigin;

            e->addComponent<CTransform>(boundingBoxPosition);

        }
        else if (token == "Back2M") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("back2M");

            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
            auto spriteSize = sprite.getLocalBounds().getSize();

            e->addComponent<CBoundingBox>(spriteSize);
            sf::Vector2f spriteOrigin = sprite.getOrigin();

            sf::Vector2f boundingBoxPosition = pos + spriteOrigin;

            e->addComponent<CTransform>(boundingBoxPosition);
        }
        else if (token == "GameOverT") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("gameovert");
            e->addComponent<CTransform>(pos);
            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;

            sprite.setOrigin(0.f, 0.f);
            sprite.setPosition(pos);

        }
        else if (token == "Restart1G") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("restart1g");

            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
            auto spriteSize = sprite.getLocalBounds().getSize();

            e->addComponent<CBoundingBox>(spriteSize);
            sf::Vector2f spriteOrigin = sprite.getOrigin();

            sf::Vector2f boundingBoxPosition = pos + spriteOrigin;

            e->addComponent<CTransform>(boundingBoxPosition);
            }
        else if (token == "Restart2G") {
                std::string name;
                sf::Vector2f pos;

                config >> name >> pos.x >> pos.y;
                auto e = m_entityManager.addEntity("restart2g");

                auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
                auto spriteSize = sprite.getLocalBounds().getSize();

                e->addComponent<CBoundingBox>(spriteSize);
                sf::Vector2f spriteOrigin = sprite.getOrigin();

                sf::Vector2f boundingBoxPosition = pos + spriteOrigin;

                e->addComponent<CTransform>(boundingBoxPosition);
                }
        else if (token == "Quit1G") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("quit1g");

            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
            auto spriteSize = sprite.getLocalBounds().getSize();

            e->addComponent<CBoundingBox>(spriteSize);
            sf::Vector2f spriteOrigin = sprite.getOrigin();

            sf::Vector2f boundingBoxPosition = pos + spriteOrigin;

            e->addComponent<CTransform>(boundingBoxPosition);

            }
        else if (token == "Quit2G") {
                std::string name;
                sf::Vector2f pos;

                config >> name >> pos.x >> pos.y;
                auto e = m_entityManager.addEntity("quit2g");

                auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
                auto spriteSize = sprite.getLocalBounds().getSize();

                e->addComponent<CBoundingBox>(spriteSize);
                sf::Vector2f spriteOrigin = sprite.getOrigin();

                sf::Vector2f boundingBoxPosition = pos + spriteOrigin;

                e->addComponent<CTransform>(boundingBoxPosition);

                }
        else if (token == "Chapter1a") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("chapter1a");
            e->addComponent<CTransform>(pos);
            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;

            sprite.setOrigin(0.f, 0.f);
            sprite.setPosition(pos);

        }
<<<<<<< Updated upstream
=======
        else if (token == "Chapter1b") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("chapter1b");
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
            auto spriteSize = sprite.getLocalBounds().getSize();
            e->addComponent<CBoundingBox>(spriteSize);

            sprite.setOrigin(0.f, 0.f);
            sprite.setPosition(pos);

        }
>>>>>>> Stashed changes
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
    registerAction(sf::Keyboard::A, "LEFT");
    registerAction(sf::Keyboard::Left, "LEFT");
    registerAction(sf::Keyboard::D, "RIGHT");
    registerAction(sf::Keyboard::Right, "RIGHT");
    registerAction(sf::Keyboard::W, "UP");
    registerAction(sf::Keyboard::Up, "UP");
    registerAction(sf::Keyboard::S, "DOWN");
    registerAction(sf::Keyboard::Down, "DOWN");
    registerAction(sf::Keyboard::C, "TOGGLE_COLLISION");
}
void Scene_Cuba::spawnPlayer(sf::Vector2f pos) {

    m_player = m_entityManager.addEntity("player");
    m_player->addComponent<CTransform>(pos);
<<<<<<< Updated upstream

=======
>>>>>>> Stashed changes
    m_player->addComponent<CInput>();

    auto& sprite = m_player->addComponent<CSprite>(Assets::getInstance().getTexture("Tony_Idle")).sprite;
    m_player->addComponent<CAnimation>(Assets::getInstance().getAnimation("Tony_Idle_Right"));


    auto spriteSize = sprite.getLocalBounds().getSize();
   // m_player->addComponent<CType>().player = true;
    m_player->addComponent<CBoundingBox>(spriteSize);
}
void Scene_Cuba::init() {

    registerActions();

    m_menu_cuba.push_back(std::make_pair("MENU", false));
    m_menu_cuba.push_back(std::make_pair("RESTART", false));
    m_menu_cuba.push_back(std::make_pair("CONTROLS", false));
    m_menu_cuba.push_back(std::make_pair("BACK", false));
    m_menu_cuba.push_back(std::make_pair("QUIT", false));

    sf::FloatRect field = getPlayerSpawnBounds();
    sf::Vector2f spawnPos{ field.left - field.width, (field.top + field.height) - 173.f };
    spawnPlayer(spawnPos);

    MusicPlayer::getInstance().play("gameTheme");
    MusicPlayer::getInstance().setVolume(50);

}
#pragma endregion

#pragma region Menu
bool Scene_Cuba::menuSound(bool check) {

   if (check == true && menuState("ALL"))
       SoundPlayer::getInstance().play("menuPing");
   
   else if (check == true && menuState("GUIDE") && !menuState("BACK")) {
       SoundPlayer::getInstance().play("menuPing");
   }
   
   return check;
}
void Scene_Cuba::menuSelection(std::string tag, bool selection) {

    if (tag == "ALL") {
        for (auto& item : m_menu_cuba) {
            item.second = selection;
        }
    }
    
    for (auto& item : m_menu_cuba) {
        if (item.first == tag) {
            item.second = selection;
        }
    }
}
bool Scene_Cuba::menuState(std::string tag) {

   if (tag == "ALL") {
       return std::all_of(m_menu_cuba.begin(), m_menu_cuba.end(), [](const auto& item) {
           return !item.second;
           });
   }
   else if (tag == "GUIDE") {
       return m_isGuide;
   }
   
   for (auto& item : m_menu_cuba) {
       if (item.first == tag) {
           return item.second;
       }
   }
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
<<<<<<< Updated upstream
            m_config.scrollSpeed = 0;
            m_hasEnd = true;
=======
            m_isEnd = true;
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
                        spawnPos = sf::Vector2f(worldViewBounds.left + worldViewBounds.width + boundingBox.size.x / 2.0f,
                            randomSpawn(worldViewBounds.top + 150.f, worldViewBounds.top + worldViewBounds.height - 20.f));
                        transform.pos = spawnPos;
                    }
                    else if (transform.pos.x > worldViewBounds.left + worldViewBounds.width) {
                        transform.pos.x = worldViewBounds.left - boundingBox.size.x / 2.0f;
                    }

                    if (transform.pos.y < worldViewBounds.top) {
                        transform.pos.y = worldViewBounds.top + worldViewBounds.height + boundingBox.size.y / 2.0f;
                    }
                    else if (transform.pos.y > worldViewBounds.top + worldViewBounds.height) {
                        transform.pos.y = worldViewBounds.top - boundingBox.size.y / 2.0f;
=======
                        e->destroy();
>>>>>>> Stashed changes
                    }
                }
            }
        }
    }
}
void Scene_Cuba::playerMovement() {
<<<<<<< Updated upstream

    bool test = sf::Keyboard::isKeyPressed(sf::Keyboard::Q);
    if (!m_hasEnd) {
        auto& pPos = m_player->getComponent<CTransform>().pos;
        sf::Vector2f pv{ 0.f,0.f };
        auto& pInput = m_player->getComponent<CInput>();
        if (pInput.LEFT) pv.x -= 1;
        if (pInput.RIGHT) pv.x += 1;
        if (pInput.UP) pv.y -= 1;
        if (pInput.DOWN) pv.y += 1;
=======
    auto worldViewBounds = getViewBounds();
    auto& transform = m_player->getComponent<CTransform>();
    auto& boundingBox = m_player->getComponent<CBoundingBox>();

    sf::FloatRect entityBounds(
        transform.pos.x - boundingBox.size.x / 2.0f,
        transform.pos.y - boundingBox.size.y / 2.0f,
        boundingBox.size.x,
        boundingBox.size.y
    );

    if (m_isIntro) {
        m_player->getComponent<CTransform>().vel.y = 0.0f;
        m_player->getComponent<CTransform>().vel.x = m_config.playerSpeed / 2;
    }
    else if (m_isPlay) {
        auto& pPos = m_player->getComponent<CTransform>().pos;
        sf::Vector2f pv{ 0.f,0.f };
        auto& pInput = m_player->getComponent<CInput>();
        if (pInput.LEFT) pv.x -= 1.f;
        if (pInput.RIGHT) pv.x += 1.f;
        if (pInput.UP) pv.y -= 1.f;
        if (pInput.DOWN) pv.y += 1.f;
>>>>>>> Stashed changes
        pv = normalize(pv);

        float horizontalSpeed = 0.8f;
        float verticalSpeed = 0.5f;

        if (pv.x == 0 && pv.y == 0) {
            m_player->getComponent<CTransform>().vel = m_config.scrollSpeed * sf::Vector2f(1.f, 0.f);
        }
        else if (m_isSpecial) {
            m_player->getComponent<CTransform>().vel = m_config.playerSpeed * pv;
        }
<<<<<<< Updated upstream

    }
    else {
=======
        else {
            m_player->getComponent<CTransform>().vel = m_config.playerSpeed * sf::Vector2f(horizontalSpeed * pv.x, verticalSpeed * pv.y);
        }
    }
    else if (m_isEnd){
>>>>>>> Stashed changes
        m_player->removeComponent<CBoundingBox>();
        m_player->getComponent<CTransform>().vel.y = 0.0f;
        m_player->getComponent<CTransform>().vel.x = m_config.playerSpeed * 1.5f;
    }

}
#pragma endregion

#pragma region System
<<<<<<< Updated upstream
void Scene_Cuba::sInit() {
    resetEntities();
=======
void Scene_Cuba::sState(sf::Time dt) {

    SoundPlayer::getInstance().removeStoppedSounds();
    //m_entityManager.update();

    //if (m_isSpecial)
    //    specialState();

    timeState(dt);
    playerState();
    gameState();
    lifeState();
>>>>>>> Stashed changes
}
void Scene_Cuba::sRender() {

    m_game->window().setView(m_worldView);

    for (auto& e : m_entityManager.getEntities()) {
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
    }

    renderEntities();
    renderUI();
    menuSound();
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
                m_isSpecial = true;
                m_special -= 1;
                specialAbility();
            }
        }
        else if (action.name() == "SHOOT")
        {
            if (m_isSpecial && m_player->getComponent<CInput>().canShoot) {
                spawnBullet(m_player);
                m_player->getComponent<CInput>().shoot = true;
                m_player->getComponent<CInput>().canShoot = false;
                m_player->addComponent<CAnimation>(Assets::getInstance().getAnimation("Tontana_Fire_Right")).animation.m_currentFrame += m_player->getComponent<CAnimation>().animation.m_currentFrame;
            }
        }
        else if (action.name() == "LEFT") { m_player->getComponent<CInput>().LEFT = true; }
        else if (action.name() == "RIGHT") { m_player->getComponent<CInput>().RIGHT = true; }
        else if (action.name() == "UP") { m_player->getComponent<CInput>().UP = true; }
        else if (action.name() == "DOWN") { m_player->getComponent<CInput>().DOWN = true; }
        else if (action.name() == "TOGGLE_COLLISION") { m_drawAABB = !m_drawAABB; }
       /* else if (action.name() == "MOUSE_CLICK") {

            if (menuState("MENU"))
                m_isMenu = true;

            else if (menuState("RESTART")) {
                onEnd();
            }
            else if (menuState("CONTROLS")) {
                m_isGuide = true;

                if (menuState("BACK")) {
                    menuSelection("ALL", false);
                    m_isGuide = false;
                }
            }
            else if (menuState("QUIT")) {
                onEnd();
            }
        }*/
    }

    else if (action.type() == "END") {
        if (action.name() == "LEFT") { m_player->getComponent<CInput>().LEFT = false; }
        else if (action.name() == "SHOOT") {

            m_player->getComponent<CInput>().canShoot = true;
            m_player->addComponent<CAnimation>(Assets::getInstance().getAnimation("Tontana_Idle_Right")).animation.m_currentFrame += m_player->getComponent<CAnimation>().animation.m_currentFrame;

        }
        else if (action.name() == "RIGHT") { m_player->getComponent<CInput>().RIGHT = false; }
        else if (action.name() == "UP") { m_player->getComponent<CInput>().UP = false; }
        else if (action.name() == "DOWN") { m_player->getComponent<CInput>().DOWN = false; }
    }
}
void Scene_Cuba::sMovement(sf::Time dt) {

    m_worldView.move(m_config.scrollSpeed * dt.asSeconds() * 1, 0.f);
    sf::FloatRect view = getViewBounds();

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
    for (auto& e : m_entityManager.getEntities("bullet")) {
        if (e->hasComponent<CTransform>()) {
            auto& tfm = e->getComponent<CTransform>();

            if (m_elapsedTime > 1.f)
                tfm.pos += tfm.vel * dt.asSeconds();
        }
    }

    for (auto& e : m_entityManager.getEntities("curtain")) {
        auto ebb = e->getComponent<CBoundingBox>();
        if (e->hasComponent<CTransform>()) {
            auto& tfm = e->getComponent<CTransform>();
            if (m_isIntro && (tfm.pos.y + ebb.size.y) > view.top) {
                tfm.pos.y -= 145.f * dt.asSeconds();
            }
            else if (m_isEnd && (tfm.pos.y + ebb.size.y) < 512.f) {
                tfm.pos.y += 145.f * dt.asSeconds();
            }
        }
    }

    for (auto& e : m_entityManager.getEntities("curtaintop")) {
        auto ebb = e->getComponent<CBoundingBox>();
        if (e->hasComponent<CTransform>()) {
            auto& tfm = e->getComponent<CTransform>();
            if (m_isPlay && (tfm.pos.y + ebb.size.y) > view.top){
                tfm.pos.y -= 50.f * dt.asSeconds();
            }
            else if (m_isEnd && (tfm.pos.y + ebb.size.y) < 512.f) {
                tfm.pos.y += 50.f * dt.asSeconds();
            }
        }
    }

}
void Scene_Cuba::sCollisions() {
    checkCollisions();
    checkPlayerPosition();
}
void Scene_Cuba::sUpdate(sf::Time dt) {

    if (m_isPaused)
        return;


    m_entityManager.update();

    sState(dt);
    sAnimation(dt);
    sEntitySpawner(dt);
    sCollisions();
    sMovement(dt);
}
void Scene_Cuba::sAnimation(sf::Time dt) {
    for (auto e : m_entityManager.getEntities()) {

        if (e->hasComponent<CAnimation>()) {
            auto& anim = e->getComponent<CAnimation>();
                anim.animation.update(dt);
        }
    }
}
void Scene_Cuba::sEntitySpawner(sf::Time dt) {
    sf::FloatRect field = getEnemySpawnBounds();

    std::exponential_distribution<float> exp(1.f);

    static std::vector<float> spawnLanes{ 478.f };

    while (spawnLanes.size() < 10) {
        float lane = spawnLanes.back() - 34.f;
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

    m_config.scrollSpeed += 50.f;

    auto& sprite = m_player->addComponent<CSprite>(Assets::getInstance().getTexture("Tontana_Sprite")).sprite;
    m_player->addComponent<CAnimation>(Assets::getInstance().getAnimation("Tontana_Idle_Right"));
    auto spriteSize = sprite.getLocalBounds().getSize();
    m_player->addComponent<CBoundingBox>(spriteSize);
    MusicPlayer::getInstance().play("specialTheme");
    MusicPlayer::getInstance().setVolume(50);

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


void Scene_Cuba::resetEntities() {

}

#pragma region sRender
void Scene_Cuba::renderEntities() {
    std::vector<std::pair<std::shared_ptr<Entity>, float>> entitiesY;

    for (auto& e : m_entityManager.getEntities("lvl1")) {

<<<<<<< Updated upstream
        if (e->getComponent<CSprite>().has) {

            auto& sprite = e->getComponent<CSprite>().sprite;
            m_game->window().draw(sprite);
        }

    }
=======
        if (e->hasComponent<CAnimation>()) {
            auto& anim = e->getComponent<CAnimation>().animation;
            auto& tfm = e->getComponent<CTransform>();
            anim.getSprite().setPosition(tfm.pos);
            anim.getSprite().setRotation(tfm.angle);
            m_game->window().draw(anim.getSprite());
        }

    }
    for (auto& e : m_entityManager.getEntities("water")) {
>>>>>>> Stashed changes

        if (e->hasComponent<CAnimation>()) {
            auto& anim = e->getComponent<CAnimation>().animation;
            auto& tfm = e->getComponent<CTransform>();
            anim.getSprite().setPosition(tfm.pos);
            anim.getSprite().setRotation(tfm.angle);
            m_game->window().draw(anim.getSprite());
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
}
void Scene_Cuba::renderUI() {

    sf::RenderWindow& window = m_game->window();
    sf::View view1;
    view1.reset(sf::FloatRect(0.f, 0.f, 900.f, 512.f));
    m_game->window().setView(view1);

    sf::View view = window.getView();
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f viewCenter = view.getCenter();
    sf::Vector2f viewMousePos = window.mapPixelToCoords(mousePos, view);
    const float maxTime = 6.0f;

<<<<<<< Updated upstream
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
=======
    if (m_isGameOver) {
        for (auto& e : m_entityManager.getEntities("gameovert")) {
>>>>>>> Stashed changes
            if (e->getComponent<CSprite>().has) {
                auto& sprite = e->getComponent<CSprite>().sprite;
                auto& tfm = e->getComponent<CTransform>();
                sprite.setPosition(tfm.pos);
                sprite.setRotation(tfm.angle);
                m_game->window().draw(sprite);
            }
        }
        for (auto& e1 : m_entityManager.getEntities("restart1g")) {

            if (e1->hasComponent<CSprite>()) {
                auto& sprite1 = e1->getComponent<CSprite>().sprite;
                auto overlap = Physics::getOverlapMouse(viewMousePos, e1);
                auto& tfm = e1->getComponent<CTransform>();
                sprite1.setPosition(tfm.pos);
                sprite1.setRotation(tfm.angle);

                for (auto e2 : m_entityManager.getEntities("restart2g")) {
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
        for (auto& e1 : m_entityManager.getEntities("quit1g")) {

            if (e1->hasComponent<CSprite>()) {
                auto& sprite1 = e1->getComponent<CSprite>().sprite;
                auto overlap = Physics::getOverlapMouse(viewMousePos, e1);
                auto& tfm = e1->getComponent<CTransform>();
                sprite1.setPosition(tfm.pos);
                sprite1.setRotation(tfm.angle);

                for (auto e2 : m_entityManager.getEntities("quit1g")) {
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

    if (m_isMenu) {
        if (!menuState("GUIDE")) {
            for (auto& e1 : m_entityManager.getEntities("restart1m")) {

                if (e1->hasComponent<CSprite>()) {
                    auto& sprite1 = e1->getComponent<CSprite>().sprite;
                    auto overlap = Physics::getOverlapMouse(viewMousePos, e1);
                    auto test = e1->getComponent<CTransform>();


                    for (auto e2 : m_entityManager.getEntities("restart2m")) {
                        if (e2->hasComponent<CSprite>()) {
                            auto& sprite2 = e2->getComponent<CSprite>().sprite;

                            if (overlap.x > 0 && overlap.y > 0) {

                                if (!menuSound()) {
                                    menuSound(true);
                                }

                                menuSelection("RESTART", true);
                                m_game->window().draw(sprite2);
                            }
                            else {
                                menuSelection("RESTART", false);
                                m_game->window().draw(sprite1);
                            }
                        }
                    }
                }
            }
            for (auto& e1 : m_entityManager.getEntities("ctrls1m")) {

                if (e1->hasComponent<CSprite>()) {
                    auto& sprite1 = e1->getComponent<CSprite>().sprite;
                    auto overlap = Physics::getOverlapMouse(viewMousePos, e1);
                    auto test = e1->getComponent<CTransform>();


                    for (auto e2 : m_entityManager.getEntities("ctrls2m")) {
                        if (e2->hasComponent<CSprite>()) {
                            auto& sprite2 = e2->getComponent<CSprite>().sprite;

                            if (overlap.x > 0 && overlap.y > 0) {

                                if (!menuSound()) {
                                    menuSound(true);
                                }
                                menuSelection("CONTROLS", true);
                                m_game->window().draw(sprite2);
                            }
                            else {
                                menuSelection("CONTROLS", false);
                                m_game->window().draw(sprite1);
                            }
                        }
                    }
                }
            }
            for (auto& e1 : m_entityManager.getEntities("quit1m")) {

                if (e1->hasComponent<CSprite>()) {
                    auto& sprite1 = e1->getComponent<CSprite>().sprite;
                    auto overlap = Physics::getOverlapMouse(viewMousePos, e1);
                    auto test = e1->getComponent<CTransform>();

                    for (auto e2 : m_entityManager.getEntities("quit2m")) {
                        if (e2->hasComponent<CSprite>()) {
                            auto& sprite2 = e2->getComponent<CSprite>().sprite;

                            if (overlap.x > 0 && overlap.y > 0) {

                                if (!menuSound()) {
                                    menuSound(true);
                                }
                                menuSelection("QUIT", true);
                                m_game->window().draw(sprite2);
                            }
                            else {
                                menuSelection("QUIT", false);
                                m_game->window().draw(sprite1);
                            }
                        }
                    }
                }
            }
        }
        else {
            for (auto& e : m_entityManager.getEntities("instruction")) {
                if (e->getComponent<CSprite>().has) {
                    auto& sprite = e->getComponent<CSprite>().sprite;
                    m_game->window().draw(sprite);
                }
            }
            for (auto& e1 : m_entityManager.getEntities("back1")) {

                if (e1->hasComponent<CSprite>()) {
                    auto& sprite1 = e1->getComponent<CSprite>().sprite;
                    auto overlap = Physics::getOverlapMouse(viewMousePos, e1);
                    auto test = e1->getComponent<CTransform>();

                    for (auto e2 : m_entityManager.getEntities("back2")) {
                        if (e2->hasComponent<CSprite>()) {
                            auto& sprite2 = e2->getComponent<CSprite>().sprite;

                            if (overlap.x > 0 && overlap.y > 0) {

                                if (!menuSound()) {
                                    menuSound(true);
                                }
                                menuSelection("BACK", true);
                                m_game->window().draw(sprite2);
                            }
                            else {
                                menuSelection("BACK", false);
                                m_game->window().draw(sprite1);
                            }
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

    for (auto& e1 : m_entityManager.getEntities("menu1")) {
    
        if (e1->hasComponent<CSprite>()) {
            auto& sprite1 = e1->getComponent<CSprite>().sprite;
            auto overlap = Physics::getOverlapMouse(viewMousePos, e1);
            auto& tfm = e1->getComponent<CTransform>();
    
            sprite1.setPosition(tfm.pos);
            sprite1.setRotation(tfm.angle);
    
            for (auto e2 : m_entityManager.getEntities("menu2")) {
                if (e2->hasComponent<CSprite>()) {
                    auto& sprite2 = e2->getComponent<CSprite>().sprite;
                    auto& tfm2 = e1->getComponent<CTransform>();
    
                    sprite2.setPosition(tfm2.pos);
                    sprite2.setRotation(tfm2.angle);
    
                    if (overlap.x > 0 && overlap.y > 0) {
    
                        if (!menuSound()) {
                            menuSound(true);
                        }
    
                        menuSelection("MENU", true);
                        m_game->window().draw(sprite2);
                    }
                    else {
                        menuSelection("MENU", false);
                        m_game->window().draw(sprite1);
                    }
                }
            }
        }
    }

    //for (auto& hp3 : m_entityManager.getEntities("uihp3")) {
    //
    //    if (hp3->hasComponent<CSprite>()) {
    //        auto& hp03 = hp3->getComponent<CSprite>().sprite;
    //        if (hp3->hasComponent<CTransform>()) {
    //            auto& tfm = hp3->getComponent<CTransform>();
    //            hp03.setPosition(tfm.pos);
    //            hp03.setRotation(tfm.angle);
    //        }
    //        if (m_life == 3) {
    //            m_game->window().draw(hp03);
    //        }
    //        else if (m_life == 2) {
    //            for (auto hp2 : m_entityManager.getEntities("uihp2")) {
    //                if (hp2->hasComponent<CSprite>()) {
    //                    auto& hp02 = hp2->getComponent<CSprite>().sprite;
    //                    if (hp2->hasComponent<CTransform>()) {
    //                        auto& tfm = hp2->getComponent<CTransform>();
    //                        hp02.setPosition(tfm.pos);
    //                        hp02.setRotation(tfm.angle);
    //                    }
    //                    m_game->window().draw(hp02);
    //                }
    //            }
    //        }
    //        else {
    //            for (auto hp1 : m_entityManager.getEntities("uihp1")) {
    //                if (hp1->hasComponent<CSprite>()) {
    //                    auto& hp01 = hp1->getComponent<CSprite>().sprite;
    //                    if (hp1->hasComponent<CTransform>()) {
    //                        auto& tfm = hp1->getComponent<CTransform>();
    //                        hp01.setPosition(tfm.pos);
    //                        hp01.setRotation(tfm.angle);
    //                    }
    //                    m_game->window().draw(hp01);
    //                }
    //            }
    //        }
    //
    //    }
    //}

    for (auto& hp3 : m_entityManager.getEntities("uicocaine3")) {

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
                for (auto hp2 : m_entityManager.getEntities("uicocaine2")) {
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
                for (auto hp1 : m_entityManager.getEntities("uicocaine1")) {
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

    if (!m_hasEnd)
        m_score_text.setString(std::to_string(m_playScore));
    else
        m_score_text.setString(std::to_string(m_finalScore));

    m_score_text.setFillColor(sf::Color::Yellow);
    m_game->window().draw(m_score_text);
<<<<<<< Updated upstream
    m_game->window().setView(m_worldView);

}
void Scene_Cuba::sDoAction(const Command& action) {

    auto& pPos = m_player->getComponent<CTransform>().pos;

    if (action.type() == "START") {
        if (action.name() == "PAUSE") { setPaused(!m_isPaused); }
        else if (action.name() == "QUIT") { m_game->quitLevel(); }
        else if (action.name() == "SPECIAL") 
        { 
            if (m_special > 0 && m_isSpecial == false) 
            { 
                m_config.scrollSpeed += 50.f;
                auto& sprite = m_player->addComponent<CSprite>(Assets::getInstance().getTexture("Montana_Boat")).sprite;
                m_player->addComponent<CAnimation>(Assets::getInstance().getAnimation("Montana_Right"));
                auto spriteSize = sprite.getLocalBounds().getSize();
                m_player->addComponent<CBoundingBox>(spriteSize);
                MusicPlayer::getInstance().play("menuTheme");
                MusicPlayer::getInstance().setVolume(50);
                m_isSpecial = true;
                m_special -= 1;
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
}
void Scene_Cuba::sCollisions() {
    adjustPlayerPosition();
    checkCollisions();
    checkPlayerState();
}
void Scene_Cuba::sUpdate(sf::Time dt) {
    auto& pST = m_player->getComponent<CState>().state;
    SoundPlayer::getInstance().removeStoppedSounds();


    // Do encapsulation instead of local variables.
    if (m_isPaused)
        return;
    
    if (m_hasEnd) {
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
    sf::FloatRect field = getPlayBounds();

    std::exponential_distribution<float> exp(1.f / 1.f);

    std::vector<float> spawnLanes{ 478.f };
    while (spawnLanes.size() < 9) {
        for (int j = 0; j < spawnLanes.size(); j++) {
            float lane = spawnLanes[j] - 34.f;
            spawnLanes.push_back(lane);
            if (spawnLanes.size() >= 9) {
                break;
            }
        }
    }
    
    std::uniform_real_distribution<float> laneDis(0.f, 9.f);
    static std::unordered_set<float> occupiedLanes; // Is unordered and has member functions like find.

    float spawnLane = (float)spawnLanes[laneDis(rng)];
    while (occupiedLanes.find(spawnLane) != occupiedLanes.end()) {
        spawnLane = (float)spawnLanes[laneDis(rng)];
    }

    occupiedLanes.insert(spawnLane);

    if (occupiedLanes.size() == 9)
        occupiedLanes.clear();
   
    std::uniform_real_distribution<float> xDis(field.left + field.width, field.left + field.width);
    //if (spawnLane > 478.f) {
    //    spawnLane += 34.f;
    //}
    std::uniform_real_distribution<float> yDis(spawnLane, spawnLane + 120.f);

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
sf::FloatRect Scene_Cuba::getPlayBounds() {

    auto viewBounds = getViewBounds();
    float spawnWidth = 150.f;
    viewBounds.width += spawnWidth;

    return viewBounds;
}
#pragma endregion

#pragma region sInit
void Scene_Cuba::resetEntities() {

=======

    if (m_isIntro || m_isEnd) {
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

        if (m_isIntro) {
            for (auto& e : m_entityManager.getEntities("chapter1a")) {

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
        if (m_isEnd) {
            for (auto& e : m_entityManager.getEntities("chapter1b")) {

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
>>>>>>> Stashed changes
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

    sf::FloatRect field = getPlayBounds();
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
            if (m_entityManager.getEntities("enemyBoat").size() < 2) {
                std::cout << "\n This is the spawn of location Y of the boat entity: " << pos.y << std::endl;

                float eHalfHeight = 41.f;
                if (pos.y > field.top + field.height - eHalfHeight) {
                    pos.y = field.top + field.height - eHalfHeight;
                }
                spawnBoat(pos);
            }
            break;
        }
        case 2:
        {
            if (m_entityManager.getEntities("enemyShark").size() < 2) {
                std::cout << "\n This is the spawn of location Y of the shark entity: " << pos.y << std::endl;

                float eHalfHeight = 11.5f;
                if (pos.y > field.top + field.height - eHalfHeight) {
                    pos.y = field.top + field.height - eHalfHeight;
                }
                if (pos.y > field.top + field.height - eHalfHeight) {
                    pos.y = field.top + field.height - eHalfHeight;
                }
                spawnShark(pos);
            }
            break;
        }
        case 3: 
        {
<<<<<<< Updated upstream
            if (m_entityManager.getEntities("enemyIsland").size() < 4) {
                std::cout << "\n This is the spawn of location Y of the island entity: " << pos.y << std::endl;
=======
            if (m_entityManager.getEntities("enemyIsland").size() < 6) {
                float eFullHeight = 148.f;
                if ((pos.y + eFullHeight) > field.top + field.height) {
                   pos.y = pos.y - eFullHeight;
                }
>>>>>>> Stashed changes

                float eHalfHeight = 74.f;
                if (pos.y > field.top + field.height - eHalfHeight) {
                    pos.y = field.top + field.height - eHalfHeight;
                }
                spawnIsland(pos);
            }
            break;
        }
        case 4: 
        {
            if (m_entityManager.getEntities("enemyCoral").size() < 4) {
                std::cout << "\n This is the spawn of location Y of the coral entity: " << pos.y << std::endl;

                float eHalfHeight = 26.f;
                if (pos.y > field.top + field.height - eHalfHeight) {
                    pos.y = field.top + field.height - eHalfHeight;
                }
                spawnCoral(pos);
            }
            break;
        }
        case 5:
        {
            if (m_entityManager.getEntities("coca").size() < 1) {
                std::cout << "\n This is the spawn of location Y of the coca entity: " << pos.y << std::endl;

                float eHalfHeight = 8.f;
                if (pos.y > field.top + field.height - eHalfHeight) {
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
<<<<<<< Updated upstream
    raceCarL->addComponent<CType>().boat += 1;
=======
    raceCarL->addComponent<CLife>(5);
    raceCarL->addComponent<CType>().boat = true;
    raceCarL->addComponent<CType>().entity = true;
>>>>>>> Stashed changes
}
void Scene_Cuba::spawnCoral(sf::Vector2f pos) {
    auto raceCarL = m_entityManager.addEntity("enemyCoral");

    raceCarL->addComponent<CTransform>(pos, sf::Vector2f{ m_config.enemySpeed, 0.f });
    auto& sprite = raceCarL->addComponent<CSprite>().sprite;
    auto& spriteName = raceCarL->addComponent<CSprite>(Assets::getInstance().getTexture("Coral")).sprite;
    sprite.setTexture(Assets::getInstance().getTexture("Coral"));
    auto spriteSize = sprite.getLocalBounds().getSize();
    raceCarL->addComponent<CBoundingBox>(spriteSize);
<<<<<<< Updated upstream

    raceCarL->addComponent<CType>().coral += 1;
=======
    raceCarL->addComponent<CType>().coral = true;
    raceCarL->addComponent<CType>().entity = true;

    auto waterAnim = m_entityManager.addEntity("water");
    auto& waterSprite = waterAnim->addComponent<CSprite>(Assets::getInstance().getTexture("Water_Coral_Sprite")).sprite;
    auto waterSpriteSize = waterSprite.getLocalBounds().getSize();
    waterAnim->addComponent<CTransform>(sf::Vector2f(pos.x, pos.y + (spriteSize.y / 2) + waterSpriteSize.y / 4), sf::Vector2f{ m_config.enemySpeed, 0.f });
    waterAnim->addComponent<CAnimation>(Assets::getInstance().getAnimation("Water_Coral"));
    waterAnim->addComponent<CBoundingBox>(waterSpriteSize);
    waterAnim->addComponent<CType>().coral = true;
>>>>>>> Stashed changes

}
void Scene_Cuba::spawnIsland(sf::Vector2f pos) {

    auto raceCarL = m_entityManager.addEntity("enemyIsland");

    raceCarL->addComponent<CTransform>(pos, sf::Vector2f{ m_config.enemySpeed, 0.f });
    auto& sprite = raceCarL->addComponent<CSprite>().sprite;
    auto& spriteName = raceCarL->addComponent<CSprite>(Assets::getInstance().getTexture("Island")).sprite;
    sprite.setTexture(Assets::getInstance().getTexture("Island"));
    auto spriteSize = sprite.getLocalBounds().getSize();
    std::cout << spriteSize;
    raceCarL->addComponent<CBoundingBox>(spriteSize);
    raceCarL->addComponent<CType>().island = true;
    raceCarL->addComponent<CType>().entity = true;

    std::cout << "Island created" <<  std::endl;
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
<<<<<<< Updated upstream

    raceCarL->addComponent<CType>().shark += 1;
=======
    raceCarL->addComponent<CType>().shark = true;
    raceCarL->addComponent<CType>().entity = true;
>>>>>>> Stashed changes
}
void Scene_Cuba::spawnCoca(sf::Vector2f pos) {

    auto raceCarL = m_entityManager.addEntity("coca");
    raceCarL->addComponent<CTransform>(pos, sf::Vector2f{ m_config.enemySpeed, 0.f });
    auto& sprite = raceCarL->addComponent<CSprite>(Assets::getInstance().getTexture("Coca")).sprite;
    raceCarL->addComponent<CAnimation>(Assets::getInstance().getAnimation("Coca_Left"));
    sprite.setTexture(Assets::getInstance().getTexture("Coca"));
    auto spriteSize = sprite.getLocalBounds().getSize();
    raceCarL->addComponent<CBoundingBox>(spriteSize);
<<<<<<< Updated upstream

    raceCarL->addComponent<CType>().coca += 1;
=======
    raceCarL->addComponent<CType>().coca = true;
    raceCarL->addComponent<CType>().entity = true;

    auto waterAnim = m_entityManager.addEntity("water");
    auto& waterSprite = waterAnim->addComponent<CSprite>(Assets::getInstance().getTexture("Water_Coca_Sprite")).sprite;
    auto waterSpriteSize = waterSprite.getLocalBounds().getSize();
    waterAnim->addComponent<CTransform>(sf::Vector2f(pos.x, pos.y + (spriteSize.y / 2)), sf::Vector2f{ m_config.enemySpeed, 0.f });
    waterAnim->addComponent<CAnimation>(Assets::getInstance().getAnimation("Water_Coca"));
    waterAnim->addComponent<CBoundingBox>(waterSpriteSize);
    waterAnim->addComponent<CType>().coca = true;
}
void Scene_Cuba::spawnBullet(std::shared_ptr<Entity> e) {
    auto tx = e->getComponent<CTransform>();
    sf::Vector2f bPos { tx.pos.x + 20.f, tx.pos.y };
    if (tx.has) {
        auto bullet = m_entityManager.addEntity("bullet");
        auto& sprite = bullet->addComponent<CSprite>().sprite;
        bullet->addComponent<CSprite>(Assets::getInstance().getTexture("Bullet")).sprite;
        bullet->addComponent<CTransform>(bPos);
        sprite.setTexture(Assets::getInstance().getTexture("Bullet"));
        auto spriteSize = sprite.getLocalBounds().getSize();

        bullet->addComponent<CBoundingBox>(spriteSize);
        bullet->addComponent<CLife>(70);
        bullet->getComponent<CTransform>().vel.x = 1.5 * m_config.bulletspeed; 
        bullet->getComponent<CTransform>().vel.y = 0;
        bullet->addComponent<CType>().bullet = true;
        bullet->addComponent<CType>().entity = true;
    }
}
#pragma endregion

#pragma region sState
void Scene_Cuba::playerState() {
    auto& pST = m_player->getComponent<CState>().state;
    sf::Vector2f spawnPos{ m_worldView.getSize().x / 2.f, m_worldView.getSize().y / 2.f };

    if (pST == "dead") {

        if (m_life == 0){
            m_isGameOver = true;
            m_player->destroy();
        }

        const float flashDuration = 5.0f;
        static sf::Clock flashClock;

        float elapsedTime = flashClock.getElapsedTime().asSeconds();
        m_player->removeComponent<CBoundingBox>();

        if (elapsedTime > flashDuration) {
            flashClock.restart();
            m_player->addComponent<CAnimation>(Assets::getInstance().getAnimation("Fony_Idle_Right"));
            auto& sprite = m_player->getComponent<CSprite>().sprite;
            auto spriteSize = sprite.getLocalBounds().getSize();

            m_player->addComponent<CBoundingBox>(spriteSize);
            m_player->addComponent<CState>().state = "alive";
        }
    }
}
void Scene_Cuba::timeState(sf::Time dt) {

    if (m_isPaused)
        return;

    if (m_elapsedTime < m_introTime)
        m_isIntro = true;
    else
        m_isIntro = false;

    if (m_isEnd) {
        static float levelBonus = 100.f;
        m_finalScore = (int)(levelBonus - m_timeScore) + m_playScore;
    }
    else {
        m_timeScore += dt.asSeconds();
        m_elapsedTime += dt.asSeconds();
    }
}
void Scene_Cuba::lifeState() {
    // move all entities
    for (auto e : m_entityManager.getEntities("bullet")) {
        auto& lifespan = e->getComponent<CLife>();
        if (lifespan.has) {
            lifespan.remaining -= 1;
            if (lifespan.remaining < 0) {
                e->destroy();
            }
        }
    }
    for (auto e : m_entityManager.getEntities("enemyBoat")) {
        auto& lifespan = e->getComponent<CLife>();
        if (lifespan.has) {
            if (lifespan.remaining < 0) {
                e->destroy();
            }
        }
    }
}
void Scene_Cuba::gameState() {

    if (m_isIntro)
        m_isPlay = false;
    else if (m_isPaused)
        m_isPlay = false;
    else if (m_isGameOver) {
        m_config.scrollSpeed = 0;
        m_isPlay = false;
    }
    else if (m_isEnd) {
        m_config.scrollSpeed = 0;
        m_isPlay = false;
    }
    else
        m_isPlay = true;
}
void Scene_Cuba::specialState() {

    const float flashDuration = 15.f;
    static sf::Clock flashClock;

    float elapsedTime = flashClock.getElapsedTime().asSeconds();

    if (elapsedTime > flashDuration) {
        auto& sprite = m_player->addComponent<CSprite>(Assets::getInstance().getTexture("Fony_Sprite")).sprite;
        m_player->addComponent<CAnimation>(Assets::getInstance().getAnimation("Fony_Idle_Right"));
        auto spriteSize = sprite.getLocalBounds().getSize();
        m_player->addComponent<CBoundingBox>(spriteSize);

        MusicPlayer::getInstance().play("gameTheme");
        MusicPlayer::getInstance().setVolume(50);
        flashClock.restart();

        m_isSpecial = false;
        m_config.scrollSpeed -= 50.f;
    }
>>>>>>> Stashed changes
}
#pragma endregion

#pragma region sCollisions
void Scene_Cuba::checkCollisions() {
<<<<<<< Updated upstream
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
=======

    for (auto& e : m_entityManager.getEntities("coca")) {
>>>>>>> Stashed changes
        auto overlap = Physics::getOverlapEntity(m_player, e, "coca");
        if (overlap.x > 0 and overlap.y > 0) {

            if (m_special != 3) {
                m_special += 1;
                e->destroy();
            }
        }
    }

<<<<<<< Updated upstream
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
=======
>>>>>>> Stashed changes
    if (m_isSpecial) {
        checkSpecialCollisions();
        return;
    }

<<<<<<< Updated upstream
=======
    for (auto& e : m_entityManager.getEntities("enemyShark")) {
        auto overlap = Physics::getOverlapEntity(m_player, e, "shark");
        if (overlap.x > 0 and overlap.y > 0) {
            e->getComponent<CTransform>().vel.x = 0.f;
            e->removeComponent<CBoundingBox>();
            e->addComponent<CAnimation>(Assets::getInstance().getAnimation("Shark_Death"));
            m_player->removeComponent<CBoundingBox>();
            m_player->addComponent<CState>().state = "dead";
            m_player->addComponent<CAnimation>(Assets::getInstance().getAnimation("Fony_Hit_Right"));
            m_playScore += 10.f;
            if (m_life != 0) {
                m_life -= 1;
            }
        }
    }

    for (auto& e : m_entityManager.getEntities("enemyBoat")) {
        auto overlap = Physics::getOverlapEntity(m_player, e, "boatMilitary");
        if (overlap.x > 0 and overlap.y > 0) {
            m_player->removeComponent<CBoundingBox>();
            m_player->addComponent<CAnimation>(Assets::getInstance().getAnimation("Fony_Hit_Right"));
            m_player->addComponent<CState>().state = "dead";
            if (m_life != 0) {
                m_life -= 1;
            }
        }
    }

    for (auto& e : m_entityManager.getEntities("enemyCoral")) {
        auto overlap = Physics::getOverlapEntity(m_player, e, "coral");
        if (overlap.x > 0 and overlap.y > 0) {

            m_player->removeComponent<CBoundingBox>();
            m_player->addComponent<CAnimation>(Assets::getInstance().getAnimation("Fony_Hit_Right"));
            m_player->addComponent<CState>().state = "dead";
            for (auto& e2 : m_entityManager.getEntities("water")) {
                auto overlap = Physics::getOverlapEntity(e2, e);
                if (overlap.x > 0 and overlap.y > 0) {
                    if (e2->getComponent<CType>().coral) {
                        e2->destroy();
                    }
                }
            }
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
    }

    for (auto& e : m_entityManager.getEntities("enemyIsland")) {
        auto overlap = Physics::getOverlapEntity(m_player, e, "island");
        if (overlap.x > 0 and overlap.y > 0) {
            m_player->removeComponent<CBoundingBox>();
            m_player->addComponent<CAnimation>(Assets::getInstance().getAnimation("Fony_Hit_Right"));
            m_player->addComponent<CState>().state = "dead";

            if (m_life != 0) {
                m_life -= 1;
            }
        }
    }

    for (auto& e : m_entityManager.getEntities("coca")) {
        auto overlap = Physics::getOverlapEntity(m_player, e, "coca");
        if (overlap.x > 0 and overlap.y > 0) {

            if (m_special != 3) {
                m_special += 1;
                for (auto& e2 : m_entityManager.getEntities("water")) {
                    auto overlap = Physics::getOverlapEntity(e2, e);
                    if (overlap.x > 0 and overlap.y > 0) {
                        if (e2->getComponent<CType>().coca) {
                            e2->destroy();
                        }
                    }
                }
                e->destroy();
            }
        }
    }

    playerState();
}
void Scene_Cuba::checkSpecialCollisions() {

    for (auto& e : m_entityManager.getEntities("enemyShark")) {
        auto overlap = Physics::getOverlapEntity(m_player, e, "shark");
        if (overlap.x > 0 and overlap.y > 0) {
            e->getComponent<CTransform>().vel.x = 0.f;
            e->removeComponent<CBoundingBox>();
            e->addComponent<CAnimation>(Assets::getInstance().getAnimation("Shark_Death"));

            m_playScore += 10.f;
        }
    }
    for (auto& e : m_entityManager.getEntities("enemyCoral")) {
        auto overlap = Physics::getOverlapEntity(m_player, e, "coral");
        if (overlap.x > 0 and overlap.y > 0) {
            for (auto& e2 : m_entityManager.getEntities("water")) {
                auto overlap = Physics::getOverlapEntity(e2, e);
                if (overlap.x > 0 and overlap.y > 0) {
                    if (e2->getComponent<CType>().coral) {
                        e2->destroy();
                    }
                }
            }
            e->destroy();
            if (m_playScore >= 5) {
                m_playScore -= 5.f;
            }
            else {
                m_playScore -= m_playScore;
            }
        }
    }

    for (auto& e : m_entityManager.getEntities("enemyBoat")) {
        auto overlap = Physics::getOverlapEntity(m_player, e, "boatMilitary");
        if (overlap.x > 0 and overlap.y > 0) {

            m_player->removeComponent<CBoundingBox>();
            m_player->addComponent<CAnimation>(Assets::getInstance().getAnimation("Fony_Hit_Right")); // Change animation
            m_player->addComponent<CState>().state = "dead";

            if (m_life != 0) {
                m_life -= 1;
            }
            playerState();
        }

        for (auto& e2 : m_entityManager.getEntities("bullet")) {
            auto overlap2 = Physics::getOverlapEntity(e, e2, "bullet");
            if (overlap2.x > 0 and overlap2.y > 0) {
                e->getComponent<CLife>().remaining -= 1;
                e2->destroy();
                m_playScore += 30.f;
            }
        }
    }



    for (auto& e : m_entityManager.getEntities("enemyIsland")) {
        auto overlap = Physics::getOverlapEntity(m_player, e, "island");
        if (overlap.x > 0 and overlap.y > 0) {
            m_player->removeComponent<CBoundingBox>();
            m_player->addComponent<CAnimation>(Assets::getInstance().getAnimation("Fony_Hit_Right")); // Change Animation
            m_player->addComponent<CState>().state = "dead";

            if (m_life != 0) {
                m_life -= 1;
            }
        }
    }

    playerState();
}
void Scene_Cuba::checkPlayerPosition() {

>>>>>>> Stashed changes
    auto center = m_worldView.getCenter();
    sf::Vector2f viewHalfSize = m_worldView.getSize() / 2.f;

    auto left = center.x - viewHalfSize.x;
    auto right = center.x + viewHalfSize.x;
    auto top = center.y - viewHalfSize.y + 150.f;
    auto bot = center.y + viewHalfSize.y;

    auto& player_pos = m_player->getComponent<CTransform>().pos;
    auto halfSize = m_player->getComponent<CBoundingBox>().halfSize;

<<<<<<< Updated upstream
    if (m_hasEnd == false) {
=======
    if (m_isPlay) {
>>>>>>> Stashed changes
        player_pos.x = std::max(player_pos.x, left + halfSize.x);
        player_pos.x = std::min(player_pos.x, right - halfSize.x);
        player_pos.y = std::max(player_pos.y, top + halfSize.y);
        player_pos.y = std::min(player_pos.y, bot - halfSize.y);
    }
}
#pragma endregion

