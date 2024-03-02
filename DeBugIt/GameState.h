#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "GameWorld.h"
#include "Menu.h"
#include "BuildPlace.h"

//class GameStateManager;

class GameState
{
//public:
//	GameState(GameStateManager& context) : m_gameStateManager(context) {}
//
//	virtual void onEnter() {} //To add initialization during state enter
//	virtual void onExit() {} //To add deinitialization during state exit
//
//	virtual void updateState() = 0;
//	virtual void update(float DeltaTime) = 0;
//	virtual void draw(sf::RenderWindow& window) = 0;
//
//	virtual TowerMenu& getTowerMenu() = 0;
//	//virtual BuildPlace getBuildPlace() = 0;
//	virtual sf::RenderWindow* getRenderWindow() const = 0;
//
//protected:
//	GameStateManager& m_gameStateManager;
//};
//
//class GameState_Playing : public GameState
//{
//public:
//	GameState_Playing(GameStateManager& context, GameWorld* gameWorld) : GameState(context), m_GameWorld(gameWorld) {}
//
//	void onEnter() override{}
//
//	void updateState() override;
//	void update(float DeltaTime) override {m_GameWorld->update(DeltaTime);
//	}
//	void draw(sf::RenderWindow& window) override;
//
//	TowerMenu& getTowerMenu()override;
//	 sf::RenderWindow* getRenderWindow() const override;
//	// BuildPlace getBuildPlace()override;
//private:
//	GameWorld* m_GameWorld;
//	BuildPlace m_buildPlace;
//
//	bool m_pressedLastFrame = true;
//};
//
//class GameState_PauseMenu : public GameState
//{
//public:
//	GameState_PauseMenu(GameStateManager& context, GameWorld* gameWorld);
//
//	void updateState() override;
//	void update(float DeltaTime) override;
//	void draw(sf::RenderWindow& window) override;
//
//	void onEnter() override;
//	void onExit() override;
//
//private:
//	GameWorld* m_GameWorld;
//
//	bool m_pressedLastFrame = true;
//
//	sf::Text m_pauseText;
//	sf::Clock m_textLoopClock;
//	bool m_isVisible = true;
//};
//class GameState_TitleScreen : public GameState
//{
//public:
//	GameState_TitleScreen(GameStateManager& context);
//
//	void onEnter() override;
//	void onExit() override;
//
//	void updateState() override;
//	void update(float DeltaTime) override;
//	void draw(sf::RenderWindow& window) override;
//
//private:
//	sf::Text m_text;
//
//	sf::Texture m_startTexture;
//	sf::Sprite m_startSprite;
//
//	//sf::Music m_music;
//};
//
//class GameState_WinMenu : public GameState
//{
//
//};
//
//class GameState_LoseMenu : public GameState
//{
//
//};
//
//class GameState_TowerMenu : public GameState
//{
//public:
//	GameState_TowerMenu(GameStateManager& m_gameStateManager, GameWorld* gameWorld);
//	void updateState() override;
//	void update(float DeltaTime) override{}
//	void draw(sf::RenderWindow& window) override{}
//
//	void onEnter() override{}
//	void onExit() override{}
//
//	TowerMenu& getTowerMenu() override { return m_TowerMenu; }
//	sf::RenderWindow* getRenderWindow() const override{return m_window;}
//
//	// BuildPlace getBuildPlace()override;
//private:
//	GameWorld* m_GameWorld;
//	TowerMenu m_TowerMenu;
//	sf::RenderWindow* m_window;
//	
//
//	bool m_pressedLastFrame = true;
//
//	//sf::Text m_pauseText;
//	sf::Clock m_textLoopClock;
//	bool m_isVisible = true;
};