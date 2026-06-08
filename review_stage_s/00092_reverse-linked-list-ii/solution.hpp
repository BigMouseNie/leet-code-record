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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* pLNode = nullptr;
        ListNode* lNode = nullptr;
        ListNode* rNode = nullptr;
        ListNode* nRNode = nullptr;

        int i=1;
        ListNode* preNode = nullptr;
        ListNode* curNode = head;
        while (curNode) {
            if (i==left) {
                pLNode = preNode;
                lNode = curNode;
            }
            if (i==right) {
                rNode = curNode;
                nRNode = curNode->next;
                break;
            }
            preNode = curNode;
            curNode = curNode->next;
            ++i;
        }

        ListNode* p1 = lNode;
        ListNode* p2 = lNode->next;
        while (p2!=nRNode) {
            ListNode* t = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = t;
        }
        lNode->next = nRNode;
        if (pLNode) pLNode->next = rNode;
        return pLNode ? head : rNode;
    }
};
