#pragma once
#include <string>
#include <vector>
#include "Base.h"

// All Value subclasses
namespace Lispy {
   class NumV : public Value {
      public:
         ~NumV();
         NumV(int num);
         int val();
         std::string serialize();
      private:
         int _num;
   };

   class BoolV : public Value {
      public:
         BoolV(bool boolean);
         bool val();
         std::string serialize();
      private:
         bool _boolean;
   };

   class ClosV : public Value {
      public:
         ~ClosV();
         ClosV(std::vector<std::string> params, ExprC* body, Env env);
         std::string serialize();
      private:
         std::vector<std::string> _params;
         ExprC* _body;
         Env _env;
   };
}
