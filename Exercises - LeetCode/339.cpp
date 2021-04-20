class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        int totalDepth = 0;
        getDepth(0, 1, nestedList, totalDepth);
        return totalDepth;
    }
    
    void getDepth(int pos, int level, vector<NestedInteger> nestedList, int& totalDepth) {
        if (pos == nestedList.size()) {
            return;
        }
        
        if (nestedList[pos].isInteger()) {
            totalDepth += (nestedList[pos].getInteger() * level);
        } else {
            getDepth(0, level + 1, nestedList[pos].getList(), totalDepth);
        }
        
        getDepth(pos + 1, level, nestedList, totalDepth);
    }
};