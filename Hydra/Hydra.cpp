// Hydra.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Deck.h"
#include "Joker.h"
#include "GameView.h"
static bool testing = false;

int main() {
    inputs:
    cout << "How Many Human Players?" << endl;
    string numOfPlayers;
    int asNumber;
    getline(cin, numOfPlayers);
    cout << "How Many Computer Players?" << endl;
    string compPlayers;
    int compAsNumber;
    getline(cin, compPlayers);
    cout << "How Many Cards Per Player?" << endl;
    string cardsPerPlayers;
    int cardsAsNum;
    getline(cin, cardsPerPlayers);
    try {
        asNumber = stoi(numOfPlayers);
        compAsNumber = stoi(compPlayers);
        cardsAsNum = stoi(cardsPerPlayers);
    } catch (std::invalid_argument) {
        cerr << "One of the inputs was not a number. Enter All Inputs as Numbers" << endl;
        goto inputs;
    }
    

    GameView v{ asNumber, compAsNumber, cardsAsNum, testing };
    v.makeController();
    int player = 2;
  
    while (v.endGame() == false) {
         v.handleInputs(player); // int input, int cardsPlayed, int cardsToPlay, int player
         player = (player % (asNumber + compAsNumber)) + 1;
    }
}


