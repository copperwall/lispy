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

Lispy::ClosV::~ClosV() {
   // This is kind of bad, if we just pass the pointer from LamC to ClosV, then
   // we'll double delete it or something when the AST gets destructed.
   //
   // Maybe this is a good reason to use shared smart pointers.
}
Lispy::ClosV::ClosV(std::vector<std::string> params, ExprC* body, Env env)
   : _params(params), _body(body), _env(env)  {}

std::string Lispy::ClosV::serialize() {
   return "<procedure>";
}
