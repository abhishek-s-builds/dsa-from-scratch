#include <iostream>
#include <stdio.h>

using namespace std;

class array
{
private:
    int capacity;
    int lastindex;
    int *ptr;

public:
    array();
    array(array &);
    array& operator=(array &);
    void createarray(int);
    void insert(int, int);
    void append(int);
    int getitem(int);
    bool isempty();
    bool isfull();
    void del(int);
    void edit(int, int);
    int count();
    int getcapacity();
    void printarray();
    ~array();
};

array::array()
{
    ptr = NULL;
    capacity = 0;
    lastindex = -1;
}

array::array(array &arr)
{
    capacity = arr.capacity;
    lastindex = arr.lastindex;
    ptr = new int[capacity];
    for (int i = 0; i <= lastindex; i++)
    {
        ptr[i] = arr.ptr[i];
    }
}

array& array::operator=(array &arr)
{
    if (this == &arr)
    {
        return *this;
    }

    capacity = arr.capacity;
    lastindex = arr.lastindex;
    if (ptr != NULL)
    {
        delete [] ptr;
    }
    ptr = new int[capacity];
    for (int i = 0; i <= lastindex; i++)
    {
        ptr[i] = arr.ptr[i];
    }
    return (*this);
}

void array::createarray(int size)
{
    capacity = size;
    lastindex = -1;
    if (ptr != NULL)
    {
        delete [] ptr;
    }
    ptr = new int[size];
}

void array::insert(int index, int data)
{
    int i;
    try
    {
        if (index < 0 || index > lastindex + 1)
        {
            throw 1;
        }
        else if (isfull())
        {
            throw 2;
        }

        for (i = lastindex; i >= index; i--)
        {
            ptr[i + 1] = ptr[i];
        }
        ptr[index] = data;
        lastindex++;
    }
    catch (int a)
    {
        if (a == 1)
        {
            cout << "Invalid Index\n";
        }
        else if (a == 2)
        {
            cout << "Overflow\n";
        }
    }
}

void array::append(int s)
{
    if (!isfull())
    {
        lastindex++;
        ptr[lastindex] = s;
    }
    else
    {
        cout << "\nArray is overflow :";
    }
}

int array::getitem(int index)
{
    try
    {
        if (index < 0 || index > lastindex)
        {
            throw 1;
        }
        return ptr[index];
    }
    catch (int e)
    {
        if (e == 1)
        {
            cout << "\nInvalid Index or Array is empty";
        }
    }
    return -1;
}

bool array::isempty()
{
    return (lastindex == -1);
}

bool array::isfull()
{
    return (lastindex == capacity - 1);
}

void array::del(int index)
{
    try
    {
        if (index < 0 || index > lastindex)
        {
            throw 1;
        }
        for (int i = index; i < lastindex; i++) 
        {
            ptr[i] = ptr[i + 1];
        }
        lastindex--;
    }
    catch (int e)
    {
        if (e == 1)
        {
            cout << "Invalid Index or underflow\n";
        }
    }
}

void array::edit(int index, int data)
{
    try
    {
        if (index < 0 || index > lastindex) 
        {
            throw 1;
        }
        ptr[index] = data;
    }
    catch (int e)
    {
        if (e == 1)
        {
            cout << "index is invalid\n";
        }
    }
}

int array::count()
{
    return lastindex + 1;
}

int array::getcapacity()
{
    return capacity;
}

void array::printarray()
{
    cout << "Array:";
    for (int i = 0; i <= lastindex; i++)
    {
        cout << " " << ptr[i];
    }
    cout << endl;
}

array::~array()
{
    if (ptr != NULL)
    {
        delete [] ptr;
    }
}

int main()
{
    array p;
    p.createarray(5);
    p.insert(0, 2);
    p.insert(1, 3);
    p.insert(2, 4);
    p.append(5);

    cout << "Empty: " << boolalpha << p.isempty() << endl;
    cout << "Full: " << boolalpha << p.isfull() << endl;
    cout << "Capacity: " << p.getcapacity() << endl;
    cout << "Total filled arr: " << p.count() << endl;

    p.printarray();
    p.edit(0, 1);
    p.printarray();
    p.del(0);
    p.printarray();
    
    return 0;
}
