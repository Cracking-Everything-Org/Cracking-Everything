using namespace std;
#include <vector>

vector<vector<int>> getSubsets(vector<int> set, int index){
    vector<vector<int>> allSubsets;
    if(set.size()==index){ //caso base, {}
        vector<int> emptySet;
        allSubsets.push_back(emptySet);
    } else {
        allSubsets = getSubsets(set, index+1);
        int item = set[index];
        vector<vector<int>> moreSubsets;
        for(vector<int> subset : allSubsets){
            vector<int> newSubset;
            newSubset.insert(newSubset.end(), subset.begin(), subset.end());
            newSubset.push_back(item);
            moreSubsets.push_back(newSubset);
        }
        allSubsets.insert(allSubsets.end(), moreSubsets.begin(), moreSubsets.end());
    }
    return allSubsets;
}