 void dfs(vector<vector<int>>& adj,int c,vector<bool>& visited)
  {
      visited[c]=true;
      for(auto i:adj[c])
      {
          if(!visited[i])
          dfs(adj,i,visited);
      }
  }
  vector<vector<int>>construct(int V,vector<vector<int>>& edges,int c,int d)
  {
      vector<vector<int>>adj(V);
      for(auto edge:edges)
      {
          if((edge[0]==c && edge[1]==d)|| (edge[0]==d && edge[1]==c))
          continue;
          
          adj[edge[0]].push_back(edge[1]);
          adj[edge[1]].push_back(edge[0]);
      }
      return adj;
  }
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        vector<vector<int>>adj=construct(V,edges,c,d);
        vector<bool>visited(V,false);
        dfs(adj,c,visited);
        
        return !visited[d];
    }
