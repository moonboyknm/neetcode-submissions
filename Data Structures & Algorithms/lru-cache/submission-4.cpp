class LRUCache {
private:
    struct Node{
        int key;
        int value;
        Node* next;
        Node* prev;

        Node(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
    };

    int maxCapacity;
    Node* dummyHead;
    Node* dummyTail;
    std::unordered_map<int, Node*> keyToNode;

    void removeNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToHead(Node* node){
        node->next = dummyHead->next;
        node->prev = dummyHead;
        dummyHead->next->prev = node;
        dummyHead->next = node;
    }

public:
    LRUCache(int capacity) : maxCapacity(capacity) {
        dummyHead = new Node(0,0);
        dummyTail = new Node(0,0);
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }
    
    int get(int key) {
        auto it = keyToNode.find(key);
        if (it == keyToNode.end()){
            return -1;
        }

        Node* node = it->second;
        removeNode(node);
        addToHead(node);

        return node->value;
    }
    
    void put(int key, int value) {
        auto it = keyToNode.find(key);

        if (it != keyToNode.end()){
            Node* node = it->second;
            node->value = value;
            removeNode(node);
            addToHead(node);
        } else {
            if (static_cast<int>(keyToNode.size()) == maxCapacity){
                Node* lruNode = dummyTail->prev;
                keyToNode.erase(lruNode->key);
                removeNode(lruNode);
                delete lruNode;
            }

            Node* newNode = new Node(key,value);
            keyToNode[key] = newNode;
            addToHead(newNode);
        }
    }
};
