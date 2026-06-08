#include <vector>
#include <unordered_map>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;
        vector<Node*> vec1;
        Node* th = head;
        unordered_map<Node*, int> _map;
        while (th) {
            vec1.push_back(th);
            _map[th] = vec1.size()-1;
            th = th->next;
        }

        for (int i=0;i<vec1.size();++i) {
            vec1[i] = new Node(vec1[i]->val);
            if (i>0) {
                vec1[i-1]->next = vec1[i];
            }
        }

        Node* th2 = vec1[0];
        th = head;
        while (th2) {
            if (th->random) {
                th2->random = vec1[_map[th->random]];
            }
            th = th->next;
            th2 = th2->next;
        }
        return vec1.front();
    }
};
