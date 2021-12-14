class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int reversed = 0;
        int power = 31;
        
        while (n != 0) {
            reversed += (n & 1) << power;
            n >>= 1;
            power--;
        }
        
        return reversed;
    }
};