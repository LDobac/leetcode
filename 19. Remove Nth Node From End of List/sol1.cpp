// Definition for singly-linked list.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if (!head->next && n > 0)
        {
            return nullptr;
        }

        ListNode* cur = head;
        int length = 0;
        while (cur)
        {
            length++;

            cur = cur->next;
        }
        
        ListNode* prevOfTarget = nullptr;
        ListNode* target = head;
        for (int i = length - n; i > 0; i--)
        {
            prevOfTarget = target;
            target = target->next;
        }

        if (prevOfTarget == nullptr)
        {
            head = target->next;
        }
        else
        {
            prevOfTarget->next = target->next;
        }
        
        return head;
    }
};

int main(void)
{
    Solution sol;
    
    ListNode head;
    ListNode next1;
    ListNode next2;
    ListNode next3;
    ListNode tail;

    head.val = 1;
    next1.val = 2;
    next2.val = 3;
    next3.val = 4;
    tail.val = 5;

    head.next = &next1;
    next1.next = nullptr;
    next2.next = &next3;
    next3.next = &tail;
    tail.next = nullptr;

    int n = 2;

    sol.removeNthFromEnd(&head, n);
}