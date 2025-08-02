void dfs(vector<vector<char>>& grid,int r,int c)
  {
       int row=grid.size();
        int col=grid[0].size();
        if(r<0 || c<0 || r>=row || c>=col || grid[r][c]!='1')
        {
            return ;
        }
        grid[r][c]='0';
        vector<int>rn={1, -1, 0, 0};
        vector<int>cn={0, 0, 1, -1};
        
        for(int i=0;i<4;i++)
        {
            int nr=r+rn[i];
            int nc=c+cn[i];
            
            dfs(grid,nr,nc);
        }
  }
    
    int numIslands(vector<vector<char>>& grid) {
         int row=grid.size();
        int col=grid[0].size();
        int cnt=0;
        
        for(int r=0;r<row;r++)
        {
            for(int c=0;c < col; c++)
            {
                if(grid[r][c]=='1')
                {
                    cnt++;
                    
                    dfs(grid,r,c);
                }
            }
        }
        return cnt;
    }
