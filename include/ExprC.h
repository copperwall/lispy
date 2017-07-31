#pragma once
#include <string>
#include "Value.h"

namespace Lispy {
   class ExprC {
      public:
         ExprC();
         virtual ~ExprC();
         virtual Value* interp() = 0;
      protected:
         // Handle for a dynamically allocated Value subclass.
         Value* v;
   };

   class NumC : public ExprC {
      public:
         ~NumC();
         NumC(int num);
         Value* interp();
      private:
         int n;
   };

   class BoolC : public ExprC {
      public:
         BoolC(bool boolean);
         Value* interp();
      private:
         bool b;
   };

   class AddC : public ExprC {
      public:
         ~AddC();
         AddC(ExprC* l, ExprC* r);
         Value* interp();
      private:
         ExprC* left;
         ExprC* right;
   };
}
