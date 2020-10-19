class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        unordered_map<int, vector<int>> A_map, B_map;
        int N = A.size();
        for (int i = 0; i < N; ++i) {
            if (A_map.find(A[i]) == A_map.end()) A_map[A[i]] = {i};
            else A_map[A[i]].push_back(i);
            
            if (B_map.find(B[i]) == B_map.end()) B_map[B[i]] = {i};
            else B_map[B[i]].push_back(i);
        }
        
        unordered_set<int> visited;
        int count = INT_MAX;
        for (int num : A) {
            if (visited.find(num) == visited.end()&&
                B_map.find(num) != B_map.end() &&
                A_map[num].size() + B_map[num].size() >= N &&
                compareSortedArrays(A_map[num], B_map[num]) >= N) {
                if (A_map[num].size() == N || B_map[num].size() == N) return 0;

                vector<int> more, less;
                if (A_map[num].size() > B_map[num].size())  more = A, less = B;
                else more = B, less = A;
                
                int curr_count = 0;
                for (int i = 0; i < N; ++i) {
                    if (less[i] == num && less[i] != more[i]) curr_count++;
                }
                count = min(count, curr_count);
            }
            visited.insert(num);
        }
        return count == INT_MAX ? -1 : count;
    }
    
    int compareSortedArrays(vector<int>& a, vector<int>& b) {
        int count = 0, i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) ++i;
            else if (a[i] > b[j]) ++j;
            else  ++i, ++j, ++count;
        }
        return a.size() + b.size() - count;
    }
};
