int findparent(vector<int>& parent,int x)
  {
      if(parent[x]==x)
      return x;
      
      return parent[x]=findparent(parent,parent[x]);
  }
  void unionsets(vector<int>& parent,int x,int y)
  {
      int px=findparent(parent,x);
      int py=findparent(parent,y);
      
      if(px!=py)
      {
          parent[px]=py;
      }
  }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>parent(V);
        for(int i=0;i<V;i++)
        {
            parent[i]=i;
        }
        for(auto& edge:edges)
        {
            unionsets(parent,edge[0],edge[1]);
        }
        for(int i=0;i<V;i++)
        {
            findparent(parent,i);
        }
        unordered_map<int,vector<int>>resmap;
        for(int i=0;i<V;i++)
    {
        resmap[parent[i]].push_back(i);
    }
    vector<vector<int>>res;
    for(auto& entry:resmap)
    {
        res.push_back(entry.second);
    }
    return res;
        
        
    }
