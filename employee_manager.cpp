
#include "employee_manager.h"

// Constructor: Load employee data from file upon initialization
EmployeeManager::EmployeeManager() {
    loadEmployeeData();
}

// Add a new employee to the system
// Parameters:
// - empId: The 6-digit employee ID
// - empName: The name of the employee
// This function adds a new employee to the system with the provided employee ID and name.
// It stores the employee data in the employees map and then saves the updated employee data to a file.
void EmployeeManager::addEmployee(const std::string& empId, const std::string& empName) {
    employees[empId] = EmployeeInfo(empId, empName);
    saveEmployeeData(); // Save updated employee data to file
}

// Clock in an employee
// Parameters:
// - empId: The 6-digit employee ID to clock in
// This function marks the employee with the given employee ID as clocked in.
// If the employee exists in the system, their clock-in status is updated to true.
void EmployeeManager::clockIn(const std::string& empId) {
    auto it = employees.find(empId);
    if (it != employees.end()) {
        it->second.isClocked = true;
        std::cout << "Employee with ID " << empId << " has clocked in." << std::endl;
    } else {
        std::cout << "Employee with ID " << empId << " does not exist." << std::endl;
    }
}

// Clock out an employee
// Parameters:
// - empId: The 6-digit employee ID to clock out
// This function marks the employee with the given employee ID as clocked out.
// If the employee exists in the system, their clock-in status is updated to false.
void EmployeeManager::clockOut(const std::string& empId) {
    auto it = employees.find(empId);
    if (it != employees.end()) {
        it->second.isClocked = false;
        std::cout << "Employee with ID " << empId << " has clocked out." << std::endl;
    } else {
        std::cout << "Employee with ID " << empId << " does not exist." << std::endl;
    }
}

// Display currently clocked in employees
// This function displays the IDs and names of employees who are currently clocked in.
void EmployeeManager::displayClockedInEmployees() const {
    std::cout << "Currently clocked in employees:" << std::endl;
    bool found = false;
    for (const auto& pair : employees) {
        if (pair.second.isClocked) {
            std::cout << pair.second.id << ": " << pair.second.name << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "No employees are currently clocked in." << std::endl;
    }
}

// Validate if input is a 6-digit number
// Parameters:
// - empId: The employee ID to validate
// This function validates if the input string is a 6-digit number.
bool EmployeeManager::isValidEmployeeId(const std::string& empId) const {
    if (empId.length() != 6) return false;
    for (char ch : empId) {
        if (!std::isdigit(ch)) return false;
    }
    return true;
}

// Load employee data from a file
// This function reads employee data from a file and populates the employees map with the loaded data.
// If the file cannot be opened or read, an error message is displayed.
void EmployeeManager::loadEmployeeData() {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string empId, empName;
            if (std::getline(iss, empId, ',') && std::getline(iss, empName)) {
                employees[empId] = EmployeeInfo(empId, empName);
            }
        }
        file.close();
        std::cout << "Employee data loaded successfully." << std::endl;
    } else {
        std::cout << "Unable to open file: " << filename << std::endl;
    }
}

// Save employee data to a file
// This function appends the employee data to a file. If the file does not exist, it will be created.
// If the file cannot be opened or written to, an error message is displayed.
void EmployeeManager::saveEmployeeData() const {
    std::ofstream file(filename, std::ios::app); // Open the file in append mode
    if (file.is_open()) {
        for (const auto& pair : employees) {
            file << pair.second.id << "," << pair.second.name << std::endl;
        }
        file.close();
        std::cout << "Employee data appended successfully." << std::endl;
    } else {
        std::cout << "Unable to open file: " << filename << std::endl;
    }
}
