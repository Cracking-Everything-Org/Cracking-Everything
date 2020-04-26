class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        vector<int>bucket(10);
        for(int i = 0; i < s.size(); i++)
            bucket[s[i] - '0'] = i;
        for(int i = 0; i < s.size(); i++)
            for(int  j = 9; j > s[i] - '0'; j--)
                if(bucket[j] > i){
                    swap(s[i], s[bucket[j]]);
                    return stoi(s);
                }
        return num;
    }
};
