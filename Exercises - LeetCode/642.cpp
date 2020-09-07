class AutocompleteSystem {
private:

    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        string str;
        int count;
        TrieNode() {
            str = "";
            count = 0;
        }
    };

    struct comp {
        bool operator() (pair<string, int>& a, pair<string, int>& b) {
            return a.second < b.second || (a.second == b.second && a.first > b.first);
        }
    };

    TrieNode* root; //inicio del arbol
    TrieNode* current; //lo uso para no perder referencia
    string currentString = "";
    priority_queue<pair<string, int>, vector<pair<string, int>>, comp> hot;

    void insert(string& toInsertString, int times) {
        TrieNode* current = root;
        for (char character : toInsertString) {
            if (!current->children.count(character)) {
                current->children[character] = new TrieNode();
            }
            current = current->children[character];
        }
        current->count += times;
        current->str = toInsertString;
    }

    void dfs(TrieNode* temp) {
        if (temp->str != "") {
            hot.push({temp->str, temp->count});
        }
        for (auto& cp : temp->children) {
            dfs(cp.second);
        }
    }


public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        for (int i = 0; i < sentences.size(); i++) {
            insert(sentences[i], times[i]);
        }
        current = root;
    }

    vector<string> input(char c) {
        hot = priority_queue<pair<string, int>, vector<pair<string, int>>, comp>();

        if (c == '#') {
            insert(currentString, 1);
            currentString = "";
            current = root;
            return {};
        }

        currentString += c;
        if (current && current->children.count(c)) {
            current = current->children[c];
        } else {
            current = nullptr;
            return {};
        }

        dfs(current);

        vector<string> results;
        while(!hot.empty() && results.size() < 3) {
            results.push_back(hot.top().first);
            hot.pop();
        }
        return results;
    }
};
