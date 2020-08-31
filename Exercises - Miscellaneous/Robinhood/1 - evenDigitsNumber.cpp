int evenDigitsNumber(std::vector<int> a) {
    if (a.size() <= 0) {
        return 0;
    }
    int evenNumbers = 0;
    for (int i = 0; i < a.size(); i++) {
        int current = a[i];
        int numberSize = 0;
        while (current) {
            current /= 10;
            numberSize++;
        }
        if (numberSize % 2 == 0) {
            evenNumbers++;
        }
    }
    return evenNumbers;
}
