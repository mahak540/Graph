class Solution {
  public:
  vector<vector<vector<int>>>construct(int V, vector<vector<int>>& edges)
  {
      vector<vector<vector<int>>>adj(V);
      for(auto edge:edges)
      {
          int u=edge[0],v=edge[1],w=edge[2];
          adj[u].push_back({v,w});
          adj[v].push_back({u,w});
      }
      return adj;
  }
  int shortestpath(int V,vector<vector<vector<int>>>& adj,int src,int dest)
  {
      vector<int>dist(V,INT_MAX);
      dist[src]=0;
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
      pq.push({0,src});
      
      while(!pq.empty())
      {
          pair<int,int>top=pq.top();
          pq.pop();
          int d=top.first,u=top.second;
          
          if(d>dist[u])
          continue;
          
          for(auto& neighbor:adj[u])
          {
              int v=neighbor[0];
              int w=neighbor[1];
              if((u==src && v==dest ) || (u==dest && v==src))
              continue;
              if(dist[v]>dist[u]+w)
              {
                  dist[v]=dist[u]+w;
                  pq.push({dist[v],v});
              }
              
          }
      }
      return dist[dest];
      
  }
    int findMinCycle(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<vector<int>>>adj=construct(V,edges);
        int mincycle=INT_MAX;
        
        for(const auto& edge:edges)
        {
            int u=edge[0],v=edge[1],w=edge[2];
            int dist=shortestpath(V,adj,u,v);
            if(dist!=INT_MAX)
            {
                mincycle=min(mincycle,dist+w);
            }
        }
        return mincycle;
    }
};
