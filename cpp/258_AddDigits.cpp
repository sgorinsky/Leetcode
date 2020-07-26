class Solution {
public:
    int addDigits(int num) {
        while (floor(num/10) != 0) {
            int temp = 0;
            while (num > 0) {
                temp += num%10;
                num = floor(num/10);
            }
            num = temp;
        }
        return num;
    }
};
