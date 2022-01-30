using namespace std;
#include <vector>
#include <unordered_set>

vector<Point> getPath(vector<vector<bool>> maze){
    if(!maze || maze.size == 0) return NULL;
    vector<Point> path;
    unordered_set<Point> visited;
    if(getPath(maze, maze.size-1, maze[0].size-1, path, visited)){
        return path;
    }
    return NULL;
}

bool getPath(vector<vector<bool>> maze, int row, int col, vector<Point> path, unordered_set<Point> visited){
    if(col < 0 || row < 0 || !maze[row][col]) return false;
    Point p = new Point(row, col);
    if(visited.find(p) != visited.end()) return false;
    bool atStart = row == 0 && col && 0;
    if(atStart || getPath(maze, row-1, col, path, visited) || getPath(maze, row, col-1, path, visited)){
        path.push_back(p);
        return true;
    }
    visited.insert(p);
    return false;
}