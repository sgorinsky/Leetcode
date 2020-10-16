class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if (k == 0) return;
        
        int count = 0;
        for (int start = 0; count < nums.size(); ++start) {
            int curr = start;
            int prev = nums[start];
            do {
                int next = (curr + k) % nums.size();
                int temp = nums[next];
                nums[next] = prev, prev = temp, curr = next;
                count++;
            } while (start != curr);
        }
    }
};
