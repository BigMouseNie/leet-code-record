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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* upNode = nullptr;
        ListNode* curNode = head;
        int size = 0;
        while (curNode) {
            ++size;
            curNode = curNode->next;
        }
        n = size - n + 1;
        curNode = head;
        for(int i=1;i<=size;++i) {
            if (i==n) {
                curNode = curNode->next;
                if(upNode) {upNode->next = curNode; return head;}
                return curNode;
                break;
            }
            upNode = curNode;
            curNode = curNode->next;
        }
        return nullptr;
    }
};

