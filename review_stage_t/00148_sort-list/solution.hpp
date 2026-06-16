using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
超时了，其实是我懒着分治
*/

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head) return head;
        ListNode* result = sortList(head->next);
        head->next = nullptr;
        if (!result) return head;
        if (result->val >= head->val) {
            head->next = result;
            return head;
        }
        ListNode* up = result;
        ListNode* cur = result->next;
        while (cur) {
            if (cur->val >= head->val) {
                up->next = head;
                head->next = cur;
                return result;
            }
            up = cur;
            cur = cur->next;
        }
        up->next = head;
        return result;
    }
};