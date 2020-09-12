#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    // int, long, char, float, and double
    int d;
    long ld;
    char c;
    float f;
    double lf;

    scanf("%d %ld %c %f %lf", &d, &ld, &c, &f, &lf);

    printf("%d \n", d);
    printf("%ld \n", ld);
    printf("%c \n", c);
    printf("%f \n", f);
    printf("%lf \n", lf);

    return 0;
}
