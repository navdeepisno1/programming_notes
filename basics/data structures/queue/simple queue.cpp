#include <bits/stdc++.h>

using namespace std;

class LLNode
{
public:
    int data;
    LLNode *next;

public:
    LLNode()
    {
    }

    LLNode(int x)
    {
        data = x;
        next = NULL;
    }
};

class Interface QueueFN
{
public:
    virtual void push(int x) = 0;
    virtual void pop() = 0;
    virtual int front() = 0;
}

class QueueUsingLL
{
private:
    LLNode *front;
    LLNode *back;

public:
    QueueUsingLL()
    {
        front = NULL;
        back = NULL;
    }

    void push(int x)
    {
        if (back == NULL)
        {
            front = back = new LLNode(x);
            return;
        }

        LLNode *node = new LLNode(x);
        back->next = node;
        back = back->next;
    }

    void pop()
    {
        LLNode *temp = front;

        free(temp);

        front = front->next;
    }

    int front()
    {
        return front->data;
    }
};

int main()
{
}