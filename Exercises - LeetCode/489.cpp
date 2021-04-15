class Solution {
public:
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    unordered_map<int, unordered_set<int>> cleaned; 
    
    void cleanRoom(Robot& robot) {
        clean(robot, 0, 0, 0);
    }
    
    void clean(Robot &robot, int x, int y, int dPos) {
        if (cleaned[x].count(y)) {
            return;
        }
        
        robot.clean();
        cleaned[x].insert(y);
        
        for (int i = 0; i < 4; i++) {
            if (robot.move()) {
                clean(robot, x + dx[dPos], y + dy[dPos], dPos);
                robot.turnRight(); // me doy vuelta
                robot.turnRight();
                robot.move(); // me muevo uno hacia atras de donde ya visité
                robot.turnRight(); // me doy vuelta nuevamente
                robot.turnRight();                
            }
            robot.turnRight();
            dPos = (dPos + 1) % 4;
        }
    }
};