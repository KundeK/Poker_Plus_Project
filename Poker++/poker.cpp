#include "poker.h"
bool Poker::sameSuit(vector<Card> v){
    string temp = v[0].suit;
    for(int i = 0; i < v.size(); i++){
        if(temp != v[i].suit){
            return false;
        }
    }
    return true;
}

bool Poker::straight(vector<Card> v){
    for(int i = 0; i < v.size(); i++){ //converting Face cards to value prior to calculation
        if(v[i].value == "Ace"){
            v[i].value = "14";
        }
        if(v[i].value == "King"){
            v[i].value = "13";
        }
        if(v[i].value == "Queen"){
            v[i].value = "12";
        }
        if(v[i].value == "Jack"){
            v[i].value = "11";
        }
    }
    int min = std::stoi(v[0].value);
    for(int i = 1; i < v.size(); i++){
        if(std::stoi(v[i].value) < min){
            min = std::stoi(v[i].value);
        }
    }
    int next = min + 1;
    int i = 0;
    while(i < v.size()) {
        if(std::stoi(v[i].value) == next){
            next++;
            i=0;
        }
        else{
            i++;
        }
    }
    if(next == (min + 5)){
        return true;
    }
    else{
        return false;
    }
}

int Poker::countPairs(vector<Card> arr){
    for(int i = 0; i < arr.size(); i++){ //converting Face cards to value prior to calculation
        if(arr[i].value == "Ace"){
            arr[i].value = "14";
        }
        if(arr[i].value == "King"){
            arr[i].value = "13";
        }
        if(arr[i].value == "Queen"){
            arr[i].value = "12";
        }
        if(arr[i].value == "Jack"){
            arr[i].value = "11";
        }
    }
    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++){
            if (std::stoi(arr[i].value) - std::stoi(arr[j].value) == 0 || std::stoi(arr[j].value) - std::stoi(arr[i].value) == 0){
                count++;
            }
        }      
    }
    return count;
}

int Poker::countDuplicates(vector<Card> arr){
    int count = 0;
    for(int i=0; i< arr.size(); i++){
        for(int j=i+1; j < arr.size(); j++){
        if(arr[i].value == arr[j].value){ //do i need stoi here?
                count++;
            }
        }
    }
    return count;
}

bool Poker::checkKing(vector<Card> v){
    for(int i = 0; i < v.size(); i++){
        if(v[i].value == "King"){
            return true;
        }
    }
return false;
}

string Poker::verifyHand(vector<Card> v) {
    if(sameSuit(v) && straight(v) && checkKing(v)){
        return "Royal Flush! The odds of that are 0.000154%!";
    }
    else if(sameSuit(v) && straight(v)){
		return "Straight Flush! The odds of that are 0.00139%!";
		}
	else if(countDuplicates(v) == 4){
		return "Four of a kind! The odds of that are 0.02401%!";
	}
	else if((countDuplicates(v) == 3) && (countPairs(v) == 1)){
		return "Full House! The odds of that are 0.1441%!";
	}
	else if(sameSuit(v)){
		return "Flush! The odds of that are 0.1965%!";
	}
    else if (straight(v)){
		return "Straight! The odds of that are 0.3925%!";
	}
    else if(countDuplicates(v) == 3){
        return "Three of a kind! The odds of that are 2.1128%!";
    }
	else if(countPairs(v) == 2){
		return "Two pair! The odds of that are 4.7539%!";
	}
	else if(countPairs(v) == 1){
		return "Pair! The odds of that are 42.2569%!";
	}
    return "nothing. The odds of that are 50.1177%.";
}