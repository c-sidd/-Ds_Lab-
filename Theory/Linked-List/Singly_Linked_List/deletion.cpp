#include <iostream>
using namespace std;
void insert_begin(int x);
void insert_mid(int x,int key);
void insert_end(int x);
int del_begin();
int del_mid(int key);
int del_end();
struct node* get_node(int x);
struct node{
    int data;
    node* next;
};
struct node * start = NULL;
node* get_node(int x)
{
    node * p = (node *)malloc(sizeof(node));
    p -> data = x;
    p -> next = NULL;
    return p;
}
void insert_begin(int x)
{
    node* p = get_node(x);
    p -> next = start;
    start = p;

}
void insert_mid(int x,int key)
{
    node * temp = start;
   
    while(temp ->data != key && temp!=NULL)
    {
        temp = temp -> next;
    }
    if (temp == NULL)
    {
        cout << "Key not found"<<endl;
    }
    else
     {
        node * p = get_node(x);
        p -> next = temp -> next;
        temp -> next = p;
     }
}
void insert_end(int x)
{
    node * p = start;
    if (start == NULL) {
        start = get_node(x);
        return;
    }
    while(p->next!= NULL)
    {
        p = p -> next;
    }
    p-> next = get_node(x);


    
}

void display() {
    node* temp = start;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int del_begin(){
    if (start == NULL){
    cout <<"Linked List is empty"<<endl;
     return -1 ;
    }
        node * p = start;
        start = p->next;
        int temp = p->data;
        free(p);
        return temp;
    

}
int del_mid(int key){

    node * p = start;
    while(p!=NULL & p->data != key)
    {
        p = p->next;
    }
    if(p==NULL){
    cout <<"Key not found"<<endl;
      return -1;}
    node * temp = p->next;
    p -> next = temp ->next;
    return temp-> data;

    

    
}
int del_end(){
     node * p = start;
     node * q = NULL;
     while(p->next != NULL)
     {
        q = p;
        p = p ->next;

     }
        if (q != NULL) {
            q->next = NULL;}
        
        int temp = p->data;
        free(p);
        return temp;
 }

int main() {
    insert_end(10);
    insert_end(20);
    insert_end(30);
    insert_end(40);
    insert_end(50);
    display();

    cout << del_begin() << " deleted from the beginning" << endl;
    display();

    cout << del_mid(30) << " deleted from the middle" << endl;
    display();

    cout << del_end() << " deleted from the end" << endl;
    display();

    return 0;
}
