#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    int e;
    int c;
    node * next;
};

node * get_node(int c,int e)
{
    node * p = (node *)(malloc(sizeof(node)));
    p->c = c;
    p->e = e;
    p->next = NULL;
    return p;
}

node * ins_poly(node * head,int c, int e){
    node * p = get_node(c,e);
    if (head == NULL)
        return p;
    node * temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = p;
    return head;
}

void display(node* head) {
    if (head == NULL) {
        cout << "0\n";
        return;
    }
    node* temp = head;
    while (temp != NULL) {
        cout << temp->c << "x^" << temp->e;
        if (temp->next != NULL)
            cout << " + ";
        temp = temp->next;
    }
    cout << endl;
}

node * multiply_poly(node * p1,node * p2)
{
    if (p1 == NULL || p2 == NULL)
        return NULL;
    int hash[1000] = {0};
    int maxexp = 0;
    for(node* p = p1; p != NULL; p = p->next)
    {
        for(node* q = p2; q != NULL; q = q->next)
        {
            int expo = p->e + q->e;
            int coef = p->c * q->c;
            hash[expo] += coef;
            if(expo > maxexp)
                maxexp = expo;
        }
    }
    node * result = NULL;
    for(int i = maxexp; i >= 0; i--)
    {
        if(hash[i] != 0)
            result = ins_poly(result, hash[i], i);
    }
    return result;
}

int main() {
    node* poly1 = NULL;
    node* poly2 = NULL;

    poly1 = ins_poly(poly1, 3, 2);
    poly1 = ins_poly(poly1, 2, 0);

    poly2 = ins_poly(poly2, 4, 1);
    poly2 = ins_poly(poly2, 1, 0);

    cout << "Polynomial 1: ";
    display(poly1);
    cout << "Polynomial 2: ";
    display(poly2);

    node* product = multiply_poly(poly1, poly2);

    cout << "Product = ";
    display(product);

    return 0;
}
