using namespace std;
#include <iostream> 
#include <string>
#include <vector>

int sortedSearchNoSize(Listy list, int value){
    int index = 1;
    while (list.elementAt(index)!= -1 && list.elementAt(index)<value) index*=2;

    return binarySearch(list, value, index/2, index);
}

int binarySearch(Listy list, int value, int low, int high){
    int mid;
    while(low<high){
        mid = (high+low)>>1;
        if(list.elementAt(mid)<value){
            low = mid++;
        } else if(list.elementAt(high)>value){
            high = mid--;
        } else{
            return mid;
        }
    }
    return -1;
}