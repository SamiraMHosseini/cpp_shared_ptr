# Using std::shared_ptr for char[] and int[] Arrays, and Custom Deleters to Manage Dynamic Memory in C++

The make_shared function in C++ is used to create shared pointers to dynamically allocated objects. However, it does not work with arrays because it requires a single object type to be created, and arrays are made up of multiple objects of the same type.

When you use make_shared to create a shared pointer, it needs to know the type of object to create, so it can allocate the appropriate amount of memory and call the constructor for that object. With arrays, it's not clear how many objects to create and how to construct them.
The std::make_shared function in C++ is primarily designed to allocate and construct a single object of a given type, rather than an array of objects. The reason why make_shared does not work for arrays in C++ is because it expects a constructor argument list, which is used to initialize a single object of the specified type. Arrays, on the other hand, require a different kind of initialization than single objects. When you allocate an array, you typically need to specify the number of elements in the array, and each element needs to be constructed separately using a loop or other means.

In other words, if you want to create an array of objects instead of a single object, you cannot use std::make_shared. This is because std::make_shared expects constructor arguments for a single object, not for an array of objects. To create an array of objects, you need to use new[] to dynamically allocate the array, and then create a std::shared_ptr object that points to the array.

Notes: Note that when you use std::shared_ptr with an array allocated using new[], you need to provide a custom deleter to ensure that the array is properly deallocated. This is because the default deleter for std::shared_ptr is designed to deallocate a single object created using new, not an array created using new[]. You should always provide a custom deleter to std::shared_ptr when you allocate an array using new[].

https://stackoverflow.com/questions/43631415/using-shared-ptr-with-char/75500472#75500472
