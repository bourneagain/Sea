#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    
    Node(int data, Node *next) {
        this->data = data;
        this->next = next;
    }
    
    ~Node() {}
};

typedef Node* pNode;

void print(Node *head){
    while(head!=NULL){
        cout << head->data << ",";
        head=head->next;
    }
}

Node *partition(Node *head, int target){

    pNode beforeEnd{};
    pNode beforeStart{};
    pNode afterStart{};
    pNode afterEnd{};
    
    while(head!=nullptr){
        pNode next=head->next;
        head->next=nullptr;
        if (head->data < target){
            if(beforeStart == nullptr){
                beforeStart=head;
                beforeEnd=beforeStart;
            }else{
                beforeEnd->next=head;
                beforeEnd=head;
            }
        }else{
            if(afterStart == nullptr){
                afterStart=head;
                afterEnd=afterStart;
            }else{
                afterEnd->next=head;
                afterEnd=head;
            }
        }
        head=next;
    }
    beforeEnd->next=afterStart;
    return beforeStart;
}
int main(){
    Node *list = new Node(4, new Node(13, new Node (20, new Node(1, new Node(-2, nullptr)))));
    print(list);
    cout << endl;
    print(partition(list,4));
}
