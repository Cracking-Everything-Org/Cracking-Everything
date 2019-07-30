using namespace std;
#include <iostream> 
#include <string>
#include <vector>

int search(vector<int> list, int target){
    return search(list, 0, list.size()-1, target);
}

int search(vector<int> list, int left, int right, int target){
    if(right<left) return -1;
    int middle = (left+right)>>1;
    if(list[middle]==target) return middle;
    if(list[left]<list[middle]){
        if(list[left]< target && target < list[middle]){
            search(list,left,middle-1,target);
        }else{
            search(list,middle+1,right,target);
        }
    }else if(list[middle]<list[right]){
        if(list[middle]<target && target<list[right]){
            search(list, middle+1, right, target);
        }else{
            search(list, left, middle-1, target);
        }
    }
    int location = -1;
    if(list[left]==list[middle]){
        location = search(list, middle+1, right, target);
    }
    if(location == -1 && list[middle] == list[right]){
        location = search(list, 0, middle-1, target);
    }
    return location;
}