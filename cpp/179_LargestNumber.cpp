class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (nums.empty()) 
            return "0";
        
        vector<string> num_strings;
        for (int n : nums)
            num_strings.push_back(to_string(n));
        
        sort(num_strings.begin(), num_strings.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });
        
        stringstream ss;
        for (string num_str : num_strings)
            ss << num_str;
        
        string result = ss.str();
        return result[0] == '0' ? "0" : result;
    }
};
