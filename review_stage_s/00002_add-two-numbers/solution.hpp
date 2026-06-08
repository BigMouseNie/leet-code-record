#include <vector>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> vec1;
        vector<int> vec2;
        while (l1 && l2) {
            if (l1) {
                vec1.push_back(l1->val);
                l1 = l1->next;
            }
            if (l2) {
                vec2.push_back(l2->val);
                l2 = l2->next;
            }
        }

        int upVal = 0;
        int i=vec1.size()-1;
        int j=vec2.size()-1;
        vector<ListNode*> res;
        for (i>=0||j>=0) {
            int curVal = upVal;
            if (i>=0) curVal += vec1[i--];
            if (j>=0) curVal += vec2[j--];
            upVal = curVal / 10;
            curVal %= 10;
            res.push_back(new ListNode(curVal));
        }
        if (upVal != 0) {
            res.push_back(new ListNode(upVal));
            upVal = 0;
        }
        for (int k=res.size()-1;k>=0;--k){
            if (k>0){
                res[k]->next = res[k-1];
            }
        }
        res[0]->next = nullptr;
        return res.back();
    }
};
