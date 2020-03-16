struct DLinkedNode {
	int key;
	int value;
	DLinkedNode *prev;
	DLinkedNode *next;
};

class LRUCache {
private:
    //Variables
    unordered_map<int,DLinkedNode*> m; //Key, Value
    int count;
    int capacity;
    DLinkedNode *head, *tail;

    //Functions

    /* Always add the new node right after head */
    void addNode(DLinkedNode* node){
        //Fit inside first
        node->prev = head;
        node->next = head->next;

        node->prev->next = node;
        node->next->prev = node;
    }

    /** Remove an existing node from the linked list */
    void removeNode(DLinkedNode* node){
        DLinkedNode *prevNode = node->prev;
        DLinkedNode *nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    /** Move certain node in between to the head. */
    void moveToHead(DLinkedNode* node){
        removeNode(node);
        addNode(node);
    }

public:
    LRUCache(int _capacity) {
        count=0;
        capacity = _capacity;

        head = new DLinkedNode();
        head->prev = NULL;

        tail = new DLinkedNode();
        tail->next = NULL;

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {

        //If Not in map
        if(m.find(key)==m.end())
            return -1;

        DLinkedNode *node = m[key];

        // Move the accessed node to the head
        moveToHead(node);

        return node->value;

    }

    void put(int key, int value) {

        //If found in map
        if(m.find(key)!=m.end())
        {
            //Update the value and move it ahead
            m[key]->value = value;
            moveToHead(m[key]);
            return;
        }

        //Else make a New Node
        DLinkedNode *newNode = new DLinkedNode();
        newNode->key = key;
        newNode->value = value;

        m[key] = newNode;
        addNode(newNode);

        ++count;

        //Remove the element before tail
        if(count > capacity){
            DLinkedNode *lastNode = tail->prev;

            m.erase(lastNode->key);
            removeNode(lastNode);
        }


    }
};
