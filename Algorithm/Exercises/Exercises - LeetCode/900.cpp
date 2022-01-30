class RLEIterator {
public:
    vector<int> list;
    int index;
    
    RLEIterator(vector<int>& encoding) {
        list = encoding;
        index = 0;
    }
    
    int next(int n) {
        if (index == list.size()) return -1;
        
        if (n <= list[index]) {
            list[index] -= n;
            return list[index + 1];
        }
        
        n -= list[index];
        index += 2;
        
        return next(n);
    }
};


/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */