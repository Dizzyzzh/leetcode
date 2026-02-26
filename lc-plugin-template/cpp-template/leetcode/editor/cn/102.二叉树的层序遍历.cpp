/*
 * @lc app=leetcode.cn id=102 lang=cpp
 * @lcpr version=30400
 *
 * [102] 二叉树的层序遍历
 *
 * https://leetcode.cn/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (70.56%)
 * Likes:    2251
 * Dislikes: 0
 * Total Accepted:    1.6M
 * Total Submissions: 2.2M
 * Testcase Example:  '[3,9,20,null,null,15,7]\n[1]\n[]'
 *
 * 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。
 *
 *
 *
 * 示例 1：
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[[3],[9,20],[15,7]]
 *
 *
 * 示例 2：
 *
 * 输入：root = [1]
 * 输出：[[1]]
 *
 *
 * 示例 3：
 *
 * 输入：root = []
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目在范围 [0, 2000] 内
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
    vector<vector<int>> levelOrder(TreeNode *root)
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

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            int sz = q.size();
            vector<int> tmp;
            for (int i = 0; i < sz; i++)
            {

                TreeNode *cur = q.front();
                q.pop();
                tmp.push_back(cur->val);

                if (cur->left != nullptr)
                {
                    q.push(cur->left);
                }

                if (cur->right != nullptr)
                {
                    q.push(cur->right);
                }
            }
            res.push_back(tmp);
            tmp.clear();
        }
    }

    vector<vector<int>> res;
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
// [1]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
