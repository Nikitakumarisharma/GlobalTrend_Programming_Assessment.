#include <iostream>
#include <climits>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxPathSumHelper(root, maxSum);
        return maxSum;
    }

private:
    int maxPathSumHelper(TreeNode* node, int& maxSum) {
        if (!node) return 0;
        
        // Recursively get the maximum path sum of the left and right subtrees
        int leftSum = max(0, maxPathSumHelper(node->left, maxSum));
        int rightSum = max(0, maxPathSumHelper(node->right, maxSum));
        
        // Update the maximum path sum that can be obtained including the current node
        maxSum = max(maxSum, leftSum + rightSum + node->val);
        
        // Return the maximum path sum starting from the current node
        return max(leftSum, rightSum) + node->val;
    }
};

// Function to create a new node
TreeNode* newNode(int data)
{
    TreeNode* node = new TreeNode(data);
    node->left = node->right = NULL;
    return (node);
}

int main() {
    Solution solution;

    // Create the binary tree
    TreeNode* root = newNode(-10);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    // Find the maximum path sum
    cout << "Maximum path sum: " << solution.maxPathSum(root) << endl;

    return 0;
}
