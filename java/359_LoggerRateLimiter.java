class Logger {
    HashMap<String, Integer> logs;
    /** Initialize your data structure here. */
    public Logger() {
        logs = new HashMap<String, Integer>();
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    public boolean shouldPrintMessage(int timestamp, String message) {
        int temp = logs.get(message) == null ? timestamp - 11 : logs.get(message);
        if (timestamp - temp >= 10)  {
            logs.put(message, timestamp);
            return true;
        }
        return false;
    }
}

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * boolean param_1 = obj.shouldPrintMessage(timestamp,message);
 */
