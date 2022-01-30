/* map upper_bound is used to get the first larger timestamp than the input. Then prior one is the answer we want. if no prior one, return "" */

class TimeMap {
private:
    unordered_map<string,map<int, string>> mp;
    
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        if (!mp.count(key)) return "";
        
        auto& it = mp[key];
        auto m = it.upper_bound(timestamp);
        
        if (m == it.begin()) return "";
        else return (--m)->second; // el proxima al lowerbound es la respuesta
    }
};


/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */