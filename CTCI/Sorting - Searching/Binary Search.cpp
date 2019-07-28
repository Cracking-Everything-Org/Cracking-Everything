using namespace std;
#include <iostream> 
#include <string>
#include <vector>

int binarySearch(vector<int> list, int x){
    int low = 0;
    int high = list.size()-1;
    int mid;

    while(low<=high){
        mid = (low+(high-low)>>1);
        if(list[mid] < x){
            low = mid++;
        }else if(list[mid] > x){
            high = mid--;
        }else{
            return mid;
        }
    }
    return -1;
}