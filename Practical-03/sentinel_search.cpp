#include <iostream>
#include <string>
using namespace std;

struct Student { string name; int marks; };

void display(Student students[], int n)
{
    cout << "\n--- Student Record ---\n";
    for (int i = 0; i < n; i++)
        cout << i + 1 << ". " << students[i].name << " - " << students[i].marks << endl;
}

int sentinelSearch(Student students[], int n, string key)
{
    if (n == 0) return -1;
    Student last = students[n - 1];
    students[n - 1].name = key;
    int i = 0;
    while (students[i].name != key) i++;
    students[n - 1] = last;
    if (i < n - 1 || students[n - 1].name == key) return i;
    return -1;
}

void insertStudent(Student students[], int &n, string name, int marks)
{
    int pos = 0;
    while (pos < n && students[pos].name < name) pos++;
    for (int i = n; i > pos; i--) students[i] = students[i - 1];
    students[pos].name = name;
    students[pos].marks = marks;
    n++;
    cout << "\nStudent inserted successfully!\n";
}

int main()
{
    Student students[100];
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    cout << "\nEnter student names and marks:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\nStudent " << i + 1 << ":\n";
        cout << "Name: "; cin >> students[i].name;
        cout << "Marks: "; cin >> students[i].marks;
    }
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (students[j].name > students[j + 1].name)
            {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
    cout << "\nAfter Sorting:";
    display(students, n);
    string searchName;
    cout << "\nEnter student's name to search: ";
    cin >> searchName;
    int index = sentinelSearch(students, n, searchName);
    if (index != -1)
    {
        cout << "\nStudent found!\n";
        cout << "Name: " << students[index].name << endl;
        cout << "Marks: " << students[index].marks << endl;
    }
    else
    {
        cout << "\nStudent not found.\n";
        int marks;
        cout << "Enter marks of new student: ";
        cin >> marks;
        insertStudent(students, n, searchName, marks);
    }
    cout << "\nFinal Student Record:";
    display(students, n);
    return 0;
}