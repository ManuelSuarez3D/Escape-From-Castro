#include "Scene.h"
#include "iostream"
#include "fstream"

Scene::Scene(GameEngine* gameEngine) : m_game(gameEngine)
{}

Scene::~Scene()
{}

void Scene::setPaused(bool paused)
{
	m_isPaused = paused;
}


void Scene::simulate(int)
{}

void Scene::doAction(Command command)
{
	this->sDoAction(command);
}


const CommandMap Scene::getActionMap() const
{
	return m_commands;
    
}

void Scene::registerAction(int inputKey, std::string command)
{
	m_commands[inputKey] = command;
}

void Scene::writeToLoadingFile(std::string level) {
    std::ofstream outputFile("../assets/levelSelected.txt");

    if (outputFile.is_open()) {

        if (level == "CUBA") {
            outputFile << "#\n" << "isCuba " << (m_isCuba ? "true" : "false") << std::endl;
        }else if (level == "BERMUDA") {
            outputFile << "isBermuda " << (m_isBermuda ? "true" : "false") << std::endl;
        }
        else if (level == "USA") {
            outputFile << "isUSA " << (m_isUSA ? "true" : "false") << std::endl;
        }
        else if (level == "OVER") {
            outputFile << "isOver " << (m_isOver ? "true" : "false") << std::endl;
        }
        outputFile.close();
        std::cout << "Successfully wrote to levelSelected.txt" << std::endl;
    }
    else {
        std::cerr << "Failed to open levelSelected.txt" << std::endl;
    }
}

void Scene::writeToScoreFile(int score) {
    std::ofstream outputFile("../assets/score.txt");

    if (outputFile.is_open()) {

        outputFile << "#\n" << "Score " << std::to_string(score) << std::endl;

        outputFile.close();
        std::cout << "Successfully wrote to score.txt" << std::endl;
    }
    else {
        std::cerr << "Failed to open score.txt" << std::endl;
    }
}

void Scene::writeToInventoryFile(int inventory) {
    std::ofstream outputFile("../assets/inventory.txt");

    if (outputFile.is_open()) {

        outputFile << "#\n" << "Coca " << std::to_string(inventory) << std::endl;

        outputFile.close();
        std::cout << "Successfully wrote to inventory.txt" << std::endl;
    }
    else {
        std::cerr << "Failed to open inventory.txt" << std::endl;
    }
}