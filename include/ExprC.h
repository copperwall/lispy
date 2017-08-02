#pragma once
#include <string>
#include "Base.h"

// All ExprC subclasses
namespace Lispy {
   class NumC : public ExprC {
      public:
         ~NumC();
         NumC(int num);
         Value* interp(Env env);
      private:
         int _num;
   };

   class BoolC : public ExprC {
      public:
         BoolC(bool boolean);
         Value* interp(Env env);
      private:
         bool _boolean;
   };

   class AddC : public ExprC {
      public:
         ~AddC();
         AddC(ExprC* left, ExprC* right);
         Value* interp(Env env);
      private:
         ExprC* _left;
         ExprC* _right;
   };
}
