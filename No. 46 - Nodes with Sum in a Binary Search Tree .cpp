#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//O(n) Space
void inorderTraverse(TreeNode* current, vector<int>& ret)
{
	if(current == NULL)
		return;
	inorderTraverse(current->left);
	ret.push_back(current->val);
	inorderTraverse(current->right);
}


bool isExist(TreeNode* root, int target)
{
	if(root == NULL)
		return false;
	vector<int> vec;
	inorderTraverse(root,vec);
	int n = vec.size();
	int i = 0; 
	int j = n-1;
	while(i < j)
	{
		int total = vec[i] + vec[j];
		if(total == target)
			return true;
		else if(total > target)
			j--;
		else i++;
	}
	return false;
}


//O(h) Space (lots of fun code to write:-) )
void buildLeft(TreeNode* current, stack<TreeNode* >& leftStack)
{
	while(current != NULL)
	{
		leftStack.push(current);
		current = current->left;
	}
}

void buildRight(TreeNode* current, stack<TreeNode*>& rightStack)
{
	while(current != NULL)
	{
		rightStack.push(current);
		current = current->right;
	}
}

TreeNode* getNext(stack<TreeNode*>& leftStack)
{
	if(leftStack.empty())
		return NULL;
	TreeNode* ret = NULL;
	ret = leftStack.top();
	leftStack.pop();
	TreeNode* current = ret->right;
	while(current != NULL)
	{
		leftStack.push(current);
		current = current->left;
	}
	return ret;
}

TreeNode* getPrev(stack<TreeNode*>& rightStack)
{
	if(rightStack.empty())
		return NULL;
	TreeNode* ret = NULL;
	ret = rightStack.top();
	rightStack.pop();
	TreeNode* current = ret->right;
	while(current != NULL)
	{
		rightStack.push(current);
		current = current->right;
	}
	return ret;
}

bool isExist(TreeNode* root, int target)
{
	if(root == NULL)
		return false;
	stack<TreeNode*> leftStack;
	stack<TreeNode*> rightStack;
	buildLeft(root,leftStack);
	buildRight(root,rightStack);
	TreeNode* left = getNext(leftStack);
	TreeNode* right = getNext(rightStack);
	while(left != NULL && right != NULL && left != right)
	{
		int total = left->val + right->val;
		if(total == target)
			return true;
		else if(total < target)
			left = getNext(leftStack);
		else right = getPrev(rightStack);
	}
	return false;
}
