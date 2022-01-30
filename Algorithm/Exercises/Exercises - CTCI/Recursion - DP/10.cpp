using namespace std;
#include <vector>

enum Color { Black, Whire, Red, Green };

bool paintFill(vector<vector<Color>> screen, int r, int c, Color newColor){
    if(screen[r][c] == newColor) return false;
    return paintFill(screen, r, c, screen[r][c], newColor);
}

bool paintFill(vector<vector<Color>> screen, int r, int c, Color oldColor, Color newColor){
    if(r < 0 || c < 0 || r>= screen.size() || c>= screen[0].size()) return false;

    if(screen[r][c] == oldColor){
        screen[r][c] = newColor;
        screen[r-1][c] = newColor;
        screen[r+1][c] = newColor;
        screen[r][c-1] = newColor;
        screen[r][c+1] = newColor;
    }
    return true;
}
