// singly linked list

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        // cout << "I am inside default constructor" << endl;
        this->next = NULL;
    }

    Node(int data)
    {
        // cout << "I am inside parameterized constructor" << endl;
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        cout<<"Destructor called for: "<<this->data<<endl;
    }
};

void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void insertAtHead(Node* &head, Node* &tail, int data){
    if(head == NULL){
        // empty LL
        // create new node
        Node* newNode = new Node(data);
        // update head
        head = newNode;
        tail = newNode;
    }
    else{
        // non-empty LL
        // create a new node
        Node* newNode = new Node(data);
        // attach new node to head node
        newNode -> next = head;
        // update head
        head = newNode;
    }
}

void insertAtTail(Node* &head, Node* &tail, int data){
    if(head == NULL){
        // empty LL
        // create new node
        Node* newNode = new Node(data);
        // single node hai entire list me, that's why head and tail ko ispar point karwado
        head = newNode;
        tail = newNode;
    }
    else{
        // non empty LL
        // create new node
        Node* newNode = new Node(data);
        // attach new node to tail node
        tail->next = newNode;
        // updata tail
        tail = newNode;
    }
}

void createTail(Node* &head, Node* &tail){
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    // jab ye loop khatm hogya hoga then apka temp wala pointer last node pe khada hoga tab tail = temp karke, tail ko last node par le aao
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int data, int position){
    // assumption: position ki value [1 to length+1] tak
    int length = getLength(head);

    if(position == 1){
        insertAtHead(head, tail, data);
    }
    else if(position == length+1){
        insertAtTail(head, tail, data);
    }
    else{
        // insert at middle of linked list
        // create a new node
        Node* newNode = new Node(data);
        // traverse prev // curr to position
        Node* prev = NULL;
        Node* curr = head;
        while(position != 1){
            prev = curr;
            curr = curr->next;
            position--;
        }
        // attach prev to newNode
        prev->next = newNode;
        // attach newNode to curr
        newNode->next = curr;
    }
}

void deleteNode(Node* &head, Node* &tail, int position){
    // empty list
    if(head == NULL){
        cout<<"Cannot delete, coz LL is empty"<<endl;
        return;
    }
    if(head == tail){
        // single element
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }

    int len = getLength(head);
    // delete from head
    if(position == 1){
        // delete first node
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }
    else if(position == len){
        // delete last node
        Node* prev = head;
        while(prev -> next != tail){
            prev = prev->next;
        }
        prev->next = NULL;
        // delete node
        delete tail;
        // update tail
        tail = prev;
    }
    else{
        // delete node in middle
        // set prev/curr pointer
        Node* prev = NULL;
        Node* curr = head;
        while(position != 1){
            prev = curr;
            curr = curr->next;
            position--;
        }
        // add curr->next in prev->next
        prev->next = curr->next;
        // isolate node
        curr->next = NULL;
        // delete node
        delete curr;
    }
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 50);
    // insertAtHead(head, tail, 40);
    // insertAtHead(head, tail, 30);
    // insertAtHead(head, tail, 20);
    // insertAtHead(head, tail, 10);
    printLL(head);
    cout<<endl;

    cout<<"Before-> length of LL is: "<<getLength(head)<<endl;
    // cout<<"Before->head-> "<<head->data <<endl;
    cout<<"Before tail -> "<<tail->data<<endl;
    deleteNode(head, tail, 1);
    cout<<"After length of LL is: "<<getLength(head)<<endl;
    cout<<"After tail -> "<<tail->data<<endl;
    // if(head == NULL){
    //     cout<<"head is null"<<endl;
    // }

    // insertAtPosition(head, tail, 5, 1);
    // insertAtPosition(head, tail, 100, 4);
    // insertAtPosition(head, tail, 1000, 51);
    // printLL(head);

    // deleteNode(head, tail, 1);
    // printLL(head);
    // cout<<endl;

    return 0;
}