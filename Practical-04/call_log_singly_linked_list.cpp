#include <iostream>
#include <string>
using namespace std;

struct CallNode
{
    string caller, number;
    float duration;
    CallNode *next;
};
CallNode *head = NULL;

void addCall()
{
    CallNode *newNode = new CallNode;
    cout << "\nEnter caller name: "; cin >> newNode->caller;
    cout << "Enter phone number: "; cin >> newNode->number;
    cout << "Enter call duration (minutes): "; cin >> newNode->duration;
    newNode->next = NULL;
    if (head == NULL) head = newNode;
    else
    {
        CallNode *ptr = head;
        while (ptr->next != NULL) ptr = ptr->next;
        ptr->next = newNode;
    }
    cout << "\nCall record added successfully.\n";
}
void displayCalls()
{
    if (head == NULL) { cout << "\nNo call records available.\n"; return; }
    CallNode *ptr = head;
    cout << "\n========== CALL RECORDS ==========\n";
    while (ptr != NULL)
    {
        cout << "Caller Name : " << ptr->caller << endl;
        cout << "Phone Number : " << ptr->number << endl;
        cout << "Duration      : " << ptr->duration << " minutes" << endl;
        cout << "---------------------------------\n";
        ptr = ptr->next;
    }
}
void searchCall()
{
    if (head == NULL) { cout << "\nNo call records available.\n"; return; }
    string searchNumber;
    cout << "\nEnter phone number to search: "; cin >> searchNumber;
    CallNode *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->number == searchNumber)
        {
            cout << "\nCall record found.\n";
            cout << "Caller Name : " << ptr->caller << endl;
            cout << "Phone Number : " << ptr->number << endl;
            cout << "Duration   : " << ptr->duration << " minutes" << endl;
            return;
        }
        ptr = ptr->next;
    }
    cout << "\nCall record not found.\n";
}
void deleteCall()
{
    if (head == NULL) { cout << "\nNo call records available.\n"; return; }
    string deleteNumber;
    cout << "\nEnter phone number to delete: "; cin >> deleteNumber;
    if (head->number == deleteNumber)
    {
        CallNode *temp = head;
        head = head->next;
        delete temp;
        cout << "\nCall record deleted successfully.\n";
        return;
    }
    CallNode *ptr = head;
    while (ptr->next != NULL && ptr->next->number != deleteNumber) ptr = ptr->next;
    if (ptr->next == NULL) { cout << "\nCall record not found.\n"; return; }
    CallNode *temp = ptr->next;
    ptr->next = temp->next;
    delete temp;
    cout << "\nCall record deleted successfully.\n";
}
int main()
{
    int choice;
    do
    {
        cout << "\n========== CALL LOG MANAGEMENT ==========\n";
        cout << "1. Add Call\n2. Display Calls\n3. Search Call\n4. Delete Call\n5. Exit\n";
        cout << "\nEnter your choice: "; cin >> choice;
        switch (choice)
        {
        case 1: addCall(); break;
        case 2: displayCalls(); break;
        case 3: searchCall(); break;
        case 4: deleteCall(); break;
        case 5: cout << "\nExiting Call Log Management System...\n"; break;
        default: cout << "\nInvalid choice. Please try again.\n";
        }
    } while (choice != 5);
    return 0;
}