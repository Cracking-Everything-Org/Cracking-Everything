using namespace std;
#include <algorithm>

int flipBit(int a){
    if(~a == 0) return 0;

    int cl = 0;
    int pl = 0;
    int ml = 1;
    while(a!=0){
        if((a&1)==1) cl++;
        else if((a&1)==0){
            pl= (a&2)== 0 ? 0 : cl;
            cl=0;
        }
        ml = max(cl+pl+1,ml);
        a>>=1;
    }
    return ml;
}