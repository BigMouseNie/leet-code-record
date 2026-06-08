

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        do {
            if (slow == nullptr) return false;
            slow = slow->next;
            if (fast == nullptr) return false;
            fast = fast->next;
            if (fast == nullptr) return false;
            fast = fast->next;
        } while (fast != slow);
        return true;
    }
};