#include <iostream>
#include <vector>
using namespace std;

class HashTable {
    int size;
    vector<vector<int>> table;

public:
    HashTable(int s) : size(s), table(s) {}

    int hashFunction(int key) {
        return key % size;
    }

    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    bool search(int key) {
        int index = hashFunction(key);
        for (int k : table[index]) {
            if (k == key) return true;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << " --> ";
            for (int k : table[i]) {
                cout << k << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n, key, choice, size;
    cout << "Enter size of hash table: ";
    cin >> size;
    HashTable ht(size);

    do {
        cout << "\n1. Insert\n2. Search\n3. Display\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            ht.insert(key);
            break;
        case 2:
            cout << "Enter key to search: ";
            cin >> key;
            if (ht.search(key)) {
                cout << "Key found." << endl;
            } else {
                cout << "Key not found." << endl;
            }
            break;
        case 3:
            ht.display();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 4);

    return 0;
}
