class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string min_word, max_word,merge="";
        if (word1.length() <= word2.length()){
            min_word = word1;
            max_word = word2;
        }
        else{
            min_word = word2;
            max_word = word1;
        }
        for(int i=0;i<min_word.length();i++)
        {  merge =  merge + word1[i] + word2[i]; }
        
        if (word1.length()==word2.length()){return merge;}

        else{
            for(int i=min_word.length();i<max_word.length();i++){
                merge = merge+ max_word[i];
            }
        }
        return merge;
    
        
    }
};