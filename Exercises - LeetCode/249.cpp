class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        // HAGO UN MAPA Y GUARDO EL STRING SEGUN EL HASH DEL SHIFTEO
        unordered_map<string, vector<string> > groupedStrings;
        for (string  s : strings)
            groupedStrings[encodeShift(s)].push_back(s);
        vector<vector<string> > groups;
        for (auto entry : groupedStrings) {
            vector<string> group = entry.second;
            sort(group.begin(), group.end());
            groups.push_back(group);
        }
        return groups;
    }

    string encodeShift(string& s) {
        string t;
        int n = s.length();
        for (int i = 1; i < n; i++) {
            int diff = s[i] - s[i - 1];
            // caso ab, ba , al hacer a - b me da negativo, por eso le sumo 26
            if (diff < 0) diff += 26;
            t += 'a' + diff + ',';
        }
        return t;
    }
};
