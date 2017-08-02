#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include "Base.h"
#include "Value.h"
#include "ExprC.h"

using namespace Lispy;

bool testNum() {
   int expected = 5;
   NumC five(5);
   Env e;

   Value* addInterp = five.interp(e);
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
   Env e;

   Value* addInterp = add.interp(e);
   NumV *n = dynamic_cast<NumV*>(addInterp);
   if (!n) {
      std::cerr << "Things are bad" << std::endl;
      return false;
   }

   return expected == n->val();
}

bool testNestedAdd() {
   int expected = 35;
   Env e;

   AddC outer(
         new AddC(new NumC(5), new NumC(10)),
         new NumC(20));

   Value* addInterp = outer.interp(e);
   NumV *n = dynamic_cast<NumV*>(addInterp);
   if (!n) {
      std::cerr << "Things are bad" << std::endl;
      return false;
   }

   return expected == n->val();
}

bool testBool() {
   bool expected = true;
   BoolC b(true);
   Env e;

   Value* result = b.interp(e);
   BoolV *n = dynamic_cast<BoolV*>(result);
   if (!n) {
      std::cerr << "Things are bad" << std::endl;
      return false;
   }

   return expected == n->val();
}

bool testLam() {
   Env e;
   std::vector<std::string> params;
   params.push_back("one");
   params.push_back("two");

   LamC lam(params, new NumC(10));
   Value* result = lam.interp(e);

   ClosV *c = dynamic_cast<ClosV*>(result);
   if (!c) {
      std::cerr << "Things are bad" << std::endl;
      return false;
   }
   c->serialize();
   return true;
}

int main() {
   assert(testNum());
   assert(testAdd());
   assert(testNestedAdd());
   assert(testBool());
   assert(testLam());
}
