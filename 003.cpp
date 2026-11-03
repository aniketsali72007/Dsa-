#include <iostream>
using namespace std;
#define SIZE 5
class CircularQueue {
private:
int queue[SIZE];
int front, rear;
public:
CircularQueue() {
front = -1;
rear = -1;
}
bool isFull() {
return ((rear + 1) % SIZE == front);
}
bool isEmpty() {
return (front == -1);
}
void enqueue(int value) {
if (isFull()) {
cout << "Queue is Full! Cannot insert " << value << endl;
return;
}
if (isEmpty()) {
front = rear = 0;
}
else {
rear = (rear + 1) % SIZE;
}
queue[rear] = value;
cout << value << " inserted into queue." << endl;
}
void dequeue() {
if (isEmpty()) {
cout << "Queue is Empty! Cannot delete." << endl;
return;
}
cout << queue[front] << " deleted from queue." << endl;
if (front == rear) {
front = rear = -1;
}
else {
front = (front + 1) % SIZE;
}
}
void display() {
if (isEmpty()) {
cout << "Queue is Empty." << endl;
return;
}
cout << "Queue Elements: ";
int i = front;
while (true) {
cout << queue[i] << " ";
if (i == rear)
break;
i = (i + 1) % SIZE;
}
cout << endl;
}
};
int main() {
CircularQueue cq;
cq.enqueue(10);
cq.enqueue(20);
cq.enqueue(30);
cq.enqueue(40);
cq.enqueue(50);
cq.display();
cq.dequeue();
cq.dequeue();
cq.display();
cq.enqueue(60);
cq.enqueue(70);
cq.display();
cq.enqueue(80);
return 0;
}