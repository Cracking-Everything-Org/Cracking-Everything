class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image.size() <= 0 || newColor == image[sr][sc]) {
            return image;
        }
        int originalColor = image[sr][sc];
        queue<pair<int,int>> toProcess;
        toProcess.push(make_pair(sr,sc));
        while (!toProcess.empty()) {
            pair<int,int> current = toProcess.front();
            toProcess.pop();
            if (image[current.first][current.second] == originalColor) {
                image[current.first][current.second] = newColor;
                if (current.first - 1 >= 0) {
                toProcess.push(make_pair(current.first - 1, current.second));
                }
                if (current.first + 1 < image.size()) {
                    toProcess.push(make_pair(current.first + 1, current.second));
                }
                if (current.second - 1 >= 0) {
                    toProcess.push(make_pair(current.first, current.second - 1));
                }
                if (current.second + 1 < image[0].size()) {
                    toProcess.push(make_pair(current.first, current.second + 1));
                }
            }
        }
        return image;
    }
};
