class Solution {
public:

    void fill(vector<vector<int>>&  image, int sr, int sc, int color, int newColor){
        if(   sr < 0
           || sr >= image.size()
           || sc < 0
           || sc >= image[sr].size()
           || image[sr][sc] != color) return;

        image[sr][sc] = newColor;

        fill(image, sr+1, sc, color, newColor);
        fill(image, sr-1, sc, color, newColor);
        fill(image, sr, sc+1, color, newColor);
        fill(image, sr, sc-1, color, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor) return image;
        fill(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
};
