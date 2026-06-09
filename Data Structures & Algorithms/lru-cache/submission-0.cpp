class Node {
public:
    Node* next;
    Node* prev;
    int val;
    int key;

    Node(int num, int k) {
        next = NULL;
        prev = NULL;
        val = num;
        key = k;
    }
};

class LRUCache {
private:
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;
    int cap;

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.count(key)) {
            // move node to head
            Node* node = cache[key];
            Node* prev = node->prev;
            Node* next = node->next;
            // detach from current position first
            prev->next = next;
            next->prev = prev;
            
            Node* oldHead = head->next;
            oldHead->prev = node;
            head->next = node;
            node->prev = head;
            node->next = oldHead;
            
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        Node* newNode = NULL;
        
        if (cache.count(key)) {
            // update old val
            cache[key]->val = value;
            newNode = cache[key];
            // remove from current position
            Node* prev = newNode->prev;
            Node* next = newNode->next;
            prev->next = next;
            next->prev = prev;
        } else {
            if (cache.size() == cap) {
                // remove tail entry
                Node* removeNode = tail->prev;
                Node* prev = removeNode->prev;
                prev->next = tail;
                tail->prev = prev;
                cache.erase(removeNode->key);
                delete(removeNode);
            }
            newNode = new Node(value, key);
            cache[key] = newNode;
        }

        // move newNode to beginning
        Node* oldHead = head->next;
        oldHead->prev = newNode;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = oldHead;
    }
};