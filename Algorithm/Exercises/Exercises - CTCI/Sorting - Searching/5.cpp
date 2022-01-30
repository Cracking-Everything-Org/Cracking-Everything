using namespace std;
#include <iostream> 
#include <string>
#include <vector>

int search(vector<string> strings, string str){
    if(strings==NULL || str==NULL || str=="") return -1;
    return search(strings, str, 0, strings.size()-1);
}

int search(vector<string> strings, string str, int low, int high){
    if(low>high) return -1;
    int mid = (low+high)>>1;
    if(strings[mid].empty()){
        int left = mid-1;
        int right = mid+1;
        while(true){
            if(left<low && right>high){
                return -1;
            }else if(right<=left && !strings[right].empty()){
                mid = right;
                break;
            }else if(left>=low && !strings[right].empty()){
                mid = left;
                break;
            }
            right++;
            left--;
        }
    }

    if(str.equals(strings[mid])) return mid;
    else if(strings[mid].compare(str) <0){
        search(strings, str, mid+1, high);
    } else search(strings, str, low, mid-1);
}