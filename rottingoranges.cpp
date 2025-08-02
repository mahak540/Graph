bool issafe(int i,int j,int n,int m)
  {
      return (i>=0 && i<n && j>=0 && j<m);
  }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
      int m=grid[0].size();
      vector<vector<int>> directions={{1,0},{0,1},{-1,0},{0,-1}};
        int elapsedtime=0;
        queue<vector<int>>q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        while(!q.empty())
        {
            elapsedtime++;
            int len=q.size();
            while(len--)
            {
                vector<int>curr=q.front();
                q.pop();
                int i=curr[0];
                int j=curr[1];
                
                for(auto it:directions)
                {
                    int x=i+it[0];
                    int y=j+it[1];
                    
                    if(issafe(x,y,n,m) && grid[x][y]==1)
                    {
                        grid[x][y]=2;
                        q.push({x,y});
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return max(0,elapsedtime-1);
        
    }
