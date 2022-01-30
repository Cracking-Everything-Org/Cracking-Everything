class RandomizedSet {
public:
    struct Node {
        int val;
        int pos;

        Node(int val, int pos) {
            val = val;
            pos = pos;
        }
    };

    // O(1) = hashmap, hashset o vector
    // para sacar el random vamos a necesitar una lista
    unordered_map<int,int> ht;
    vector<int> randomList;

    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (ht.find(val) != ht.end()) {
            return false;
        } else {
            randomList.push_back(val);
            ht[val] = randomList.size() - 1;
        }
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (ht.find(val) == ht.end()) {
            return false;
        }
        // como no podemos borrar en la mitad de la lista, swapeamos y borramos el ultimo
        int lastVal = randomList[randomList.size()-1];
        int newPos = ht[val];
        swap(randomList[ht[val]] ,randomList[randomList.size()-1]);
        ht[lastVal] = newPos;
        randomList.pop_back();
        ht.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int random = rand() % randomList.size();
        return random;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
