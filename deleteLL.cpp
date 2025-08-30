#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    // Constructor with default value for next
    Node(int data1, Node* next1 = nullptr) {
        data = data1;
        next = next1;
    }
};

void print(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* deletehead(Node* head) {
    if (head == nullptr) return nullptr;
    Node* temp = head;
    head = head->next;
    delete temp;   // ✅ use delete instead of free
    return head;
}

Node* deletetail(Node* head){
    if(head==NULL||head->next==NULL){
        return NULL;
    }
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete(temp->next);
    temp->next=nullptr;
    return head;
}


Node* deletek(Node*head, int k){
    if(head==NULL)return head;
    if(k==1){
        Node*temp=head;
        head=head->next;
        delete(temp);
        return head;
    }
    int count=0;Node*temp=head;
    Node* prev=nullptr;
    while(temp!=NULL){
        count++;
        if(count==k){
            prev->next=prev->next->next;
            delete(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }return head;
}

Node* deleteele(Node*head, int ele){
    if(head==NULL)return head;
    if(head->data==ele){
        Node*temp=head;
        head=head->next;
        delete(temp);
        return head;
    }
    Node*temp=head;
    Node* prev=nullptr;
    while(temp!=NULL){
        if(temp->data==ele){
            prev->next=prev->next->next;
            delete(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }return head;
}

Node* convertArr2LL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int main() {
    vector<int> arr = {2, 3, 4, 5,6,7};
    Node* head = convertArr2LL(arr);

    cout << "Original list: ";
    print(head);

    head = deletehead(head);
    cout << "After deleting head: ";
    print(head);

    head=deletetail(head);
    cout<<"after deleting tail: ";
    print(head);

    head= deletek(head,3);
    cout<<"after deleting kth position element : ";
    print(head);

    head=deleteele(head,3);
    cout<<"after deleting the value: ";
    print(head);

    return 0;
}
