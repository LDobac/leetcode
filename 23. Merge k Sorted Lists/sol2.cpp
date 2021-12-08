#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;

        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        auto cmp = [](ListNode* left, ListNode* right) {
            return left->val > right->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> queue(cmp);

        for (auto &&head : lists)
        {
            for (auto node = head; node != nullptr; node = node->next)
            {
                queue.push(node);
            }
        }

        while (!queue.empty()) 
        {
            auto r = queue.top(); 
            queue.pop();

            if (!head) 
            {
                head = r;
                tail = head;
                continue;
            }

            tail->next = r;
            r->next = nullptr;
            tail = r;
        }

        return head;
    }
};

int main(void)
{
    Solution sol;

    ListNode list1;
    list1.val = -2;

    ListNode node1;
    node1.val=-2;

    ListNode node2;
    node2.val=-1;

    list1.next = &node1;
    node1.next = &node2;
    node2.next = nullptr;

    ListNode list2;
    list2.val = -1;

    ListNode node3;
    node3.val = -1;

    ListNode node4;
    node4.val=-1;

    list2.next = &node3;
    node3.next = &node4;
    node4.next = nullptr;

    ListNode list3;
    list3.val = 2;

    ListNode node5;
    node5.val = 6;

    // ListNode node6;
    // node6.val=4;

    list3.next = &node5;
    // node5.next = &node6;
    node5.next = nullptr;
    // node6.next = nullptr;

    auto lists = vector<ListNode*>{&list1, &list2};
    auto r = sol.mergeKLists(lists);

    for (auto node = r; node != nullptr; node = node->next)
    {
        cout << node->val << ", "; 
    }
    cout << endl;
}