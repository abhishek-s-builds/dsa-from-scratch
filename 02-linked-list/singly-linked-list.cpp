#include <iostream>
using namespace std;

struct node
{
    int item;
    node* next;
};

class sll
{
private:
    node* start;

public:
    sll();
    sll(const sll&);
    sll& operator=(const sll&);

    void insert_at_start(int);
    void insert_at_last(int);
    void insert_after(node*, int);

    void delete_first();
    void delete_last();
    void delete_node(node*);

    void edit();
    node* search(int);
    void count();

    ~sll();
};

// Constructor
sll::sll()
{
    start = NULL;
}

// Copy Constructor
sll::sll(const sll& list)
{
    start = NULL;

    node* t = list.start;

    while (t)
    {
        insert_at_last(t->item);
        t = t->next;
    }
}

// Assignment Operator
sll& sll::operator=(const sll& list)
{
    if (this == &list)
        return *this;

    while (start)
        delete_first();

    node* p = list.start;

    while (p)
    {
        insert_at_last(p->item);
        p = p->next;
    }

    return *this;
}

// Insert at Start
void sll::insert_at_start(int data)
{
    node* n = new node;

    n->item = data;
    n->next = start;

    start = n;
}

// Insert at Last
void sll::insert_at_last(int data)
{
    node* n = new node;

    n->item = data;
    n->next = NULL;

    // Empty list
    if (start == NULL)
    {
        start = n;
        return;
    }

    node* t = start;

    while (t->next != NULL)
    {
        t = t->next;
    }

    t->next = n;
}

// Search
node* sll::search(int data)
{
    node* t = start;

    while (t)
    {
        if (t->item == data)
        {
            return t;
        }

        t = t->next;
    }

    return NULL;
}

// Insert After Given Node
void sll::insert_after(node* t, int data)
{
    if (t == NULL)
    {
        cout << "Invalid node!" << endl;
        return;
    }

    node* n = new node;

    n->item = data;
    n->next = t->next;

    t->next = n;
}

// Delete First Node
void sll::delete_first()
{
    if (start == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    node* p = start;

    start = start->next;

    delete p;
}

// Delete Last Node
void sll::delete_last()
{
    if (start == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    // Only one node
    if (start->next == NULL)
    {
        delete start;
        start = NULL;
        return;
    }

    node* t = start;

    // Reach second-last node
    while (t->next->next != NULL)
    {
        t = t->next;
    }

    delete t->next;
    t->next = NULL;
}

// Delete Given Node
void sll::delete_node(node* n)
{
    if (start == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    if (n == NULL)
    {
        cout << "Invalid node!" << endl;
        return;
    }

    // Delete first node
    if (start == n)
    {
        start = start->next;
        delete n;
        return;
    }

    node* t = start;

    // Find previous node
    while (t->next != NULL && t->next != n)
    {
        t = t->next;
    }

    // Node not found
    if (t->next == NULL)
    {
        cout << "Node not found!" << endl;
        return;
    }

    t->next = n->next;

    delete n;
}

// Count Nodes
void sll::count()
{
    int c = 0;
    node* t = start;

    while (t)
    {
        c++;
        t = t->next;
    }

    cout << "Total nodes: " << c << endl;
}

// Edit Node
void sll::edit()
{
    int oldValue, newValue;

    cout << "Enter value to edit: ";
    cin >> oldValue;

    node* t = search(oldValue);

    if (t == NULL)
    {
        cout << "Node not found!" << endl;
        return;
    }

    cout << "Enter new value: ";
    cin >> newValue;

    t->item = newValue;

    cout << "Value updated successfully!" << endl;
}

// Destructor
sll::~sll()
{
    while (start)
    {
        delete_first();
    }
}

// Main Function
int main()
{
    sll list;

    list.insert_at_last(10);
    list.insert_at_last(20);
    list.insert_at_last(30);

    list.insert_at_start(5);

    node* t = list.search(20);

    if (t != NULL)
    {
        list.insert_after(t, 25);
    }

    list.count();

    list.delete_first();
    list.delete_last();

    list.count();

    return 0;
}
