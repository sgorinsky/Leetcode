class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int left = 0;
        for (int i = 1; i < asteroids.size(); ++i) {
            if (asteroids[i] <= 0  && asteroids[left] >= 0) {
                if (abs(asteroids[i]) == abs(asteroids[left]) && asteroids[left] > 0) {
                    asteroids[i] = 0, asteroids[left] = 0;
                }
                while (left > 0 && abs(asteroids[i]) > abs(asteroids[left]) && asteroids[left] >= 0) 
                    asteroids[left--] = 0;
                if (asteroids[left] > 0) {
                    if (abs(asteroids[left]) == abs(asteroids[i])) 
                        asteroids[i] = 0, asteroids[left] = 0;
                    else if (abs(asteroids[left]) > abs(asteroids[i])) 
                        asteroids[i] = 0;
                    else asteroids[left] = 0;
                }
            } else {
                left = i;
            }
        }
        vector<int> results;
        for (int n : asteroids) {
            if (n != 0) results.push_back(n);
        }
        return results;
    }
};
