class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> exclusiveTimes(n, 0);
		// we're using a pair [processId, startTime]
        stack<pair<int, int>> processing;

        for (const auto& log : logs) {                               // ITERAMOS
            stringstream sstream(log);                         // LEEMOS EL STRING      "{function_id}:{"start" | "end"}:{timestamp}"
            string id; 
            getline(sstream, id, ':');
            string operation; 
            getline(sstream, operation, ':');
            string timestamp; 
            getline(sstream, timestamp, ':');

            if (operation == "start") {                                // SI ES START
                // add process to stack, convert strings to ints
                processing.push(make_pair(stoi(id), stoi(timestamp)));
            } else {                                                   // SI ES END
                // c++17 structured binding
                auto [processId, startTime] = processing.top();
                processing.pop();

                // get the process time and set it
                int offset = stoi(timestamp) - startTime + 1;
                exclusiveTimes[processId] += offset;

                // si el stack no esta vacio significa que habia un proceso esperando
                // le restamos el offset
                if (!empty(processing)) {
                    exclusiveTimes[processing.top().first] -= offset;
                }
            }
        }
        return exclusiveTimes;
    }
};