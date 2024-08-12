class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,pair<int,int>>> pq;

        for( int i=0 ; i<points.size(); i++){

            double temp = sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1]);

            if( pq.size()<k ){
                pq.push({temp,{points[i][0],points[i][1]}});
            }else{
                if( temp< pq.top().first ){
                    pq.pop();
                    pq.push({temp,{points[i][0],points[i][1]}});
                }
            }
        }
        vector<vector<int>> ans;
        while( !pq.empty() ){
            vector<int> arr;
            auto [x,y]=pq.top().second;
            arr.push_back(x);
            arr.push_back(y);
            ans.push_back(arr);
            pq.pop();
        }

        return ans;        
    }
};