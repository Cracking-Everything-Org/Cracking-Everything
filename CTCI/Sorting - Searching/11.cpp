using namespace std;
#include <iostream> 
#include <string>
#include <vector>

void sortValleyPeak(vector<int> list){
    sort(list);
    for(int i=1; i< list.size(); i+=2) swap(list[i-1], list[i]);
}