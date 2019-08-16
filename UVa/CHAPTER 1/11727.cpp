using namespace std;
#include <iostream>

int main () {
    int lines,a,b,c;
    int i=1;
    cin >> lines;
    while(lines--){
        cin >> a >> b >> c;
        if(a>b && a>c) cout << "Case "<< i <<": " << max(b,c);
        else if(a>b && a<c) cout << "Case "<< i <<": " << a;
        else if(b>a && b>c) cout << "Case "<< i <<": " << max(a,c);
        else if(b>a && b<c) cout << "Case "<< i <<": " << b;
        else if(c>a && c>b) cout << "Case "<< i <<": " << max(a,b);
        else cout << "Case "<< i <<": " << c;
        cout << endl;
        i++;
    }
    return 0;
}