// Basic Array Implementation.
// Supports insert, delete, append, operations.

#include <iostream>
using namespace std;

class array
{
private:
    int capacity;
    int lastindex;
    int *ptr;

public:
    array();
    ~array();

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
};

array::array()
{
    ptr = nullptr;
}

array::~array()
{
    delete[] ptr;
}

void array::createarray(int size)
{
    capacity = size;
    lastindex = -1;

    if (ptr != nullptr)
        delete[] ptr;

    ptr = new int[size];
}

void array::insert(int index, int data)
{
    try
    {
        if (index < 0 || index > lastindex + 1)
            throw 1;

        if (isfull())
            throw 2;

        for (int i = lastindex; i >= index; i--)
        {
            ptr[i + 1] = ptr[i];
        }

        ptr[index] = data;
        lastindex++;
    }
    catch (int e)
    {
        if (e == 1)
            cout << "Invalid Index";
        else
            cout << "Overflow";
    }
}

void array::append(int data)
{
    if (!isfull())
    {
        lastindex++;
        ptr[lastindex] = data;
    }
    else
    {
        cout << "\nArray Overflow";
    }
}

int array::getitem(int index)
{
    try
    {
        if (index < 0 || index > lastindex)
            throw 1;

        return ptr[index];
    }
    catch (int e)
    {
        cout << "\nInvalid Index or Array is Empty";
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
            throw 1;

        for (int i = index; i < lastindex; i++)
        {
            ptr[i] = ptr[i + 1];
        }

        lastindex--;
    }
    catch (int e)
    {
        cout << "Invalid Index";
    }
}

void array::edit(int index, int data)
{
    try
    {
        if (index < 0 || index > lastindex)
            throw 1;

        ptr[index] = data;
    }
    catch (int e)
    {
        cout << "Index is Invalid";
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
    cout << "Array : ";

    for (int i = 0; i <= lastindex; i++)
    {
        cout << ptr[i] << " ";
    }

    cout << endl;
}

int main()
{
    array p;

    p.createarray(5);

    p.insert(0, 2);
    p.insert(1, 3);
    p.insert(2, 4);

    p.append(5);

    cout << "\nEmpty : " << boolalpha << p.isempty();
    cout << "\nFull : " << boolalpha << p.isfull();
    cout << "\nCapacity : " << p.getcapacity();
    cout << "\nTotal Filled : " << p.count() << endl;

    p.printarray();

    p.edit(0, 1);
    p.printarray();

    p.del(0);
    p.printarray();

    cout << "\nItem at index 1 : " << p.getitem(1) << endl;

    return 0;
}
