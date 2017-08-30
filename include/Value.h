#pragma once
#include <string>
#include <vector>
#include "Base.h"

// All Value subclasses
namespace Lispy {
   /**
    * Number Value
    *
    * Represents a number value.
    */
   class NumV : public Value {
      public:
         ~NumV();
         NumV(int num);
         int val();
         std::string serialize();
      private:
         int _num;
   };

   /**
    * Boolean Value
    *
    * Represents a boolean value. A BoolV can result from interpreting a BoolC
    * or an equality expression (TODO).
    */
   class BoolV : public Value {
      public:
         BoolV(bool boolean);
         bool val();
         std::string serialize();
      private:
         bool _boolean;
   };

   /**
    * Closure Value
    *
    * A ClosV is composed of a list of parameter names, an ExprC body, and an
    * environment. The environment bound to a closure includes the closure's
    * parameters, and the environment from when the function expression was
    * defined. This gives the ClosV lexical scope.
    */
   class ClosV : public Value {
      public:
         ~ClosV();
         ClosV(std::vector<std::string> params, ExprC* body, Env env);
         std::string serialize();
         const std::vector<std::string>& params();
         ExprC* body();
      private:
         std::vector<std::string> _params;
         ExprC* _body;
         Env _env;
   };
}
