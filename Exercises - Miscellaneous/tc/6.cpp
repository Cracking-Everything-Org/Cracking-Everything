#include <map>
template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K,V> m_map;
  public:
	// constructor associates whole range of K with val
	interval_map(V const& val)
	: m_valBegin(val)
	{}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.

	void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
		// INSERT YOUR SOLUTION HERE
        if(!(keyBegin < keyEnd)) return;

        //inserting
        V valend;
        bool erase = true; //erasing condition

        auto start = m_map.lower_bound(keyBegin);

        auto delst = start;

        //to check if it exists and if it does then change it
        if(start != m_map.end() && start->first == keyBegin){
            valend = start->second;
            start->second = val;

            ++delst;
            if(delst == m_map.end()){
                erase = false;
            }
        }else{
            auto prev = start;
            --prev;
            valend = prev->second;
            if (prev->second != val){
                auto it = m_map.insert(start, std::make_pair(keyBegin, val)); 
                start = it;
                delst = ++it;   
            }
        }

        auto end = m_map.lower_bound(keyEnd); 
        auto delfs = end;
        if (delfs == delst)
            erase = false;
        if (end == m_map.end() || end->first != keyEnd){
            auto prev = end;
            --prev;
            if (prev != start){
                valend = prev->second;
            }
            if (valend != val) {
                auto it = m_map.insert(end, std::make_pair(keyEnd, valend)); 
                delfs = it;
                if ((++it) != m_map.end() && it->second == valend) 
                    m_map.erase(it);
            }
        }
        //remove elements
        if (erase && delst != m_map.end() && delfs != m_map.end() && delst->first < delfs->first){
            m_map.erase(delst, delfs); 
        }
	}

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}
}; 2018

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.