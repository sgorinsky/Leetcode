class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> stack;
        // cout << "k: " << k << endl;
        for (int i = 0; i < nums.size(); ++i) {
            // cout << (nums.size() - i) << " " << (stack.size() > k ? 0 : k - stack.size()) << " " << stack.size() << ",  ";
            while (!stack.empty() && 
                   stack.back() > nums[i] && 
                   nums.size() - i > (stack.size() > k ? 0 : k - stack.size()))  // bug with negative int value processed from binary when k < stack.size()
                stack.pop_back();
            
            stack.push_back(nums[i]);
        }
        cout << endl;
        while (stack.size() > k)
            stack.pop_back();
        
        return stack;
    }
    
//     void print(vector<int>& arr) {
//         for (int n : arr)
//             cout << n << " ";
        
//         cout << endl;
//     }
};

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int N = nums.size();
        vector<int> stack;
        int i = 0;
        while (i < N) {
            int n = nums[i++];
            if (!stack.empty() && n < stack.back() && i < N - (k - stack.size()) + 1) {
                while (!stack.empty() && stack.size() + (N - i) >= k && stack.back() > n) stack.pop_back();
            }
            stack.push_back(n);
        }
        while (stack.size() > k) stack.pop_back();
        return stack;
    }
};
