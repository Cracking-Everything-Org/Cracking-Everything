
#include <iostream>
using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    float h, u, d, f;
    while(cin >> h >> u >> d >> f && h){
        float currentPos=0;
        int day = 1;
        f = u*f/100;
        while(currentPos < h && currentPos >= 0){
            currentPos += u;
            if(u>0) u -= f;
            if(currentPos>h) break; 
            currentPos-=d;
            if(currentPos<0) break;
            ++day;
        } 
        if (currentPos < 0) cout << "failure on day " << day << endl; 
        else cout << "success on day " << day << endl;
    }
    return 0;
}