#include <iostream>
#include <vector>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int data1,Node* next1=nullptr){
        data=data1;
        next=next1;
    }
};

void print(Node*head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

Node* insertatstart(Node*head, int value){
    Node*temp=new Node(value,head);
    return temp;
}

Node*insertatend(Node*head,int value){
     Node* newnode= new Node(value);
    if(head==NULL){
        return newnode;
    }
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    return head;
}

Node*insertatk(Node*head,int k,int ele){
    Node* newnode= new Node(ele);
    if(head==NULL){
        if(k==1) return new Node(ele);
        else return nullptr;
    }
    if(k==1){
        Node*temp = new Node(ele,head);
        return temp;
    }
    int count=0; Node * temp=head;
    while(temp!=NULL){
        count++;
        if(count==k-1){
            Node*newnode= new Node(ele);
            newnode->next=temp->next;
            temp->next=newnode;
            break;
        }
        temp=temp->next;
    }
    return head;
}

Node* convertArr2LL(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node*temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }return head;
}

int main(){
    vector<int>arr={1,2,3,4};
    Node*head=convertArr2LL(arr);
    cout<<"original list: ";
    print(head);

    head=insertatstart(head,0);
    cout<<"after insertion at start: ";
    print(head);

     head=insertatend(head,5);
    cout<<"after insertion at end: ";
    print(head);

    head=insertatk(head,5,6);
    cout<<"after insertion at kth position : ";
    print(head);


}

