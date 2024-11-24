#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MaxHeap {
    priority_queue<int> heap;

public:
    void insert(int marks) {
        heap.push(marks);
    }

    int getMax() {
        if (!heap.empty())
            return heap.top();
        else
            return -1; 
    }
};

int main() {
    MaxHeap mh;
    int n, marks;

    cout << "Enter the number of students: ";
    cin >> n;

    cout << "Enter the marks obtained by each student:\n";
    for (int i = 0; i < n; i++) {
        cin >> marks;
        mh.insert(marks);
    }

    cout << "Maximum marks obtained: " << mh.getMax() << endl;

    return 0;
}
