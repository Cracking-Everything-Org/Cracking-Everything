class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length() || t.length() == 0) return "";
        int i, j = 0, a = 0, position, l = INT_MAX;
        map<string,int> map3;
        map<string,int> match;
        vector<string> element;
        for (i = 0; i != t.length(); i++) {
            element.push_back(t.substr(i,1));
        }
        for (i = 0; i != element.size(); i++) {
            if (map3.find(element[i]) == map3.end()) {
                map3.insert(pair<string,int>(element[i] ,count(element.begin(),element.end(),element[i])));
            }
        }
        i = 0;
        while (i != s.length()) {
            match[s.substr(i,1)]++;
            if (match[s.substr(i,1)] <= map3[s.substr(i,1)]) a++;
            while (a == t.length()) {
                if (i - j + 1 < l) {
                    l = i - j + 1;
                    position = j;
                }
                match[s.substr(j,1)]--;
                if (match[s.substr(j,1)] < map3[s.substr(j,1)]) a--;
                j++;
            }
            i++;
        }
        if (l == INT_MAX) return "";
        return s.substr(position,l);
    }
};
