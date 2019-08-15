using namespace std;
#include <iostream>

int main () {
    int n, x, y;
    cin >> n;
    while(n--){
        cin >> x >> y;
        if (x < y) cout << "<";
        else if (x > y) cout << ">";
        else cout << "=";
        cout << endl;
    }   
    return 0;
}