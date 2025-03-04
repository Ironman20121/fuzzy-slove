class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        vector<int>subset;
        function<void(vector<int>&,int )>bt=[&](auto &subset,int i){
            //falure base case and succues base case
            //handling out of bonce
            if(i>=nums.size()){
                for(auto &j:res){
                    if(j==subset){
                        return;
                    }
                }
                res.push_back(subset);
                return;
            }
            subset.push_back(nums[i]);
            bt(subset,i+1);
            subset.pop_back();
            bt(subset,i+1);
        };
        bt(subset,0);
        return res;
    }
};