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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;
        ListNode* sHNode = nullptr;
        ListNode* sCNode = nullptr;
        ListNode* lHNode = nullptr;
        ListNode* lCNode = nullptr;
        ListNode* curNode = head;
        while (curNode) {
            if (curNode->val < x) {
                if (!sHNode) {
                    sHNode = curNode;
                    sCNode = curNode;
                } else {
                    sCNode->next = curNode;
                    sCNode = curNode;
                }
            } else {
                if (!lHNode) {
                    lHNode = curNode;
                    lCNode = curNode;
                } else {
                    lCNode->next = curNode;
                    lCNode = curNode;
                }
            }
            ListNode* t = curNode->next;
            curNode->next = nullptr;
            curNode = t;
        }
        if (sCNode)
            sCNode->next = lHNode;
        return sHNode ? sHNode : lHNode;
    }
};
