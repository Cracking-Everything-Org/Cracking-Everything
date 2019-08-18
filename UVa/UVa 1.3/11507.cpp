#include <iostream>
#include <string>
#include <map>
using namespace std;

int main (){
    map <string,map<string,string> > bends; 
    bends["+x"]["+y"] = "+y";
    bends["+x"]["-y"] = "-y";
    bends["+x"]["+z"] = "+z";
    bends["+x"]["-z"] = "-z";
    bends["-x"]["+y"] = "-y";
    bends["-x"]["-y"] = "+y";
    bends["-x"]["+z"] = "-z";
    bends["-x"]["-z"] = "+z";
    bends["+y"]["+y"] = "-x";
    bends["+y"]["-y"] = "+x";
    bends["+y"]["+z"] = "+y";
    bends["+y"]["-z"] = "+y";
    bends["-y"]["+y"] = "+x";
    bends["-y"]["-y"] = "-x";
    bends["-y"]["+z"] = "-y";
    bends["-y"]["-z"] = "-y";
    bends["+z"]["+y"] = "+z";
    bends["+z"]["-y"] = "+z";
    bends["+z"]["+z"] = "-x";
    bends["+z"]["-z"] = "+x";
    bends["-z"]["+y"] = "-z";
    bends["-z"]["-y"] = "-z";
    bends["-z"]["+z"] = "+x";
    bends["-z"]["-z"] = "-x";
    int L;
    string pointer, newbend;
    while(true){
        scanf("%d", &L);
        if(L==0) break;
        pointer = "+x";
        for(int i=0; i< L-1; i++){
            cin >> newbend;
            if(newbend != "No") pointer = bends[pointer][newbend];
        }
        cout << pointer << endl;
    }
    return 0;
}
