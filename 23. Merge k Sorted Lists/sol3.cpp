#include <vector>
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

        auto amount = lists.size();
        auto interval = 1;
        while (interval < amount)
        {
            for (auto i = 0; i < amount - interval; i += interval * 2)
            {
                lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }

        return lists[0];
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 && !list2) return nullptr;
        
        ListNode* mergedHead = nullptr;
        ListNode* lastNode = nullptr;

        ListNode* node1 = list1;
        ListNode* node2 = list2;

        while (node1 && node2)
        {
            ListNode* selectedNode = nullptr;

            if (node1->val < node2->val)
            {
                selectedNode = node1;
                node1 = node1->next;
            }
            else
            {
                selectedNode = node2;
                node2 = node2->next;
            }

            if (mergedHead == nullptr)
            {
                mergedHead = selectedNode;
            }
            else
            {
                lastNode->next = selectedNode;
            }

            lastNode = selectedNode;
        }

        if (node1)
        {
            if (!mergedHead)
            {
                mergedHead = node1;
            }
            else
            {
                for (auto node = node1; node != nullptr; node = node->next)
                {
                    lastNode->next = node;
                    lastNode = node;
                }
            }
        }

        if (node2)
        {
            if (!mergedHead)
            {
                mergedHead = node2;
            }
            else
            {
                for (auto node = node2; node != nullptr; node = node->next)
                {
                    lastNode->next = node;
                    lastNode = node;
                }
            }
        }

        return mergedHead;   
    }
};

int main(void)
{
    Solution sol;

    ListNode list1;
    list1.val = 1;

    ListNode node1;
    node1.val=4;

    ListNode node2;
    node2.val=5;

    list1.next = &node1;
    node1.next = &node2;
    node2.next = nullptr;

    ListNode list2;
    list2.val = 1;

    ListNode node3;
    node3.val = 3;

    ListNode node4;
    node4.val=4;

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

    // auto lists = vector<ListNode*>{&list1, &list2, &list3};
    // sol.mergeKLists(lists);

    ListNode* r = sol.mergeTwoLists(&list1, &list2);
    r = sol.mergeTwoLists(r, &list3);

    for (auto node = r; node != nullptr; node = node->next)
    {
        cout << node->val << ", "; 
    }
    cout << endl;
}