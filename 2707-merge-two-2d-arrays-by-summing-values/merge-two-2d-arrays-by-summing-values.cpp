class Solution {
public:
     map<int,int>ans;
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {

        std::function<void(vector<vector<int>>&)> mapinsert = [&](vector<vector<int>>& nums){
            for(int i=0;i<nums.size();i++){
                if (ans.find(nums[i][0])!=ans.end()){
                    ans[nums[i][0]] = ans[nums[i][0]]+nums[i][1];
                }
                else{ ans[nums[i][0]] = nums[i][1];}
            }  
        }; 
        mapinsert(nums1);
        mapinsert(nums2);
        vector<vector<int>> sol;
        for(auto i:ans){
            sol.push_back(vector<int>{i.first,i.second});
        }
        return sol;
        
    }
};