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
        int multiplier = 0;
        int numOfl1 = 0;
        int numOfl2 = 0;

        for (ListNode* node = l1; node != nullptr ; node = node->next)
        {
            numOfl1 += node->val * powl(10, multiplier);
            multiplier++;
        }

        multiplier = 0;

        for (ListNode* node = l2; node != nullptr ; node = node->next)
        {
            numOfl2 += node->val * powl(10, multiplier);
            multiplier++;
        }

        int add = numOfl1 + numOfl2;

        ListNode* head = new ListNode(add % 10);
        ListNode* result = head;
        for (int num = add/10; num > 0 ; num /= 10 )
        {
            int digit = num % 10;

            ListNode* node = new ListNode(digit);
            result->next = node;

            result = node;
        }

        return head;
        
        // 반환할 때도 ListNode형으로 반환해야함.
        // sol2. 반복문을 돌면서 자리수 마다 덧셈 후 ListNode 생성, 올림 따로 처리하기
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