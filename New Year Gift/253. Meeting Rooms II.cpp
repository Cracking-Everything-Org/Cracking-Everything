class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));
        priority_queue<int, vector<int>, greater<int>> to_process;
        int min_rooms = 0;
        for (const auto& interval : intervals) {
            while (!empty(to_process) && to_process.top() <= interval[0]) {
                to_process.pop();
            }
            to_process.emplace(interval[1]);
            min_rooms = max(min_rooms, static_cast<int>(size(to_process)));
        }
        return min_rooms;
    }
};