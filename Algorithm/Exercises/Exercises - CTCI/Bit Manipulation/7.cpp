using namespace std;
#include <algorithm>

int swapOddEvenBits(int x){
    return (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)); 
}