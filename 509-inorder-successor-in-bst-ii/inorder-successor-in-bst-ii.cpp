/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
       if(node->right){
        node = node->right;
        while(node->left){
            node = node->left;
        }
       }
       else{
        while(node->parent && node->parent->right ==node){
            // pure magoc we go until this fails to up
            // when ever it fails that is ur parent  is ur anwer 
            node = node->parent;
        }
        node =node->parent;
       }
       return node;
    }
};