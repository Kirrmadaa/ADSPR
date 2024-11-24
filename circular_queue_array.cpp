#include <iostream>
using namespace std;

class CircularQueue {
    int *queue;
    int front, rear, size, capacity;

public:
    CircularQueue(int c) : capacity(c), front(-1), rear(-1) {
        queue = new int[capacity];
    }

    ~CircularQueue() {
        delete[] queue;
    }

    bool isFull() {
        return (front == 0 && rear == capacity - 1) || (rear == (front - 1) % (capacity - 1));
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }

        if (front == -1) {
            front = rear = 0;
        } else if (rear == capacity - 1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }

        queue[rear] = value;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        int value = queue[front];
        if (front == rear) {
            front = rear = -1; // Queue becomes empty
        } else if (front == capacity - 1) {
            front = 0; // Wrap around
        } else {
            front++;
        }

        return value;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                cout << queue[i] << " ";
            }
        } else {
            for (int i = front; i < capacity; i++) {
                cout << queue[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << queue[i] << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    int capacity, choice, value;
    cout << "Enter the capacity of the circular queue: ";
    cin >> capacity;

    CircularQueue cq(capacity);

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            cq.enqueue(value);
            break;
        case 2:
            value = cq.dequeue();
            if (value != -1) {
                cout << "Dequeued: " << value << endl;
            }
            break;
        case 3:
            cq.display();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}
