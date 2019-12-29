class Solution {
public:
    string reverseVowels(string s) {
        if(s.length()==0) return s;
        int first = 0;
        int second = s.length()-1;
        unordered_set<char> hs;
        hs.insert('a');
        hs.insert('e');
        hs.insert('i');
        hs.insert('o');
        hs.insert('u');
        hs.insert('A');
        hs.insert('E');
        hs.insert('I');
        hs.insert('O');
        hs.insert('U');
        while(first<second){
            if(hs.find(s[first]) != hs.end() && hs.find(s[second]) != hs.end()){
                swap(s[first], s[second]);
                first++;
                second--;
            } else {
                if(hs.find(s[first]) != hs.end()) second--;
                else first++;
            }
        }
        return s;
    }
};
