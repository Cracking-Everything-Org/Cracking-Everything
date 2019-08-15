using namespace std;
#include <iostream>
#include <fstream>

void main () {
    int queries, divisaX, divisaY;
    bool valid = true;
    while(valid){
        scanf("%d", &queries);
        scanf("%d %d", &divisaX, &divisaY);
        while(queries--){
            scanf("%d %d", &x, &y);
            if(divisaX-x == 0 || divisaY-y==0) printf("divisa\n");
            //W
            else if(divisaX-x < 0){
                //SW
                if(divisaY-y < 0){
                    printf("SO\n");
                //NW
                }else{
                    printf("NO\n");
                }
            //E
            } else {
                //SE
                if(divisaY-y < 0){
                    printf("SE\n");
                //NE
                }else{
                    printf("NE\n");
                }
            }
        }
    }   
}