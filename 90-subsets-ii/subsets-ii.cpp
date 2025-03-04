class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        vector<int>subset;
        function<void(vector<int>&,int )>bt=[&](auto &subset,int i){
            if(i>=nums.size()){
                // for(auto &j:res){
                //     if(j==subset){
                //         return;
                //     }
                // }
                res.push_back(subset);
                return;
            }
            subset.push_back(nums[i]);
            bt(subset,i+1);
            subset.pop_back();
            while(i+1<nums.size()&& nums[i]==nums[i+1]){i++;}
            bt(subset,i+1);
        };
        bt(subset,0);
        return res;
    }
};