class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> exec_time(n, 0);
		// we're using a pair [process_id, start_time]
        stack<pair<int, int>> processing;

        for (const auto& log : logs) {
            // tokenize the string
            std::stringstream sstream(log);
            string id; getline(sstream, id, ':');
            string op; getline(sstream, op, ':');
            string ts; getline(sstream, ts, ':');

            if (op == "start") {
                // add process to stack, convert strings to ints
                processing.push(make_pair(stoi(id), stoi(ts)));
            } else {
                // c++17 structured binding
                auto [process_id, start_time] = processing.top();
                processing.pop();

                // get the process time and set it
                int offset = stoi(ts) - start_time + 1;
                exec_time[process_id] += offset;

                // if stack is not empty, a process was on hold
                // we need to remove the time elapsed since before we resume
                if (!empty(processing)) {
                    exec_time[processing.top().first] -= offset;
                }
            }
        }
        return exec_time;
    }
};
