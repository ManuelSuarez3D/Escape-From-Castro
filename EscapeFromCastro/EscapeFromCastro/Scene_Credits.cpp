#include <fstream>
#include <iostream>

#include "Scene_Credits.h"

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
Scene_Credits::Scene_Credits(GameEngine* gameEngine, const std::string& levelPath)
    : Scene(gameEngine),
    m_worldView(gameEngine->window().getDefaultView()) {

    loadLevel(levelPath);
    init();
}
void Scene_Credits::loadLevel(const std::string& path) {

    std::ifstream config(path);
    if (config.fail()) {
        std::cerr << "Open file " << path << " failed\n";
        config.close();
        exit(1);
    }

    std::string token{ "" };
    config >> token;
    while (!config.eof()) {
        if (token == "Curtain") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("bkg");

            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
            sprite.setOrigin(0.f, 0.f);
            sprite.setPosition(pos);

        }
        else if (token == "ScoreCredits") {
            std::string name;
            sf::Vector2f pos;
        
            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("score");
        
            e->addComponent<CTransform>(pos);
            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
            sprite.setOrigin(0.f, 0.f);
            sprite.setPosition(pos);
        
        }
        else if (token == "FinalCredits") {
            std::string name;
            sf::Vector2f pos;
        
            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("credits");
        
            e->addComponent<CTransform>(pos);
            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
            sprite.setOrigin(0.f, 0.f);
            sprite.setPosition(pos);
        
        }
        else if (token == "Bck1") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("back1");
            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
            auto spriteSize = sprite.getLocalBounds().getSize();


            e->addComponent<CBoundingBox>(spriteSize);
            sf::Vector2f spriteOrigin = sprite.getOrigin();

            sf::Vector2f boundingBoxPosition = pos + spriteOrigin;

            e->addComponent<CTransform>(boundingBoxPosition);
            sprite.setOrigin(0.f, 0.f);
            sprite.setPosition(pos);
        }
        else if (token == "Bck2") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("back2");

            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
            e->addComponent<CBoundingBox>(sprite.getLocalBounds().getSize());
            sprite.setOrigin(0.f, 0.f);
            sprite.setPosition(pos);

        }
        else if (token == "UiHp1") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("uihp1");
            e->addComponent<CTransform>();
            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;

            sprite.setOrigin(0.f, 0.f);

        }
        else if (token == "UiHp2") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("uihp2");
            e->addComponent<CTransform>();
            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;

            sprite.setOrigin(0.f, 0.f);

        }
        else if (token == "UiHp3") {
            std::string name;
            sf::Vector2f pos;

            config >> name >> pos.x >> pos.y;
            auto e = m_entityManager.addEntity("uihp3");
            e->addComponent<CTransform>();
            auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;

            sprite.setOrigin(0.f, 0.f);

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
        else if (token[0] == '#') {
            std::cout << token;
        }

        config >> token;
    }

    config.close();
}
void Scene_Credits::loadScore(const std::string& filePath) {

    std::ifstream config(filePath);
    if (config.fail()) {
        std::cerr << "Open file " << filePath << " failed\n";
        config.close();
        exit(1);
    }
    std::string token;
    while (config >> token) {
        if (token == "Score") {
            std::string scoreStr;
            config >> scoreStr;

            m_finalScore = std::stoi(scoreStr);
        }
        else if (token[0] == '#') {
            std::cout << token;
            std::string tmp;
            std::getline(config, tmp);
        }
    }
}
void Scene_Credits::loadInventory(const std::string& filePath) {

    std::ifstream config(filePath);
    if (config.fail()) {
        std::cerr << "Open file " << filePath << " failed\n";
        config.close();
        exit(1);
    }
    std::string token;
    while (config >> token) {
        if (token == "Coca") {
            std::string inventoryStr;
            config >> inventoryStr;

            m_special = std::stoi(inventoryStr);
        }
        else if (token[0] == '#') {
            std::cout << token;
            std::string tmp;
            std::getline(config, tmp);
        }
    }
}
void Scene_Credits::init() {

    MusicPlayer::getInstance().play("specialTheme");
    MusicPlayer::getInstance().setVolume(20);

    m_menu_credits.push_back(std::make_pair("BACK", false));

    loadScore("../assets/score.txt");
    loadInventory("../assets/inventory.txt");

    registerAction(sf::Mouse::Left, "MOUSE_CLICK");
}
void Scene_Credits::onEnd() {
    
    writeToScoreFile(0);
    writeToInventoryFile(0);

    MusicPlayer::getInstance().play("menuTheme");
    MusicPlayer::getInstance().setVolume(50);
    m_game->quitLevel();
}
#pragma endregion

#pragma region System
void Scene_Credits::sDoAction(const Command& action) {

    if (action.type() == "START") {
    
        if (action.name() == "TOGGLE_COLLISION") { m_drawAABB = !m_drawAABB; }
        if (action.name() == "MOUSE_CLICK") {
            if (menuState("BACK")) {
                //loadMenu();
                onEnd();
            }
        }
    }
}
void Scene_Credits::sState(sf::Time dt) {

    SoundPlayer::getInstance().removeStoppedSounds();
    m_entityManager.update();

    if (!timeState(dt))
        return;

    gameState();
}
void Scene_Credits::sRender() {

    sf::RenderWindow& window = m_game->window();
    sf::Event event;
    sf::View view = window.getView();
    view.setCenter(window.getSize().x / 2.f, window.getSize().y / 2.f);
    window.setView(view);

    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f viewMousePos = window.mapPixelToCoords(mousePos, view);

    for (auto& e : m_entityManager.getEntities("bkg")) {
        auto& sprite = e->getComponent<CSprite>().sprite;
        auto tfm = e->getComponent<CTransform>();
        sprite.setPosition(tfm.pos);
        sprite.setRotation(tfm.angle);

        m_game->window().draw(sprite);
    }

    if (m_isCredits) {

        for (auto& e : m_entityManager.getEntities("credits")) {
            auto& sprite = e->getComponent<CSprite>().sprite;
            auto tfm = e->getComponent<CTransform>();
            sprite.setPosition(tfm.pos);
            sprite.setRotation(tfm.angle);

            m_game->window().draw(sprite);
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

                            if (!m_playSound && menuState("BACK")) {
                                SoundPlayer::getInstance().play("menuPing");
                                m_playSound = true;
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
    else {
        //m_special = 3;
        for (auto& e : m_entityManager.getEntities("score")) {
            auto& sprite = e->getComponent<CSprite>().sprite;
            auto tfm = e->getComponent<CTransform>();
            sprite.setPosition(tfm.pos);
            sprite.setRotation(tfm.angle);

            m_score_text.setFont(Assets::getInstance().getFont("Arcade"));
            m_score_text.setPosition(450.f, 430.f);
            m_score_text.setCharacterSize(50);
            m_score_text.setString(std::to_string(m_finalScore));
            m_score_text.setFillColor(sf::Color::Yellow);
            m_game->window().draw(m_score_text);

            m_game->window().draw(sprite);
        }
        //for (auto& hp3 : m_entityManager.getEntities("uicocaine3")) {
        //
        //    if (hp3->hasComponent<CSprite>()) {
        //
        //        if (m_special == 3) {
        //            auto& hp03 = hp3->getComponent<CSprite>().sprite;
        //            if (hp3->hasComponent<CTransform>()) {
        //                auto& tfm = hp3->getComponent<CTransform>();
        //                hp03.setPosition(tfm.pos);
        //                hp03.setRotation(tfm.angle);
        //            }
        //            m_game->window().draw(hp03);
        //        }
        //        else if (m_special == 2) {
        //            for (auto hp2 : m_entityManager.getEntities("uicocaine2")) {
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
        //        else if (m_special == 1) {
        //            for (auto hp1 : m_entityManager.getEntities("uicocaine1")) {
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
    }
    
    renderUI();
    menuSound();
}
void Scene_Credits::sMovement(sf::Time dt) {

    //sf::FloatRect view = getViewBounds();
    //m_worldView.move(m_config.scrollSpeed * dt.asSeconds() * 1, 0.f);

    //for (auto& e : m_entityManager.getEntities("player")) {
    //    if (e->hasComponent<CTransform>()) {
    //        auto& tfm = e->getComponent<CTransform>();

    //        tfm.pos += tfm.vel * dt.asSeconds();
    //    }
    //}
} // To remove?
void Scene_Credits::sUpdate(sf::Time dt) {

    sState(dt);
    sAnimation(dt);
    sMovement(dt);
}
void Scene_Credits::sAnimation(sf::Time dt) {
    for (auto e : m_entityManager.getEntities()) {

        if (e->hasComponent<CAnimation>()) {
            auto& anim = e->getComponent<CAnimation>();
            anim.animation.update(dt);
        }
    }
}
#pragma endregion

#pragma region Menu
bool Scene_Credits::menuSound(bool check) {

    if (check == true && menuState("ALL"))
        SoundPlayer::getInstance().play("menuPing");

    //else if (check == true && menuState("GUIDE") && !menuState("BACK")) {
    //    SoundPlayer::getInstance().play("menuPing");
    //}

    return check;
}
void Scene_Credits::menuSelection(std::string tag, bool selection) {

    if (tag == "ALL") {
        for (auto& item : m_menu_credits) {
            item.second = selection;
        }
    }

    for (auto& item : m_menu_credits) {
        if (item.first == tag) {
            item.second = selection;
        }
    }
}
bool Scene_Credits::menuState(std::string tag) {

    if (tag == "ALL") {
        return std::all_of(m_menu_credits.begin(), m_menu_credits.end(), [](const auto& item) {
            return !item.second;
            });
    }
    //else if (tag == "GUIDE") {
    //    return m_isGuide;
    //}

    for (auto& item : m_menu_credits) {
        if (item.first == tag) {
            return item.second;
        }
    }
}
#pragma endregion

#pragma region sRender
void Scene_Credits::renderUI() {

    //sf::RenderWindow& window = m_game->window();
    //sf::View view1;
    //view1.reset(sf::FloatRect(0.f, 0.f, 900.f, 512.f));
    //m_game->window().setView(view1);
    //
    //sf::View view = window.getView();
    //sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    //sf::Vector2f viewCenter = view.getCenter();
    //sf::Vector2f viewMousePos = window.mapPixelToCoords(mousePos, view);
    //
    //
    //if (m_isCuba) {
    //    for (auto& e : m_entityManager.getEntities("loadCuba")) {
    //
    //        auto& anim = e->getComponent<CAnimation>().animation;
    //        auto& tfm = e->getComponent<CTransform>();
    //        anim.getSprite().setPosition(tfm.pos);
    //        anim.getSprite().setRotation(tfm.angle);
    //        m_game->window().draw(anim.getSprite());
    //
    //    }
    //}
    //else if (m_isBermuda) {
    //    for (auto& e : m_entityManager.getEntities("loadBermuda")) {
    //
    //        auto& anim = e->getComponent<CAnimation>().animation;
    //        auto& tfm = e->getComponent<CTransform>();
    //        anim.getSprite().setPosition(tfm.pos);
    //        anim.getSprite().setRotation(tfm.angle);
    //        m_game->window().draw(anim.getSprite());
    //
    //    }
    //}
    //else if (m_isUSA) {
    //    for (auto& e : m_entityManager.getEntities("loadMiami")) {
    //
    //        auto& anim = e->getComponent<CAnimation>().animation;
    //        auto& tfm = e->getComponent<CTransform>();
    //        anim.getSprite().setPosition(tfm.pos);
    //        anim.getSprite().setRotation(tfm.angle);
    //        m_game->window().draw(anim.getSprite());
    //
    //    }
    //}
    //else if (m_isOver) {
    //    for (auto& e : m_entityManager.getEntities("loadCredits")) {
    //
    //        auto& anim = e->getComponent<CAnimation>().animation;
    //        auto& tfm = e->getComponent<CTransform>();
    //        anim.getSprite().setPosition(tfm.pos);
    //        anim.getSprite().setRotation(tfm.angle);
    //        m_game->window().draw(anim.getSprite());
    //
    //    }
    //}

}
#pragma endregion

#pragma region Utility
void Scene_Credits::update(sf::Time dt) {
    sUpdate(dt);
}
#pragma endregion

#pragma region sState
bool Scene_Credits::timeState(sf::Time dt) {

    const float flashDuration = 9.f;
    m_elapsedTime = m_timeFlashClock.getElapsedTime().asSeconds();

    if (m_elapsedTime > flashDuration) {
        return true;
    }
    return false;
}
void Scene_Credits::gameState() {
    m_isCredits = true;
}
#pragma endregion
