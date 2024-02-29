#include "Scene_Menu.h"
#include "Physics.h"
#include "MusicPlayer.h"
#include "SoundPlayer.h"
#include "Scene_Cuba.h"
#include <memory>

void Scene_Menu::onEnd()
{
	m_game->window().close();
}

Scene_Menu::Scene_Menu(GameEngine* gameEngine)
	: Scene(gameEngine)
{
	loadMenu("../assets/menu.txt");
	init();

	MusicPlayer::getInstance().play("menuTheme");
	MusicPlayer::getInstance().setVolume(50);

}

void Scene_Menu::sDoAction(const Command& action) {

	if (action.type() == "START") {
		//if (action.name() == "PAUSE") { setPaused(!m_isPaused); }
		//else if (action.name() == "QUIT") { m_game->quitLevel(); }
		//else if (action.name() == "BACK") { m_game->backLevel(); }
		if (action.name() == "TOGGLE_COLLISION") { m_drawAABB = !m_drawAABB; }
	}
}

void Scene_Menu::init()
{
	//registerAction(sf::Keyboard::P, "PAUSE");
	//registerAction(sf::Keyboard::Escape, "BACK");
	//registerAction(sf::Keyboard::Q, "QUIT");
	registerAction(sf::Keyboard::C, "TOGGLE_COLLISION");
	//registerAction(sf::Keyboard::A, "LEFT");
	//registerAction(sf::Keyboard::Left, "LEFT");
	//registerAction(sf::Keyboard::D, "RIGHT");
	//registerAction(sf::Keyboard::Right, "RIGHT");
	//registerAction(sf::Keyboard::W, "UP");
	//registerAction(sf::Keyboard::Up, "UP");
	//registerAction(sf::Keyboard::S, "DOWN");
	//registerAction(sf::Keyboard::Down, "DOWN");
	//m_game->currentScene("MENU", std::make_shared<Scene_EscapeFromCastro>(m_game, "../assets/menu.txt"));
	//m_levelPaths.push_back("../assets/menu.txt");
	m_levelPaths.push_back("../assets/level1.txt");

}

void Scene_Menu::update(sf::Time dt)
{
	m_entityManager.update();
}

void Scene_Menu::sRender()
{
	sf::RenderWindow& window = m_game->window();

	sf::View view = window.getView();
	view.setCenter(window.getSize().x / 2.f, window.getSize().y / 2.f);
	window.setView(view);

	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	sf::Vector2f viewMousePos = window.mapPixelToCoords(mousePos, view);

	for (auto& e : m_entityManager.getEntities("bkg")) {
		if (e->getComponent<CSprite>().has) {
			auto& sprite = e->getComponent<CSprite>().sprite;
			m_game->window().draw(sprite);
		}
	}

	if (!m_isGuide) {
		for (auto& e1 : m_entityManager.getEntities("start1")) {

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
				auto test = e1->getComponent<CTransform>();


				for (auto e2 : m_entityManager.getEntities("start2")) {
					if (e2->hasComponent<CSprite>()) {
						auto& sprite2 = e2->getComponent<CSprite>().sprite;

						if (overlap.x > 0 && overlap.y > 0) {
							m_game->window().draw(sprite2);

							if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
								m_game->changeScene("LEVEL1", std::make_shared<Scene_Cuba>(m_game, m_levelPaths[0]));
							}
						}
						else {
							m_game->window().draw(sprite1);
						}
					}
				}
			}
		}
		for (auto& e1 : m_entityManager.getEntities("htp1")) {

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
				auto test = e1->getComponent<CTransform>();


				for (auto e2 : m_entityManager.getEntities("htp2")) {
					if (e2->hasComponent<CSprite>()) {
						auto& sprite2 = e2->getComponent<CSprite>().sprite;

						if (overlap.x > 0 && overlap.y > 0) {
							m_game->window().draw(sprite2);

							if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
								m_isGuide = true;
							}
						}
						else {
							m_game->window().draw(sprite1);
						}
					}
				}
			}
		}

		for (auto& e1 : m_entityManager.getEntities("quit1")) {

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
				auto test = e1->getComponent<CTransform>();

				for (auto e2 : m_entityManager.getEntities("quit2")) {
					if (e2->hasComponent<CSprite>()) {
						auto& sprite2 = e2->getComponent<CSprite>().sprite;

						if (overlap.x > 0 && overlap.y > 0) {
							m_game->window().draw(sprite2);

							if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
								onEnd();
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
	else {
		for (auto& e : m_entityManager.getEntities("instruction")) {
			if (e->getComponent<CSprite>().has) {
				auto& sprite = e->getComponent<CSprite>().sprite;
				m_game->window().draw(sprite);
			}
		}

		for (auto& e1 : m_entityManager.getEntities("back1")) {

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
				auto test = e1->getComponent<CTransform>();

				for (auto e2 : m_entityManager.getEntities("back2")) {
					if (e2->hasComponent<CSprite>()) {
						auto& sprite2 = e2->getComponent<CSprite>().sprite;

						if (overlap.x > 0 && overlap.y > 0) {
							m_game->window().draw(sprite2);

							if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
								m_isGuide = false;
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


}

void Scene_Menu::loadMenu(const std::string& path) {
	std::ifstream config(path);

	if (config.fail()) {
		std::cerr << "Open file " << path << " failed\n";
		config.close();
		exit(1);
	}

	std::string token{ "" };
	config >> token;

	while (!config.eof()) {
		if (token == "Bkg") {

			std::string name;
			sf::Vector2f pos;

			config >> name >> pos.x >> pos.y;
			auto e = m_entityManager.addEntity("bkg");

			auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
			sprite.setOrigin(0.f, 0.f);
			sprite.setPosition(pos);

		}
		else if (token == "Strt1") {
			std::string name;
			sf::Vector2f pos;

			config >> name >> pos.x >> pos.y;
			auto e = m_entityManager.addEntity("start1");

			auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
			auto spriteSize = sprite.getLocalBounds().getSize();

			e->addComponent<CBoundingBox>(spriteSize);
			sf::Vector2f spriteOrigin = sprite.getOrigin();

			sf::Vector2f boundingBoxPosition = pos + spriteOrigin;

			e->addComponent<CTransform>(boundingBoxPosition);
			sprite.setOrigin(0.f, 0.f);
			sprite.setPosition(pos);

		}
		else if (token == "Strt2") {
			std::string name;
			sf::Vector2f pos;

			config >> name >> pos.x >> pos.y;
			auto e = m_entityManager.addEntity("start2");

			auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;

			sprite.setOrigin(0.f, 0.f);
			sprite.setPosition(pos);
		}
		else if (token == "Htp1") {
			std::string name;
			sf::Vector2f pos;

			config >> name >> pos.x >> pos.y;
			auto e = m_entityManager.addEntity("htp1");

			auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
			auto spriteSize = sprite.getLocalBounds().getSize();

			e->addComponent<CBoundingBox>(spriteSize);
			sf::Vector2f spriteOrigin = sprite.getOrigin();

			sf::Vector2f boundingBoxPosition = pos + spriteOrigin;

			e->addComponent<CTransform>(boundingBoxPosition);
			sprite.setOrigin(0.f, 0.f);
			sprite.setPosition(pos);

		}
		else if (token == "Htp2") {
			std::string name;
			sf::Vector2f pos;

			config >> name >> pos.x >> pos.y;
			auto e = m_entityManager.addEntity("htp2");

			auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
			auto spriteSize = sprite.getLocalBounds().getSize();

			e->addComponent<CBoundingBox>(spriteSize);
			sf::Vector2f spriteOrigin = sprite.getOrigin();

			sf::Vector2f boundingBoxPosition = pos + spriteOrigin;

			e->addComponent<CTransform>(boundingBoxPosition);
			sprite.setOrigin(0.f, 0.f);
			sprite.setPosition(pos);

		}
		else if (token == "Qut1") {
			std::string name;
			sf::Vector2f pos;

			config >> name >> pos.x >> pos.y;
			auto e = m_entityManager.addEntity("quit1");
			auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
			auto spriteSize = sprite.getLocalBounds().getSize();


			e->addComponent<CBoundingBox>(spriteSize);
			sf::Vector2f spriteOrigin = sprite.getOrigin();

			sf::Vector2f boundingBoxPosition = pos + spriteOrigin;

			e->addComponent<CTransform>(boundingBoxPosition);
			sprite.setOrigin(0.f, 0.f);
			sprite.setPosition(pos);
		}
		else if (token == "Qut2") {
			std::string name;
			sf::Vector2f pos;

			config >> name >> pos.x >> pos.y;
			auto e = m_entityManager.addEntity("quit2");

			auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
			e->addComponent<CBoundingBox>(sprite.getLocalBounds().getSize());
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
		else if (token == "Instrc") {
			std::string name;
			sf::Vector2f pos;

			config >> name >> pos.x >> pos.y;
			auto e = m_entityManager.addEntity("instruction");

			auto& sprite = e->addComponent<CSprite>(Assets::getInstance().getTexture(name)).sprite;
			e->addComponent<CBoundingBox>(sprite.getLocalBounds().getSize());
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
