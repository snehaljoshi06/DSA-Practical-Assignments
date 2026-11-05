#include <iostream>
using namespace std;

int main()
{
    int arr[100], n, choice, pos, value, i, search;
    cout << "Enter number of students: ";
    cin >> n;
    cout << "Enter marks of students:\n";
    for (i = 0; i < n; i++) cin >> arr[i];

    do
    {
        cout << "\n--- Student Mark Analysis System ---\n";
        cout << "1. Display Marks\n2. Insert Marks\n3. Delete Marks\n4. Search Marks\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Student Marks: ";
            for (i = 0; i < n; i++) cout << arr[i] << " ";
            cout << endl;
            break;
        case 2:
            cout << "Enter position to insert: ";
            cin >> pos;
            cout << "Enter marks: ";
            cin >> value;
            for (i = n; i >= pos; i--) arr[i] = arr[i - 1];
            arr[pos - 1] = value;
            n++;
            cout << "Marks inserted successfully.\n";
            break;
        case 3:
            cout << "Enter position to delete: ";
            cin >> pos;
            for (i = pos - 1; i < n - 1; i++) arr[i] = arr[i + 1];
            n--;
            cout << "Marks deleted successfully.\n";
            break;
        case 4:
            cout << "Enter marks to search: ";
            cin >> search;
            for (i = 0; i < n; i++)
                if (arr[i] == search) { cout << "Marks found at position " << i + 1 << endl; break; }
            if (i == n) cout << "Marks not found.\n";
            break;
        case 5: cout << "Program ended.\n"; break;
        default: cout << "Invalid choice.\n";
        }
    } while (choice != 5);
    return 0;
}