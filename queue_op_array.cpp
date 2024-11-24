#include <iostream>
using namespace std;

class Queue {
    int *arr, front, rear, maxSize;
public:
    Queue(int size) : maxSize(size), front(-1), rear(-1) {
        arr = new int[maxSize];
    }
    ~Queue() {
        delete[] arr;
    }
    void enqueue(int value) {
        if (rear == maxSize - 1) {
            cout << "Queue Overflow\n";
        } else {
            if (front == -1) front = 0;
            arr[++rear] = value;
            cout << value << " enqueued\n";
        }
    }
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow\n";
        } else {
            cout << arr[front++] << " dequeued\n";
        }
    }
    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty\n";
        } else {
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int size, choice, value;
    cout << "Enter queue size: ";
    cin >> size;

    Queue queue(size);

    do {
        cout << "\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nChoose: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Value: "; cin >> value; queue.enqueue(value); break;
            case 2: queue.dequeue(); break;
            case 3: queue.display(); break;
        }
    } while (choice != 4);

    return 0;
}
