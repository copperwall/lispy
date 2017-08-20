#pragma once
#include <string>
#include <unordered_map>

namespace Lispy {
   /**
    * A Value is the type returned by the interp method of the ExprC type
    * A Value represents the result of interpreting an expression.
    *
    * Every Value subclass implements a serialize function that returns the
    * string value of the subclass. For example, calling serialize on a NumV
    * (number value) would print the string representation of the int value of
    * that object.
    */
   class Value {
      public:
         virtual ~Value();
         virtual std::string serialize() = 0;
   };

   /**
    * An Env is the environment used to lookup and store variables in.
    *
    * It is an unordered_map where variable names are the keys to the variable
    * values.
    */
   typedef std::unordered_map<std::string, Value*> Env;

   /**
    * An ExprC is the superclass for all expression types.
    *
    * All types that implement ExprC have an interp method that takes an Env
    * and returns a Value*.
    */
   class ExprC {
      public:
         ExprC();
         virtual ~ExprC();
         virtual Value* interp(Env env) = 0;
      protected:
         // Handle for a dynamically allocated Value subclass.
         Value* _value;
   };
}
