class NumMatrix {
public:
    vector<vector<int>>arr;
    NumMatrix(vector<vector<int>>& matrix) {
        arr.resize(matrix.size(), vector<int>(matrix[0].size()));
        for(int row=0;row<matrix.size();row++){
            arr[row][0] = matrix[row][0];
            for(int col=1;col < matrix[row].size();col++){
                arr[row][col] = arr[row][col -1]+matrix[row][col];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        if (col1 !=0){
            for(int i=row1;i<=row2;i++){
                ans += arr[i][col2] - arr[i][col1-1];
            }

        }
        else{
            for(int i=row1;i<=row2;i++){
                ans += arr[i][col2] ;
            }
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */