class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>Stack;
        for(int &i:asteroids){
            while(!Stack.empty()  && i<0 && Stack.back()>0){
                int diff = i + Stack.back();
                if(diff < 0){
                    Stack.pop_back();
                }
                else if(diff > 0){
                    i=0;
                }
                else{
                    i=0;
                    Stack.pop_back();
                }
            }

            if (i){Stack.push_back(i);}

        }
        return Stack;

    }
};