#include <string>
#include "Value.h"
#include "ExprC.h"

Lispy::Value::~Value() {}
Lispy::NumV::NumV(int num): _num(num) {}
Lispy::NumV::~NumV() {}

std::string Lispy::NumV::serialize() {
   return std::to_string(this->_num);
}

int Lispy::NumV::val() {
   return this->_num;
}

Lispy::BoolV::BoolV(bool boolean): _boolean(boolean) {}
bool Lispy::BoolV::val() {
   return this->_boolean;
}

std::string Lispy::BoolV::serialize() {
   return std::to_string(this->_boolean);
}
