using namespace std;
#include <iostream>
#include <cmath>

void main () {
    int lines,a,b,c;
    int i=1;
    scanf("%d",&lines);
    while(lines--){
        scanf("%d",&a);
        scanf("%d",&b);
        scanf("%d",&c);
        int preMax = max(b,c);
        if(a>b && a>c) printf("Case %d: %d\n",i,max(b,c));
        else if(b>a && b>c) printf("Case %d: %d\n",i,max(a,c));
        else if(c>a && c>b) printf("Case %d: %d\n",i,max(a,b));
        i++;
    }
}