class LRUCache {
public:
    class Node{
        public:
            int key;
            int val;
            Node* prev;
            Node* next;

            Node(int key, int val){
                this->key = key;
                this->val = val;
            }
    };
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    int cap;
    unordered_map<int,Node*> mp;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void add_node(Node* newnode){
        Node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;

        head->next = newnode;
        temp->prev = newnode;
    }


    void delete_node(Node* delnode){
        Node* prevv = delnode->prev;
        Node* nextt = delnode->next;

        prevv->next = nextt;
        nextt->prev = prevv;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* res_node = mp[key];
            int ans = res_node->val;
            mp.erase(key);
            delete_node(res_node);
            add_node(res_node);

            mp[key] = head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* curr = mp[key];
            mp.erase(key);
            delete_node(curr);
        }
        if(mp.size() == cap){
            mp.erase(tail->prev->key);
            delete_node(tail->prev);
        }
        add_node(new Node(key,value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */