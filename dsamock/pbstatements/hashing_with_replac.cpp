#include <iostream>
#include <list>
using namespace std;

class Student {
public:
    int pnr;
    int marks;

    Student(int p, int m) {
        pnr = p;
        marks = m;
    }
};

class HashTable {
    int size;
    list<Student>* table;

public:
    HashTable(int s) {
        size = s;
        table = new list<Student>[size];
    }

    int hashFunction(int pnr) {
        return pnr % size;
    }

    void insert(int pnr, int marks) {
        int index = hashFunction(pnr);

        for (auto& student : table[index]) {
            if (student.pnr == pnr) {
                student.marks = marks;
                return;
            }
        }

        table[index].push_back(Student(pnr, marks));
    }

    int lookup(int pnr) {
        int index = hashFunction(pnr);

        for (auto& student : table[index]) {
            if (student.pnr == pnr) {
                return student.marks;
            }
        }

        return -1; // PNR not found
    }
};

int main() {
    HashTable hashTable(10);

    // Insert students' PNR and marks
    hashTable.insert(11, 85);
    hashTable.insert(21, 92);
    hashTable.insert(31, 78);
    hashTable.insert(34, 89);
    hashTable.insert(55, 76);
    hashTable.insert(52, 93);
    hashTable.insert(33, 81);

    // Lookup students' marks
    cout << "Marks for PNR 31: " << hashTable.lookup(31) << endl;
    cout << "Marks for PNR 34: " << hashTable.lookup(34) << endl;
    cout << "Marks for PNR 52: " << hashTable.lookup(52) << endl;

    return 0;
}
