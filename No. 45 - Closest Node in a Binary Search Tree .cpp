#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void searchRec(TreeNode* current, TreeNode*& minNode, const int& k, int& minVal)
{

	if(current == NULL)
		return;
	int dif = abs(current->val - k);
	if(dif < minVal)
	{
		minVal = dif;
		minNode = current;
	}
	if(current->val > k)
		searchRec(current->left,minNode,k,minVal);
	else if(current->val < k)
		searchRec(current->right,minNode,k,minVal);
	else return;
}


TreeNode* search(TreeNode* root,const int& k)
{
	if(root == NULL)
		return NULL;
	TreeNode* minNode = NULL;
	int minVal = INT_MAX;
	searchRec(root,minNode,k,minVal);
	return minNode;
}

