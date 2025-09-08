#include <iostream>
using namespace std;
#define SIZE 5

class CircularQueue {
    int arr[SIZE];
    int a, b;
public:
    CircularQueue() {
        a = -1;
        b = -1;
    }
    bool isEmpty() {
        return (a == -1);
    }
    bool isFull() {
        return ((b + 1) % SIZE == a);
    }
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is Full\n";
            return;
        }
        if (a == -1) a = 0;
        b = (b + 1) % SIZE;
        arr[b] = x;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "Deleted: " << arr[a] << endl;
        if (a == b) {
            a = b = -1;
        } else {
            a = (a + 1) % SIZE;
        }
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        int i = a;
        while (true) {
            cout << arr[i] << " ";
            if (i == a) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
    void peek() {
        if (isEmpty())
            cout << "Queue is Empty\n";
        else
            cout << "Front element: " << arr[a] << endl;
    }
};

int main() {
    CircularQueue q;
    int ch, val;
    do {
        cout << "\n1.Enqueue 2.Dequeue 3.Display 4.Peek 5.Exit\n";
        cin >> ch;
        switch (ch) {
            case 1: cout << "Enter value: "; cin >> val; q.enqueue(val); break;
            case 2: q.dequeue(); break;
            case 3: q.display(); break;
            case 4: q.peek(); break;
        }
    } while (ch != 5);
    return 0;
}
