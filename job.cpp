#include <iostream>
using namespace std;

struct Job {
    int jobId;
    Job* next;
};

Job* front = nullptr;
Job* rear = nullptr;

void insertJob(int jobId) {
    Job* newJob = new Job();
    newJob->jobId = jobId;
    newJob->next = nullptr;
    if (!rear) {
        front = rear = newJob;
    } else {
        rear->next = newJob;
        rear = newJob;
    }
    cout << "Job " << jobId << " inserted into the queue.\n";
}

void deleteJob() {
    if (!front) {
        cout << "No jobs to delete. Queue is empty.\n";
        return;
    }
    Job* temp = front;
    cout << "Job " << front->jobId << " is being processed and deleted.\n";
    front = front->next;
    if (!front) rear = nullptr;
    delete temp;
}

void displayJobs() {
    if (!front) {
        cout << "No jobs in the queue.\n";
        return;
    }
    Job* temp = front;
    cout << "Jobs in the queue: ";
    while (temp) {
        cout << temp->jobId << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, jobId;

    do {
        cout << "\n1.Insert Job 2.Delete Job 3.Display Jobs 4.Exit\nChoose an option: ";
        cin >> choice;
        switch (choice) {
            case 1: 
                cout << "Enter Job ID: ";
                cin >> jobId;
                insertJob(jobId); 
                break;
            case 2: 
                deleteJob(); 
                break;
            case 3: 
                displayJobs(); 
                break;
        }
    } while (choice != 4);

    return 0;
}
