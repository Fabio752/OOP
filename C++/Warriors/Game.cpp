#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <iostream>

#include "Game.hpp"

Game::Game(){
    srand(time(NULL));
    game_over_ = 0;
    turn_ = rand() % 2;
    winners_ = "";
    
    int teams_size = rand() % 20;
    for(int i = 0; i < teams_size; i++){
        Warrior* ninja = new Ninja();
        team_one_.push_back(ninja);

        Warrior* samurai = new Samurai();
        team_two_.push_back(samurai);
    }

}

void Game::game_play(){
    while(!game_over_){
        if(!turn_){
            int attacker_index = rand() % team_one_.size();
            while(!team_one_[attacker_index]->is_alive()){
                attacker_index++;
                attacker_index = attacker_index % team_one_.size();
            }
            int attacked_index = rand() % team_two_.size();
            while(!team_two_[attacked_index]->is_alive()){
                attacked_index++;
                attacked_index = attacked_index % team_two_.size();
            }
            team_one_[attacker_index]->attack(team_two_[attacked_index]);
            turn_ = 1;
        }
        else{
            int attacker_index = rand() % team_two_.size();
            while(!team_two_[attacker_index]->is_alive()){
                attacker_index++;
                attacker_index = attacker_index % team_two_.size();
            }
            int attacked_index = rand() % team_one_.size();
            while(!team_one_[attacked_index]->is_alive()){
                attacked_index++;
                attacked_index = attacked_index % team_one_.size();
            }
            team_two_[attacker_index]->attack(team_one_[attacked_index]);
            turn_ = 0;
        }   
        
        game_status();
        game_over();

        if(game_over_){
            std::cout <<"the winners are the: " <<winners_ <<"\n";
            char answer;
            std::cout <<"press any key to restart the game, press q to quit\n";
            std::cin >>answer;
            if(answer != 'q' && answer != 'Q')
                restart_game();
        }
    }


}
void Game::game_over(){
    //check if team 1 lost
    bool game_over = 1;
    for(int i = 0; i < team_one_.size(); i++){
        if(team_one_[i]->is_alive())
            game_over = 0;
    }
    if(game_over == 1){
        game_over_ = 1;
        winners_ = "samurais";
        return;
    }
    //check if team 2 lost
    for(int i = 0; i < team_two_.size(); i++){
        if(team_two_[i]->is_alive())
            game_over = 0;
    }
    if(game_over == 1){
        game_over_ = 1;
        winners_ = "ninjas";
    }
}

void Game::restart_game(){
    srand(time(NULL));
    game_over_ = 0;
    turn_ = rand() % 2;
    winners_ = "";
    
    int teams_size = rand() % 20;
    for(int i = 0; i < teams_size; i++){
        Warrior* ninja = new Ninja();
        team_one_.push_back(ninja);

        Warrior* samurai = new Samurai();
        team_two_.push_back(samurai);
    }
}

void Game::game_status(){
    std::cout <<"######### GAME STATUS ###########\n";
    std::cout <<"_________________________________\n";
    std::cout <<"__Team Ninjas__|__Team Samurais__\n";
    for(int i = 0; i < team_one_.size(); i++){
        std::cout <<" S: " <<team_one_[i]->strength_ <<"               S: " << team_two_[i]->strength_ <<"\n";
        std::cout <<" LP: " <<team_one_[i]->life_points_ <<"               LP: " << team_two_[i]->life_points_ <<"\n"; 
        std::cout <<"_____________________________\n";

    }
    std::cout <<"_________________________________\n\n\n\n";
}