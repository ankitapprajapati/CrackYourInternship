class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int originalColor = image[sr][sc];
        
        if ( originalColor == color ){
            return image;
        }

        vector<vector<int>> directions = {{-1,0},{1,0},{0,1},{0,-1}} ;

        int m = image.size();
        int n = image[0].size();

        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc]=color;

        while( !q.empty() ){

            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for( auto el: directions ){

                int x = i+el[0];
                int y = j+el[1];

                if( x>=0 && y>=0 && x<m && y<n && image[x][y]==originalColor ){
                    q.push({x,y});
                    image[x][y]=color;
                }
            }
        } 
        return image;       
    }
};