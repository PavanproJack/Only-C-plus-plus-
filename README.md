# Namespaces

A namespace is a collection of symbols.

Namespaces provide a method for preventing name conflicts in large projects.

Symbols declared inside a namespace block are placed in a named scope that prevents them from being mistaken for identically-named symbols in other scopes.

The 'using' directive tells the compiler to use that namespace in the current scope. The ‘using’ directive can also be used to refer to a particular item within a namespace. For eg: 
using std::cout;

