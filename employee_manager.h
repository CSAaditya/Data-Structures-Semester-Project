#ifndef EMPLOYEE_MANAGER_H
#define EMPLOYEE_MANAGER_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iomanip>

struct EmployeeInfo {
    std::string id;
    std::string name;
    bool isClocked; // Flag to track clock-in status

    EmployeeInfo() = default; // Default constructor

    EmployeeInfo(const std::string& empId, const std::string& empName) : id(empId), name(empName), isClocked(false) {}
};

class EmployeeManager {
public:
    std::unordered_map<std::string, EmployeeInfo> employees; // Stores employee ID, EmployeeInfo pair
    std::string filename = "employee_data.txt"; // File to store employee data

public:
    EmployeeManager();

    void addEmployee(const std::string& empId, const std::string& empName);
    void clockIn(const std::string& empId);
    void clockOut(const std::string& empId);
    void displayClockedInEmployees() const;
    bool isValidEmployeeId(const std::string& empId) const;
    void loadEmployeeData();
    void saveEmployeeData() const;
};

#endif // EMPLOYEE_MANAGER_H
