/**Question:**

Write a program to print the path from the root to a given node in a binary tree. You are given a binary tree and a node value. You need to find and print the path from the root to the node.

**Approach:**

To find the path from the root to the given node, we can use a recursive function. The idea is to traverse the tree from the root and keep track of the path in a vector. If the target node is found, add the node's value to the path vector, and return true. Otherwise, recursively search for the target node in the left and right subtrees. If the target node is not found, remove the last node from the path vector before returning false.

**Complexity Analysis:**

Time Complexity:
Traversal: O(N)
Copying paths into ans: O(N
2
) worst case
Overall: O(N
2
) worst case
Space Complexity:
Recursive stack + path: O(H)
Including output ans: O(N
2
) worst case

Where:

N = number of nodes
H = height of tree

**Code:**/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
	public:

        void dfs(TreeNode* root,vector<vector<int>>&ans,vector<int>&path){
            if(!root) return;
            path.push_back(root->data);
            if(!root->left && !root->right) ans.push_back(path);
            else {
                dfs(root->left,ans,path);
                dfs(root->right,ans,path);
            }
            path.pop_back();
        }

		vector<vector<int>> allRootToLeaf(TreeNode* root) {
            //your code goes here
            vector<vector<int>>ans;
            vector<int>path;
            dfs(root,ans,path);
            return ans;
		}
};

