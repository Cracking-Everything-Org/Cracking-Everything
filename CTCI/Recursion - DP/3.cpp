using namespace std;
#include <vector>

int magicFast(vector<int> list){
    return magicFast(list, 0, list.size()-1);
}

int magicFast(vector<int> list, int min, int max){
    if(max < min) return -1;
    int mid = (min+max)>>1;
    if(list[mid]==mid){
        return mid;
    }
    else if(list[mid]>mid){
        return magicFast(list, min, mid-1);
    }
    else {
        return magicFast(list, mid+1, max);
    }
}