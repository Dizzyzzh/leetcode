/*
 * @lc app=leetcode.cn id=590 lang=cpp
 * @lcpr version=30400
 *
 * [590] N 叉树的后序遍历
 *
 * https://leetcode.cn/problems/n-ary-tree-postorder-traversal/description/
 *
 * algorithms
 * Easy (79.96%)
 * Likes:    346
 * Dislikes: 0
 * Total Accepted:    178K
 * Total Submissions: 222.6K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]\n' +
  '[1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]'
 *
 * 给定一个 n 叉树的根节点 root ，返回 其节点值的 后序遍历 。
 *
 * n 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 null 分隔（请参见示例）。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：root = [1,null,3,2,4,null,5,6]
 * 输出：[5,6,3,2,4,1]
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：root =
 * [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
 * 输出：[2,6,14,11,7,3,12,8,4,13,9,10,5,1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 节点总数在范围 [0, 10^4] 内
 * 0 <= Node.val <= 10^4
 * n 叉树的高度小于或等于 1000
 *
 *
 *
 *
 * 进阶：递归法很简单，你可以使用迭代法完成此题吗?
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    vector<int> postorder(Node *root)
    {
        traverse(root);
        return res;
    }

    void traverse(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }

        for(auto* tmp : root->children)
        {
            traverse(tmp);
        }

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
// [1,null,3,2,4,null,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]\n
// @lcpr case=end

 */
