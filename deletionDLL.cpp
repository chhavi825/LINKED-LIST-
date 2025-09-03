#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* back;

    // Constructor with default value for next
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back=back1;
    }
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;

    }
};


Node* convertArr2LL(vector<int>&arr){
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<arr.size();i++){
        Node*temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }return head;
}
void print(Node*head){
    while(head!=NULL){
        cout<<head->data;
        head=head->next;
    }
}

Node* deletehead(Node*head){
    if(head==NULL||head->next==NULL){
        return NULL;
    }
    Node*prev=head;
    head=head->next;
    head->back=nullptr;
    prev->next=nullptr;
    delete prev;
    return head;

}

Node* deletetail(Node*head){
    if(head==NULL||head->next==NULL){
        return NULL;
    }
    Node*tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node*newtail=tail->back;
    newtail->next=nullptr;
    tail->back=nullptr;
    delete tail;
    return head;

}

Node* deletekthelement(Node*head,int k){
    if(head==NULL){
        return NULL;
    }
    int cnt=0;
    Node*temp=head;
    while(temp!=NULL){
        cnt++;
        if(cnt==k)break;
        temp=temp->next;
    }
    Node* prev=temp->back;
    Node* front=temp->next;
    if(prev==NULL && front==NULL){
        delete (temp);
        return NULL;
    }
    else if(prev==NULL){
        deletehead(head);
        return head;
    }
    else if(front==NULL){
        deletetail(head);
        return head;
    }
    prev->next=front;
    front->back=prev;
    temp->next=nullptr;
    temp->back=nullptr;
    delete(temp);
    return head;


}

Node* deletenode(Node*temp){
    Node*prev=temp->back;
    Node*front=temp->next;
    if(front==NULL){
        prev->next=nullptr;
        delete(temp);
    }
    prev->next=front;
    front->back=prev;
    temp->next=temp->back=nullptr;
    delete(temp);
}


int main(){
    vector<int>arr={1,2,3,4,5,6,7}; 
    Node* head=convertArr2LL(arr);
    print(head);

    cout<<endl;
    head=deletehead(head);
    print(head);

     cout<<endl;
    head=deletetail(head);
    print(head);

     cout<<endl;
    head=deletekthelement(head,4);
    print(head);


    cout<<endl;
    deletenode(head->next->next);
    print(head);

    return 0;
}