#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *creating_node()
{
    struct node *newnode = (struct node *)(malloc(sizeof(struct node)));

    cin >> newnode->data;
    newnode->next = NULL;
    return newnode;
}
void inserting_data(struct node *p, int n)

{
    cout << "Enter the data of node 1" << endl;
    p = creating_node();
    struct node *temp;
    temp = p;
    for (int i = 1; i < n; i++)
    {
        cout << "Enter the data of node " << i + 1 << endl;
        temp->next = creating_node();
        temp = temp->next;
    }
    temp->next = NULL;
    head = p;
}
void traversing(struct node *p)
{
    struct node *temp;
    temp = p;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    int n;
    cout << "Enter the number of nodes you want to create" << endl;
    cin >> n;
    struct node *p;
    inserting_data(p, n);
    char choice;
    do
    {
        cout << "What do you want to do ?" << endl;
        cout << "1. Traversing the linked list" << endl;
        cout << "2. adding a node at the end of linked list" << endl;
        cout << "3. adding a node at the beginning of linked list" << endl;
        cout << "4. adding a node at a given position of linked list" << endl;
        cin >> choice;
        switch (choice)
        {
        case '1':
            traversing(head);
            break;
        case '2':
            cout << "Adding a node at the end of linked list" << endl;
            break;

        case '3':
            cout << "Adding a node at the beginning of linked list" << endl;
            break;
        case '4':
            cout << "Adding a node at a given position of linked list" << endl;
            break;
        case '0':
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != '0');
    


}
