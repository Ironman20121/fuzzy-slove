class Solution {
public:
    // vector<vector<int>>ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
     std::function<void(int ,vector<int>&,int,vector<vector<int>>&)> dfs = [&](int i,vector<int>&curr,int total,auto& ans){
        //succ base case
        if(total==target){
            ans.push_back(curr);
            return;
        }
        //faliure base case
        if(i>=candidates.size() || total > target ){
            return;
        }
        curr.push_back(candidates[i]);
        dfs(i,curr,total+candidates[i],ans);
        curr.pop_back();
        dfs(i+1,curr,total,ans);

     };
     vector<int>curr;
     vector<vector<int>>ans;
     dfs(0,curr,0,ans);

     return ans;
        
    }



};