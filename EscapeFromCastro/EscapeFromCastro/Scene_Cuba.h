//
// Created by David Burchill on 2023-09-27.
//

#ifndef BREAKOUT_SCENE_BREAKOUT_H
#define BREAKOUT_SCENE_BREAKOUT_H

#include <queue>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics.hpp>
#include "EntityManager.h"
#include "Entity.h"
#include "Scene.h"
#include "GameEngine.h"

struct LevelConfig {
    float       bulletSpeed{ 100.f };
    float       scrollSpeed{ 100.f };
    float       enemySpeed{ 200.f };
    float       playerSpeed{ 200.f };

    std::map<std::string,
        std::vector<std::pair<float, sf::Time>>> directions;
};

struct SpawnPoint {
    float           y;
    std::string     type;
    unsigned char   number;
    //auto operator<=>(const SpawnPoint& rhs) const = default;
    auto operator<=>(const SpawnPoint& rhs) const {
        return y <=> rhs.y;
    }
};

class Scene_Cuba : public Scene {
private:
    std::vector<std::pair<std::string, bool>> m_menu_cuba;
    bool			m_isGuide{ false };

    sPtrEntt        m_player{ nullptr };
    sf::View        m_worldView;
    sf::FloatRect   m_worldBounds;
    sf::Text        m_pos_text;

    float           m_playerLastPos{ 0.f };
    float           m_elapsedTime = 0.0f;
    float           m_timeScore = 0.0f;
    float           m_deathTime = 0.0f;
    float           m_introTime = 5.f;

    bool            m_isEnd{ false };
    bool            m_isIntro{ false };
    bool            m_isPlay{ false };
    bool            m_isSpecial{ false };
    bool            m_isMenu{ false };
    bool            m_isFiring{ false };
    bool            m_isGameOver{ false };

    int             m_playScore{ 0 };
    int             m_finalScore{ 0 };
    sf::Text		m_score_text;

    int             m_special{ 0 };
    int             m_life{ 3 };

    bool			m_drawAABB{ false };

    LevelConfig                         m_config;

    //systems
    void            sMovement(sf::Time dt);
    void            sCollisions();
    void            sUpdate(sf::Time dt);
    void            sAnimation(sf::Time dt);
    void            sState(sf::Time dt);
    void            sEntitySpawner(sf::Time dt);
    void		    sDoAction(const Command& command) override;
    void		    sRender() override;

    // helper functions
    void            timeState(sf::Time dt);
    void            gameState();
    void            playerState();
    void            lifeState();
    void            specialState();

    void            playerMovement();
    void            checkPlayerPosition();
    void            checkCollisions();
    void            checkSpecialCollisions();

    void	        registerActions();
    void            init();

    void            entityMovement();
    void            mapMovement();


    void	        onEnd() override;
    sf::FloatRect   getViewBounds();
    sf::FloatRect   getEnemySpawnBounds();
    sf::FloatRect   getPlayerSpawnBounds();

    // Spawn functions
    float           randomSpawn(float min, float max);
    void            spawnPlayer(sf::Vector2f pos);
    void            spawnEnemy(sf::Vector2f pos);
    void            spawnBoat(sf::Vector2f pos);
    void            spawnCoral(sf::Vector2f pos);
    void            spawnIsland(sf::Vector2f pos);
    void            spawnShark(sf::Vector2f pos);
    void            spawnCoca(sf::Vector2f pos);
    void            spawnBullet(std::shared_ptr<Entity> e);

    void            renderEntities();
    void            renderUI();

    void            specialAbility();
    void            loadLevel(const std::string& path);


public:

    Scene_Cuba(GameEngine* gameEngine, const std::string& levelPath);

    bool            menuSound(bool check = false);
    bool            menuState(std::string tag);
    void            menuSelection(std::string tag, bool selection);
    void            resetEntities();
    void		    update(sf::Time dt) override;

};



#endif //BREAKOUT_SCENE_BREAKOUT_H
