class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>res;
        function<void(int,int ,vector<int>&)>bt = [&](int total,int i,auto &combi){
            if (total == n && combi.size()==k){
                res.push_back(combi);
                return;
            }
            
            if(total > n || combi.size()==k || i>9){
                return;
            }   
            combi.push_back(i);
            bt(total+i,i+1,combi);
            combi.pop_back();
            bt(total,i+1,combi);

        };
        vector<int>subset;
        bt(0,1,subset);
        return res;
        
    }
};