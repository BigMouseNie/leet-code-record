using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return node;
        unordered_map<int, Node*> map;
        queue<Node*> que;
        que.push(node);
        map.insert({node->val, new Node(node->val)});
        while (!que.empty()) {
            Node* f = que.front();
            que.pop();
            Node* curNode = map[f->val];
            curNode->neighbors.reserve(f->neighbors.size());
            for (Node* n : f->neighbors) {
                auto it = map.find(n->val);
                if (it == map.end()) {
                    Node* newNode = new Node(n->val);
                    map.insert({n->val, newNode});
                    que.push(n);
                }
                curNode->neighbors.push_back(map[n->val]);
            }
        }
        return map[node->val];
    }
};

