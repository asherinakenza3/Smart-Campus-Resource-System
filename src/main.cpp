#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;

const int MAX_STUDENTS = 50;
const int RESOURCE_COUNT = 5;
const int ROWS = 4;
const int COLS = 4;

struct Student {
    int id;
    string name;
    string section;
    string yearLevel;
    string status;
};

struct Resource {
    string id;
    string name;
    string category;
    int capacity;
};

// Static array for student records
Student students[MAX_STUDENTS];
int studentCount = 0;

// Pointer used for dynamic memory
Resource* resources = nullptr;

int resourceMatrix[ROWS][COLS] = {
    {12, 3, 8, 5},
    {9, 2, 4, 10},
    {5, 6, 10, 2},
    {4, 8, 6, 3}
};

string departments[ROWS] = {
    "IT Department",
    "Engineering",
    "Business",
    "Education"
};

string matrixResources[COLS] = {
    "R-01",
    "R-02",
    "R-03",
    "R-04"
};

void clearInput();
void showMenu();
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();
void initializeResources();
void manageResources();
void displayResources();
void updateResource();
void displayResourceMatrix();
void analyzeResourceUtilization();
void generateReport();
void cleanupResources();

int main() {
    initializeResources();

    int choice;

    do {
        showMenu();
        cout << "Enter choice: ";
        cin >> choice;

        if (cin.fail()) {
            clearInput();
            cout << "\nInvalid input. Please enter a number from 1 to 10.\n";
            continue;
        }

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                manageResources();
                break;
            case 7:
                displayResourceMatrix();
                break;
            case 8:
                analyzeResourceUtilization();
                break;
            case 9:
                generateReport();
                break;
            case 10:
                cout << "\nExiting system...\n";
                break;
            default:
                cout << "\nInvalid menu choice. Please select from 1 to 10.\n";
        }

    } while (choice != 10);

    cleanupResources();

    cout << "Dynamic memory released successfully.\n";
    cout << "Thank you for using the system.\n";

    return 0;
}

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void showMenu() {
    cout << "\n========================================\n";
    cout << "SMART CAMPUS RESOURCE MANAGEMENT SYSTEM\n";
    cout << "========================================\n";
    cout << "1. Add Student\n";
    cout << "2. Display Students\n";
    cout << "3. Search Student\n";
    cout << "4. Update Student\n";
    cout << "5. Delete Student\n";
    cout << "6. Manage Campus Resources\n";
    cout << "7. Display Resource Matrix\n";
    cout << "8. Analyze Resource Utilization\n";
    cout << "9. Generate Report\n";
    cout << "10. Exit\n";
    cout << "========================================\n";
}

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "\nMaximum student capacity reached.\n";
        return;
    }

    Student newStudent;

    cout << "\n--- ADD STUDENT ---\n";
    cout << "Enter Student ID: ";
    cin >> newStudent.id;

    if (cin.fail() || newStudent.id <= 0) {
        clearInput();
        cout << "Invalid Student ID.\n";
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == newStudent.id) {
            cout << "Duplicate Student ID. Student not added.\n";
            return;
        }
    }

    clearInput();

    cout << "Enter Name: ";
    getline(cin, newStudent.name);

    if (newStudent.name.empty()) {
        cout << "Name cannot be empty.\n";
        return;
    }

    cout << "Enter Section: ";
    getline(cin, newStudent.section);

    if (newStudent.section.empty()) {
        cout << "Section cannot be empty.\n";
        return;
    }

    cout << "Enter Year Level: ";
    getline(cin, newStudent.yearLevel);

    if (newStudent.yearLevel.empty()) {
        cout << "Year level cannot be empty.\n";
        return;
    }

    cout << "Enter Status: ";
    getline(cin, newStudent.status);

    if (newStudent.status.empty()) {
        cout << "Status cannot be empty.\n";
        return;
    }

    students[studentCount] = newStudent;
    studentCount++;

    cout << "\nStudent added successfully.\n";
}

void displayStudents() {
    cout << "\n--- STUDENT RECORDS ---\n";

    if (studentCount == 0) {
        cout << "No student records available.\n";
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        cout << "\nStudent #" << i + 1 << "\n";
        cout << "Student ID : " << students[i].id << "\n";
        cout << "Name       : " << students[i].name << "\n";
        cout << "Section    : " << students[i].section << "\n";
        cout << "Year Level : " << students[i].yearLevel << "\n";
        cout << "Status     : " << students[i].status << "\n";
    }

    cout << "\nTotal Students: " << studentCount << "\n";
}

void searchStudent() {
    if (studentCount == 0) {
        cout << "\nNo student records available.\n";
        return;
    }

    int searchID;

    cout << "\n--- SEARCH STUDENT ---\n";
    cout << "Enter Student ID: ";
    cin >> searchID;

    if (cin.fail() || searchID <= 0) {
        clearInput();
        cout << "Invalid Student ID.\n";
        return;
    }

    // Linear search
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == searchID) {
            cout << "\nStudent found.\n";
            cout << "Student ID : " << students[i].id << "\n";
            cout << "Name       : " << students[i].name << "\n";
            cout << "Section    : " << students[i].section << "\n";
            cout << "Year Level : " << students[i].yearLevel << "\n";
            cout << "Status     : " << students[i].status << "\n";
            return;
        }
    }

    cout << "\nRecord not found.\n";
}

void updateStudent() {
    if (studentCount == 0) {
        cout << "\nNo student records available.\n";
        return;
    }

    int searchID;

    cout << "\n--- UPDATE STUDENT ---\n";
    cout << "Enter Student ID to update: ";
    cin >> searchID;

    if (cin.fail() || searchID <= 0) {
        clearInput();
        cout << "Invalid Student ID.\n";
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == searchID) {
            clearInput();

            string newName;
            string newSection;
            string newYearLevel;
            string newStatus;

            cout << "Enter New Name: ";
            getline(cin, newName);

            cout << "Enter New Section: ";
            getline(cin, newSection);

            cout << "Enter New Year Level: ";
            getline(cin, newYearLevel);

            cout << "Enter New Status: ";
            getline(cin, newStatus);

            if (newName.empty() ||
                newSection.empty() ||
                newYearLevel.empty() ||
                newStatus.empty()) {

                cout << "Fields cannot be empty. Update cancelled.\n";
                return;
            }

            students[i].name = newName;
            students[i].section = newSection;
            students[i].yearLevel = newYearLevel;
            students[i].status = newStatus;

            cout << "\nStudent information updated successfully.\n";
            return;
        }
    }

    cout << "\nRecord not found.\n";
}

void deleteStudent() {
    if (studentCount == 0) {
        cout << "\nNo student records available.\n";
        return;
    }

    int searchID;

    cout << "\n--- DELETE STUDENT ---\n";
    cout << "Enter Student ID to delete: ";
    cin >> searchID;

    if (cin.fail() || searchID <= 0) {
        clearInput();
        cout << "Invalid Student ID.\n";
        return;
    }

    int foundIndex = -1;

    // Linear search
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == searchID) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        cout << "\nRecord not found.\n";
        return;
    }

    for (int i = foundIndex; i < studentCount - 1; i++) {
        students[i] = students[i + 1];
    }

    studentCount--;

    cout << "\nStudent deleted successfully.\n";
}

void initializeResources() {
    // Dynamic memory allocation
    resources = new Resource[RESOURCE_COUNT];

    resources[0] = {
        "R-01", "Computer Laboratory 1", "Laboratory", 40
    };

    resources[1] = {
        "R-02", "Conference Room", "Meeting Space", 20
    };

    resources[2] = {
        "R-03", "Library Study Hub", "Study Area", 60
    };

    resources[3] = {
        "R-04", "Robotics Lab", "Laboratory", 25
    };

    resources[4] = {
        "R-05", "Multimedia Room", "Laboratory", 30
    };
}

void manageResources() {
    int choice;

    do {
        cout << "\n--- CAMPUS RESOURCE MANAGEMENT ---\n";
        cout << "1. Display Resources\n";
        cout << "2. Update Resource Capacity\n";
        cout << "3. Return to Main Menu\n";
        cout << "Enter choice: ";

        cin >> choice;

        if (cin.fail()) {
            clearInput();
            cout << "\nInvalid numerical input.\n";
            continue;
        }

        switch (choice) {
            case 1:
                displayResources();
                break;
            case 2:
                updateResource();
                break;
            case 3:
                cout << "\nReturning to main menu...\n";
                break;
            default:
                cout << "\nInvalid resource menu choice.\n";
        }

    } while (choice != 3);
}

void displayResources() {
    cout << "\n--- CAMPUS RESOURCES ---\n";

    for (int i = 0; i < RESOURCE_COUNT; i++) {
        cout << "\nResource #" << i + 1 << "\n";
        cout << "Resource ID : " << resources[i].id << "\n";
        cout << "Name        : " << resources[i].name << "\n";
        cout << "Category    : " << resources[i].category << "\n";
        cout << "Capacity    : " << resources[i].capacity << "\n";
    }
}

void updateResource() {
    string resourceID;

    clearInput();

    cout << "\n--- UPDATE RESOURCE CAPACITY ---\n";
    cout << "Enter Resource ID: ";
    getline(cin, resourceID);

    for (int i = 0; i < RESOURCE_COUNT; i++) {
        if (resources[i].id == resourceID) {
            int newCapacity;

            cout << "Current Capacity: "
                 << resources[i].capacity << "\n";

            cout << "Enter New Capacity: ";
            cin >> newCapacity;

            if (cin.fail() || newCapacity <= 0) {
                clearInput();
                cout << "Invalid capacity.\n";
                return;
            }

            resources[i].capacity = newCapacity;

            cout << "\nResource capacity updated successfully.\n";
            return;
        }
    }

    cout << "\nResource not found.\n";
}

void displayResourceMatrix() {
    cout << "\n--- CAMPUS RESOURCE UTILIZATION MATRIX ---\n\n";

    cout << left << setw(18) << "Department";

    for (int j = 0; j < COLS; j++) {
        cout << setw(8) << matrixResources[j];
    }

    cout << "\n";

    // 2D array traversal
    for (int i = 0; i < ROWS; i++) {
        cout << left << setw(18) << departments[i];

        for (int j = 0; j < COLS; j++) {
            cout << setw(8) << resourceMatrix[i][j];
        }

        cout << "\n";
    }
}

void analyzeResourceUtilization() {
    cout << "\n--- RESOURCE UTILIZATION ANALYSIS ---\n";

    cout << "\nRow Totals:\n";

    for (int i = 0; i < ROWS; i++) {
        int rowTotal = 0;

        for (int j = 0; j < COLS; j++) {
            rowTotal += resourceMatrix[i][j];
        }

        cout << departments[i]
             << ": "
             << rowTotal
             << " hours\n";
    }

    cout << "\nColumn Totals:\n";

    for (int j = 0; j < COLS; j++) {
        int columnTotal = 0;

        for (int i = 0; i < ROWS; i++) {
            columnTotal += resourceMatrix[i][j];
        }

        cout << matrixResources[j]
             << ": "
             << columnTotal
             << " hours\n";
    }
}

void generateReport() {
    cout << "\n========================================\n";
    cout << "SMART CAMPUS SUMMARY REPORT\n";
    cout << "========================================\n";

    cout << "Total Student Records: "
         << studentCount << "\n";

    cout << "Maximum Student Capacity: "
         << MAX_STUDENTS << "\n";

    cout << "Total Campus Resources: "
         << RESOURCE_COUNT << "\n";

    cout << "\nStudent Summary:\n";

    if (studentCount == 0) {
        cout << "No student records available.\n";
    } else {
        for (int i = 0; i < studentCount; i++) {
            cout << students[i].id
                 << " - "
                 << students[i].name
                 << " - "
                 << students[i].status
                 << "\n";
        }
    }

    cout << "\nResource Summary:\n";

    for (int i = 0; i < RESOURCE_COUNT; i++) {
        cout << resources[i].id
             << " - "
             << resources[i].name
             << " - Capacity: "
             << resources[i].capacity
             << "\n";
    }

    int grandTotal = 0;

    cout << "\nResource Utilization Totals:\n";

    for (int i = 0; i < ROWS; i++) {
        int rowTotal = 0;

        for (int j = 0; j < COLS; j++) {
            rowTotal += resourceMatrix[i][j];
        }

        grandTotal += rowTotal;

        cout << departments[i]
             << ": "
             << rowTotal
             << " hours\n";
    }

    cout << "\nOverall Resource Usage: "
         << grandTotal
         << " hours\n";
}

void cleanupResources() {
    // Release memory allocated using new[]
    delete[] resources;
    resources = nullptr;
}