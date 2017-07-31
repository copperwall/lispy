#include <string>
#include <exception>
#include "Value.h"
#include "ExprC.h"

Lispy::ExprC::ExprC(): v(nullptr) {}
Lispy::ExprC::~ExprC() {
   delete this->v;
}

Lispy::NumC::~NumC() {}

Lispy::NumC::NumC(int num): n(num) {}

Lispy::Value* Lispy::NumC::interp() {
   this->v = new NumV(n);
   return this->v;
}

int Lispy::NumC::val() {
   return this->n;
}

Lispy::AddC::AddC(ExprC* l, ExprC* r): left(l), right(r) {}
Lispy::AddC::~AddC() {
   delete this->left;
   delete this->right;
}

Lispy::Value* Lispy::AddC::interp() {
   Value* l = this->left->interp();
   Value* r = this->right->interp();

   NumV *lv = dynamic_cast<NumV*>(l);
   if (!lv) {
      throw std::exception();
   }

   NumV *rv = dynamic_cast<NumV*>(r);
   if (!rv) {
      throw std::exception();
   }

   this->v = new Lispy::NumV(lv->val() + rv->val());
   return this->v;
}
