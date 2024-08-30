class DisjointSet {
    vector<int> size,parent;
public:
    DisjointSet( int n){
        size.resize(n+1,0);
        parent.resize(n+1);
        for( int i=0; i<=n; i++){
            parent[i]=i;
        }
    }

    int findParent( int child ){
        if( child==parent[child]) return child;
        return parent[child]=findParent(parent[child]); // path compration
    }

    void unionBySize( int u, int v ){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if( ulp_u == ulp_v ) return;

        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_u] += size[ulp_v];
        }

    }

};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=0; 
        int m=0;
        for( int i=0; i<stones.size(); i++){
            n = max(n,stones[i][0]);
            m = max(m,stones[i][1]);
        }

        DisjointSet ds( n+m+1 );
        unordered_map<int,int> stoneNode;
        for( auto it: stones ){
            int row = it[0];
            int col = it[1]+n+1;
            ds.unionBySize( row, col);
            stoneNode[row]=1;
            stoneNode[col]=1;
        }
        
        int count =0; 
        for( auto it: stoneNode ){
            if(ds.findParent(it.first) == it.first) count++;
        }
        return stones.size()-count;
    }
};