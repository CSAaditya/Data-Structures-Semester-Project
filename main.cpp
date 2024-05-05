#include "employee_manager.h"
using namespace std;

char getMenuChoice() {
    char choice;
    cout << "=============================================\n";
    cout << "             Employee Management             \n";
    cout << "=============================================\n";
    cout << "1. Add Employee - Register a new employee\n";
    cout << "2. Clock In - Start working\n";
    cout << "3. Clock Out - Finish work\n";
    cout << "4. Display Clocked In Employees - See who's currently working\n";
    cout << "5. Exit - Quit the program\n";
    cout << "=============================================\n";
    cout << "Enter the number of your choice: ";
    cin >> choice;
    return choice;
}

int main() {
    EmployeeManager empManager;

    char choice;
    string empId, empName;

    do {
        choice = getMenuChoice();

        switch (choice) {
            case '1':
                cout << "\nEmployee Registration\n";
                cout << "=====================\n";
                cout << "Enter the 6-digit employee ID: ";
                cin >> empId;
                if (!empManager.isValidEmployeeId(empId)) {
                    cout << "Error: Employee ID must be a 6-digit number.\n\n";
                    break;
                }
                cout << "Enter the employee name: ";
                cin.ignore(); // Ignore newline character from previous input
                getline(cin, empName);
                empManager.addEmployee(empId, empName);
                cout << endl;
                break;
            case '2':
                cout << "\nClock In\n";
                cout << "========\n";
                cout << "Enter the 6-digit employee ID to start working: ";
                cin >> empId;
                if (!empManager.isValidEmployeeId(empId)) {
                    cout << "Error: Employee ID must be a 6-digit number.\n\n";
                    break;
                }
                empManager.clockIn(empId);
                cout << endl;
                break;
            case '3':
                cout << "\nClock Out\n";
                cout << "=========\n";
                cout << "Enter the 6-digit employee ID to finish work: ";
                cin >> empId;
                if (!empManager.isValidEmployeeId(empId)) {
                    cout << "Error: Employee ID must be a 6-digit number.\n\n";
                    break;
                }
                empManager.clockOut(empId);
                cout << endl;
                break;
            case '4':
                cout << "\nClocked In Employees\n";
                cout << "=====================\n";
                empManager.displayClockedInEmployees();
                cout << endl;
                break;
            case '5':
                cout << "Exiting the Employee Management System...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n\n";
                break;
        }
    } while (choice != '5');

    return 0;
}
