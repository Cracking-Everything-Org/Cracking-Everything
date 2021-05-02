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
        //basecheck!
		if(!(keyBegin < keyEnd))return;

		auto intervalbegin = keyBegin;
		auto intervalend = keyEnd;

		//get the range!
		auto int_begin = m_map.lower_bound(keyBegin);
		auto int_end = m_map.lower_bound(keyEnd);
		
		//cache for later use!
		auto startcache = std::prev(int_begin)->first;
		auto endcache = int_end->first;

		//delete existing
		m_map.erase(int_begin, int_end);
		
		//insert values
		typename std::map<K,V>::iterator itrbegin = m_map.find(startcache);
		typename std::map<K,V>::iterator itrend = m_map.find(endcache);
		
		while((itrbegin != itrend) || (intervalbegin < intervalend)){
			m_map.insert(std::pair<K,V>(intervalbegin, val));
			intervalbegin++;
			itrbegin++;
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