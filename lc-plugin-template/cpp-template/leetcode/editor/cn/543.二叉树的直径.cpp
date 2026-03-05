/*
 * @lc app=leetcode.cn id=543 lang=cpp
 * @lcpr version=30400
 *
 * [543] 二叉树的直径
 *
 * https://leetcode.cn/problems/diameter-of-binary-tree/description/
 *
 * algorithms
 * Easy (63.93%)
 * Likes:    1874
 * Dislikes: 0
 * Total Accepted:    759.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,3,4,5]\n[1,2]'
 *
 * 给你一棵二叉树的根节点，返回该树的 直径 。
 *
 * 二叉树的 直径 是指树中任意两个节点之间最长路径的 长度 。这条路径可能经过也可能不经过根节点 root 。
 *
 * 两节点之间路径的 长度 由它们之间边数表示。
 *
 *
 *
 * 示例 1：
 *
 * 输入：root = [1,2,3,4,5]
 * 输出：3
 * 解释：3 ，取路径 [4,2,1,3] 或 [5,2,1,3] 的长度。
 *
 *
 * 示例 2：
 *
 * 输入：root = [1,2]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目在范围 [1, 10^4] 内
 * -100 <= Node.val <= 100
 *
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
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
class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        traverse(root);
        return maxDiameter;
    }

    void traverse(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        int maxDepthLeft = maxDepth(root->left);
        int maxDepthRight = maxDepth(root->right);
        int curDiameter = maxDepthLeft + maxDepthRight;

        maxDiameter = max(maxDiameter, curDiameter);

        traverse(root->left);
        traverse(root->right);
    }

    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int leftMax = maxDepth(root->left);
        int rightMax = maxDepth(root->right);
        return 1 + max(leftMax, rightMax);
    }

    int maxDiameter = 0;
};
// @lc code=end

int main()
{
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */
