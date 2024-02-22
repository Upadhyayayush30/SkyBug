#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

// Function to add a task to the list
void addTask(vector<Task>& tasks, const string& description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added: " << description << endl;
}

// Function to view tasks in the list
void viewTasks(const vector<Task>& tasks) {
    cout << "Task List:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << "[" << (tasks[i].completed ? "X" : " ") << "] " << tasks[i].description << endl;
    }
}

// Function to mark a task as completed
void markCompleted(vector<Task>& tasks, size_t index) {
    if (index < tasks.size()) {
        tasks[index].completed = true;
        cout << "Task marked as completed: " << tasks[index].description << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

// Function to remove a task from the list
void removeTask(vector<Task>& tasks, size_t index) {
    if (index < tasks.size()) {
        cout << "Task removed: " << tasks[index].description << endl;
        tasks.erase(tasks.begin() + index);
    } else {
        cout << "Invalid task index." << endl;
    }
}

int main() {
    vector<Task> tasks;

    char choice;
    do {
        cout << "\nTodo List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Quit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case '1':
                {
                    string description;
                    cout << "Enter task description: ";
                    cin.ignore();  // Clear newline from previous input
                    getline(cin, description);
                    addTask(tasks, description);
                }
                break;
            case '2':
                viewTasks(tasks);
                break;
            case '3':
                {
                    size_t index;
                    cout << "Enter task index to mark as completed: ";
                    cin >> index;
                    markCompleted(tasks, index);
                }
                break;
            case '4':
                {
                    size_t index;
                    cout << "Enter task index to remove: ";
                    cin >> index;
                    removeTask(tasks, index);
                }
                break;
            case '5':
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }

    } while (choice != '5');

    return 0;
}
