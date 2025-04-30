class NumArray {
public:
   vector<int>calarr;
    NumArray(vector<int>& nums) {
        int total =0;
        for(auto i:nums){
            total+=i;
            calarr.push_back(total);
        }
    }
    
    int sumRange(int left, int right) {
        if (left ==0){
            return calarr[right];
        }
        else{
            return calarr[right] - calarr[left -1];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */