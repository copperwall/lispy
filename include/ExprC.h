#pragma once
#include <vector>
#include <string>
#include "Base.h"

// All ExprC subclasses
namespace Lispy {
   /**
    * Number Expression
    *
    * A NumC represents a number literal. Interpreting a NumC should always
    * result in a NumV with the same represented number as the NumC.
    */
   class NumC : public ExprC {
      public:
         ~NumC();
         NumC(int num);
         Value* interp(Env env);
      private:
         int _num;
   };

   /**
    * Boolean Expression
    *
    * A BoolC represents a boolean literal. Interpreting a BoolC should always
    * result in a BoolV with the same represented boolean as the BoolC.
    */
   class BoolC : public ExprC {
      public:
         BoolC(bool boolean);
         Value* interp(Env env);
      private:
         bool _boolean;
   };

   /**
    * Boolean Expression
    *
    * A BoolC represents a boolean literal.
    */
   class AddC : public ExprC {
      public:
         ~AddC();
         AddC(ExprC* left, ExprC* right);
         Value* interp(Env env);
      private:
         ExprC* _left;
         ExprC* _right;
   };

   /**
    * Identifier Expression
    *
    * An IdC represents a symbol. IdCs are used to lookup variables stored in
    * an environment.
    */
   class IdC : public ExprC {
      public:
         IdC(std::string sym);
         Value* interp(Env env);
      private:
         std::string _sym;
   };

   /**
    * Function Expression
    *
    * A LamC represents a function expression or lambda. It is composed of a
    * list of string parameters and an ExprC body. A LamC has no name.
    */
   class LamC : public ExprC {
      public:
         ~LamC();
         LamC(std::vector<std::string> params, ExprC* body);
         Value* interp(Env env);
      private:
         std::vector<std::string> _params;
         ExprC* _body;
   };

   /**
    * Function Application
    *
    * An AppC represents a function application or invocation. It is composed
    * of an ExprC for the function body/expression and a list of ExprC arguments.
    *
    * When interpreted, all ExprCs in args are interpreted into Values. Those
    * Values are added to the environment and the func ExprC is evaluated with
    * that new environment.
    *
    * Creating an AppC with a func ExprC that does not evaluate into a closure
    * (ClosV) will cause an error.
    *
    * Applying a func ExprC with the wrong number of args will result in an
    * arity error.
    */
   class AppC : public ExprC {
      public:
         ~AppC();
         AppC(ExprC* func, std::vector<ExprC*> args);
         Value* interp(Env env);
      private:
         ExprC* _func;
         std::vector<ExprC*> _args;
   };
}
