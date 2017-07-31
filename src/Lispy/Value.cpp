#include <string>
#include "Value.h"
#include "ExprC.h"

Lispy::Value::~Value() {}
Lispy::NumV::NumV(int num): n(num) {}
Lispy::NumV::~NumV() {}

std::string Lispy::NumV::serialize() {
   return std::to_string(n);
}

int Lispy::NumV::val() {
   return this->n;
}

Lispy::BoolV::BoolV(bool boolean): b(boolean) {}
bool Lispy::BoolV::val() {
   return this->b;
}

std::string Lispy::BoolV::serialize() {
   return std::to_string(this->b);
}
