class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>res;
        function <void(int ,int ,vector<int>&)>bt=[&](int i,int total,vector<int>&plist){
            // index out of box and 
            
            if(total == target ){
                res.push_back(plist);
                return;
            }
            if(i >= candidates.size() || total > target){return;}
            plist.push_back(candidates[i]);
            
            bt(i+1,total+candidates[i],plist);
            while (i+1 < candidates.size() && candidates[i] == candidates[i+1] ){i++;}
            plist.pop_back();
            bt(i+1,total,plist);

        };
        vector<int>plist;
        bt(0,0,plist);
        return res;
    }
};