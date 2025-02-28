class Solution {
public:
    string removeStars(string s) {
        //LIFO
        vector<char>char_stack ;
        for(int i=0;i<s.length();i++){
            if(s[i]!='*'){char_stack.push_back(s[i]);}
            else{
                if(char_stack.empty()){return "";}
                char_stack.pop_back();
            }
        }
        string new_s = "";
        for(auto&i :char_stack){
            new_s+=i;
        }
        return new_s;
    }
};