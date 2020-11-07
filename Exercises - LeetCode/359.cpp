class Logger {
    unordered_map<string, int> umap;

public:
    /** Initialize your data structure here. */
    Logger() { }

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (umap.count(message) == 0) {
            umap[message] = timestamp;
            return true;
        }

        if (umap[message] + 10 <= timestamp) {
            umap[message] = timestamp;
            return true;
        }

        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
