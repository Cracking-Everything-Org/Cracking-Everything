class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        deque<char> que;
        string result = "";
        for (int i = 0; i < n; ++i) {
            while (!que.empty() && que.back() > num[i]) {
                que.pop_back();
            }
            que.push_back(num[i]);
            if (i >= k) {
                result = result + (que.front());
                que.pop_front();
            }
        }
        int begin = 0;
        while (begin < result.length() && result[begin] == '0') {
            begin ++;
        }
        if (begin == result.length()) return "0";
        else return result.substr(begin);
    }
};
