#pragma once

#include "Scene.h"

class Scene_Menu : public Scene
{
private:
	std::vector<std::string>	m_levelPaths;
	std::vector<std::pair<std::string, bool>> m_menu_menu;
	int							m_menuIndex{ 0 };

	bool						m_drawAABB{ false };

	bool						m_isGuide{ false };

	void loadMenu(const std::string& path);
	void init();
	void onEnd() override;

public:

	Scene_Menu(GameEngine* gameEngine);

	void update(sf::Time dt) override;

	void sRender() override;
	void sDoAction(const Command& action) override;

	bool menuSound(bool check = false);
	bool menuState(std::string tag);
	void menuSelection(std::string tag, bool selection);

};

