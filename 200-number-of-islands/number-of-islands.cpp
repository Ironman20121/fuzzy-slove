class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size();
        if (ROWS ==0)return 0;
        int COLS = grid[0].size();
        int islands=0;

        function<void(int ,int)> bfs = [&](int row,int col){
            int directions[4][2]  = {{1,0},{-1,0},{0,1},{0,-1}};
            deque<pair<int,int>> q ;
            q.push_back({row,col});
            grid[row][col]='0';

            while(!q.empty()){
                auto node = q.front(); 
                q.pop_front();
                int r = node.first;
                int c = node.second;
                for(int i=0;i<4;i++){
                    int nr = r + directions[i][0];
                    int nc = c + directions[i][1];
                    if(nr >=0 && nc >=0 && nr <grid.size() && nc <grid[0].size() &&grid[nr][nc]=='1' ){
                        q.push_back({nr,nc});
                        grid[nr][nc]='0';
                    }

                }   
            }
        };
        function<void(int ,int)>dfs = [&](int row,int col){
            if(min(row,col)<0 || row >= grid.size()|| col >= grid[0].size()|| grid[row][col]=='0'){
                return;
            }
            int directions[4][2]  = {{1,0},{-1,0},{0,1},{0,-1}};
            grid[row][col] = '0';
           for(int i=0;i<4;i++){
            dfs(row+directions[i][0],col+directions[i][1]);
           }

        };
        for(int r=0;r<ROWS;r++){
            for(int c=0;c<COLS;c++){
                if(grid[r][c]=='1'){
                    dfs(r,c);
                    islands++;
                }
            }
        }

        return islands;
        
    }
};