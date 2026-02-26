/*
 * @lc app=leetcode.cn id=145 lang=cpp
 * @lcpr version=30400
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode.cn/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Easy (77.86%)
 * Likes:    1270
 * Dislikes: 0
 * Total Accepted:    980.8K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,null,2,3]\n[1,2,3,4,5,null,8,null,null,6,7,9]\n[]\n[1]'
 *
 * 给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,null,2,3]
 *
 * 输出：[3,2,1]
 *
 * 解释：
 *
 *
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1,2,3,4,5,null,8,null,null,6,7,9]
 *
 * 输出：[4,6,7,5,2,9,8,3,1]
 *
 * 解释：
 *
 *
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = []
 *
 * 输出：[]
 *
 *
 * 示例 4：
 *
 *
 * 输入：root = [1]
 *
 * 输出：[1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数目在范围 [0, 100] 内
 * -100 <= Node.val <= 100
 *
 *
 *
 *
 * 进阶：递归算法很简单，你可以通过迭代算法完成吗？
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
    vector<int> postorderTraversal(TreeNode *root)
    {
        traverse(root);
        return res;
    }

    void traverse(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        traverse(root->left);
        traverse(root->right);
        res.push_back(root->val);
    }
    vector<int> res;
};
// @lc code=end

int main()
{
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,null,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,null,8,null,null,6,7,9]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
