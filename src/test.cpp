#include <iostream>
#include <string>
#include "Value.h"
#include "ExprC.h"

using namespace Lispy;

bool testNum() {
   int expected = 5;
   NumC five(5);

   Value* addInterp = five.interp();
   NumV *n = dynamic_cast<NumV*>(addInterp);
   if (!n) {
      std::cerr << "Things are bad" << std::endl;
      return false;
   }

   return expected == n->val();
}

bool testAdd() {
   int expected = 15;
   AddC add(new NumC(5), new NumC(10));
   Value* addInterp = add.interp();
   NumV *n = dynamic_cast<NumV*>(addInterp);
   if (!n) {
      std::cerr << "Things are bad" << std::endl;
      return false;
   }

   return expected == n->val();
}

bool testNestedAdd() {
   int expected = 35;

   AddC outer(
         new AddC(new NumC(5), new NumC(10)),
         new NumC(20));

   Value* addInterp = outer.interp();
   NumV *n = dynamic_cast<NumV*>(addInterp);
   if (!n) {
      std::cerr << "Things are bad" << std::endl;
      return false;
   }

   return expected == n->val();
}

/**
 * Tests that we don't lost memory when the arguments to AddC are pointers to
 * heap data, not stack variables.
 */
bool testDynamicallyAllocatedAdd() {
   AddC add(new NumC(5), new NumC(10));
   return true;
}

int main() {
   testNum();
   testAdd();
   testNestedAdd();
   testDynamicallyAllocatedAdd();
}
