#include <string>
#include <exception>
#include "Value.h"
#include "ExprC.h"

Lispy::ExprC::ExprC(): _value(nullptr) {}
Lispy::ExprC::~ExprC() {
   delete this->_value;
}

Lispy::NumC::~NumC() {}
Lispy::NumC::NumC(int num): _num(num) {}

Lispy::Value* Lispy::NumC::interp() {
   this->_value = new NumV(this->_num);
   return this->_value;
}

Lispy::BoolC::BoolC(bool boolean): _boolean(boolean) {}
Lispy::Value* Lispy::BoolC::interp() {
   this->_value = new BoolV(this->_boolean);
   return this->_value;
}

Lispy::AddC::AddC(ExprC* left, ExprC* right): _left(left), _right(right) {}
Lispy::AddC::~AddC() {
   delete this->_left;
   delete this->_right;
}

Lispy::Value* Lispy::AddC::interp() {
   Value* l = this->_left->interp();
   Value* r = this->_right->interp();

   NumV *lv = dynamic_cast<NumV*>(l);
   if (!lv) {
      throw std::exception();
   }

   NumV *rv = dynamic_cast<NumV*>(r);
   if (!rv) {
      throw std::exception();
   }

   this->_value = new Lispy::NumV(lv->val() + rv->val());
   return this->_value;
}
