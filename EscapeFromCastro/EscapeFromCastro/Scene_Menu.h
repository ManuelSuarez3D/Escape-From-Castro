#pragma once

#include "Scene.h"

class Scene_Menu : public Scene
{
private:
	std::vector<std::string>	m_menuStrings;
	sf::Text					m_menuText;
	std::vector<std::string>	m_levelPaths;
	int							m_menuIndex{ 0 };
	std::string					m_title;
	bool			m_drawAABB{ false };
	bool			m_isGuide{ false };
	void loadMenu(const std::string& path);
	void init();
	void onEnd() override;
	std::vector<bool>			m_menu_overlap;
public:

	Scene_Menu(GameEngine* gameEngine);

	void update(sf::Time dt) override;

	void sRender() override;
	void sDoAction(const Command& action) override;


};

