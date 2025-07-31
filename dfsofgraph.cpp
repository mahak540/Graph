void dfsrec(vector<vector<int>>& adj,vector<bool>& visited,int s,vector<int>& res)
  {
      visited[s]=true;
      res.push_back(s);
      for(int i:adj[s])
      if(visited[i]==false)
      dfsrec(adj,visited,i,res);
  }
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<bool>visited(adj.size(),false);
        vector<int>res;
        dfsrec(adj,visited,0,res);
        return res;
    }
    void addedge(vector<vector<int>>& adj,int s,int t)
    {
        adj[s].push_back(t);
        adj[t].push_back(s);
    }
};
