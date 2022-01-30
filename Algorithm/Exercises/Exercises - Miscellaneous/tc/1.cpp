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
	    // Base case
        if (!(keyBegin < keyEnd)) {
			return;
		}

		// Define variables
        std::optional<std::pair<K,V>> additionalInterval;
        auto leftBound = m_map.lower_bound(keyBegin);
        auto rightBound = m_map.lower_bound(keyEnd);

		// Check for additional interval
        if (rightBound == m_map.end() || keyEnd < rightBound->first) {
            additionalInterval = std::pair(keyEnd, operator[]( keyEnd ));
        } else if (leftBound == m_map.end() || keyBegin < leftBound->first) {
            additionalInterval = std::pair(keyEnd, operator[]( keyBegin ));
		}

		// Erase interval
        if (leftBound != m_map.end()) {
            m_map.erase(leftBound, rightBound);
		}

		// Assign requested interval
        m_map.insert(std::pair(keyBegin, val));

		// Assign additional interval
        if (additionalInterval) {
            m_map.insert(additionalInterval.value());
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
}; 09/2020

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.