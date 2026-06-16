#include <unordered_map>

using namespace std;

struct Node
{
    int key;
    int val;
    Node* prev;
    Node* next;
    Node() : key(0), val(0), prev(nullptr), next(nullptr){}
    Node(int _key, int _val, Node* _prev, Node* _next) : key(_key), val(_val), prev(_prev), next(_next){}
};

class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity), size(0), head(nullptr), tail(nullptr) {
        
    }
    
    int get(int key) {
        auto it = map.find(key);
        if (it == map.end()) return -1;
        used(it->second);
        return it->second->val;
    }
    
    void put(int key, int value) {
        auto it = map.find(key);
        if (it != map.end()) {
            it->second->val = value;
            used(it->second);
            return;
        }
        if (size >= capacity) pop();
        insert(key, value);
    }

private:
    void used(Node* node) {
        if (capacity == 1 || size == 1 || node == tail) return;
        if (node == head) {
            Node* newHead = head->next;
            newHead->prev = nullptr;
            head->next = nullptr;
            tail->next = head;
            head->prev = tail;
            tail = head;
            head = newHead;
            return;
        }
        Node* p = node->prev;
        Node* n = node->next;
        p->next = n;
        n->prev = p;
        node->next = nullptr;
        tail->next = node;
        node->prev = tail;
        tail = node;
    }

    void pop() {
        if (head == nullptr) return;
        map.erase(head->key);
        --size;
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }
        Node* newHead = head->next;
        newHead->prev = nullptr;
        delete head;
        head = newHead;
    }

    void insert(int key, int value) {
        Node* node = new Node(key, value, nullptr, nullptr);
        map.insert({key, node});
        ++size;
        if (head == nullptr) {
            head = node;
            tail = head;
            return;
        }
        tail->next = node;
        node->prev = tail;
        tail = node;
    }

private:
    int capacity;
    int size;
    unordered_map<int, Node*> map;
    Node* head;
    Node* tail;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */