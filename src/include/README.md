* The primary purpose of a header file is to propagate declarations to code files. They allow us to put declarations in one location and then import them wherever we need them. This can save a lot of typing in multi-file programs.

* When you #include a file, the content of the included file is inserted at the point of inclusion. This provides a useful way to pull in declarations from another file.


1. Header files should generally not contain function and variable definitions
2. Source files should #include their paired header file (if one exists).
3. Use double quotes to include header files that you’ve written or are expected to be found in the current directory. Use angled brackets to include headers that come with compiler or OS.
4. When including a header file from the standard library, use the version without the .h extension if it exists. User-defined headers should still use a .h extension.
5. Use Header guards
