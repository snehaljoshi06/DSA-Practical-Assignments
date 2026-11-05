#include <iostream>
using namespace std;

int s1[100], s2[100];
int top1 = -1, top2 = -1;
void enqueue()
{
    int x;
    if (top1 == 99) { cout << "Queue Overflow.\n"; return; }
    cout << "Enter element: "; cin >> x;
    s1[++top1] = x;
    cout << "Element inserted successfully.\n";
}
void dequeue()
{
    if (top1 == -1 && top2 == -1) { cout << "Queue Underflow.\n"; return; }
    if (top2 == -1)
        while (top1 != -1) s2[++top2] = s1[top1--];
    cout << "Deleted element: " << s2[top2--] << endl;
}
void display()
{
    if (top1 == -1 && top2 == -1) { cout << "Queue is empty.\n"; return; }
    cout << "Queue elements:\n";
    for (int i = top2; i >= 0; i--) cout << s2[i] << endl;
    for (int i = 0; i <= top1; i++) cout << s1[i] << endl;
}
int main()
{
    int choice;
    do
    {
        cout << "\n--- Queue Using Two Stacks ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter choice: "; cin >> choice;
        if (choice == 1) enqueue();
        else if (choice == 2) dequeue();
        else if (choice == 3) display();
        else if (choice == 4) cout << "Program Ended.\n";
        else cout << "Invalid choice.\n";
    } while (choice != 4);
    return 0;
}