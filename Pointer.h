/* 
 * File:   Pointer.h
 * Author: ivan
 *
 * Created on November 9, 2011, 1:08 AM
 */

#ifndef SMART_POINTER
#define	SMART_POINTER

#include <iostream>

#define log(a) (std::cout << (a) << std::endl)

template<class T>
class Pointer
{
  private:
    T* ptr;
    int* counter;
    void copy(Pointer<T> &p)
    {
      this->ptr = p.ptr;
      this->counter = p.counter;
      ++(*counter);
    }
  public:
    // default constructur
    Pointer(): ptr(NULL), counter(NULL) {}
    
    // explicit constructur so there will be no implicit casts!
    explicit Pointer(T* ptr)
    {
      this->ptr = ptr;
      try
      {
        this->counter = new int(1);
      }
      catch(std::bad_alloc ex)  // delete the ptr if can't allocate the counter so there will be no memory leaked!
      {
        delete ptr;
        throw ex;
      }
      log("initializing!");
    }
    
    Pointer(Pointer<T> &p)
    {
      log("copy-constructor");
      copy(p);
    }
    
    Pointer<T> &operator=(Pointer<T> &p)
    {
      log("=");
      copy(p);
      return *this;
    }
    
    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }
    
    ~Pointer()
    {
      log("destructor...");
      if(counter && --(*counter) == 0)
      {
        log("deleting");
        delete ptr;
      }      
    }
};

#endif	/* SMART_POINTER */