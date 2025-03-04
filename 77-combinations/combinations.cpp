class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        vector<int>subset;
        function<void(int ,vector<int>&)>bt = [&](int i, auto& subset){
            if(i>n) {
            if (subset.size()==k){
                res.push_back(subset);
            }
            return ;
            }
       
            subset.push_back(i);
            bt(i+1,subset);
            subset.pop_back();
            bt(i+1,subset);

        };
        bt(1,subset);
        return res;
        
    }
};