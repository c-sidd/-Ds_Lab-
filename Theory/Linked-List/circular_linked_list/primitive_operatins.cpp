
using namespace std;
void insert_begin(int x);
void insert_mid(int x,int key);
void insert_end(int x);
#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
    int data;
    node* next;
};

node* start = NULL;

// Create a new node
node* get_node(int x) {
    node* p = (node*)malloc(sizeof(node));
    p->data = x;
    p->next = NULL;
    return p;
}

// 1️⃣ Insert at beginning
void insert_begin(int x) {
    node* p = get_node(x);
    if (start == NULL) {
        start = p;
        p->next = start;
        return;
    }

    node* temp = start;
    while (temp->next != start)
        temp = temp->next;

    p->next = start;
    start = p;
    temp->next = start; // maintain circular link
}

// 2️⃣ Insert at end
void insert_end(int x) {
    node* p = get_node(x);
    if (start == NULL) {
        start = p;
        p->next = start;
        return;
    }

    node* temp = start;
    while (temp->next != start)
        temp = temp->next;

    temp->next = p;
    p->next = start;
}

// 3️⃣ Insert after a key
void insert_after(int key, int x) {
    if (start == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    node* temp = start;
    do {
        if (temp->data == key) {
            node* p = get_node(x);
            p->next = temp->next;
            temp->next = p;
            return;
        }
        temp = temp->next;
    } while (temp != start);

    cout << "Key not found!" << endl;
}

// 4️⃣ Display list
void display() {
    if (start == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    node* temp = start;
    cout << "Circular List: ";
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != start);
    cout << "(back to start)" << endl;
}

// 5️⃣ Delete from beginning
int del_begin() {
    if (start == NULL) {
        cout << "List is empty!" << endl;
        return -1;
    }

    int val = start->data;

    if (start->next == start) { // Only one node
        free(start);
        start = NULL;
        return val;
    }

    node* temp = start;
    while (temp->next != start)
        temp = temp->next;

    node* to_delete = start;
    start = start->next;
    temp->next = start;
    free(to_delete);

    return val;
}

// 6️⃣ Delete from end
int del_end() {
    if (start == NULL) {
        cout << "List is empty!" << endl;
        return -1;
    }

    node* temp = start;
    node* prev = NULL;

    while (temp->next != start) {
        prev = temp;
        temp = temp->next;
    }

    int val = temp->data;
    if (prev != NULL) {
        prev->next = start;
    } else {
        start = NULL; // only one node
    }

    free(temp);
    return val;
}

// 7️⃣ Delete by key
int del_mid(int key) {
    if (start == NULL) {
        cout << "List is empty!" << endl;
        return -1;
    }

    node* temp = start;
    node* prev = NULL;

    do {
        if (temp->data == key) {
            int val = temp->data;
            if (temp == start) {
                return del_begin();
            } else {
                prev->next = temp->next;
                free(temp);
                return val;
            }
        }
        prev = temp;
        temp = temp->next;
    } while (temp != start);

    cout << "Key not found!" << endl;
    return -1;
}

// 8️⃣ Search for key
bool search(int key) {
    if (start == NULL)
        return false;

    node* temp = start;
    do {
        if (temp->data == key)
            return true;
        temp = temp->next;
    } while (temp != start);

    return false;
}

// 9️⃣ Count total nodes
int count_nodes() {
    if (start == NULL)
        return 0;

    int count = 0;
    node* temp = start;
    do {
        count++;
        temp = temp->next;
    } while (temp != start);
    return count;
}

// 🧪 Main function for testing
int main() {
    insert_end(10);
    insert_end(20);
    insert_end(30);
    insert_begin(5);
    insert_after(20, 25);

    display();

    cout << del_begin() << " deleted from beginning" << endl;
    cout << del_mid(25) << " deleted from middle" << endl;
    cout << del_end() << " deleted from end" << endl;

    display();

    cout << "Total nodes: " << count_nodes() << endl;
    cout << (search(20) ? "20 Found" : "20 Not Found") << endl;
    cout << (search(100) ? "100 Found" : "100 Not Found") << endl;

    return 0;
}
