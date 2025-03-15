class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size(),COLS = grid[0].size();
        if(ROWS==0)return 0;
        int islands = 0;
        int directions[4][2]  = {{1,0},{-1,0},{0,1},{0,-1}};
        function<int(int,int)> dfs = [&](int row,int col){
        if(min(row,col)<0 || row>=ROWS||col>=COLS || grid[row][col]==0){
            return 0;
        }
        grid[row][col] =0;
        int res =1;
        for(int i=0;i<4;i++){res += dfs(row+directions[i][0],col+directions[i][1]);}
        return res;
        };
        for(int r=0;r<ROWS;r++){
            for(int c =0;c<COLS;c++){
                if(grid[r][c]==1){islands = max(islands,dfs(r,c)); }
            }
        }
     return islands;   
    }
};