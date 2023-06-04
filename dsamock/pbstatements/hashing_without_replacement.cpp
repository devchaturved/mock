#include <iostream>
#include <list>
using namespace std;

const int TABLE_SIZE = 10;

class Student {
public:
    int pnr;
    int marks;

    Student(int pnr, int marks) {
        this->pnr = pnr;
        this->marks = marks;
    }
};

class HashTable {
private:
    list<Student>* table;

public:
    HashTable() {
        table = new list<Student>[TABLE_SIZE];
    }

    int hashFunction(int pnr) {
        return pnr % TABLE_SIZE;
    }

    void insert(int pnr, int marks) {
        int index = hashFunction(pnr);
        list<Student>& slot = table[index];

        // If the slot is empty, insert the student
        if (slot.empty()) {
            slot.push_back(Student(pnr, marks));
        } else {
            // Find the next available slot using linear probing
            while (!slot.empty() && slot.front().pnr != pnr) {
                index = (index + 1) % TABLE_SIZE;
                slot = table[index];
            }

            // Chain the new student to the existing student in the slot
            slot.push_back(Student(pnr, marks));
        }
    }

    int lookup(int pnr) {
        int index = hashFunction(pnr);
        list<Student>& slot = table[index];

        // Find the student with the given PNR in the slot
        for (const auto& student : slot) {
            if (student.pnr == pnr) {
                return student.marks;
            }
        }

        // Student not found
        return -1;
    }
};

int main() {
    HashTable hashTable;

    // Insert the given PNRs and marks
    int pnrs[] = { 31, 13, 14, 51, 16, 71, 48, 19 };
    int marks[] = { 13, 25, 77, 91, 68, 88, 53, 99 };
    int numStudents = sizeof(pnrs) / sizeof(pnrs[0]);

    for (int i = 0; i < numStudents; i++) {
        hashTable.insert(pnrs[i], marks[i]);
    }

    // Lookup the marks for the given PNRs
    int lookupPnrs[] = { 31, 13, 14, 51, 16, 71, 48, 19 };
    int numLookups = sizeof(lookupPnrs) / sizeof(lookupPnrs[0]);

    for (int i = 0; i < numLookups; i++) {
        int marks = hashTable.lookup(lookupPnrs[i]);

        if (marks != -1) {
            cout << "PNR: " << lookupPnrs[i] << ", Marks: " << marks << endl;
        } else {
            cout << "PNR: " << lookupPnrs[i] << ", Marks not found" << endl;
        }
    }

    return 0;
}
