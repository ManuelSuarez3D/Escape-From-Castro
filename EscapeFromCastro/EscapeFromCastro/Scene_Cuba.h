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
    sPtrEntt        m_player{ nullptr };
    sf::View        m_worldView;
    sf::FloatRect   m_worldBounds;
    sf::Text        m_pos_text;
    float           m_playerLastPos{ 0.f };
    float           m_elapsedTime = 0.0f;
    float           m_deathTime = 0.0f;
    bool            m_hasEnd{ false };
    bool            m_isSpecial{ false };
    int             m_score{ 0 };
    sf::Text		m_hiscore_text;
    sf::Text		m_score_text;

    int             m_special{ 0 };
    int             m_life{ 3 };
    int             m_frogScore{ 0 };
    bool			m_drawTextures{ true };
    bool			m_drawAABB{ false };
    bool			m_drawGrid{ false };

    std::priority_queue<SpawnPoint>     m_spawnPoints;
    LevelConfig                         m_config;

    //systems
    void            sMovement(sf::Time dt);
    void            sCollisions();
    void            sUpdate(sf::Time dt);
    void            sAnimation(sf::Time dt);
    void            entityMovement();
    void            mapMovement();

    void	        onEnd() override;

    // helper functions
    void            playerMovement();
    void            adjustPlayerPosition();
    void            checkPlayerState();
    void            checkCollisions();
    void	        registerActions();
    void            spawnPlayer(sf::Vector2f pos);
    void            spawnEnemy(sf::Vector2f pos);
    void            spawnBoat(sf::Vector2f pos);
    void            spawnCoral(sf::Vector2f pos);
    void            spawnIsland(sf::Vector2f pos);
    void            spawnShark(sf::Vector2f pos);
    void            spawnCoca(sf::Vector2f pos);
    void            sEnemySpawner(sf::Time dt);
    void            initLife();
    void            specialAbility();
    void            loadLevel(const std::string& path);
    void            sDestroyOutsideBounds();
    sf::FloatRect   getViewBounds();
    sf::FloatRect   getPlayBounds();
    float           randomSpawn(float min, float max);

public:

    Scene_Cuba(GameEngine* gameEngine, const std::string& levelPath);

    void            resetEntities();
    void		    update(sf::Time dt) override;
    void		    sDoAction(const Command& command) override;
    void		    sRender() override;

};



#endif //BREAKOUT_SCENE_BREAKOUT_H
