// Dynamic Array Implementation
// Supports insert, delete, append, resize operations

#include <iostream>
#include <stdio.h>
using namespace std;

class Darray
{
private:
    int capacity;
    int lastindex;
    int *ptr;

public:
    Darray();
    Darray(Darray &);
    Darray& operator=(Darray &);

    void doublearray();
    void halfarray();

    void createarray(int);
    void insert(int,int);
    void append(int);

    int getitem(int);

    bool isempty();
    bool isfull();

    void del(int);
    void edit(int,int);

    int count();
    int getcapacity();

    void shortarray();
    void printarray();

    ~Darray();
};


Darray::Darray()
{
    capacity=0;
    lastindex=-1;
    ptr=NULL;
}


Darray::Darray(Darray &arr)
{
    capacity=arr.capacity;
    lastindex=arr.lastindex;

    ptr=new int[capacity];

    for(int i=0;i<=lastindex;i++)
    {
        ptr[i]=arr.ptr[i];
    }
}


Darray& Darray::operator=(Darray &arr)
{
    if(this==&arr)
        return *this;

    capacity=arr.capacity;
    lastindex=arr.lastindex;

    if(ptr!=NULL)
        delete []ptr;

    ptr=new int[capacity];

    for(int i=0;i<=lastindex;i++)
    {
        ptr[i]=arr.ptr[i];
    }

    return *this;
}


void Darray::createarray(int size)
{
    capacity=size;
    lastindex=-1;

    if(ptr!=NULL)
        delete []ptr;

    ptr=new int[capacity];
}


void Darray::insert(int index,int data)
{
    int i;

    try
    {
        if(index<0 || index>lastindex+1)
            throw 1;

        if(isfull())
            doublearray();


        for(i=lastindex;i>=index;i--)
        {
            ptr[i+1]=ptr[i];
        }

        ptr[index]=data;
        lastindex++;
    }

    catch(int)
    {
        cout<<"Invalid Index";
    }
}


void Darray::append(int data)
{
    if(isfull())
        doublearray();

    lastindex++;
    ptr[lastindex]=data;
}


int Darray::getitem(int index)
{
    try
    {
        if(index<0 || index>lastindex)
            throw 1;

        return ptr[index];
    }

    catch(int)
    {
        cout<<"\nInvalid Index or Array is empty";
    }

    return -1;
}


bool Darray::isempty()
{
    return lastindex==-1;
}


bool Darray::isfull()
{
    return lastindex==capacity-1;
}


void Darray::del(int index)
{
    try
    {
        if(index<0 || index>lastindex)
            throw 1;


        for(int i=index;i<lastindex;i++)
        {
            ptr[i]=ptr[i+1];
        }

        lastindex--;


        if(capacity>1 && lastindex+1<=capacity/2)
            halfarray();
    }

    catch(int)
    {
        cout<<"Invalid Index or underflow";
    }
}



void Darray::edit(int index,int data)
{
    try
    {
        if(index<0 || index>lastindex)
            throw 1;

        ptr[index]=data;
    }

    catch(int)
    {
        cout<<"Index is invalid";
    }
}



void Darray::shortarray()
{
    int n=capacity/2;

    while(lastindex!=n-1)
    {
        lastindex--;
    }

    halfarray();
}



int Darray::count()
{
    return lastindex+1;
}



int Darray::getcapacity()
{
    return capacity;
}



void Darray::printarray()
{
    cout<<"Array ";

    for(int i=0;i<=lastindex;i++)
    {
        cout<<ptr[i]<<" ";
    }

    cout<<endl;
}



Darray::~Darray()
{
    delete []ptr;
}



void Darray::doublearray()
{
    int *temp=new int[capacity*2];

    for(int i=0;i<=lastindex;i++)
    {
        temp[i]=ptr[i];
    }

    delete []ptr;

    ptr=temp;

    capacity*=2;
}



void Darray::halfarray()
{
    if(capacity<=1)
        return;


    int *temp=new int[capacity/2];


    for(int i=0;i<=lastindex;i++)
    {
        temp[i]=ptr[i];
    }


    delete []ptr;

    ptr=temp;

    capacity/=2;
}



int main()
{
    Darray p;


    p.createarray(4);


    p.insert(0,2);
    p.insert(1,3);
    p.insert(2,4);


    p.append(5);
    p.append(6);
    p.append(7);
    p.append(8);
    p.append(9);


    cout<<endl<<"Empty "<<boolalpha<<p.isempty();

    cout<<endl<<"Full "<<boolalpha<<p.isfull();

    cout<<endl<<"Capacity "<<p.getcapacity();

    cout<<endl<<"Total filled array "<<p.count()<<endl;

    p.printarray();

    p.del(4);

    p.printarray();

    return 0;
}