#ifndef GAMEOVER_STATE_MAIN_HPP
#define GAMEOVER_STATE_MAIN_HPP

#include "game.hpp"
#include "strapon/state/state.hpp"

class GameoverState : public State {
public:
    GameoverState(Game *game);
    ~GameoverState();
    int init() override;
    void update(double dt) override;

private:
    Game *m_game;
  	std::string background_key;
};

#endif /* end of include guard: STATE_MAIN_HPP */
