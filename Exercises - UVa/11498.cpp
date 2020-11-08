#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int k, n, m, x, y;
    while (scanf("%d", &k)) {
        scanf("%d %d", &n, &m);
        while (k--) {
            scanf("%d %d", &x, &y);
            if (x == n || y == m) {
                printf("divisa\n");
            }
            else if (x < n) {
                if (y < m) {
                    printf("SO\n");
                }
                else {
                    printf("NO\n");
                }
            }
            else {
                if (y < m) {
                    printf("SE\n");
                }
                else {
                    printf("NE\n");
                }
            }
        }
    }
    return 0;
}