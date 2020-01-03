class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1;
        int high = num;
        int mid;
        while(low < high){
            mid = low+(high-low)/2;
            if(pow(mid,2) == num) return true;
            else if(pow(mid,2) > num) {
                high = mid;
            } else {
                low = mid+1;
            }
        }
        return pow(low,2) == num ? true : false;
    }
};
