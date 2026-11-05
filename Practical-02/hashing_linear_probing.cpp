#include <iostream>
using namespace std;

class HashTable
{
    int table[10];
    int size;
public:
    HashTable()
    {
        size = 10;
        for (int i = 0; i < size; i++) table[i] = -1;
    }
    int hashFunction(int key) { return key % size; }
    void insert(int key)
    {
        int index = hashFunction(key), start = index;
        while (table[index] != -1)
        {
            index = (index + 1) % size;
            if (index == start) { cout << "Hash table is full.\n"; return; }
        }
        table[index] = key;
        cout << "Book ISBN " << key << " inserted at index " << index << endl;
    }
    void search(int key)
    {
        int index = hashFunction(key), start = index;
        while (table[index] != -1)
        {
            if (table[index] == key)
            {
                cout << "Book ISBN " << key << " found at index " << index << endl;
                return;
            }
            index = (index + 1) % size;
            if (index == start) break;
        }
        cout << "Book ISBN " << key << " not found.\n";
    }
    void display()
    {
        cout << "\nHash Table:\n";
        for (int i = 0; i < size; i++) cout << i << " : " << table[i] << endl;
    }
};

int main()
{
    HashTable h;
    int choice, key;
    do
    {
        cout << "\n--- Library Book Management System ---\n";
        cout << "1. Insert Book ISBN\n2. Search Book ISBN\n3. Display Hash Table\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1: cout << "Enter Book ISBN: "; cin >> key; h.insert(key); break;
        case 2: cout << "Enter Book ISBN to search: "; cin >> key; h.search(key); break;
        case 3: h.display(); break;
        case 4: cout << "Program ended.\n"; break;
        default: cout << "Invalid choice.\n";
        }
    } while (choice != 4);
    return 0;
}