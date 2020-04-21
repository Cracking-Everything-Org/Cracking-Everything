class Solution {
public:
    unordered_map<char,char> mapping = {{'0','0'}, {'1','1'}, {'6','9'}, {'8','8'}, {'9','6'}};

    vector<string> findStrobogrammatic(int n) {
        // voy generando desde el principio y el fin hasta la mitad
        vector<string> numbers;
        if (n < 1) return numbers;
        vector<char> current(n);
        generateSNumbers(0, n-1, current, numbers);
        return numbers;
    }

    void generateSNumbers(int low, int high, vector<char> current, vector<string>& numbers) {
        if (low > high) {
            // me fijo de que no empiece con 0 o que el tamaño sea 1
            if (current.size() == 1 || current[0] != '0') {
                // podemos usar el constructor del String
                string toPush(current.begin(), current.end());
                numbers.push_back(toPush);
            }
            return ;
        }
        // generate all
        for (auto pair : mapping) {
            // si solo me queda 1 posicion
            if (low == high && pair.first != pair.second) {
                 continue;
            }
            current[low] = pair.first;
            current[high] = pair.second;
            generateSNumbers(low + 1, high - 1, current, numbers);
        }
    }
};
