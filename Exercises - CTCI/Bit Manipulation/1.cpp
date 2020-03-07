int updateBits(int n, int m, int i, int j){
    if(i>j || i<0 || j>=32) return 0;

    int allOnes = ~0;
    int left = j<31 ? (allOnes << (j + 1)) : 0;
    int right = ((1<<i)-1);
    int mask = left | right;

    int n_cleared = n & mask;
    int m_shifted = m << i;
    return n_cleared | m_shifted;
}