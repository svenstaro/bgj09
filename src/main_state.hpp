#ifndef MAIN_STATE_MAIN_HPP
#define MAIN_STATE_MAIN_HPP

#include "game.hpp"
#include "entityx/entityx.h"
#include "strapon/state/state.hpp"

class MainState : public State
{
public:
    MainState(Game *game);
    ~MainState();
    int init() override;
    void update(double dt) override;

private:
    Game *m_game;
    entityx::EventManager m_events;
  	entityx::EntityManager m_entities{m_events};
  	entityx::SystemManager m_systems{m_entities, m_events};
  	//Level1
  	std::string background_key;
  	int enemies = 1;
};

#endif /* end of include guard: STATE_MAIN_HPP */
