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

Lispy::Value* Lispy::NumC::interp(Env env) {
   this->_value = new NumV(this->_num);
   return this->_value;
}

Lispy::BoolC::BoolC(bool boolean): _boolean(boolean) {}
Lispy::Value* Lispy::BoolC::interp(Env env) {
   this->_value = new BoolV(this->_boolean);
   return this->_value;
}

Lispy::AddC::AddC(ExprC* left, ExprC* right): _left(left), _right(right) {}
Lispy::AddC::~AddC() {
   delete this->_left;
   delete this->_right;
}

Lispy::Value* Lispy::AddC::interp(Env env) {
   Value* l = this->_left->interp(env);
   Value* r = this->_right->interp(env);

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

Lispy::IdC::IdC(std::string sym): _sym(sym) {}
Lispy::Value* Lispy::IdC::interp(Env env) {
   // TODO: Add better error message.
   return env.at(this->_sym);
}

Lispy::LamC::~LamC() {
   delete this->_body;
}
Lispy::LamC::LamC(std::vector<std::string> params, ExprC* body): _params(params), _body(body) {}

Lispy::Value* Lispy::LamC::interp(Env env) {
   this->_value = new ClosV(this->_params, this->_body, env);
   return this->_value;
}

Lispy::AppC::~AppC() {
   delete this->_func;

   for (auto i = _args.begin(); i != _args.end(); ++i) {
      delete *i;
   }
}
Lispy::AppC::AppC(ExprC* func, std::vector<ExprC*> args): _func(func), _args(args) {}

Lispy::Value* Lispy::AppC::interp(Env env) {
   Value* clos = this->_func->interp(env);

   ClosV* cv = dynamic_cast<ClosV*>(clos);
   if (!cv) {
      // Can't apply a non-function value.
      throw std::exception();
   }

   const std::vector<std::string>& params = cv->params();

   if (params.size() != this->_args.size()) {
      // wrong arity
      throw std::exception();
   }

   // Copy environment
   Env newEnv(env);

   for (int i = 0; i < this->_args.size(); i++) {
      newEnv[params[i]] = (this->_args[i])->interp(env);
   }

   return cv->body()->interp(newEnv);
}

Lispy::IfC::~IfC() {
   delete this->_predicate;
   delete this->_t;
   delete this->_f;
}

Lispy::IfC::IfC(ExprC* predicate, ExprC* t, ExprC* f): _predicate(predicate), _t(t), _f(f) {}

Lispy::Value* Lispy::IfC::interp(Env env) {
   Value* v = this->_predicate->interp(env);
   BoolV* b = dynamic_cast<BoolV*>(v);

   if (!b) {
      // Needs to be boolean value
      throw std::exception();
   }

   if (b->val()) {
      return this->_t->interp(env);
   } else {
      return this->_f->interp(env);
   }
}
