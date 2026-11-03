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
TreeNode* solve(vector<int>&preorder,vector<int>&inorder,int &idx, int l , int r){
    if(l>r) return NULL;
    int val = preorder[idx++];
    TreeNode* node = new TreeNode(val);
    int mid = l;
    while(inorder[mid]!=val) mid++;
    node->left = solve(preorder,inorder,idx,l,mid-1);
    node->right = solve(preorder,inorder,idx,mid+1,r);
    return node;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int idx = 0;
       return solve(preorder,inorder,idx,0,n-1);


        
    }
};