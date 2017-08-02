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
         Value* _value;
   };

   class NumC : public ExprC {
      public:
         ~NumC();
         NumC(int num);
         Value* interp();
      private:
         int _num;
   };

   class BoolC : public ExprC {
      public:
         BoolC(bool boolean);
         Value* interp();
      private:
         bool _boolean;
   };

   class AddC : public ExprC {
      public:
         ~AddC();
         AddC(ExprC* left, ExprC* right);
         Value* interp();
      private:
         ExprC* _left;
         ExprC* _right;
   };
}
