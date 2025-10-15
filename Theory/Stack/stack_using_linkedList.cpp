#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *next;
};
struct node * start = NULL;

struct node * get_node(int x){
      struct node *p = (struct node *)malloc(sizeof(struct node));
      p ->data = x;
      p ->next = NULL;
        return p;

}
void push(int x)
{
    struct node * p = get_node(x);
    p -> next = start;
    start = p;

}

void pop(){
    if(start == NULL){
        cout<<"Underflow"<<endl;
        return;
    }
    else{
     struct node * p = start;
     start = p -> next;
    cout << p -> data;
    free (p);
      }
    
}
void peek(){
    if(start == NULL){
        cout<<"Underflow"<<endl;
        return;
    }
    else{
     struct node * p = start;
     cout << p -> data;
      }

}
void display(){
    struct node * p = start;
    if(start == NULL){
        cout<<"Underflow"<<endl;
        return;
    }
    while(p != NULL){
        cout << p -> data << " ";
        p = p -> next;
    }
    cout << endl;
}



int main()
{
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
    peek();
    return 0;

}