using namespace std;
#include <iostream>
#include <fstream>

void main () {
    int k, a, b;
    int c = 1;
    scanf("%d", &k);
    while(k--){
        if(c>1) printf("\n");
        scanf("%d %d", &a, &b);
        if (a < b) printf("<");
        else if (a > b) printf(">");
        else printf("=");
        c++; 
    }   
}