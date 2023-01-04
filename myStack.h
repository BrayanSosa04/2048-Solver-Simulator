#include <iostream>
#include <fstream>

using namespace std;

template <typename T> //or <class T>, they are equivalent
struct snode
{
  T value;
  snode<T>* next;
};

template <typename T> //or <class T>, they are equivalent
class myStack
{
private:
  snode<T>* theTop;
  int size;
public:
  myStack() {theTop = nullptr; size = 0;}
  int getSize() {return size;}
  bool isEmpty() {return theTop == nullptr;}
  T top() {return theTop->value;}
  void push(T a)
  {
    // create new snode
    snode<T>* temp = new snode<T>();
    temp->value = a;
    // update pointer
    temp->next = theTop;
    // update top
    theTop = temp; 

    size = size + 1;
  }
  void pop()
  {
    snode<T>* temp = theTop;
    theTop = theTop->next;
    delete temp; 

    size = size - 1;
  }
  void print(ofstream& ofs_)
  {
    snode<T>* cur = theTop;
    while(cur != nullptr)
    {
      ofs_ << cur->value << endl;
      cur = cur->next;
    }
          
  }
  void printPop(ofstream& ofs_) //this prints and pops at the same time
  {
    snode<T>* cur = theTop;
    while(cur != nullptr)
    {
      ofs_ << cur->value << endl;
      cur = cur->next;
      pop();
      size = size -1;
    }
  }
};