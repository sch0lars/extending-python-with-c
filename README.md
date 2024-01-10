# Extending Python with C++

This repo serves as a `Hello World` for extending Python using C++.


## Custom C++ Classes

In this tutorial, we will be creating two classes, `Circle` and `Rectangle`, which we will extend to Python via a module called `geometry`. These classes will each have their own constructors, attributes, and methods, which are defined in `geometry.cpp`.

### Circle
| Name             | Type        | Arguments       | Returns  |
|------------------|-------------|-----------------|----------|
| Circle           | Constructor | `double` radius | `Circle` |
| getRadius        | Method      | `void`          | `double` |
| getDiameter      | Method      | `void`          | `double` |
| getArea          | Method      | `void`          | `double` |
| getCircumference | Method      | `void`          | `double` |

### Rectangle

| Name         | Type        | Arguments                       | Returns     |
|--------------|-------------|---------------------------------|-------------|
| Rectangle    | Constructor | `double` length, `double` width | `Rectangle` |
| getLength    | Method      | `void`                          | `double`    |
| getWidth     | Method      | `void`                          | `double`    |
| getPerimeter | Method      | `void`                          | `double`    |
| getArea      | Method      | `void`                          | `double`    |

## Files

The following files are included in this project:
- `geometry.hpp`
  - This file declares the classes `Circle` and `Rectangle`
- `geometry.cpp`
  - This file defines the classes `Circle` and `Rectangle`
- `geometrymodule.cpp`
  - This file extends the C++ classes `Circle` and `Rectangle` to Python
- `hello_world.py`
  - This file exemplifies the extension of the C++ classes
- `setup.py`
  - This is the setup file for the Python module
- `build.sh`
  - This is a shell script which will compile the C++ code into a shared Python library
  - The file produced will be in [https://docs.python.org/3/c-api/stable.html](ABI3) format

## C API

### C API Objects

| Object Name    | Description                                                                                                                                                                                  |
|----------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| `PyObject`     | Represents a Python object in C.<br>Used as the base type for all Python objects.                                                                                                            |
| `PyTypeObject` | Represents the type of a Python object.<br>Contains information about the type, including methods, attributes, and other details.<br>Used to define new Python types in C extension modules. |
| `PyMethodDef`  | Defines a method in a Python extension type.<br>Contains information about the method, including its name, implementation, and calling convention.                                           |
| `PyModuleDef`  | Defines the structure of a Python module.<br>Contains information such as the module's name, documentation, and method definitions.                                                          |

### C API Methods

| Method Name        | Description                                                                                                       |
|--------------------|-------------------------------------------------------------------------------------------------------------------|
| `PyArg_ParseTuple` | Parses Python arguments from a tuple.<br>Used to extract values from Python function arguments.                   |
| `PyObject_Init`    | Initializes a Python object.<br>Used to initialize the CircleObject and RectangleObject instances.                |
| `Py_BuildValue`    | Creates a new Python object from a C value.<br>Used to build Python values to return from C functions.            |
| `PyModule_Create`  | Creates a new Python module.<br>Used to create the main module for the extension.                                 |
| `Py_INCREF`        | Increments the reference count of a Python object.<br>Used for memory management to avoid premature deallocation. |
| `Py_DECREF`        | Decrements the reference count of a Python object.<br>Used for memory management to avoid premature deallocation. |
| `PyType_Ready`     | Initializes a Python type.<br>Used to ensure the custom classes `Circle` and `Rectangle` are ready for use.       |

