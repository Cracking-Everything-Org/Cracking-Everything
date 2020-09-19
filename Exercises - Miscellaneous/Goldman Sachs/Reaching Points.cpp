string canReach(int x1, int y1, int x2, int y2) {
    string isPosible = "No";
    queue<pair<int,int>> q;
    q.push(make_pair(x1, y1));
    while (!q.empty()) {
        pair<int,int> current = q.front();
        q.pop();
        if (current.first == x2 && current.second == y2) {
            return "Yes";
        }
        if (current.first + current.second <= x2 && current.second <= y2) {
            q.push(make_pair(current.first + current.second, current.second));
        }
        if (current.first <= x2 && current.first + current.second <= y2) {
            q.push(make_pair(current.first, current.first + current.second));
        }
    }
    return isPosible;
}
