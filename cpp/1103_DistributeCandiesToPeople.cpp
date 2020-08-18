class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people, 0);
        
        int i = 1;
        while (candies > 0) {
            res[(i-1) % num_people] += candies >= i ? i: candies;
            candies -= i++;
        }
        return res;
    }
};
