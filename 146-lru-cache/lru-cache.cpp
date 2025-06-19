class Node {
public:
    int key, val;
    Node* prev;
    Node* next;

    Node(int _key, int _val) {
        key = _key;
        val = _val;
        prev = next = nullptr;
    }
};
class LRUCache {
public:
    int capacity_;
    Node* head;
    Node* tail;
    map<int,Node*> mpp;

    void deleteNode(Node* node){
        Node* prevNode = node->prev;
        Node* afterNode = node->next;

        prevNode->next = afterNode;
        afterNode->prev = prevNode;
    }
    void InsertAfterHead(Node* node){
        Node* curAfterHead = head->next;
        head->next = node;
        node->next = curAfterHead;
        node->prev = head;
        curAfterHead->prev = node;

    }

    LRUCache(int capacity) { 
        //constructoe 
        capacity_ = capacity;
        //mpp.clear();
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;

       
        
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end()){
            return -1;
        }
        Node* node = mpp[key];
        deleteNode(node);
        InsertAfterHead(node);


        return node->val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            Node* node = mpp[key];
            node->val = value;
            deleteNode(node);
            InsertAfterHead(node);


        }
        else{
            if(mpp.size()==capacity_){
                Node* lru = tail->prev;
                mpp.erase(lru->key);
                deleteNode(lru);
                delete lru;

            }
            Node* node = new Node(key,value);
            mpp[key] = node;
            InsertAfterHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */