
std::string reduceTheNumber(std::string number, int k) {
    if (number.length() <= k) {
        return number;
    }

    vector<int> subsetsSum;

    int i = 0;
    int currentSum = 0;
    while (i < number.size() / k) {
        currentSum = 0;
        int startWindow = i * k;
        int endWindow = startWindow + k;
        while (startWindow < endWindow) {
            currentSum += (number[startWindow] - 48);
            startWindow++;
        }
        subsetsSum.push_back(currentSum);
        i++;
    }
    currentSum = 0;
    int start = i * k;
    while (start < number.size()) {
        currentSum += (number[start] - 48);
        start++;
    }
    subsetsSum.push_back(currentSum);

    string result = "";
    for (int i = 0; i < subsetsSum.size(); i++) {
        int currentNum = subsetsSum[i];
        string currentResult = "";
        if (currentNum >= 10) {
            while (currentNum >= 10) {
                currentResult += '0'+ (currentNum % 10);
                currentNum /= 10;
            }
            currentResult += '0'+ currentNum;
            reverse(currentResult.begin(), currentResult.end());
            result += currentResult;
        } else {
            result += '0' + currentNum;
        }
    }

    return reduceTheNumber(result, k);
}
