class Logger {
public:
    unordered_map<string, int> logs;
    /** Initialize your data structure here. */
    Logger() {
        logs = {};
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        int temp;
        temp = logs.find(message) != logs.end() ? logs[message] : timestamp-11;
        if (timestamp - temp >= 10) {
            logs[message] = timestamp; // last time printed
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
