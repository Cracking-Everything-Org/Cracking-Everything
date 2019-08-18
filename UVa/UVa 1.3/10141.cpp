#include <iostream>
#include <cstring>
using namespace std;

int main () {
    int r, n;
    int tc =0;
    string x;
    while(cin >> r >> n, r || n){
        tc++;
        int reqMet = -1, rm;
        double price = 2000000000, p;
        string proposalName, proposer;
        for (int i =0; i< r; i++){
			cin.ignore();
			getline(cin, x);
            //cin >> x;
        }
        while(n--){
            getline(cin,proposer);
			scanf("%lf %d\n", &p, &rm);
            //cin >> proposer;
            //cin >> p >> rm;
            if(rm>reqMet){
                reqMet = rm;
                price = p;
                proposalName = proposer;
            } else if (rm==reqMet && p < price){
                reqMet = rm;
                price = p;
                proposalName = proposer;
            }
            for(int j=0; j< rm; j++) {
                getline(cin, x);
                //cin >> x;
            }
        }
        if(tc>1) cout << endl;
        cout << "RFP #" << tc << endl;
        cout << proposalName << endl;
    }
    return 0;
}