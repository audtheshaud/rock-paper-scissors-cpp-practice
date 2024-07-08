/*
This program is meant toplay a round of Rock, Paper, 
Scizzors, Lizard, Spock and decalare the winner of said match
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
#include <chrono>
#include <thread>

void game(std::string pl, std::string op){ // Added delays for readability
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "3!\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "2!\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "1!\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "go!\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    if (pl == op){ // Checks for tie and exits the game function call
        std::cout << "Game tied! Both the player and opponent chose " + pl;
        return;
    }
    if (pl == "Rock"){ 
        if (op == "Lizzard" || "Scizzors"){ 
            std::cout << "Player wins with Rock against " + op; // Good ol' string concatenation
        }else{ // Catchall for the other two possibilities
            std::cout << "Opponent wins with " + op + " against Rock"; 
        }
    }
    if (pl == "Paper"){
        if (op == "Spock" || "Rock"){
            std::cout << "Player wins with Paper against " + op;
        }else{
            std::cout << "Opponent wins with " + op + " against Paper";
        }  
    }
    if (pl == "Scizzors"){
        if (op == "Paper" || "Lizard"){
            std::cout << "Player wins with Scizzors against " + op;
        }else{
            std::cout << "Opponent wins with " + op + " against Scizzors";
        }
    }
    if (pl == "Lizard"){
        if (op == "Spock" || "Paper"){
            std::cout << "Player wins with Lizard against " + op;
        }else{
            std::cout << "Opponent wins with " + op + " against Lizard";
        }
    }
    if (pl == "Spock"){
        if (op == "Scizzors" || "Rock"){
            std::cout << "Player wins with Spock against " + op;
        }else{
            std::cout << "Opponent wins with " + op + " against Spock";
        }
    }
}
// ^^ Decides who wins the match based on player and opponents choices

int main(){ // Default return type is int

    std::string choices[5] = {"Rock", "Paper", "Scizzors", "Lizard", "Spock"};
    srand(time(0));
    int rand_index = rand() % 4;
    std::string opponents_choice = choices[rand_index];
    // ^^ Creates the opponents choice randomly

    std::string list_choices; 
    for (int i = 0; i < 5; i++){ // Iterate through the array
        if (i == 0){ // On the first iteration, add Rock to the list
            list_choices = choices[i];
        }
        if (i > 0){ // Add all other strings with a comma prepended
            list_choices += ", " + choices[i];
        }
    }
    std::string players_choice;
    do {
        std::cout << "Enter a move from the list provided: (" + list_choices + ")\n";
        std::cin >> players_choice;
    } while(list_choices.find(players_choice) == -1);
    /*
    -1 is the same as std::string::npos. When the find() method does not find 
    players_choice in list_choices, it returns the ending index
     */
    // ^^ Player inputs their choice using std::cin, checks to make sure choice is valid

    game(players_choice, opponents_choice);
    return 0;
}