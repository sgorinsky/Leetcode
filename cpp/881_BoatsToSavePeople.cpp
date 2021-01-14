class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boats = 0;
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1;
        while (i <= j) {
            while (i < j && people[i] + people[j--] > limit) boats++;
            boats++, i++;
        }
        return boats;
    }
};
