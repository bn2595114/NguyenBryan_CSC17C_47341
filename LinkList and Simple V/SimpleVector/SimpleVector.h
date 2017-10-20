// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

template <class T>
class SimpleVector
{
private:
    struct Link{
            T data;         //Mainly for Objects
            Link *linkPtr;  //Self Reference which when utilized forms a linked list
        };
        Link *front,*next,*temp,*end,*found;//Permanent and Temp pointers
   T *aptr;          // To point to the allocated array
   int arraySize;    // Number of elements in the array
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range
   

public:
   // Default constructor
   SimpleVector()
      { aptr = 0; arraySize = 0;}
      
   // Constructor declaration
   SimpleVector(T);
   
   // Copy constructor declaration
   SimpleVector(const SimpleVector &);
   
   // Destructor declaration
   ~SimpleVector();
   
   // Accessor to return the array size
   int size() const
      { return arraySize; }

   // Accessor to return a specific element
   void getElementAt();

   // Overloaded [] operator declaration
   T &operator[](const int &);
   
   void push_back(const T&);
   void pop_off();
};

template <class T>
void SimpleVector<T>::push_back(const T& s){
    temp=front; //Declare pointers used to step through the list
    do{
        end=temp;          //Point to the current link with a swap
        temp=temp->linkPtr; //Point to the next link
    }while(temp!=NULL);     //Your done when you hit the end
    
    Link* add=new Link;
    add->data=s;
    add->linkPtr=NULL;
    end->linkPtr=add;
    
}

template <class T>
void SimpleVector<T>::pop_off(){
    
    int n=2;
    next=front;
    for(int i=0;i<n;i++)
        next=next->linkPtr;

    next->linkPtr=NULL;
    
}

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(T s)
{
    front=new Link;
    front->data=s;
    front->linkPtr=NULL;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
   // Copy the array size.
   arraySize = obj.arraySize;
   
   // Allocate memory for the array.
   aptr = new T [arraySize];
   if (aptr == 0)
      memError();
      
   // Copy the elements of obj's array.
   for(int count = 0; count < arraySize; count++)
      *(aptr + count) = *(obj.aptr + count);
}


//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError()
{
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
void SimpleVector<T>::getElementAt()
{
    next=front;
    
    do{
        cout<<next->data;
        next=next->linkPtr;
    }while(next!=NULL);
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

template<class T>
SimpleVector<T>::~SimpleVector(){
    do{
       temp=front->linkPtr;   //Point to the next link in the list
       delete front;          //Delete the front of the list
       front=temp;            //Swap the front
    }while(front!=NULL);
}



#endif