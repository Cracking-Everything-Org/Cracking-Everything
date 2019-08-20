#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{  
    size_t round;
    while (cin >> round, round != -1)
    {
        string solution, guess;
        cin >> solution >> guess;

        int stroke = 0;
        for (size_t i = 0; i < guess.size() 
                           && stroke <= 6 
                           && solution != ""; ++i)
        {
            if (solution.find(guess[i]) != string::npos)
            {
                solution.erase(remove(solution.begin(), solution.end(),
                                      guess[i]),
                               solution.end());
            }
            else
                ++stroke;
        }
        cout << "Round " << round << endl;
        if (stroke == 7)
            cout << "You lose." << endl;
        else if (solution == "")
            cout << "You win." << endl;
        else
            cout << "You chickened out." << endl;
    }
    return 0;
}

// #include <iostream>
// #include <algorithm>
// #include <map>

// using namespace std;

// int main (){
//     int tc, chances, wons;
//     string result, expected, actual;
//     map<char, int> ht;
//     while(scanf("%d", &tc), tc != -1){
//         chances = 0;
//         cin >> expected;
//         for(int i=0; i< expected.length(); i++){
//             if(ht[expected[i]]>0){
//                 expected[i]++;
//             }else{
//                 ht[expected[i]] = 1;
//             }
//         }
//         cin >> actual;
//         sort(actual.begin(), actual.end());
//         for(int j=0; j< actual.length(); j++){
//             if(ht[actual[j]]>0){
//                 wons+= ht[actual[j]];
//                 ht[actual[j]] = 0;
//             }else if(ht[actual[j]] == -1){
//                 chances++;
//             }
//             if(wons == expected.length()) {
//                 result = "You win.";
//             }
//             else if(chances == 7) {
//                 result = "You lose.";
//             }
//             else if(expected.length() <= chances+j+1) {
//                 result = "You chickened out.";
//             }
//         }
//         cout << "Round " << tc << endl;
//         cout << result << endl;
//     }
//     return 0;
// }