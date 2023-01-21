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

    //functions
    //Push_back

    void insert_back(int key)
    {
        Node* ptr= new Node(key);
        if(head==NULL)
            head= ptr;
        else{
            Node* move=head;
            while(move->next!=NULL)
                move= move->next;
            
            move->next= ptr;
        }
    }

    void insert_front(int key)
    {
        Node* ptr= new Node(key);
        ptr->next= head;

        head= ptr;
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

int main()
{
    //linked list codes
    List ls;
    ls.insert_back(14);
    ls.insert_back(24);
    ls.insert_back(34);
    ls.insert_back(44);
    ls.insert_back(54);
    ls.print_list();
}