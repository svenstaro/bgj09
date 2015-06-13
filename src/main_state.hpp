#ifndef STATE_MAIN_HPP
#define STATE_MAIN_HPP

#include "game.hpp"

#include "strapon/state/state.hpp"

class MainState : public State
{
public:
    MainState(Game *game);
    ~MainState();
    int init();
    void update(float dt);

private:
    Game *m_game;
};

#endif /* end of include guard: STATE_MAIN_HPP */
