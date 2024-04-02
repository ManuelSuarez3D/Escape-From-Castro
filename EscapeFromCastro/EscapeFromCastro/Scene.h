#pragma once

#include "EntityManager.h"
#include "GameEngine.h"
#include "Command.h"
#include <map>
#include <string>


using CommandMap = std::map<int, std::string>;

//class Scene_EscapeFromCastro;

class Scene
{

protected:

	GameEngine*		m_game;
	EntityManager	m_entityManager;
	CommandMap		m_commands;


	void			writeToLoadingFile(std::string level);
	void			writeToScoreFile(int score); 
	void			writeToInventoryFile(int inventory);

	bool			m_isPaused{ false };

	size_t			m_currentFrame{ 0 };

	bool			m_isCuba{ false };
	bool			m_isBermuda{ false };
	bool			m_isUSA{ false };
	bool			m_isOver{ false };

	virtual void	onEnd() = 0;
	void			setPaused(bool paused);

public:
	Scene(GameEngine* gameEngine);
	virtual ~Scene();

	virtual void		update(sf::Time dt) = 0;
	virtual void		sDoAction(const Command& action) = 0;
	virtual void		sRender() = 0;

	void				simulate(int);
	void				doAction(Command);
	void				registerAction(int, std::string);
	const CommandMap	getActionMap() const;
};

