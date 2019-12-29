class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> umap;
        for (auto c : ransomNote)
            if (umap.find(c) == umap.end())
                umap.insert({c, 1});
            else
                umap[c]++;
        for (auto c : magazine){
            if (umap.find(c) == umap.end())
                continue;
            else{
                umap[c]--;
                if (umap[c] == 0)
                    umap.erase(c);
            }
        }
        return umap.empty();
    }
};
