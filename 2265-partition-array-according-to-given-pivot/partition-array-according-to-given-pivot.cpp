class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
       int pivotless=0,pivoteq=0;
       for(int num:nums){
        if(num<pivot)pivotless++;
        if(num==pivot)pivoteq++;
       }
       vector<int>sol(nums.size());
       int less_index =0,equal_index =pivotless,greater_index=pivotless+pivoteq;
       for(int num:nums){
        if(num<pivot){sol[less_index++] = num;}
        else if(num==pivot){sol[equal_index++]=num;}
        else{sol[greater_index++]=num;}
       }
       return sol;
    }
};