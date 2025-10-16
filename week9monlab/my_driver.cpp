#include <iostream>
#include <string>
#include "LinkedQueue.hpp"
using namespace std;

struct Point { int x; int y; };

ostream& operator<<(ostream& out, const Point& p) {
    out << "(" << p.x << "," << p.y << ")";
    return out;
}

template <typename T>
void printAndDrain(LinkedQueue<T>& q) {
    while (!q.isEmpty()) {
        cout << q.front() << " ";
        q.dequeue();
    }
    cout << endl;
}

int main() {
    cout << "Testing LinkedQueue" << endl;

    LinkedQueue<int> qi;
    cout << "empty? " << (qi.isEmpty() ? "yes" : "no") << endl;
    cout << "len: " << qi.getLength() << endl;

    try { qi.front(); }
    catch (string e) { cout << e << endl; }
    try { qi.dequeue(); }
    catch (string e) { cout << e << endl; }

    qi.enqueue(10);
    qi.enqueue(20);
    qi.enqueue(30);
    cout << "front: " << qi.front() << endl;
    cout << "back: " << qi.back() << endl;

    qi.dequeue();
    cout << "front after 1 dequeue: " << qi.front() << endl;

    qi.enqueue(40);
    qi.enqueue(50);
    cout << "ints: ";
    printAndDrain(qi);
    cout << "empty? " << (qi.isEmpty() ? "yes" : "no") << " len: " << qi.getLength() << endl;

    LinkedQueue<string> qs;
    qs.enqueue("apple");
    qs.enqueue("banana");
    qs.enqueue("cherry");
    cout << "\nstring front: " << qs.front() << endl;
    cout << "string back: " << qs.back() << endl;

    LinkedQueue<string> qcopy(qs);
    cout << "copy front: " << qcopy.front() << endl;

    cout << "strings: ";
    printAndDrain(qs);

    cout << "copy still: ";
    printAndDrain(qcopy);

    LinkedQueue<Point> qp;
    qp.enqueue({ 1,2 });
    qp.enqueue({ 3,4 });
    qp.enqueue({ 5,6 });
    cout << "\npoint front: " << qp.front() << endl;
    cout << "point back: " << qp.back() << endl;
    cout << "points: ";
    printAndDrain(qp);

    cout << "\nDone." << endl;
    return 0;
}
