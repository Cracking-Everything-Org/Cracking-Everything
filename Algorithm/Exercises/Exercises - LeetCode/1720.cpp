class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int size = encoded.size() + 1;
        vector<int> decoded(size);
        
        decoded[0] = first;
        for (int i = 1; i < size; i++) {
            decoded[i] = decoded[i - 1] ^ encoded[i - 1];
        }
        
        return decoded;
    }
};