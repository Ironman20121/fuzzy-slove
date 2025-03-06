class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> countrack(n*n);

        for(int row=0;row<n;row++){
            for(int col = 0;col<n;col++){
                countrack[grid[row][col]-1]++;
            }
        }
        int twice_num=0,missing_num=0;
        for(int i=0;i<n*n;i++){
            if(countrack[i]==2){twice_num = i+1;}
            if(countrack[i]==0){missing_num=i+1;}
            
        }
        
       return {twice_num,missing_num};
    }
};