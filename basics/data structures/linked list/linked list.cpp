#include <bits/stdc++.h>

using namespace std;

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
struct Node
{
    int val;
    struct Node *next;
};

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// Create New Node for value N
Node *getNode(int n)
{
    Node *res;
    res->val = n;
    res->next = NULL;

    return res;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// Check NULL node
bool isNull(Node *head)
{
    return head == NULL;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// Add New Node to Beginning of LinkedList
Node *addNodeToBegin(Node *head, int val)
{
    Node *res = getNode(val);
    if (head == NULL)
    {
        return res;
    }

    res->next = head;
    head = res;

    return head;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// Add New Node to End of LinkedList
Node *addNodeToEnd(Node *head, int val)
{
    Node *curr = head;
    Node *prev = NULL;

    Node *newNode = getNode(val);

    while (curr)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = newNode;

    return head;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// Add New Node after given Node of LinkedList
Node *addNodeAfterNode(Node *head, int val, Node *n)
{
    Node *node = getNode(val);
    Node *next = n->next;
    n->next = node;
    node->next = next;

    return head;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// Delete Node From Beginning in LinkedList
Node *deleteNodeFromBegin(Node *head)
{
    if (isNull(head) || isNull(head->next))
    {
        free(head);
        return NULL;
    };

    Node *res = head - next;

    head->next = NULL;
    free(head);

    return res;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// Delete Node From End in LinkedList
Node *deleteNodeFromEnd(Node *head)
{
    if (isNull(head) || isNull(head->next))
    {
        free(head);
        return NULL;
    }

    Node *prev = NULL;
    Node *curr = head;

    while (curr->next)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = NULL;
    free(curr);

    return head;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// Delete Particular Node from LinkedList
Node *deleteNodeFromLinkedList(Node *head, Node *temp)
{
    if (isNull(head) || isNull(head->next))
    {
        free(head);
        return NULL;
    }

    Node *prev = NULL;
    Node *curr = head;
    while (curr != temp)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = NULL;
    free(curr);

    return head;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// Reverse the LinkedList
Node *reverseLinkedList(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// Check for Cycle in LinkedList using Floyd Loyd Cycle detection or Tortoise and Hare technique
bool isCyclic(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// Get number of nodes in Linked List
int getSize(Node *head)
{
    int count = 0;

    while (head != NULL)
    {
        head = head->next;
        count++;
    }

    return count;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// Merge 2 sorted LinkedList
Node *mergeSortedLinkedList(Node *head1, Node *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    Node *res;
    if (head1->val > head2->val)
    {
        res = head2;
        res->next = mergeSortedLinkedList(head1, head2->next);
    }
    else
    {
        res = head1;
        res->next = mergeSortedLinkedList(head1->next, head2);
    }

    return res;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
int main()
{
    Node *head = NULL;

    head = addNodeToBegin(head, 5);
    head = addNodeToBegin(head, 2);
    head = addNodeToBegin(head, 8);
    head = addNodeToBegin(head, 10);

    head = addNodeToEnd(head, 5);
    head = addNodeToEnd(head, 2);
    head = addNodeToEnd(head, 8);
    head = addNodeToEnd(head, 10);
}