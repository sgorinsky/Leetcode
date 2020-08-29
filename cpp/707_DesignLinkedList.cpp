class MyLinkedList {
    struct ListNode {
        int val;
        ListNode* prev;
        ListNode* next;
        
        ListNode(int v) {
            val = v;
            prev = NULL;
            next = NULL;
        }
    };
public:
    ListNode* head;
    ListNode* tail;
    int size;
    
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    
    ListNode* getNode(int index) {
        if (index < 0 || index >= size) {
            return NULL;
        } else if (index == 0) {
            return head;
        } else if (index == size-1) {
            return tail;
        }
        
        ListNode* curr = head;
        for (int i = 0; i < index; ++i)
            curr = curr->next;
        
        return curr;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        ListNode* curr = getNode(index);
        return curr != NULL ? curr->val : -1;
    }
    
    void printNodes() {
        ListNode* curr = head;
        int i = 0;
        while (curr) {
            cout << "i: " << i++ << ", node: " << curr->val << endl;
            curr = curr->next;
        }
    }
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        if (size == 0) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        ++size;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        if (size == 0) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        ++size;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) {
            return;
        } else if (index == size) {
            addAtTail(val);
        } else if (index == 0) {
            addAtHead(val);
        } else {
            ListNode* newNode = new ListNode(val);
            ListNode* entry = getNode(index-1);
            ListNode* next = entry->next;
            
            entry->next = newNode;
            newNode->prev = entry;
            newNode->next = next;
            next->prev = newNode;
            ++size;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        } else if (size == 1) {
            head = NULL;
            tail = NULL;
        } else if (index == size-1) {
            tail = tail->prev;
            tail->next = NULL;
        } else if (index == 0) {
            head = head->next;
            head->prev = NULL;
        } else {
            ListNode* prev = getNode(index-1);
            ListNode* next = prev->next->next;
            prev->next = next;
            next->prev = prev;
        }
        --size;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

class MyLinkedList {
private:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int v) : val(v), next(nullptr) {}
    };

public:
    ListNode* head;
    int size;
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }
    
    // for debugging
    void printNodes() {
        ListNode* curr = head;
        int i = 0;
        cout << "Printing nodes" << endl;
        while (curr) {
            cout << i << ": " << curr->val << endl;
            curr = curr->next;
            ++i;
        }
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= size)
            return -1;
        int i = 0;
        ListNode* curr = head;
        while (curr) {
            if (i == index)
                return curr->val;
            
            curr = curr->next;
            ++i;
        }
        return curr->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* h = new ListNode(val);
        h->next = head;
        head = h;
        ++size;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if (size == 0) {
            addAtHead(val);
        } else {
            ListNode* t = new ListNode(val);
            ListNode* curr = head;
            while (curr) {
                if (curr->next == nullptr) {
                    curr->next = t;
                    ++size;
                    break;
                }
                curr = curr->next;
            }
        }
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size) {
            return;
        } else if (index == size) {
            addAtTail(val);
        } else if (index == 0) {
            addAtHead(val);
        } else {
            int i = 0;
            ListNode* curr = head;
            ListNode* prev;
            while (curr) {
                if (i == index) {
                    ListNode* node = new ListNode(val);
                    prev->next = node;
                    node->next = curr;
                    break;
                }
                ListNode* temp = curr;
                curr = curr->next;
                prev = temp;
                ++i;
            }
            ++size;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index == 0 && head != nullptr) {
            head = head->next;
        } else if (index < size) {
            int i = 0;
            ListNode* curr = head;
            ListNode* prev;
            while (curr) {
                if (i == index) {
                    prev->next = curr->next;
                    break;
                }
                ListNode* temp = curr;
                curr = curr->next;
                prev = temp;
                ++i;
            }
            --size;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
