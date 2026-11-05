#include <iostream>
#include <queue>
using namespace std;

queue<int> q1, q2;
void push()
{
    int x;
    cout << "Enter element: "; cin >> x;
    q2.push(x);
    while (!q1.empty()) { q2.push(q1.front()); q1.pop(); }
    swap(q1, q2);
    cout << "Element pushed successfully.\n";
}
void pop()
{
    if (q1.empty()) { cout << "Stack Underflow.\n"; return; }
    cout << "Popped element: " << q1.front() << endl;
    q1.pop();
}
void display()
{
    if (q1.empty()) { cout << "Stack is empty.\n"; return; }
    queue<int> temp = q1;
    cout << "Stack elements (Top to Bottom):\n";
    while (!temp.empty()) { cout << temp.front() << endl; temp.pop(); }
}
int main()
{
    int choice;
    do
    {
        cout << "\n--- Stack Using Two Queues ---\n";
        cout << "1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << "Enter choice: "; cin >> choice;
        switch (choice)
        {
        case 1: push(); break;
        case 2: pop(); break;
        case 3: display(); break;
        case 4: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice.\n";
        }
    } while (choice != 4);
    return 0;
}