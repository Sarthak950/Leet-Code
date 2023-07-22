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
  // The answer is the level with the maximum sum.
  int ans = 1;

  // The maximum sum so far.
  int maxLevelSum = INT_MIN;

  // A queue of nodes in the current level.
  queue<TreeNode*> q{{root}};

  // Process nodes in level order.
  for (int level = 1; !q.empty(); ++level) {
    // Compute the sum of the current level.
    int levelSum = 0;

    // Process all nodes in the current level.
    for (int sz = q.size(); sz > 0; --sz) {
      // Remove the next node from the queue.
      TreeNode* node = q.front();
      q.pop();

      // Add this node's value to the sum.
      levelSum += node->val;

      // Add the node's children to the queue.
      if (node->left != nullptr)
        q.push(node->left);
      if (node->right != nullptr)
        q.push(node->right);
    }

    // If this level's sum is greater than the max sum so far,
    // update the answer.
    if (maxLevelSum < levelSum) {
      maxLevelSum = levelSum;
      ans = level;
    }
  }

  // Return the answer.
  return ans;
  }
};