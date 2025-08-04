 vector<vector<int>>construct(int V,vector<vector<int>>& edges)
  {
    vector<vector<int>> adj(V);
    for(auto &edge: edges)
      {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
     
     }
      return adj;
    }
void find(vector<vector<int>> &adj,int u,vector<int> &visited,vector<int> &disc,vector<int>& low,int &time,int parent,vector<int> &isap)
    {
      visited[u]=1;
      disc[u]=low[u]=++time;
      int children=0;
      for(int v:adj[u])
      {
          if(!visited[v])
          {
              children++;
              find(adj,v,visited,disc,low,time,u,isap);
              low[u]=min(low[u],low[v]);
              
              if(parent!=-1 && low[v]>=disc[u])
              {
                  isap[u]=1;
              }
          }
          else if(v!=parent)
          {
              low[u]=min(low[u],disc[v]);
          }
      }
      if(parent==-1 && children>1)
      {
          isap[u]=1;
      }
      
    }
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj=construct(V,edges);
        vector <int>disc(V,0),low(V,0),visited(V,0),isap(V,0);
        int time=0;
        for(int u=0;u<V;u++)
        {
            if(!visited[u])
            {
                find(adj,u,visited,disc,low,time,-1,isap);
            }
        }
        vector<int>res;
        for(int u=0;u<V;u++)
        {
            if(isap[u])
            {
                res.push_back(u);
            }
        }
        return res.empty() ? vector<int>{-1} : res;
        
    }
