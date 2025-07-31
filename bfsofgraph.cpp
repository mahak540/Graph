  vector<int> bfs(vector<vector<int>> &adj) {
        int V=adj.size();
        int s=0;
        vector<int>res;
        queue<int>q;
        vector<bool>visited(V,false);
        visited[s]=true;
        
        q.push(s);
        
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            res.push_back(curr);
            
            for(int x:adj[curr])
            {
                if(!visited[x])
                {
                    visited[x]=true;
                    q.push(x);
                }
            }
        }
        return res;
        
    }
