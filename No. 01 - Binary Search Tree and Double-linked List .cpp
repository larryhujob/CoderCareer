#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void convertRec(TreeNode* current, TreeNode*& last)
{
	if(current == NULL)
		return;
	convertRec(current->left,last);
	current->left = last;
	if(last != NULL)
		last->right = current;
	last = current;
	convertRec(current->right,last);
}

TreeNode* convert(TreeNode* root)
{
	if(root == NULL)
		return NULL;
	TreeNode* last = NULL;
	convertRec(root,last);
	while(last->left != NULL)
		last = last->left;
	return last;
}

