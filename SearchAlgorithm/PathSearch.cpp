#include<iostream>
#include<cmath>
using namespace std;


//Definition for binary tree.
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

//Search the path of the tree, st: Sum(path) = sum.
bool hasPathSum(TreeNode *root, int sum){
	if(root == NULL) return false;
	if(root->left == NULL && root->right == NULL){
		if(root->val == sum)
			return true;
	}
	return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
}

int getDepth(TreeNode *root){
	if(root == NULL) return 0;
	int left_depth = getDepth(root->left)+1;
	int right_depth = getDepth(root->right)+1;
	return left_depth > right_depth ? left_depth : right_depth;
}

bool isBanlanced(TreeNode *root){
	if(root == NULL) return false;
	int ld = getDepth(root->left)+1;
	int rd = getDepth(root->right)+1;

	if(abs(ld - rd) < 1)
		return isBanlanced(root->left) || isBanlanced(root->right);
	else
		return false;
}

