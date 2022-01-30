class MyCalendar {
public:
    map<int, int> mp;
    
    MyCalendar() {
        
    }
    
    // upper_bound Returns an iterator pointing to the first element in the range [first,last) which compares greater than val.
    bool contains(int k) {
        auto it = mp.upper_bound(k);
        return it != mp.end() && it->second <= k;
    }
    
    bool book(int start, int end) {
        if (contains(start) || contains(end - 1) || mp.upper_bound(start) != mp.lower_bound(end))
            return false;
        
        mp[end] = start;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */