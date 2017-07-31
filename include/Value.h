#pragma once

namespace Lispy {
   class Value {
      public:
         virtual ~Value();
         virtual std::string serialize() = 0;
   };

   class NumV : public Value {
      public:
         ~NumV();
         NumV(int num);
         int val();
         std::string serialize();
      private:
         int n;
   };

   class BoolV : public Value {
      public:
         BoolV(bool boolean);
         bool val();
         std::string serialize();
      private:
         bool b;
   };
}
