#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
using namespace std;

struct Task { string name; int priority; };

int main()
{
    deque<Task> tasks;
    // Add tasks at the rear
    tasks.push_back({"Task A", 2});
    tasks.push_back({"Task B", 1});
    // Add a task at the front
    tasks.push_front({"Task C", 3});

    // Sort tasks by priority (highest first)
    sort(tasks.begin(), tasks.end(),
         [](Task a, Task b) { return a.priority > b.priority; });

    cout << "Task Execution Order:\n";
    // Process tasks in priority order
    while (!tasks.empty())
    {
        cout << tasks.front().name << " - Priority: "
             << tasks.front().priority << endl;
        tasks.pop_front();
    }
    return 0;
}