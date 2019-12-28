class Solution {
public:

    bool binarySearch(int number, int min, int max){
        if (min>max) return false;
        int mid = (max+min)/2;
        if (pow(2, mid) == number) return true;
        else if (pow(2, mid) > number){
            return binarySearch(number, min, mid-1);
        } else {
            return binarySearch(number, mid+1, max);
        }
    }

    bool isPowerOfTwo(int n) {
        return binarySearch(n,0,n);
    }
};
