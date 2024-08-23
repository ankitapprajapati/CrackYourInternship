class Solution {
    void bfs( int index , vector<vector<int>>& adjList, vector<int>& visited ){
        queue<int> q;
        q.push(index);
        visited[index]=1;

        while( !q.empty() ){
            int temp = q.front();
            q.pop();

            for( auto num:adjList[temp]){
                if(visited[num]==0){
                    visited[num]=1;
                    q.push(num);
                }
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if( connections.size()<n-1 ) return -1;

        vector<int> visited(n,0);
        vector<vector<int>> adjList(n);

        for( auto pair : connections ){
            adjList[pair[0]].push_back(pair[1]);
            adjList[pair[1]].push_back(pair[0]);
        }

        int count = 0; 
        for( int i=0 ; i<n; i++ ){
            if(visited[i]==0 ){
                count++;
                bfs(i,adjList,visited);
            }
        }

        return count-1; 
    }
};