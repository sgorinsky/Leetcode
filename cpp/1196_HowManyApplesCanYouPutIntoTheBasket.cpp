public:
    int maxNumberOfApples(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](const int& a, const int& b) {
            return a < b;
        });
        
        int total = 5000, count = 0;
        for (int apple : arr) {
            if (total - apple < 0) {
                break;
            } else {
                total -= apple;
                ++count;
            }
        }
        return count;
    }
};
