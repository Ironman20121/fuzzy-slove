class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>arr = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> res;
        function<void(string,int)>bt=[&](string curr,int i){
            //base case 
            if(curr.length() == digits.length()){
                res.push_back(curr);
                return;
            }
            // coming up with this is not easy 
            for(char c:arr[digits[i]-'0']){
                bt(curr+c,i+1);
            }
        };
        if (digits != "") {bt("",0);}
        return res;
        
    }
};