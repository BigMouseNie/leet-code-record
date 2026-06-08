using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* upNode = nullptr;
        ListNode* curNode = head;
        bool flag = false;
        head = nullptr;
        while (curNode) {
            if (curNode->next && curNode->val == curNode->next->val) {
                while (curNode->next && curNode->val == curNode->next->val) {
                    curNode = curNode->next;
                }
            } else {
                if (!flag) {
                    flag = true;
                    head = curNode;
                }
                if (upNode) 
                    upNode->next = curNode;
                upNode = curNode;
            }
            curNode = curNode->next;
            if (upNode) upNode->next = nullptr;
        }

        return head;
    }
};
