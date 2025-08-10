vector<vector<int>>construct(int V,vector<vector<int>>& edges)
  {
      vector<vector<int>>adj(V);
      for(auto it: edges)
      {
          adj[it[0]].push_back(it[1]);
           adj[it[1]].push_back(it[0]);
      }
      return adj;
  }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<int>res(V,-1);
        vector<vector<int>>adj=construct(V,edges);
        queue<int>q;
        
        for(int i=0;i<V;i++)
        {
            if(res[i]==-1)
            {
                res[i]=1;
                q.push(i);
                
                while(!q.empty())
                {
                    int u=q.front();
                    q.pop();
                    
                    for(auto& v:adj[u])
                    {
                        if(res[v]==-1)
                        {
                            res[v]=1-res[u];
                            q.push(v);
                        }
                        else if(res[v]==res[u])
                        {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
        
    }
