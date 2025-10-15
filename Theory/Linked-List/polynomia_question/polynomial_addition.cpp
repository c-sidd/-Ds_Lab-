#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int exp;
    Node* next;
};


Node* createNode(int c, int e) {
    Node* temp = new Node();
    temp->coeff = c;
    temp->exp = e;
    temp->next = NULL;
    return temp;
}


Node* insertTerm(Node* head, int c, int e) {
    Node* newNode = createNode(c, e);

    if (head == NULL)
        return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Display the polynomial
void display(Node* head) {
    if (head == NULL) {
        cout << "0\n";
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        cout << temp->coeff << "x^" << temp->exp;
        if (temp->next != NULL)
            cout << " + ";
        temp = temp->next;
    }
    cout << endl;
}

// Add two sorted polynomials
Node* addPoly(Node* p1, Node* p2) {
    Node* result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            result = insertTerm(result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            result = insertTerm(result, p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            result = insertTerm(result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    // Copy remaining terms
    while (p1 != NULL) {
        result = insertTerm(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        result = insertTerm(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;

    int n1, n2, coeff, exp;

    cout << "Enter number of terms in first polynomial: ";
    cin >> n1;
    cout << "Enter terms (coeff exp) in descending order:\n";
    for (int i = 0; i < n1; i++) {
        cin >> coeff >> exp;
        poly1 = insertTerm(poly1, coeff, exp);
    }

    cout << "Enter number of terms in second polynomial: ";
    cin >> n2;
    cout << "Enter terms (coeff exp) in descending order:\n";
    for (int i = 0; i < n2; i++) {
        cin >> coeff >> exp;
        poly2 = insertTerm(poly2, coeff, exp);
    }

    cout << "\nPolynomial 1: ";
    display(poly1);

    cout << "Polynomial 2: ";
    display(poly2);

    Node* sum = addPoly(poly1, poly2);
    cout << "\nSum = ";
    display(sum);

    return 0;
}
