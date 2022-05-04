#ifndef POKER_H
#define POKER_H
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
#include <string>


struct Card {
    string suit;
    string value;
};
class Poker {
    public:
        Poker() = default;
        bool sameSuit(vector<Card> v);
        bool straight(vector<Card> v);
        int countPairs(vector<Card> arr);
        int countDuplicates(vector<Card> arr);
        bool checkKing(vector<Card> v);
        string verifyHand(vector<Card> v);
};

#endif