class Solution {
public:
    map<int,int> ht;

    int getSumSquare(int n){
        int count=0;
        string number = to_string(n);

        for(char a:number)
            count+=ht[a-'0'];

        return count;
    }

    bool isHappy(int n) {
        for(int i=0; i<10; i++){
            ht[i]=i*i;
        }

        int slow = n;
        int fast = n;

         while(slow!=1 && fast!=1){
            slow = getSumSquare(slow);
            fast = getSumSquare(getSumSquare(fast));
            if(slow == fast && slow!=1 && fast!=1) return false;
        }
        return true;
    }
};	
