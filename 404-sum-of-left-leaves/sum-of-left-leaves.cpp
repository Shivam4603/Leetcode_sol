class Solution {
public:
    void getLeftSum(TreeNode* root, int &sum){
        if(!root) return;
        if(root->left && !root->left->left && !root->left->right)//cheaking if left exists and the left is a leaf node (i.e it has no children itself)
           sum+=root->left->val;
        getLeftSum(root->left, sum);
        getLeftSum(root->right, sum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
       int sum = 0;
       getLeftSum(root, sum);
       return sum;
    }
};