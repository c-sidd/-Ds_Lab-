#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node* next;
};

struct node* getnode(int x) {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->data = x;
    p->next = NULL;
    return p;
}

void traverse(struct node* start) {
    struct node* p = start;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

struct node* ins_beg(struct node* start, int x) {
    struct node* p = getnode(x);
    p->next = start;
    start = p;
    return start;
}

struct node* ins_after_node(struct node* start, int x, int key) {
    struct node* q = start;
    while (q != NULL && q->data != key) {
        q = q->next;
    }
    if (q != NULL) {
        struct node* p = getnode(x);
        p->next = q->next;
        q->next = p;
    } else {
        cout << "Key not found\n";
    }
    return start;
}

struct node* ins_end(struct node* start, int y) {
    struct node* p = getnode(y);
    if (start == NULL) return p; 
    struct node* q = start;
    while (q->next != NULL) {
        q = q->next;
    }
    q->next = p;
    return start;
}

struct node* del_beg(struct node* start) {
    if (start == NULL) {
        cout << "List is empty\n";
        return NULL;
    }
    struct node* p = start;
    cout << p->data << " deleted from beginning\n";
    start = start->next;
    
    return start;
}

struct node* del_end(struct node* start) {
    if (start == NULL) {
        cout << "List is empty\n";
        return NULL;
    }
    struct node* p = start, *q = NULL;
    while (p->next != NULL) {
        q = p;
        p = p->next;
    }
    cout << p->data << " deleted from end\n";
    if (q != NULL)
        q->next = NULL;
    else
        start = NULL; 
   
    return start;
}

struct node* del_after_node(struct node* start, int key) {
    struct node* p = start;
    while (p != NULL && p->data != key) {
        p = p->next;
    }
    if (p != NULL && p->next != NULL) {
        struct node* q = p->next;
        cout << q->data << " deleted after " << key << "\n";
        p->next = q->next;
        free(q);
    } else {
        cout << "Key not found or no node to delete after key\n";
    }
    return start;
}

void searching(struct node* start, int key) {
    struct node* p = start;
    while (p != NULL) {
        if (p->data == key) {
            cout << key << " is present in the linked list\n";
            return;
        }
        p = p->next;
    }
    cout << key << " not found in the linked list\n";
}

int total_node(struct node* head) {
    int count = 0;
    struct node* p = head;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

int main() {
    struct node* head = NULL;

    head = ins_beg(head, 10);
    traverse(head);

    head = ins_beg(head, 20);
    traverse(head);

    head = ins_beg(head, 30);
    traverse(head);

    head = ins_after_node(head, 25, 20);
    traverse(head);

    head = ins_end(head, 5);
    traverse(head);

    head = del_beg(head);
    traverse(head);

    head = del_end(head);
    traverse(head);

    head = del_after_node(head, 20);
    traverse(head);

    searching(head, 25);
    cout << "Total nodes: " << total_node(head) << endl;

    return 0;
}
