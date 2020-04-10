class Solution {
public:
   vector<string> restoreIpAddresses(string s) {
        vector<string> ips;
        string ip;
        restore(s, 0, 0, ip, ips);
        return ips;
    }
private:
    void restore(string s, int i, int dots, string ip, vector<string>& ips) {
        if (dots == 4) {
            if (i == s.size()) {
                ips.push_back(ip);
            }
        } else {
            if (!ip.empty()) {
                ip.push_back('.');
            }
            for (int j = i, n = 0; j < s.size(); j++) {
                n = n * 10 + (s[j] - '0');
                if (n > 255) {
                    break;
                }
                restore(s, j + 1, dots + 1, ip + to_string(n), ips);
                if (!n) {
                    break;
                }
            }
            if (!ip.empty()) {
                ip.pop_back();
            }
        }
    }
}; 
