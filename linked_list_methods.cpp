#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* next;
    Node(int v){
        val=v;
        next=NULL;
    }

    Node(int v, Node* ptr){
        val=v;
        next= ptr;
    }
};

struct List
{
    Node* head= NULL;
    Node* lazy= NULL; //lazy points to the last node
    //functions
    //Push_back

    void push_back(int key)
    {
        Node* ptr= new Node(key);
        if(head==NULL){
            head= ptr;
            lazy= head;
        }
        else{
            lazy->next= ptr;
            lazy= ptr;   
        }   
    }

    void push_front(int key)
    {
        Node* ptr= new Node(key);
        ptr->next= head;

        head= ptr;
    }

    void pop_back()
    {
        //delete the last node
        if(head==NULL){
            cout<<"Underflow error\n";
            return;
        }

        if(head->next==NULL)
            head=NULL;
        else{
            Node* move= head;
            while(move->next->next)
                move=move->next;
            
            delete move->next;
            move->next=NULL;
        }
    }

    void pop_front()
    {
        if(head==NULL){
            cout<<"underflow error\n";
            return;
        }

        Node* temp= head->next;
        delete head;
        head= temp;
    }

    void print_list()
    {
        Node* move= head;
        while(move){
            cout<<move->val<<" ";
            move=move->next;
        }
        cout<<'\n';
    }
};

void print_global(Node* head)
{
    while(head){
        cout<<head->val<<" ";
        head= head->next;
    }
    cout<<'\n';
}

Node* merge_alternate(Node* l1, Node* l2, int fg=0)
{
    if(l1==NULL)
        return l2;
    if(l2==NULL)
        return l1;
    
    if(fg==0){
        l1->next= merge_alternate(l1->next,l2,1);
        return l1;
    }
    else{
        l2->next= merge_alternate(l1,l2->next,0);
        return l2;
    }
}
int main()
{
    //linked list codes
    // List ls;
    // ls.push_back(24);
    // ls.push_back(14);
    // ls.push_back(34);
    // ls.push_back(44);
    // ls.push_back(54);
    // ls.print_list();

    // ls.push_front(1);
    // ls.push_front(2);
    // ls.push_front(3);
    // ls.push_front(4);
    // ls.print_list();

    // //clone this list
    // Node* clone_head=NULL;
    // Node* org_head= ls.head;

    // if(org_head!=NULL){
    //     Node* ptr= new Node(org_head->val);
    //     clone_head= ptr;
    // }
    // Node* org_move= org_head;
    // Node* clone_move= clone_head;
    // while(org_move->next){
    //     Node* ptr= new Node(org_move->next->val);
    //     clone_move->next= ptr;

    //     clone_move= clone_move->next;
    //     org_move= org_move->next;
    // }

    // //check
    // print_global(org_head);
    // print_global(clone_head);
    

    //alternating linked lise
    List l1;
    l1.push_back(1);
    l1.push_back(3);
    l1.push_back(10);
    l1.push_back(5);
    l1.push_back(2);

    List l2;
    l2.push_back(12);
    l2.push_back(2);
    l2.push_back(24);
    l2.push_back(89);
    print_global(l1.head);
    print_global(l2.head);
    Node* res= merge_alternate(l1.head,l2.head);
    print_global(res);
    return 0;
}