class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> result;
        
        unordered_map<string, int> domainCount;
        for (auto cpdomain : cpdomains) {
            int spacePosition = cpdomain.find(" ");
            int number = stoi(cpdomain.substr(0, spacePosition));
            string domain = cpdomain.substr(spacePosition + 1);
            for (int i = 0; i < domain.size(); ++i) {
                if (domain[i] == '.') {
                    domainCount[domain.substr(i + 1)] += number;
                }
            }
            domainCount[domain] += number;
        }
        for (auto entry : domainCount)
            result.push_back(to_string(entry.second) + " " + entry.first);
        
        return result;
    }
};