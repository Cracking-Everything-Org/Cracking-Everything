class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int totalImportance = 0;
        unordered_map<int, Employee*> hm;
        
        for (auto emp : employees) {
            hm[emp->id] = emp;
        }
        
        dfs(id, hm, totalImportance);
        
        return totalImportance;
    }
    
    void dfs(int id, unordered_map<int, Employee*> hm, int& totalImportance) {
        totalImportance += hm[id]->importance;
        
        for (auto sub : hm[id]->subordinates) {
            dfs(sub, hm, totalImportance);
        }
    }
};

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