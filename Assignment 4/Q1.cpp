#include <iostream>
using namespace std;
#define SIZE 5

class Queue {
    int arr[SIZE];
    int a, b;
public:
    Queue() {
        a = -1;
        b = -1;
    }
    bool isEmpty() {
        return (a == -1);
    }
    bool isFull() {
        return (b == SIZE - 1);
    }
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is Full\n";
            return;
        }
        if (a == -1) a = 0;
        arr[++b] = x;
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
            a++;
        }
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        for (int i = a; i <= b; i++)
            cout << arr[i] << " ";
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
    Queue q;
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
