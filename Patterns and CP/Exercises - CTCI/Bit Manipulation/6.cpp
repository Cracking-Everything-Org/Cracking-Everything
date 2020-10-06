int bitSwapRequired(int a, int b){
    int count =0;
    int c = a^b; //xor
    while(c!=0){
        count += c+1;
        c>>=1;
    }
    return count;
}