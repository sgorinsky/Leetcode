class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        deque<string> q = {beginWord};
        int count = 0;
        
        bool visited[wordList.size()];
        memset(visited, false, wordList.size());
        
        while (!q.empty()) {
            int sz = q.size();
            count++;
            for (int _ = 0; _ < sz; ++_) {
                string curr = q.front();
                q.pop_front();
                
                if (curr == endWord) 
                    return count;
                
                for (int i = 0; i < wordList.size(); ++i) {
                    if (visited[i]) continue;
                    
                    string word = wordList[i];
                    if (compare_words(word, curr)) {
                        visited[i] = true;
                        q.push_back(word);
                    }
                }
            }
        }
        return 0;
    }
    
    bool compare_words(string a, string b) {
        int count = 0;
        for (int i = 0; i < a.length(); ++i) {
            if (a[i] != b[i])
                count++;
            if (count > 1) 
                return false;
        }
        return count == 1;
    }
};
