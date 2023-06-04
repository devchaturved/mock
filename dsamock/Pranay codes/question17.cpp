#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    string division;
    string address;
};

void addStudent(const Student& student) {
    ofstream outfile("students.txt", ios::app);
    if (!outfile) {
        cerr << "Error opening file." << endl;
        return;
    }

    outfile << student.rollNo << " " << student.name << " " << student.division << " " << student.address << endl;
    outfile.close();

    cout << "Student added successfully." << endl;
}

void displayStudent(const Student& student) {
    cout << "Roll No: " << student.rollNo << endl;
    cout << "Name: " << student.name << endl;
    cout << "Division: " << student.division << endl;
    cout << "Address: " << student.address << endl;
    cout << endl;
}

void searchStudent(int rollNo) {
    ifstream infile("students.txt");
    if (!infile) {
        cerr << "Error opening file." << endl;
        return;
    }

    Student student;
    bool found = false;

    while (infile >> student.rollNo >> student.name >> student.division >> student.address) {
        if (student.rollNo == rollNo) {
            displayStudent(student);
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found." << endl;
    }

    infile.close();
}

void deleteStudent(int rollNo) {
    ifstream infile("students.txt");
    if (!infile) {
        cerr << "Error opening file." << endl;
        return;
    }

    ofstream outfile("temp.txt");
    if (!outfile) {
        cerr << "Error opening file." << endl;
        return;
    }

    Student student;
    bool found = false;

    while (infile >> student.rollNo >> student.name >> student.division >> student.address) {
        if (student.rollNo != rollNo) {
            outfile << student.rollNo << " " << student.name << " " << student.division << " " << student.address << endl;
        } else {
            found = true;
        }
    }

    infile.close();
    outfile.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found) {
        cout << "Student deleted successfully." << endl;
    } else {
        cout << "Student not found." << endl;
    }
}

void insertStudent(const Student& newStudent, int position) {
    ifstream infile("students.txt");
    if (!infile) {
        cerr << "Error opening file." << endl;
        return;
    }

    ofstream outfile("temp.txt");
    if (!outfile) {
        cerr << "Error opening file." << endl;
        return;
    }

    Student student;
    int currentPosition = 1;
    bool inserted = false;

    while (infile >> student.rollNo >> student.name >> student.division >> student.address) {
        if (currentPosition == position) {
            outfile << newStudent.rollNo << " " << newStudent.name << " " << newStudent.division << " " << newStudent.address << endl;
            inserted = true;
        }

        outfile << student.rollNo << " " << student.name << " " << student.division << " " << student.address << endl;
        currentPosition++;
    }

    if (!inserted && currentPosition == position) {
        outfile << newStudent.rollNo << " " << newStudent.name << " " << newStudent.division << " " << newStudent.address << endl;
        inserted = true;
    }

    infile.close();
    outfile.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (inserted) {
        cout << "Student inserted successfully." << endl;
    } else {
        cout << "Invalid position. Student not inserted." << endl;
    }
}

int main() {
    int choice;
    Student student;

    while (true) {
        cout << "----- Student Information Management -----" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Delete Student" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Insert Student" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Roll No: ";
                cin >> student.rollNo;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, student.name);
                cout << "Enter Division: ";
                getline(cin, student.division);
                cout << "Enter Address: ";
                getline(cin, student.address);

                addStudent(student);
                break;

            case 2:
                cout << "Enter Roll No of the student to delete: ";
                cin >> student.rollNo;

                deleteStudent(student.rollNo);
                break;

            case 3:
                cout << "Enter Roll No of the student to search: ";
                cin >> student.rollNo;

                searchStudent(student.rollNo);
                break;

            case 4:
                cout << "Enter Roll No: ";
                cin >> student.rollNo;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, student.name);
                cout << "Enter Division: ";
                getline(cin, student.division);
                cout << "Enter Address: ";
                getline(cin, student.address);

                int position;
                cout << "Enter the position to insert the student: ";
                cin >> position;

                insertStudent(student, position);
                break;

            case 5:
                cout << "Exiting program. Thank you!" << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }
}
