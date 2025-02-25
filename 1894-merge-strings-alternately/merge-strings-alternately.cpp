class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        // string min_word, max_word,merge="";
        int len1 = word1.length();
        int len2 = word2.length();
        int i =0,j =0;
        string merge = "";
        while(i<len1 && j<len2){
            merge+=word1[i];
            merge+=word2[j];
            i++;
            j++;
        }
        while(i<len1){
            merge+=word1[i];
            i++;
        }
        while(j<len2){
            merge+=word2[j];
            j++;
        }


        // if (word1.length() <= word2.length()){
        //     min_word = word1;
        //     max_word = word2;
        // }
        // else{
        //     min_word = word2;
        //     max_word = word1;
        // }
        // for(int i=0;i<min_word.length();i++)
        // {  merge =  merge + word1[i] + word2[i]; }
        
        // if (word1.length()==word2.length()){return merge;}

        // else{
        //     for(int i=min_word.length();i<max_word.length();i++){
        //         merge = merge+ max_word[i];
        //     }
        // }
        return merge;
    
        
    }
};