#include <string>

class Warrior {
    protected: 
        std::string name_;

    public:
        int strength_;
        int life_points_;
        virtual void attack(Warrior* enemy) = 0;
        void be_attacked(int damages);
        bool is_alive();

        friend std::ostream& operator<<(std::ostream& os, const Warrior& warrior);
};


class Ninja: public Warrior {
    public: 
        Ninja();
        void attack(Warrior* enemy);
};


class Samurai: public Warrior {
    public: 
        Samurai();
        void attack(Warrior* enemy);
};
