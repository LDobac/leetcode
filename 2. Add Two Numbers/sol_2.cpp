#include <vector>
#include <tuple>
#include <cmath>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int carry = 0;

        ListNode* node1 = l1;
        ListNode* node2 = l2;

        ListNode* head = nullptr;
        ListNode* lastNode = nullptr;

        while (node1 != nullptr || node2 != nullptr)
        {
            int numOf1 = node1 ? node1->val : 0;
            int numOf2 = node2 ? node2->val : 0;

            int sum = numOf1 + numOf2 + carry;

            carry = sum / 10;

            ListNode* newNode = new ListNode(sum % 10);

            if (!head) head = newNode;
            else lastNode->next = newNode;

            lastNode = newNode;

            if(node1) node1 = node1->next;
            if(node2) node2 = node2->next;
        }

        if (carry > 0)
        {
            ListNode* node = new ListNode(carry);
            lastNode->next = node;
        }
    
        return head;
        
        // 반환할 때도 ListNode형으로 반환해야함.
        // Sol1. 따로따로 구해서 덧셈 후 다시 ListNode로 분해해서 구하기
    }
};

int main(void)
{
    Solution sol;

    // ListNode * l1 = new ListNode(3);
    // l1 = new ListNode(4, l1);
    // l1 = new ListNode(2, l1);

    // ListNode * l2 = new ListNode(4);
    // l2 = new ListNode(6, l2);
    // l2 = new ListNode(5, l2);

    ListNode * l1 = new ListNode(9);

    ListNode * l2 = new ListNode(9);
    l2 = new ListNode(9, l2);
    l2 = new ListNode(9, l2);
    l2 = new ListNode(9, l2);
    l2 = new ListNode(9, l2);
    l2 = new ListNode(9, l2);
    l2 = new ListNode(9, l2);
    l2 = new ListNode(9, l2);
    l2 = new ListNode(9, l2);
    l2 = new ListNode(1, l2);

    auto answer = sol.addTwoNumbers(l1, l2);
}