/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root){return nullptr;}
        Node* head ;
        Node* tail;
        function<void(Node*)>dfs = [&](Node *root){
            if(root){
            dfs(root->left);
            if (tail){
                tail->right =root;
                root->left = tail;
            }
            else{head = root;}
            tail = root;
            dfs(root->right);
            }    
        };
        dfs(root);
        head->left = tail;
        tail->right = head;
        return head;
       
    }
};