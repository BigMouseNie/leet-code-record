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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        ListNode* leftFront = head;
        ListNode* leftBack = nullptr;
        ListNode* rightFront = nullptr;
        ListNode* rightBack = nullptr;
        ListNode* curNode = head;
        int size = 1;
        while (curNode->next) {
            curNode = curNode->next;
            ++size;
        }
        rightBack = curNode;

        // if ((k / size) % 2 != 0) {
        //     ListNode* upNode = nullptr;
        //     curNode = head;
        //     while(curNode) {
        //         ListNode* t = curNode->next;
        //         curNode->next = upNode;
        //         upNode = curNode;
        //         curNode = t;
        //     }
        //     rightBack = head;
        //     head = upNode;
        // }
        k %= size;
        if (k==0) {return head;}

        int target = size - k;
        curNode = head;
        while (target != 0) {
            --target;
            leftBack = curNode;
            curNode = curNode->next;
        }
        rightFront = leftBack->next;

        leftBack->next = nullptr;
        if (rightBack) rightBack->next = leftFront;
        return rightFront ? rightFront : leftFront;
    }
};
