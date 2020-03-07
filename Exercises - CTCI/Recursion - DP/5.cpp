int minProd (int a, int b){
    int bigger = a > b ? a:b;
    int smaller = a < b ? a:b;
    return minProdHelper(a,b);
}

int minProdHelper (int smaller, int bigger){
    if(smaller == 0) return 0;
    else if(smaller == 1) return bigger;

    int s = smaller>>1;
    int halfProd = minProd(s, bigger);

    if(smaller % 2 == 0){
        return halfProd + halfProd;
    } else {
        return halfProd + halfProd + bigger;
    }
}