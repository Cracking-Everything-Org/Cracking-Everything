#include <iostream>

using namespace std;

int main () {
    int TC, students, max, ci, current;
    cin >> TC;
    current = 0;
    while(TC--){
        current ++;
        cin >> students;
        max = 0;
        for(int i=0; i<students; i++){
            cin >> ci;
            if(ci > max) max = ci;
        }
        cout << "Case " << current << ": " << max;
        cout << endl;
    } 


    return 0;
}