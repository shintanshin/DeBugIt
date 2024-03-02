#include "GameStateManager.h"
#include "GameState.h"

//GameStateManager::GameStateManager(GameWorld* gameWorld, GameStateId initialGameStateId)
//{
//	//m_gameStates[static_cast<std::size_t>(GameStateId::TitleScreen)] = new GameState_TitleScreen(*this);
//	//m_gameStates[static_cast<std::size_t>(GameStateId::PauseMenu)] = new GameState_PauseMenu(*this, gameWorld);
//	//m_gameStates[static_cast<std::size_t>(GameStateId::Playing)] = new GameState_Playing(*this, gameWorld);
//	m_gameStates[static_cast<std::size_t>(GameStateId::TowerMenu)] = new GameState_TowerMenu(*this, gameWorld);
//
//
//	m_currentGameState = m_gameStates[static_cast<std::size_t>(initialGameStateId)];
//	m_currentGameState->onEnter();
//}
//
//void GameStateManager::setGameState(GameStateId newGameState)
//{
//	m_currentGameState->onExit();
//	m_currentGameState = m_gameStates[static_cast<std::size_t>(newGameState)];
//	m_currentGameState->onEnter();
//}
