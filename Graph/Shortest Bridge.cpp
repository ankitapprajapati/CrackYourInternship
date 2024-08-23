#include <bits/stdc++.h>
class Solution {
    void dfs ( int i, int j,int& n, vector<vector<int>>& grid, vector<vector<int>>& visited, vector<vector<int>>& directions, queue<pair<int,int>>& q ){
        visited[i][j]=1;
        q.push({i,j});
        for( auto p:directions ){
            int newX = i+p[0];
            int newY = j+p[1];
            if( newX>=0 && newX<n && newY>=0 && newY<n && grid[newX][newY]==1 && visited[newX][newY]==0 ){
                dfs(newX,newY,n,grid,visited,directions,q);
            }
        }
    }

    int bfs (int& n, vector<vector<int>>& grid, vector<vector<int>>& visited, vector<vector<int>>& directions, queue<pair<int,int>>& q ){
        int count =0;
        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();

                for( auto pair:directions ){
                    int newX = x+pair[0];
                    int newY = y+pair[1];
                    if( newX>=0 && newX<n && newY>=0 && newY<n && visited[newX][newY]==0 ){
                        if(grid[newX][newY]==1) return count;
                        else{
                            visited[newX][newY]=1;
                            q.push({newX,newY});
                        }
                    }
                }
            }
            count++;
        }
        return -1;
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        
        vector<vector<int>> directions = {{0,-1},{0,1},{-1,0},{1,0}};

        int n = grid.size();
        vector<vector<int>> visited(n,vector<int>(n,0));
        queue<pair<int,int>> q;
        
        for ( int i=0; i<n; i++ ){
            for( int j=0; j<n ; j++ ){
                if(grid[i][j]){
                    dfs(i,j,n,grid,visited,directions,q);
                    return bfs(n,grid,visited,directions,q);
                }
            }
        }
        return -1;       
    }
};