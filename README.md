# lispy

This is a project to write a tiny lisp using C++.

## Interpreter

The interpreter is heavily inspired from a programming languages class I took in school, but with a more OO spin this time. Each expression type has an `interp` method that takes an `Env`, which is a typedef'd `std::unordered_map<std::string, Value*>`.

Supported expressions
* NumC (number literal)
* BoolC (boolean literal)
* IdC (symbol literal)
* AddC (addition expression)
* LamC (anonymous function expressions)
* AppC (function application)
* Ifs coming soon...

Supported values:
* NumV (number value)
* ClosV (function value)
* BoolV (boolean value)
* Strings coming soon...

## Parser

The parser will come along after the interpreter is all set up.
