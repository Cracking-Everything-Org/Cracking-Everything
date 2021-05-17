/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int importance = 0;
        unordered_map<int, int> pos;
        unordered_set<int> visited;
        int posFound = -1;
        
        for (int i = 0; i < employees.size(); i++) {
            pos[employees[i]->id] = i;
            if (id == employees[i]->id) posFound = i;
        }
        
        if (posFound == -1) {
            return -1;
        }
        
        queue<Employee*> q;
        q.push(employees[posFound]);
        while (!q.empty()) {
            Employee* current = q.front();
            q.pop();
            if (visited.find(current->id) == visited.end()) {
                visited.insert(current->id);
                importance += current->importance;
                for (int i = 0; i < current->subordinates.size(); i++) {
                    q.push(employees[pos[current->subordinates[i]]]);
                }
            }
        }
        
        return importance;
    }
};