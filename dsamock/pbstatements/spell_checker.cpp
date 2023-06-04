#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

const int TABLE_SIZE = 10;

class HashTable {
private:
    list<string>* table;

public:
    HashTable() {
        table = new list<string>[TABLE_SIZE];
    }

    int hashFunction(const string& word) {
        int sum = 0;
        for (char c : word) {
            sum += c;
        }
        return sum % TABLE_SIZE;
    }

    void insert(const string& word) {
        int index = hashFunction(word);
        table[index].push_back(word);
    }

    bool lookup(const string& word) {
        int index = hashFunction(word);
        list<string>& slot = table[index];

        for (const string& w : slot) {
            if (w == word) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    HashTable hashTable;
    ifstream dictionaryFile("dictionary.txt");
    string word;

    // Read words from the dictionary file and insert them into the hash table
    if (dictionaryFile.is_open()) {
        while (dictionaryFile >> word) {
            hashTable.insert(word);
        }
        dictionaryFile.close();
    } else {
        cerr << "Error opening dictionary file." << endl;
        return 1;
    }

    // Prompt the user to enter words and check if they are spelled correctly
    while (true) {
        cout << "Enter a word (or 'q' to quit): ";
        cin >> word;

        if (word == "q") {
            break;
        }

        if (hashTable.lookup(word)) {
            cout << "The word is spelled correctly." << endl;
        } else {
            cout << "The word is not spelled correctly." << endl;
        }
    }

    return 0;
}
