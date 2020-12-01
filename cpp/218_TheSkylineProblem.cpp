class compare{
public:
    bool operator()(const vector<int> &lhs, const vector<int> &rhs) const {
        if(lhs[2] == rhs[2]) return lhs[1] < rhs[1];
        else return lhs[2] < rhs[2];
    }
};

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> skyline;
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;
        int n = (int)buildings.size(), i = 0;
        
        while(i < n){
            vector<int> b = buildings[i];
            // check if the left vertex (b[0], b[2]) can be a candidate of the skyline. Yes if:  
            // (1) skyline for coordinates < b[0] have been finalized. 
            //     So you can now consider b as the "first" building in the subsequent skyline
            // (2) (b[0], b[2]) is above the tallest building in queue, 
            //     and b's left side is cutting through the tallest building in priority queue 
            // however, watch for edge cases for consecutive rectangles with the same left side x
            // we need to merge the overlapping left sides of them. 
            // e.g. [1, 2, 1], [1, 2, 2], [1, 2, 3] => [1, 3], [2, 0]  
            if(pq.empty() || b[0] <= pq.top()[1]){
                if(pq.empty() || !skyline.size()) skyline.push_back({b[0], b[2]});
                else if(pq.top()[2] < b[2]) {
                    if(b[0] == skyline.back()[0]) skyline.back()[1]= b[2]; // edge case 
                    else skyline.push_back({b[0], b[2]});
                }
                pq.push(b); // add right side to queue (for convenience, just add b), because right side contribution to skyline is depending on other rectangles (those in queue)
                i++; // continue to next building
            }

            // check if right side of rectangles in queue contributes to the skyline
            // if left side of building b is not cutting through the tallest building T(pq.top()) in queue
            // then the right side of T should make the next turn in skyline by cutting through
            // another rectangle in queue or touch the ground(if you consider ground as unlimited length and height 0, so T always has something to cut through)
            while (!pq.empty() && (b[0] > pq.top()[1] || i == n)) {
                int x = pq.top()[1];
                // pop buildings in queue that building T doesn't cut through. 
                // Those buildings are shorter than T, and their right sides are left to T's right side, 
                // so their right sides don't contribute to the skyline.
                while(!pq.empty() && pq.top()[1] <= x) pq.pop(); 
                // the top of the queue now should have the tallest building that T cuts through
                int y = pq.empty() ? 0 : pq.top()[2];
                // so we find the next point in skyline
                skyline.push_back({x, y});
                // we continue this step until b starts cutting the tallest building in queue 
                // (when queue becomes empty, we can consider b cuts through ground, so while loops stops too)
            }
        }
        
        return skyline; 
    }
};
