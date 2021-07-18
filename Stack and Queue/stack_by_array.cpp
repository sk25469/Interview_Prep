/** Implementation of stack by array **/
#include <bits/stdc++.h>
using namespace std;

const static int MAX_SIZE = 1000;

class Stack
{
    int t;

public:
    int ar[MAX_SIZE];

    Stack() { t = -1; }

    bool push(int x);
    int top();
    int pop();
    bool empty();
    int size();
};

bool Stack::push(int x)
{
    if (t >= (MAX_SIZE - 1))
    {
        cout << "Stack Overflow\n";
        return false;
    }
    else
    {
        ar[++t] = x;
        cout << x << " Pushed into stack\n";
        return true;
    }
}

int Stack::pop()
{
    if (t == -1)
    {
        cout << "Stack Underflow\n";
        return false;
    }
    else
    {
        int d = ar[t--]; /** We are not actually erasing anything from the array,
        we are just moving the t to the position where it would be after deleting the
        last element **/
        return d;
    }
}

int Stack::top()
{
    if (t < 0)
    {
        cout << "Stack is empty\n";
        return false;
    }
    else
        return ar[t];
}

bool Stack::empty()
{
    return t < 0;
}

int Stack::size()
{
    return t + 1;
}

int main()
{
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(55);
    s.push(90);
    cout << s.pop() << " Popped from stack\n";
    cout << "Size of stack : " << s.size() << endl;
    cout << "Elements present in stack : ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\nMemory of stack " << sizeof(s) << endl;

    return 0;
}
