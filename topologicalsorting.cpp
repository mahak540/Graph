 void topo(int V, vector<vector<int>>& adj,vector<bool>& visited,stack<int>& st)
  {
      visited[V]=true;
      for(int i:adj[V])
      {
          if(!visited[i])
          {
              if(!visited[i])
              topo(i,adj,visited,st);
          }
         
      }
       st.push(V);
  }
  vector<vector<int>>construct(int V,vector<vector<int>>& edges)
  {
      vector<vector<int>>adj(V);
      for(auto it:edges)
      {
          adj[it[0]].push_back(it[1]);
      }
      return adj;
  }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        stack<int>st;
        vector<bool> visited(V,false);
        vector<vector<int>>adj=construct(V,edges);
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            topo(i,adj,visited,st);
            
        }
    vector<int>ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
        
        
    }
