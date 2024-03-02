#include "GameState.h"
#include "GameStateManager.h"


//GameState_TowerMenu::GameState_TowerMenu(GameStateManager& context, GameWorld* gameWorld)
//	: GameState(context), m_GameWorld(gameWorld)
//{
//
//}
//
//void GameState_TowerMenu::updateState()
//{
//	TowerMenu towerMenu = m_gameStateManager.getCurrentGameState()->getTowerMenu();
//
//	if (towerMenu.getDrawEnabled())
//	{
//        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
//        {
//            // Отримайте позицію миші
//            sf::Vector2i mousePosition = sf::Mouse::getPosition();
//            // Передайте подію в TowerMenu для обробки
//            //towerMenu.handleEvent(mousePosition, nullptr);
//            sf::Event mouseEvent;
//            mouseEvent.type = sf::Event::MouseButtonPressed;
//            mouseEvent.mouseButton.button = sf::Mouse::Left;
//            mouseEvent.mouseButton.x = mousePosition.x;
//            mouseEvent.mouseButton.y = mousePosition.y;
//
//            towerMenu.handleEvent(mouseEvent, *m_gameStateManager.getCurrentGameState()->getRenderWindow());
//
//            // Отримайте вибрану башту та змінну drawEnabled
//            Tower* selectedTower = towerMenu.getSelectedTower();
//            bool drawEnabled = towerMenu.getDrawEnabled();
//
//            // Додайте інші необхідні дії відповідно до вашої логіки
//            // ...
//
//            // Змініть стан гри, якщо необхідно
//            if (!drawEnabled)
//            {
//                m_gameStateManager.setGameState(GameStateId::Playing);
//            }
//        }
//	}
//	
//}
//
//void GameState_Playing::updateState()
//{
//    /*BuildPlace buildPlace = m_gameStateManager.getCurrentGameState()->getBuildPlace();
//    if (buildPlace.handleEvent(event, window, towerSelection))
//    {
//        if (!m_pressedLastFrame)
//        {
//            m_pressedLastFrame = true;
//            m_gameStateManager.setGameState(GameStateId::Pause);
//        }
//    }
//    else
//    {
//        m_pressedLastFrame = false;
//    }*/
//}
//
//void GameState_Playing::draw(sf::RenderWindow& window)
//{
//    m_GameWorld->draw(window);
//}
