typedef struct Node{
    int val;
    struct Node* next;
}Node;


typedef struct {
    int size;
    Node* dummyHead;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->size=0;
    obj->dummyHead=(Node*)malloc(sizeof(Node));
    obj->dummyHead->next=NULL;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if(index<0||index>=obj->size){
        return -1;
    }
    Node* cur =obj->dummyHead->next;
    for(int i=0;i<index;i++){
        cur=cur->next;
    }
    return cur->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val=val;
    newNode->next=obj->dummyHead->next;
    obj->dummyHead->next=newNode;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val=val;
    newNode->next=NULL;
    Node* cur = obj->dummyHead;
    while(cur->next!=NULL){
        cur=cur->next;
    }
    cur->next=newNode;
    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if(index<0||index>obj->size){
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val=val;
    Node* cur = obj->dummyHead;
    for(int i=0;i<index;i++){
        cur=cur->next;
    }
    newNode->next=cur->next;
    cur->next=newNode;
    obj->size++;

}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if(index<0||index>=obj->size){
        return;
    }
    Node* cur = obj->dummyHead;
    for(int i=0;i<index;i++){
        cur=cur->next;
    }
    Node* temp = cur->next;
    cur->next=cur->next->next;
    free(temp);
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    Node* cur =obj->dummyHead;
    while(cur != NULL){
        Node* temp = cur->next;
        free(cur);
        cur = temp;
    }
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/
