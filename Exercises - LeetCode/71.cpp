class Solution {
public:
    string simplifyPath(string path) {

        string ans;
        if (!path.length()) return ans;
        stack<string> pushStk;

        string current = "";
        for (int i = 0; i < path.length(); i++) {
            if (path[i] == '/') {
                if (current.size() > 0) {
                    pushStk.push(current);
                    current = "";
                }
            } else {
                current += path[i];
            }
        }

        if (current.length()) pushStk.push(current);

        int toRemove = 0;

        stack<string> popStk;

        while (!pushStk.empty()) {
            if (pushStk.top() == "..") {
                toRemove++;
            } else if (pushStk.top() != ".") {
                if (toRemove > 0) {
                    toRemove--;
                } else {
                    popStk.push(pushStk.top());
                }
            }
            pushStk.pop();
        }

        while (!popStk.empty()) {
            ans += '/' + popStk.top();
            popStk.pop();
        }

        return ans.length() == 0 ? "/" : ans;
    }
};
