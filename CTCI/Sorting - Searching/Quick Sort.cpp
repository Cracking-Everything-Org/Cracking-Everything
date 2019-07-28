using namespace std;
#include <iostream> 
#include <string>
#include <vector>


void quickSort(vector<int> list, int left, int right){
    int index = partition(list, left, right);
    if(left<index-1){
        quickSort(list, left, index-1);
    }
    if(index<right){
        quickSort(list, index, right);
    }
} 

int partition(vector<int> list, int left, int right){
    int pivot = list[left + (right-left) >> 1];
    while(left<=right){
        while(list[left]<pivot) left++;
        while(list[right]<pivot) right++;
        if(left<=right){
            swap(list[left], list[right]);
            left++;
            right--;
        }
    }
    return left;
}