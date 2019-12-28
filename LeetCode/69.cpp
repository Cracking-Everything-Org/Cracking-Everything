class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        int mid;
        if(x<2) return x;
        while(low<high) {
            mid = (low + high)/2;
            if(x/mid >= mid) low = mid+1;
            else high = mid;
        }
        return high-1;
    }
};
