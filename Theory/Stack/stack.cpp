#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void push(int stack[], int n, int x);
void display(int stack[], int n);
int pop(int stack[], int n);
int top = -1;
int x;
int n;
void push(int stack[], int n, int x)
{
    if (top == n - 1)
        cout << "Overflow" << endl;
    else
        stack[++top] = x;
}
int pop(int stack[], int n)
{
    if (top == -1)
    {
        cout << "Underflow" << endl;
        return INT_MIN ;
    }
    else
        return stack[top--];
}
void display(int stack[], int n)
{
    for (int i = top; i > -1; i--)
        cout << stack[i] << " ";
        cout<<endl;
}
int main()
{
    cout << "Enter the size of stack" << endl;
    cin >> n;
    int stack[n];
    int choice;
    do
    {

        cout << "1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter number to push" << endl;
            cin >> x;
            push(stack, n, x);
            break;
    
         case 2:
    x = pop(stack, n);
    if (x != INT_MIN)
        cout << "Popped Element: " << x << endl;
    // No need for else — pop() already prints "Underflow"
    break;
        case 3:
            display(stack, n);
            break;
        case 4:
            cout << "Exiting ....";
            break;
        default:
            cout << endl
                 << "You have entered the wrong choice";
        }

    } while (choice != 4);
}