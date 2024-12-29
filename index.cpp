
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Expense {
public:
    string category;
    double amount;

    // Constructor to initialize the expense
    Expense(string cat, double amt) {
        category = cat;
        amount = amt;
    }
};

// Ecpense Tracker Class
class ExpenseTracker {
private:
    double budget;
    vector<Expense> expenses;

public:
    // Constructor to set the budget
    ExpenseTracker(double budget) {
        this->budget = budget;
    }

    // Function to add an expense
    void addExpense() {
        string cat;
        double amt;

        cout << "Enter category (Food, Transport, Entertainment): ";
        cin >> cat;
        cout << "Enter amount: $";
        cin >> amt;

        expenses.push_back(Expense(cat, amt));
        cout << "Expense added successfully!" << endl;
    }

    // Function to view all expenses
    void viewExpenses() {
        cout << "\nYour Expenses:" << endl;
        double total = 0.0;
       for (int i = 0; i < expenses.size(); i++) {
    cout << expenses[i].category << ": $" << expenses[i].amount << endl;
      total += expenses[i].amount;
}

        cout << "Total Expenses: $" << total << endl;
    }

    // Function to check if the budget is exceeded
    void checkBudget() {
        double total = 0.0;
          for (int i = 0; i < expenses.size(); i++) {
    // cout << expenses[i].category << ": $" << expenses[i].amount << endl;
      total += expenses[i].amount;
}

        if (total > budget) {
            cout << "You have exceeded your budget by $" << total - budget << endl;
        } else {
            cout << "You are within your budget." << endl;
        }
    }
};

int main() {
    double budget;

    cout << "Enter your daily budget: $";
    cin >> budget;

    ExpenseTracker tracker(budget);

    int choice;

    do {
        cout << "\nMenu: \n";
        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. Check Budget\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                tracker.addExpense();
                break;
            case 2:
                tracker.viewExpenses();
                break;
            case 3:
                tracker.checkBudget();
                break;
            case 4:
                cout << "Exiting the Expense Tracker." << endl;
                break;
            default:
                cout << "Invalid choice, try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}



