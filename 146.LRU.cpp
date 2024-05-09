class LRUCache {
public:
    class Node{
        public:
            int value;
            Node* prev;
            Node* next;
            int key;
            Node (int key,int value){
                this->key = key;
                this->value=value;
                this->prev=nullptr;
                this->next=nullptr;
            }
    } ;
    int get(int key) {
        if(cache.find(key)!=cache.end())
        {
            Node* n=cache[key];
            del(n);
            add(n);
            return n->value;
        }
        else
        {
            return -1;
        }
    }
    LRUCache(int capacity) {
        cap = capacity;
        head->next=tail;
        tail->prev=head;
    }
    void put(int key, int value) {
        if(cache.find(key)!=cache.end())
        {
            Node * t = cache[key];
            t->value=value;
            del(t);
            add(t);
        }
        else if(cache.size()<cap)
        {
            Node *t = new Node(key,value);
            cache[key]=t;
            add(t);
        }
        else
        {
            int old_key = tail->prev->key;
            cache.erase(old_key);
            del((tail->prev));
            Node *t = new Node(key,value);
            cache[key]=t;
            add(t);
        }
    }
    void add(Node* temp){
        temp->next=head->next;
        temp->prev=head;
        head->next=temp;
        temp->next->prev=temp;
    }
    void del(Node* temp){
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;
    }
    unordered_map<int,Node*> cache;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    int cap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */