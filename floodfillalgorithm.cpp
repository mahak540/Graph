vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        
        if(image[sr][sc]==newColor)
        {
            return image;
        }
        vector<pair<int,int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
        
        queue<pair<int,int>>q;
        int old=image[sr][sc];
        q.push({sr,sc});
        image[sr][sc]=newColor;
        
        while(!q.empty())
        {
            pair<int,int>front=q.front();
            int x=front.first,y=front.second;
            q.pop();
            for(const pair<int,int> &direction:directions)
            {
                int nx=x+direction.first;
                int ny=y+direction.second;
                
                if(nx>=0 && nx<image.size() && ny>=0 && ny<image[0].size() && image[nx][ny]==old )
                {
                        image[nx][ny]=newColor;
                        q.push({nx,ny});
                }
            }
           
        }
         return image;
    }
