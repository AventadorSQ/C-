/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	//·ÇµÝ¹é
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> v;
		TreeNode* ptr = root;
		stack<TreeNode*> st;

		while (ptr || !st.empty())
		{
			while (ptr)
			{
				st.push(ptr);
				v.push_back(ptr->val);
				ptr = ptr->left;
			}

			TreeNode* top = st.top();
			st.pop();
			ptr = top->right;
		}

		return v;
	}

	//µÝ¹é
	vector<int> preorderSTraversal(TreeNode* root)
	{
		vector<int> v;
		TreeNode* ptr = root;
		Preorder(ptr, v);

		return v;
	}

	void Preorder(TreeNode* ptr, vector<int>& v)
	{
		if (ptr == NULL)
		{
			return;
		}

		v.push_back(ptr->val);
		Preorder(ptr->left, v);
		Preorder(ptr->right, v);
	}
};

int main()
{
	return 0;
}