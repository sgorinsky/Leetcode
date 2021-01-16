class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto cmp = [](int a, int b) {
            return a > b;
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (int n : nums) {
            pq.push(n);
            while (pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return a > b;
        });
        return nums[k - 1];
    }
};
