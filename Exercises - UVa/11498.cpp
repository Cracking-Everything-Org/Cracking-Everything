using namespace std;
#include <iostream>

int main () {
    int divisaX, divisaY, actual, x, y;
    cin >> actual;
    while(actual != 0){
        cin >> divisaX >> divisaY;
        while(actual--){
            cin >> x >> y;
            if(divisaX == x || divisaY == y) cout << "divisa";
            else if(x < divisaX && y < divisaY) cout << "SO";
            else if(x < divisaX && y > divisaY) cout << "NO";
            else if(x > divisaX && y < divisaY) cout << "SE";
            else cout << "NE";
            cout << endl;
        }
        cin >> actual;
    }   
    return 0;
}