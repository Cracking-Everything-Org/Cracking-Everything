class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==0) return 0;
        if(stones.size()==1) return stones[0];
        sort(stones.begin(),stones.end());
        int zMax = stones[stones.size()-1];
        int yMax = stones[stones.size()-2];
        stones.pop_back();
        stones.pop_back();
        stones.push_back(zMax-yMax);
        return lastStoneWeight(stones);
    }
};
