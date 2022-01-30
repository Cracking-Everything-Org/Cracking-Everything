class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        // UNION FIND
        vector<vector<string>> res;
        
        vector<int> parent(accounts.size(), 0); // lista de parents para mergear con Union find
        unordered_map<string, int> emails; // para saber a que parent id pertenece el email
        
        // recorremos los accounts y agrupamos los mails con el dueño
        // We make groups for the case that one e-mail has multiple accounts
        for (int i = 0; i < accounts.size(); i++) {
            // Initialize the parent vector
            parent[i] = i;
            for (int j = 1; j < accounts[i].size(); j++) {
                // If this e-mail has been found again then union-find in order to 
                // add under the same group the current e-mail and the already stored e-mail
                if (emails.find(accounts[i][j]) != emails.end()) {
                    int f1 = find(parent, i);
                    int f2 = find(parent, emails[accounts[i][j]]);
                    // Union
                    parent[f1] = f2;
                } else {
                    // If this e-mail has never seen before
                    emails[accounts[i][j]] = i; //account index
                }
            }
        }
        // We make a new map in order to store for every group the e-mails it contains
        unordered_map<int, vector<string>> mres;
        for (auto entry : emails) {
            int parentIndex = find(parent, entry.second);
            mres[parentIndex].push_back(entry.first);
        }
        
        // In the previous (mres) map we have our answer but we must give the proper structure
        // We add the name of the account (we retieve it from the initial vector since we have
        // the number of the group) and we sort the e-mails.
        for (auto it : mres) {
            sort(it.second.begin(), it.second.end()); // sort emails  //nlogn
            vector<string> tmp = { accounts[it.first][0] };
            for (auto i : it.second) tmp.push_back(i);
            res.push_back(tmp);
        }
        return res;
    }
    
    int find (vector<int>& parent, int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent, parent[i]);
    }
};