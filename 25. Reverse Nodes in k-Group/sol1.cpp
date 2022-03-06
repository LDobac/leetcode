#include <stack>

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution 
{
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if (k <= 1) return head;

        std::stack<ListNode*> s;

        ListNode* reversedHead = nullptr;
        ListNode* curLocalHead = head;
        ListNode* prevLocalHead = nullptr;
    
        while (RemainNodeNums(curLocalHead) >= k)
        {
            ListNode* cur = curLocalHead;
            ListNode* nextLocalHead = nullptr;

            // Push to stack
            for (int n = 0; n < k; n++)
            {
                s.push(cur);

                cur = cur->next;
            }
            nextLocalHead = cur;
            
            // Pop from stack
            cur = s.top(); s.pop();
            curLocalHead = cur;

            if (prevLocalHead) prevLocalHead->next = curLocalHead;

            if (!reversedHead) reversedHead = cur;

            while (!s.empty())
            {
                cur = s.top();

                curLocalHead->next = cur;
                curLocalHead = cur;

                s.pop();
            }
            
            prevLocalHead = curLocalHead;
            // Connect next node
            curLocalHead->next = nextLocalHead;
            // Move localhead to next node
            curLocalHead = nextLocalHead;
        }

        return reversedHead;
    }

    int RemainNodeNums(ListNode* head)
    {
        int count = 0;

        for (ListNode* node = head; node; node = node->next) count++;

        return count;
    }
};

int main()
{
    Solution sol;

    ListNode head;
    ListNode node1;
    head.next = &node1;
    ListNode node2;
    node1.next = &node2;
    ListNode node3;
    node2.next = &node3;
    ListNode node4;
    node3.next = &node4;

    node4.next = nullptr;

    head.val = 1;
    node1.val = 2;
    node2.val = 3;
    node3.val = 4;
    node4.val = 5;

    sol.reverseKGroup(&head, 2);

    return 0;
}