using namespace std;
#include <iostream> 
#include <string>
#include <vector>

void mergeSort(vector<int> list){
    vector<int> helper;
    mergeSort(list, helper, 0, list.size()-1);
}

void mergeSort(vector<int> list, vector<int> helper, int low, int high){
    if(low<high){
        int middle = (low+(high-low)>>1);
        mergeSort(list, helper, low, middle);
        mergeSort(list, helper, middle+1, high);
        merge(list, helper, low, middle, high);
    }
}

void merge(vector<int> list, vector<int> helper, int low, int middle, int high){
    for(int i=low; i<=high; i++){
        helper[i] = list[i];
    }

    int helperLeft = low;
    int helperRight = middle+1;
    int current = low;

    while(helperLeft <= middle && helperRight <= high){
        if(helper[helperLeft] < helper[helperRight]){
            list[current] = helper[helperLeft];
            helperLeft++;
        } else {
            list[current] = helper[helperRight];
            helperRight++;
        }
        current++;
    }

    int remaining = middle - helperLeft;
    for(int i = 0; i<remaining; i++){
        list[current+i] = helper[helperLeft+i];
    }
}