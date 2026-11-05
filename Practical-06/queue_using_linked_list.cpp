#include <iostream>
using namespace std;

struct Node { int data; Node* next; };
Node* front = NULL;
Node* rear = NULL;

void enqueue()
{
    int x;
    cout << "Enter element: "; cin >> x;
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    if (front == NULL) { front = newNode; rear = newNode; }
    else { rear->next = newNode; rear = newNode; }
    cout << "Element inserted successfully.\n";
}
void dequeue()
{
    if (front == NULL) { cout << "Queue Underflow.\n"; return; }
    Node* temp = front;
    cout << "Deleted element: " << front->data << endl;
    front = front->next;
    if (front == NULL) rear = NULL;
    delete temp;
}
void display()
{
    if (front == NULL) { cout << "Queue is empty.\n"; return; }
    Node* temp = front;
    cout << "Queue elements:\n";
    while (temp != NULL) { cout << temp->data << endl; temp = temp->next; }
}
int main()
{
    int choice;
    do
    {
        cout << "\n--- Queue Using Linked List ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter choice: "; cin >> choice;
        if (choice == 1) enqueue();
        else if (choice == 2) dequeue();
        else if (choice == 3) display();
        else if (choice == 4) cout << "Program Ended.\n";
        else cout << "Invalid choice.\n";
    } while (choice != 4);
    while (front != NULL)
    {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
    rear = NULL;
    return 0;
}