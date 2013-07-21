#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
	TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void generateMirror(TreeNode* current, TreeNode*& dupCurrent)
{
	if(current == NULL)
	{
		dupCurrent = NULL;
		return;
	}
	dupCurrent = new TreeNode(current->val);
	generateMirror(current->left,dupCurrent->right);
	generateMirror(current->right,dupCurrent->left);

}


void swapTree(TreeNode*& current)
{
	if(current == NULL)
		return;
	TreeNode* tem = current->left;
	current->left = current->right;
	current->right = tem;
	swapTree(current->left);
	swapTree(current->right);
}

