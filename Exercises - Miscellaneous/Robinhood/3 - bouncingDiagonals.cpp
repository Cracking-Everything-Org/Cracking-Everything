std::vector<int> bouncingDiagonals(std::vector<std::vector<int>> matrix) {
    vector<int> result;
    bool up = true;
    int current = 0;
    for (int i = 0; i < matrix.size(); i++) {
        current = 0;
        int col = 0;
        while (col < matrix[0].size()) {
            current += matrix[i][col];
            col++;
            if (up && i > 0) {
                i--;
            } else if (up && i == 0) {
                up = false;
                i++;
            } else if (!up && i < matrix[0].size()) {
                i++;
            } else if (!up) {
                up = true;
                i--;
            }
        }
        result.push_back(current);
    }
    return result;
}
