class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> ht;
        for (int i = 0; i < S.length(); i++) {
            if (ht.find(S[i]) != ht.end()) {
                ht[S[i]]++;
            } else ht[S[i]] = 1;
        }


        priority_queue<pair<int, char>> maxHeap;

        for (auto entry : ht) {
            maxHeap.push(make_pair(entry.second, entry.first));
        }

        string ans = "";

        while (!maxHeap.empty()) {
            pair<int, char> temp = maxHeap.top();
            maxHeap.pop();
            if (temp.second == ans[ans.length()-1]) {
                if (!maxHeap.empty()) {
                    pair<int, char> newTemp = maxHeap.top();
                    maxHeap.pop();
                    if (newTemp.first != temp.first) return "";
                    maxHeap.push(temp);
                    ans += newTemp.second;
                    newTemp.first-=1;
                    maxHeap.push(newTemp);
                } else {
                    return "";
                }
            } else {
                 ans += temp.second;
                 temp.first -= 1;
                 if (temp.first > 0) maxHeap.push(temp);
            }
        }
        return ans;
    }
};
