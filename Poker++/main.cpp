#include <bits/stdc++.h>
#include <iostream>
#include <time.h>
#include "poker.h"
#include "poker.cpp"
using namespace std;

int main() {   //comment different parts of the code
    bool play = true;
    while(play = true){
        Poker p;
        cout << "\nEnter your name: " << endl;
        string name;
        cin >> name;
        cout << "Hi, " << name << "\n" << endl;
        vector<Card> deck;
        for(int i = 1; i < 14; i++) {
            for(int j = 0; j < 4; j++) {
                Card tmp;
                if(j == 0) tmp.suit = "Clubs";
                if(j == 1) tmp.suit = "Diamonds";
                if(j == 2) tmp.suit = "Hearts";
                if(j == 3) tmp.suit = "Spades";
                if(i == 1) tmp.value = "Ace";
                if(i == 11) tmp.value = "Jack";
                if(i == 12) tmp.value = "Queen";
                if(i == 13) tmp.value = "King";
                else tmp.value = to_string(i);
                deck.push_back(tmp);
            }
        }

        //generate the deck
        //this random shuffle isn't truly random, reset the random thing 
        //random_shuffle(deck.begin(), deck.end());  //implemented the Fisher-Yates Shuffling Algorithm with time bs involved instead
        srand (time(NULL));    
        for (int i = 0; i < deck.size() - 1; i++){
            // Pick a random index from 0 to i
            int j = i + rand() % (deck.size() - i);
            std::swap(deck[i], deck[j]);
        }

        pair<Card,Card> hand;
        hand.first = deck[0];
        hand.second = deck[1];
        vector<Card> table;
        /*
        for(int i = 2; i < 7; i++) {  //alter this loop so that the table only receives 3 cards for simplicity
            table.push_back(deck[i]);
        }
        */

        for(int i = 2; i < 6; i++) {  //alter this loop so that the table only receives 3 cards for simplicity
            table.push_back(deck[i]);
        }

        cout << "------------------------------\n";
        cout << "This is your hand: " << endl;
        cout << hand.first.value << " of " << hand.first.suit << endl;
        cout << hand.second.value << " of " << hand.second.suit << endl;
        cout << "------------------------------\n";
        cout << "------------------------------\n";
        cout << "These are the cards on the table: " << endl;
        for (int i = 0; i < table.size()-1; i++) {
            cout << table[i].value << " of " << table[i].suit << endl;
        }
        cout << "------------------------------\n\n";

        /*
        for(int i = 3; i < 5; i++) { //Alter loops so that tmp gets the table and user hands for simplicity
            vector<Card> tmp;
            for(int j = 0; j < i; j++) {
                tmp.push_back(table[i]);
            }
            tmp.push_back(hand.first);
            tmp.push_back(hand.second);
            cout << p.verifyHand(tmp) << endl; //make it possible to rerun simulation(?)
        }
        */
        vector<Card> tmp;
        for(int i = 0; i < 3; i++){
        tmp.push_back(table[i]);
        }
        tmp.push_back(hand.first);
        tmp.push_back(hand.second);
        cout << "You have a " << p.verifyHand(tmp) << endl;

        cout << "Would you like to draw again? Y/N" << endl;
        string game;
        cin >> game;
        if(game == "Y" || game == "y"){
            system("CLS");
            play = true;
        }
        else if(game == "N" || game == "n"){
            system("CLS");
            cout << "Thanks for playing!" << endl;
            exit(1);
        }
        else{
            system("CLS");
            cout << "Invalid input. Try again later!" << endl;
            exit(1);
        }
    }
    return 0;
}
