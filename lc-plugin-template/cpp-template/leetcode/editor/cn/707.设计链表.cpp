/*
 * @lc app=leetcode.cn id=707 lang=cpp
 * @lcpr version=30400
 *
 * [707] 设计链表
 *
 * https://leetcode.cn/problems/design-linked-list/description/
 *
 * algorithms
 * Medium (34.73%)
 * Likes:    1210
 * Dislikes: 0
 * Total Accepted:    438.5K
 * Total Submissions: 1.3M
 * Testcase Example:  '["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]\n' +
  '[[],[1],[3],[1,2],[1],[1],[1]]'
 *
 * 你可以选择使用单链表或者双链表，设计并实现自己的链表。
 *
 * 单链表中的节点应该具备两个属性：val 和 next 。val 是当前节点的值，next 是指向下一个节点的指针/引用。
 *
 * 如果是双向链表，则还需要属性 prev 以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。
 *
 * 实现 MyLinkedList 类：
 *
 *
 * MyLinkedList() 初始化 MyLinkedList 对象。
 * int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。
 * void addAtHead(int val) 将一个值为 val
 * 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
 * void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
 * void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果
 * index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。
 * void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。
 *
 *
 *
 *
 * 示例：
 *
 * 输入
 * ["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get",
 * "deleteAtIndex", "get"]
 * [[], [1], [3], [1, 2], [1], [1], [1]]
 * 输出
 * [null, null, null, null, 2, null, 3]
 *
 * 解释
 * MyLinkedList myLinkedList = new MyLinkedList();
 * myLinkedList.addAtHead(1);
 * myLinkedList.addAtTail(3);
 * myLinkedList.addAtIndex(1, 2);    // 链表变为 1->2->3
 * myLinkedList.get(1);              // 返回 2
 * myLinkedList.deleteAtIndex(1);    // 现在，链表变为 1->3
 * myLinkedList.get(1);              // 返回 3
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= index, val <= 1000
 * 请不要使用内置的 LinkedList 库。
 * 调用 get、addAtHead、addAtTail、addAtIndex 和 deleteAtIndex 的次数不超过 2000 。
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
class MyLinkedList
{
public:
    class Node
    {
    public:
        Node() = default;
        Node(int val) : val(val), prev(nullptr), next(nullptr)
        {
        }

        int val;
        Node *prev;
        Node *next;
    };

    MyLinkedList()
    {
        head = new Node();
        tail = new Node();
        head->next = tail;
        head->prev = nullptr;
        tail->prev = head;
        tail->next = nullptr;
        size = 0;
    }

    int get(int index)
    {
        if (checkElementIndex(index))
        {
            Node *p = head;
            for (int i = 0; i <= index; i++)
            {
                p = p->next;
            }

            return p->val;
        }
        else
        {
            return -1;
        }
    }

    Node *getNode(int index)
    {
        if (checkElementIndex(index))
        {
            Node *p = head;
            for (int i = 0; i <= index; i++)
            {
                p = p->next;
            }

            return p;
        }
        else
        {
            return nullptr;
        }
    }

    void addAtHead(int val)
    {
        Node *newNode = new Node(val);

        Node *tmp = head->next;
        head->next = newNode;
        tmp->prev = newNode;

        newNode->prev = head;
        newNode->next = tmp;

        size++;
    }

    void addAtTail(int val)
    {
        Node *newNode = new Node(val);

        Node *tmp = tail->prev;
        tmp->next = newNode;
        tail->prev = newNode;

        newNode->prev = tmp;
        newNode->next = tail;

        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index == size)
        {
            addAtTail(val);
            return;
        }

        if (checkElementIndex(index))
        {
            Node *newNode = new Node(val);
            Node *p = getNode(index);
            Node *p_prev = p->prev;
            p_prev->next = newNode;
            p->prev = newNode;

            newNode->next = p;
            newNode->prev = p_prev;
            size++;
        }
    }

    void deleteAtIndex(int index)
    {
        if (checkElementIndex(index))
        {
            Node *p = getNode(index);
            Node *p_prev = p->prev;
            Node *p_next = p->next;
            p_prev->next = p_next;
            p_next->prev = p_prev;

            delete p;
            size--;
        }
    }

    bool checkElementIndex(int index)
    {
        return index >= 0 && index < size;
    }

    bool checkPositionIndex(int index)
    {
        return index >= 0 && index <= size;
    }

    Node *head;
    Node *tail;
    int size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

int main()
{
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// ["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]\n[[],[1],[3],[1,2],[1],[1],[1]]\n
// @lcpr case=end

 */
