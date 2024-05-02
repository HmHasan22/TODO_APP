#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ToDoItem {
public:
    ToDoItem(const string& title, bool completed = false) : title(title), completed(completed) {}
    string getTitle() const { return title; }
    bool isCompleted() const { return completed; }
    void markAsCompleted() { completed = true; }
private:
    string title;
    bool completed;
};

class ToDoList {
public:
    void addItem(const string& title) {
        items.push_back(ToDoItem(title));
    }

    void markItemAsCompleted(int index) {
        if (index >= 0 && index < items.size()) {
            items[index].markAsCompleted();
        } else {
            cout << "Invalid item index!" << endl;
        }
    }

    void displayItems() const {
        cout << "To-Do List:" << endl;
        for (size_t i = 0; i < items.size(); ++i) {
            cout << i + 1 << ". ";
            if (items[i].isCompleted()) {
                cout << "[X] ";
            } else {
                cout << "[ ] ";
            }
            cout << items[i].getTitle() << endl;
        }
    }

private:
    vector<ToDoItem> items;
};

int main() {
    ToDoList myList;

    char choice;
    do {
        cout << "1. Add Item" << endl;
        cout << "2. Mark Item as Completed" << endl;
        cout << "3. Display Items" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case '1': {
                string title;
                cout << "Enter the title of the item: ";
                cin.ignore();
                getline(cin, title);
                myList.addItem(title);
                break;
            }
            case '2': {
                int index;
                cout << "Enter the index of the item to mark as completed: ";
                cin >> index;
                myList.markItemAsCompleted(index - 1);
                break;
            }
            case '3':
                myList.displayItems();
                break;
            case '4':
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
        }
    } while (choice != '4');

    return 0;
}
