/*
 * @lc app=leetcode.cn id=111 lang=cpp
 * @lcpr version=30400
 *
 * [111] 二叉树的最小深度
 *
 * https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (56.73%)
 * Likes:    1328
 * Dislikes: 0
 * Total Accepted:    881.5K
 * Total Submissions: 1.6M
 * Testcase Example:  '[3,9,20,null,null,15,7]\n[2,null,3,null,4,null,5,null,6]'
 *
 * 给定一个二叉树，找出其最小深度。
 *
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 *
 * 说明：叶子节点是指没有子节点的节点。
 *
 *
 *
 * 示例 1：
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：2
 *
 *
 * 示例 2：
 *
 * 输入：root = [2,null,3,null,4,null,5,null,6]
 * 输出：5
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数的范围在 [0, 10^5] 内
 * -1000 <= Node.val <= 1000
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
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        traverse(root);
        return depth;
    }

    void traverse(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int sz = q.size();
            while (sz-- > 0)
            {
                TreeNode *cur = q.front();
                q.pop();

                if (cur->left != nullptr)
                {
                    q.push(cur->left);
                }

                if (cur->right != nullptr)
                {
                    q.push(cur->right);
                }

                if (cur->left == nullptr && cur->right == nullptr)
                {
                    return;
                }
            }
            depth++;
        }
    }

    int depth{1};
};
// @lc code=end

int main()
{
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [2,null,3,null,4,null,5,null,6]\n
// @lcpr case=end

 */
