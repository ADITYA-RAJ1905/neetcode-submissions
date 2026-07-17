class NumMatrix {
public:
    vector<vector<int>> nums;
    NumMatrix(vector<vector<int>>& matrix) {
        nums=matrix;
    }
    
    int sumRegion(int x, int y, int nx, int ny) {
        int sum=0;
        for(int i=x;i<=nx;i++){
            for(int j=y;j<=ny;j++){
                sum+=nums[i][j];
            }
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */