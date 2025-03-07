class Solution {
public:
    vector<int> closestPrimes(int left, int right) {     
        function<vector<bool>(long  )>sieve = [&](long val){
            vector<bool>primebool(val+1,true);
            primebool[0] = false;
            primebool[1] = false;
            for(int num = 2;num*num<=val;num++){
                if(primebool[num]){
                    for(int mul = num*num ;mul<=val ;mul+=num){
                        primebool[mul]=false;
                    }
                }
            }
            return primebool;
        };

        vector<bool>primbool = sieve(right+1);
        vector<int>primlist;
        for(int i=left;i<right+1;i++){
            if(primbool[i]){
                primlist.push_back(i);
                // cout<<i<<" "<<primlist.back()<<endl;//prim list is going correctly
            }
        }

        if(primlist.size()<2){return vector<int>{-1,-1};}

        int diff = numeric_limits<int>::max();
        int num1 = 0;
        int num2  = 0;
        
        for(int i=1;i<primlist.size();i++){
            // cout << primlist[i]<<primlist[i-1]<<endl;
            if(diff > primlist[i] - primlist[i-1]){
                diff = primlist[i] -primlist[i-1];
                num1 = primlist[i-1];
                num2 = primlist[i];
                // cout << diff<<num1<<num2;
            }
        }

       return vector<int>{num1,num2};
        
    }
};