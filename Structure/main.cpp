// Assignment1.cpp : This file contains the 'main' function. Program execution
// begins and ends there.
//

////// Segmentation fault solved (Error in display() function:- if condition brackets)

#include <iostream>

struct Name {
    const char* firstName;
    const char* middlename;
    const char* lastname;
};

struct Location {
    const char* city;
    const char* country;
};

struct Employee {
    int empID;
    Name name;
    const char* department;
    Location location;
    bool gender;
    const char* email;
    int phoneNo;
    Employee* reportingTo;

    void addLocation(Location& loc) { location = loc; }

    void addName(Name& nm) { name = nm; }
};

void displayFullname(const Name& name) {
    std::cout << name.firstName << " " << name.middlename << " " << name.lastname;
}

void addReportsTo(Employee& emp, Employee* mentor) { emp.reportingTo = mentor; }

void display(Employee& emp) {
    std::cout << "Employee ID: " << emp.empID << "\n";

    std::cout << "Employee Name: ";
    displayFullname(emp.name);
    std::cout << "\n";

    std::cout << "Department: " << emp.department << "\n";
    std::cout << "Location: " << emp.location.city << ","
        << emp.location.country << "\n";

    std::cout << "Gender: " << ((emp.gender) ? "Male" : "Female") << "\n";

    std::cout << "Email: " << emp.email << "\n";
    std::cout << "Mobile No.: " << emp.phoneNo << "\n";

    if (emp.reportingTo) {
        std::cout << "Reports to: ";
        displayFullname((*emp.reportingTo).name);
        std::cout << "\n";
    }

    std::cout << "*************************************************************"
        "********************************************************\n";
}

int main() {
    Employee Rushi = { 305,     {"Rushi", "Mineshkumar", "Gandhi"},
                      "C++",   {"Ahmedabad", "India"},
                      1,       "rushi.gandhi@zuru.com",
                      2544132, nullptr };

    Employee Devendra = {
        256,     {"Rushi", "Mineshkumar", "Gandhi"}, "C++", {"Ahmedabad", "India"}, 1, "devendrakumar@zuru.com",
        2342394, nullptr };

    Name devendraName = { "Devendra", "Kumar", "Patel" };

    Devendra.addName(devendraName);

    Location devendraLocation = { "Pune", "India" };

    Devendra.addLocation(devendraLocation);

    addReportsTo(Rushi, &Devendra);

    display(Rushi);
    display(Devendra);
}
