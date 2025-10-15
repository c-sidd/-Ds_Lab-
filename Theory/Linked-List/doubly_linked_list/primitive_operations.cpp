#include<iostream>
using namespace std;
struct node* get_node(int x);
void insert_begin(int x);
void insert_mid(int x,int key);
void insert_end(int x);
int del_begin();
int del_mid(int key);
int del_end();
int count_nodes();
bool search(int key);
void display();
#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
    int data;
    node* prev;
    node* next;
};

node* start = NULL;

// Create a new node
node* get_node(int x) {
    node* p = (node*)malloc(sizeof(node));
    p->data = x;
    p->prev = NULL;
    p->next = NULL;
    return p;
}

// 1️⃣ Insert at the beginning
void insert_begin(int x) {
    node* p = get_node(x);
    if (start == NULL) {
        start = p;
        return;
    }
    p->next = start;
    start->prev = p;
    start = p;
}

// 2️⃣ Insert at the end
void insert_end(int x) {
    node* p = get_node(x);
    if (start == NULL) {
        start = p;
        return;
    }
    node* temp = start;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = p;
    p->prev = temp;
}

// 3️⃣ Insert after a specific key
void insert_after(int key, int x) {
    if (start == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    node* temp = start;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Key not found!" << endl;
        return;
    }

    node* p = get_node(x);
    p->next = temp->next;
    p->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = p;
    temp->next = p;
}

// 4️⃣ Display forward
void display_forward() {
    node* temp = start;
    cout << "Forward: ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// 5️⃣ Display backward
void display_backward() {
    if (start == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    node* temp = start;
    while (temp->next != NULL)
        temp = temp->next;

    cout << "Backward: ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

// 6️⃣ Delete from beginning
int del_begin() {
    if (start == NULL) {
        cout << "List is empty!" << endl;
        return -1;
    }
    node* p = start;
    int val = p->data;
    start = p->next;

    if (start != NULL)
        start->prev = NULL;

    free(p);
    return val;
}

// 7️⃣ Delete from end
int del_end() {
    if (start == NULL) {
        cout << "List is empty!" << endl;
        return -1;
    }
    node* temp = start;
    while (temp->next != NULL)
        temp = temp->next;

    int val = temp->data;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        start = NULL; // only one node

    free(temp);
    return val;
}

// 8️⃣ Delete by key (middle)
int del_mid(int key) {
    if (start == NULL) {
        cout << "List is empty!" << endl;
        return -1;
    }

    node* temp = start;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Key not found!" << endl;
        return -1;
    }

    int val = temp->data;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        start = temp->next; // if first node

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    return val;
}

// 9️⃣ Search for a key
bool search(int key) {
    node* temp = start;
    while (temp != NULL) {
        if (temp->data == key)
            return true;
        temp = temp->next;
    }
    return false;
}

// 🔟 Count total nodes
int count_nodes() {
    int count = 0;
    node* temp = start;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// 🧪 Main Function for Testing
int main() {
    insert_end(10);
    insert_end(20);
    insert_end(30);
    insert_begin(5);
    insert_after(20, 25);

    display_forward();
    display_backward();

    cout << del_begin() << " deleted from beginning" << endl;
    cout << del_mid(25) << " deleted from middle" << endl;
    cout << del_end() << " deleted from end" << endl;

    display_forward();

    cout << "Total nodes: " << count_nodes() << endl;
    cout << (search(20) ? "20 Found" : "20 Not Found") << endl;
    cout << (search(100) ? "100 Found" : "100 Not Found") << endl;

    return 0;
}
