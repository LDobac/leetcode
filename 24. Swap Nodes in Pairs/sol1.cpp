struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) 
    {
        if (!head) return nullptr;

        ListNode* prev = nullptr;
        ListNode* left = head;
        ListNode* right = head->next;

        while (left && right)
        {
            ListNode* tmp = right->next;

            right->next = left;
            left->next = tmp;

            if (prev) prev->next = right;
            prev = left;

            if (head == left) head = right;
            
            left = tmp;
            if (tmp) right = tmp->next;
        }
        
        return head;
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
    // node1.next = nullptr;
    ListNode node3;
    node2.next = &node3;

    node3.next = nullptr;

    head.val = 1;
    node1.val = 2;
    node2.val = 3;
    node3.val = 4;

    sol.swapPairs(&head);

    return 0;
}