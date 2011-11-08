/* 
 * File:   main.cpp
 * Author: ivan
 *
 * Created on November 8, 2011, 9:01 PM
 */

#include "Pointer.h"

int main(int argc, char** argv)
{
  Pointer<int> p(new int);
  {
    Pointer<int> p2 = p;
    *p2 = 3;
    {
      Pointer<int> p3;
      p3 = p2;
      log(*p3);
    }
    log(*p2);
  }
  log(*p);
  log("exiting");
  return 0;
}