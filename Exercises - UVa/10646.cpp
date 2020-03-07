#include <iostream>
#include <vector>
#include <string>

using namespace std;

int getTopVal(string card){
    int cardNum = card[0];
    return (cardNum >= '2' && cardNum <= '9'? cardNum - '0' : 10);
}

int main () {
    int i = 0, tc;
    cin >> tc;
    while(tc--){
        vector<string> pile;
        vector<string> hand;
        string card;
        int y, x, toRemove;
        i++;

        //pusheo todas las cartas a la pila
        for(int i=0; i<52; i++){
            cin >> card;
            pile.push_back(card);          
        }
        // saco 25 del top y los paso a la hand
        for(int j=0; j<25; j++){
            hand.push_back(pile.back());
            pile.pop_back();
        }
        y = 0;
        //realizo los pasos 3 veces
        for(int k=0; k<3; k++){
            x = getTopVal(pile.back());
            y += x;
            toRemove = (10-x)+1;
            for(int l=0; l<toRemove; l++) pile.pop_back();
        }
        //agrego los 25 de la hand otra a la pila
        for(int c=0; c<hand.size(); c++){
            pile.push_back(hand.back());
            hand.pop_back();
        }
        cout << "Case " << i << ": " << pile[y-1] << endl;
    }
    return 0;
}