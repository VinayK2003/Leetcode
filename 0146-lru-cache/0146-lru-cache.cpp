class LRUCache {
public:

    class Node{
        public:
            int data ,key;
            Node *next,*prev;

            Node(int k, int v ){
                key=k;
                data=v;
                prev=next=NULL;
            }
    };
    int cap;

    Node* head= new Node(-1,-1);
    Node* tail= new Node(-1,-1);

    unordered_map<int,Node*>mp;

    LRUCache(int capacity) {
           head->next=tail;
           tail->prev=head;
           cap=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return-1;
        }
        int x=mp[key]->data;
        DeleteNode(mp[key]);
        insertAtBegin(mp[key]);
        return x;
    }

    void insertAtBegin( Node *node){
        Node* nextnode=head->next;
        head->next=node;
        node->prev=head;
        node->next=nextnode;
        nextnode->prev=node;
    }

    void DeleteNode( Node* node){
        Node* nextnode=node->next;
        Node* prevnode=node->prev;

        prevnode->next=nextnode;
        nextnode->prev=prevnode;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            mp[key]->data=value;
            DeleteNode(mp[key]);
            insertAtBegin(mp[key]);
        }
        else{
            if(mp.size()==cap){
                int k= tail->prev->key;
                mp.erase(k);
                DeleteNode(tail->prev);
            }
                Node * node= new Node(key,value);
                mp[key]=node;
                insertAtBegin(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */