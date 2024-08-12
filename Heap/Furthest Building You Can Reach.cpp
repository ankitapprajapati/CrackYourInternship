class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq; 

        int i = 0;
        for (i = 1; i < heights.size(); i++) {
            int diff = heights[i] - heights[i-1];

            if (diff > 0) {
                pq.push(diff);
                bricks -= diff;

                if (bricks < 0 && ladders > 0) {
                    bricks += pq.top(); 
                    pq.pop();
                    ladders--;
                }
                else if (bricks < 0) {
                    break;
                }
            }
        }

        return i-1;
    }
};
