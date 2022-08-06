#include <bits/stdc++.h>

using namespace std;

class LLNode
{
    public:
        int data;
        LLNode* next;
    
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

class StackUsingArray
{
    private:
        int stack[1000];
        int top;
        int max = 1000;

    public:
        StackUsingArray()
        {
            top = -1;
        }

        bool empty()
        {
            return top == -1;
        }

        void push(int x)
        {
            stack[++top] = x;
        }

        void pop()
        {
            top--;
        }

        int front()
        {
            return stack[top];
        }
};

class StackUsingLL
{
    public:      
    LLNode *head;  

    public: 
    StackUsingLL()
    {
        head = NULL;        
    }

    void push(int x)
    {
        if(head==NULL)
        {
            head = new LLNode(x);
            head->next = NULL;            
            return;
        }

        LLNode *r = new LLNode(x);
        r->next = head;
        head = r;
    }

    void pop()
    {
        LLNode *temp = head;

        if(head->next==NULL)
        {
            head = NULL;
            free(temp);
            return;
        }        

        head = temp->next;
        free(temp);
    }

    int top()
    {
        if(head==NULL)
        {
            return -1;
        }

        return head->data;
    }
};

int main()
{
    StackUsingLL *s = new StackUsingLL();
    s->push(4);
    s->push(2);
    s->push(1);
    s->push(5);
    cout << s->top();
}