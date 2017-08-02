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
}
