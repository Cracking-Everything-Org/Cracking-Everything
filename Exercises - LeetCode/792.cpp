class Solution {
public:
    //approach is to mantain a map in which we store the count of each string in "words", so that we can avoid traversing duplicates in "words" again and again. 
    //We just need to add the count of that string in word if found to our ans.
    //this is efficient only if there are duplicates present in the "words"    
    
    int numMatchingSubseq(string s, vector<string>& words) { // O(words.size()*size of string)
        int count = 0;
        int n = s.size();
        
        //storing the words in a map
        unordered_map<string, int> hm;
        for (int i = 0; i < words.size(); i++) {
            hm[words[i]]++;
        }
        
        //finding whether is word is sequence or not
        for (auto entry : hm) {
            int start1 = 0, start2 = 0;
            string current = entry.first;
            //comparing letter by letter 
            while (start1 < current.size() && start2 < n) {
                if (current[start1] == s[start2]) {
                    start1++;
                    start2++;
                } else{
                    start2++;
                }
            }
            //if start1 ie. pointer of word reaches end that ensures that entry is present and we add entry count to our ans
            if (start1 == current.size()) {
                count += entry.second;
            }
        }
        return count;   
    }
};