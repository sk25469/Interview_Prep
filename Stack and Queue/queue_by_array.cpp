/** Queue implementation by array **/
#include <bits/stdc++.h>
#include <queue>
using namespace std;

const static int MAX_SIZE = 1000;

class Queue
{
private:
    int fr, rear;
    int ar[MAX_SIZE];

public:
    Queue() { fr = rear = 0; }
    bool push(int x);
    int front();
    int back();
    bool pop();
    int size();
    bool empty();
};

bool Queue::push(int x)
{
    if (rear > MAX_SIZE - 1)
    {
        cout << "Stack Overflow\n";
        return 0;
    }
    ar[rear] = x;
    rear++;
    cout << x << " Pushed in the queue\n";
    return 1;
}

bool Queue::pop()
{
    if (fr == rear)
    {
        cout << "Stack Underflow\n";
        return 0;
    }
    for (int i = 0; i < rear - 1; i++)
        ar[i] = ar[i + 1];

    rear--;
    //cout << "Popped from front\n";
    return 1;
}

int Queue::front()
{
    if (fr == rear)
    {
        cout << "Queue is empty\n";
        return 0;
    }
    return ar[fr];
}

int Queue::back()
{
    if (fr == rear)
    {
        cout << "Queue is empty\n";
        return 0;
    }
    return ar[rear - 1];
}

int Queue::size()
{
    return rear;
}

bool Queue::empty()
{
    return (fr == rear);
}

int main()
{
    class Queue q;
    q.push(20);
    q.push(40);
    q.push(30);
    q.push(60);

    cout << "Size of queue " << q.size() << endl;

    cout << "Front element is " << q.front() << endl;

    cout << "Back element is " << q.back() << endl;

    q.pop();

    cout << "After pop\n";
    cout << "Front element is " << q.front() << endl;

    cout << "Back element is " << q.back() << endl;

    cout << "Queue contains\n";
    while (!q.empty())
    {
        int x = q.front();
        cout << x << " ";
        q.pop();
    }

    cout << "\nMemory of queue " << sizeof(q) << endl;
}