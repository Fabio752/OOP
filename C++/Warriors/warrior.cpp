#include <cmath>
#include <iostream>
#include "warrior.hpp"


// virtual void attack(Warrior* enemy) = 0;
void Warrior::be_attacked(int damages){
    if(life_points_ > damages)
        life_points_ = life_points_ - damages;
    else
        life_points_ = 0;
}

bool Warrior::is_alive(){
    if(life_points_ > 0)
        return true;
    return false;   
}

Ninja::Ninja(){
    name_ = "Ninja";
    strength_ = rand() % 100;
    life_points_ = rand() % 100;
}

void Ninja::attack(Warrior* enemy){
    int damages = rand() % strength_;
    enemy->be_attacked(damages);
    std::cout << "ninja attack, damages = " <<damages <<std::endl;
}

Samurai::Samurai(){
    name_ = "Samurai";
    strength_ = rand() % 100;
    life_points_ = rand() % 100;
}

void Samurai::attack(Warrior* enemy){
    int damages = rand() % strength_;
    enemy->be_attacked(damages);
    std::cout << "samurai attack, damages = " <<damages <<std::endl;
}


std::ostream& operator<<(std::ostream& os, const Warrior& warrior){
    if(warrior.life_points_ > 0){
        os << "S: " <<warrior.strength_ <<"\n";
        os << "LP: " <<warrior.life_points_;
    }
    return os;
}
