#include <iostream>
using namespace std;
void insert_begin(int x);
void insert_mid(int x,int key);
void insert_end(int x);
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

int main() {
    insert_end(10);
    insert_end(20);
    insert_end(30);
    insert_begin(5);
    insert_mid(25, 20);
    display();
    return 0;
}