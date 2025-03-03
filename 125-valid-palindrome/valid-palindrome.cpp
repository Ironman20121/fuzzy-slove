class Solution {
public:
    bool isPalindrome(string s) {
        //covert to string
        string new_s="";
        for(auto &c:s){
            if(isalnum(c)){
                new_s+=tolower(c);
            }
            // cout<<new_s<<endl;
        }
        int left=0,right = new_s.length() -1;
        while(left < right){
            if(new_s[left]!=new_s[right]){return false;}
            else{
                left++;
                right--;
            }
        }
        
        return true;
    }
};