// class Solution {
// public:
//     string decodeString(string s) {
//         vector<char>myStack;
//         string new_str ="";
//         string num_str="";
//         int number =0;
//         map<char,int>numbermap ;
//         for(int i=1;i<=9;i++){ 
//             char ch = i+'0';
//             numbermap[ch] = i;
//         }
//         for(int j=0;j<s.length();j++){
//             if( s[j]==']'){
//                 number=0;
//                 string letter ="";
//                 while(myStack.back()!='['){
//                      letter = myStack.back()+letter;
//                       myStack.pop_back();
//                 }
//                 if(myStack.back()=='['){
//                     myStack.pop_back();

//                     number =numbermap[myStack.back()];
//                     myStack.pop_back();
//                 }
                
//                 // cout <<letter<< number<<(char)myStack.back()<<numbermap[(char)myStack.back()]<<" ";
               
//                 for(int i=0;i<number;i++){
//                     num_str+=letter;
//                 }

//                 if(j+1<s.length() && s[j+1]==']'){
//                    for(auto &c:num_str){
//                     myStack.push_back(c);
//                    }
//                 }
//                 else{
//                     new_str+=num_str;
//                 }
//                 num_str="";  
//             }
//             //normal strings
//             else if(numbermap.find(s[j]) !=numbermap.end() && !myStack.empty()){
//                 while(!myStack.empty()){
//                     new_str=myStack.back()+new_str;
//                     myStack.pop_back();
//                 }
//             }
//             else{myStack.push_back(s[j]);}
//         }
//         if(!myStack.empty()){
//             for(char &c:myStack){new_str+=c;}
//         }
       
//         return new_str;  
//     }
// };
class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == ']') {
                string ans = "";
                while(st.top() != "[") {
                    ans = st.top() + ans;
                    st.pop();
                }
                st.pop();
                string times = "";
                while(!st.empty() && isdigit(st.top()[0])) {
                    times = st.top() + times;
                    st.pop();
                }
                int to_times = stoi(times);
                string ret = "";
                while(to_times--) {
                    ret = ans + ret;
                }
                st.push(ret);
            } else {
                st.push(string(1, s[i]));
            }
        }
        string res = "";
        while(!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};