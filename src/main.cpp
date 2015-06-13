#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#include "game.hpp"

#include <functional>

int main() {
    Game game;

    if (!game.init())
        return 1;

#ifdef __EMSCRIPTEN__
    std::function<bool()> f = [&game](){ return game.mainloop(); };
    //auto f = [&game](){ return game.mainloop(); };
    emscripten_set_main_loop(f.target(), 0, true);
#else
    while (game.mainloop()) {}
#endif

    return 0;
}
