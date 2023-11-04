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

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    printLL(head);

    // insertAtPosition(head, tail, 5, 1);
    insertAtPosition(head, tail, 100, 4);
    // insertAtPosition(head, tail, 1000, 51);
    printLL(head);

    // // creation of node
    // // static creation
    // // Node a;
    // // dynamic creation
    // Node *first = new Node(10);
    // Node *second = new Node(20);
    // Node *third = new Node(30);
    // Node *fourth = new Node(40);
    // Node* fifth = new Node(50);
    // Node* tail = fifth;

    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = fifth;
    // // linked list created

    // Node *head = first;
    // cout << "Printing the entire LL: " << endl;
    // printLL(head);

    // insertAtHead(head, tail, 500);
    // printLL(head);

    // insertAtTail(head, tail, 60);
    // printLL(head);

    // cout<<"length of LL is: "<<getLength(head)<<endl;

    return 0;
}