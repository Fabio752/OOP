#include <string>
#include <vector>

#include "warrior.hpp"

class Game {
    private:
        bool game_over_;
        bool turn_;
        std::string winners_;
        std::vector<Warrior*> team_one_;
        std::vector<Warrior*> team_two_;

    public: 
        Game();
        void game_play();
        void game_over();
        void restart_game();
        void game_status();
};
