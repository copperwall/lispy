#pragma once
#include <string>
#include <unordered_map>

namespace Lispy {
   class Value {
      public:
         virtual ~Value();
         virtual std::string serialize() = 0;
   };

   // Env should just be an unordered_map
   typedef std::unordered_map<std::string, Value*> Env;

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
