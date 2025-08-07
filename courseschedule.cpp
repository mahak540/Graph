vector<int> findOrder(int n, vector<vector<int>> prerequisites) {
        // code here
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        
        for(auto& pre: prerequisites)
        {
            int dest=pre[0],src=pre[1];
            adj[src].push_back(dest);
            indegree[dest]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>order;
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            order.push_back(curr);
            for(int it:adj[curr])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        if(order.size()==n)
        {
            return order;
        }
        return {};
    }
