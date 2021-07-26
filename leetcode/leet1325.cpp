// https://leetcode.com/problems/delete-leaves-with-a-given-value/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int remove(TreeNode* node, int target) {
        if(node->left != nullptr){
            if(node->left->left == nullptr && node->left->right == nullptr){
                if(node->left->val == target) {
                    node->left = nullptr;
                }
            }
            else{
                remove(node->left, target);
            }
        }
        if(node->right != nullptr) {
            if(node->right->left == nullptr && node->right->right == nullptr){
                if(node->right->val == target) {
                    node->right = nullptr;
                }
            }
            else{
                remove(node->right, target);
            }
        }
        
        if(node->left != nullptr){
            if(node->left->left == nullptr && node->left->right == nullptr){
                if(node->left->val == target) {
                    node->left = nullptr;
                }
            }
        }
        if(node->right != nullptr) {
            if(node->right->left == nullptr && node->right->right == nullptr){
                if(node->right->val == target) {
                    node->right = nullptr;
                }
            }
        }

        return 0;
    }
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        remove(root, target);
        
        if(root->left == nullptr && root->right == nullptr){
            if(root->val == target) return nullptr;
        }
        
        return root;
    }
};
