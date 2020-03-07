using namespace std;
#include <vector>

int makeChange(int n, vector<int> denoms){
    vector<vector<int>> map;
    return makeChangeHelper(n, denoms, 0, map);
}

int makeChangeHelper(int n, vector<int> denoms, int index, vector<vector<int>> map){
    if(map[n][index]>0) return map[n][index]; 
    int coin = denoms[index];
    if(index == denoms.size() -1){
        int remaining = n%coin;
        return remaining == 0? 1 : 0;
    }
    int ways = 0;
    for(int amount =0; amount<= n; amount+=coin){
        makeChangeHelper(n-amount,denoms, index+1, map);
    }
    map[n][index]= ways;
    return ways;
}