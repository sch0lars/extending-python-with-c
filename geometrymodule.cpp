#include "python3.10/Python.h"    // NOTE: You may have to change this, depending on where your Python.h header file is located
#include "./geometry.hpp"

PyModuleDef geometry_module {
  PyModuleDef_HEAD_INIT,
  "geometry",
  "Contains functions for various geometric objects",
  -1
};

/* We extend the Circle class here */

typedef struct {
  PyObject_HEAD
  Circle* circleInstance;
} CircleObject;

static PyObject *
circle_new(PyTypeObject *type, PyObject *args, PyObject *kwds) {
  CircleObject *self;
  double radius;

  if (!PyArg_ParseTuple(args, "d", &radius)) {
        return NULL;
  }
  
  self = (CircleObject *)type->tp_alloc(type, 0);
  if (self != NULL) {
        self->circleInstance = new Circle(radius);
	PyObject_Init((PyObject*)self, type);
  }
  
  return (PyObject*)self;
}

static int circle_init(CircleObject* self, PyObject* args, PyObject* kwds) {
    double radius;
    if (!PyArg_ParseTuple(args, "d", &radius)) {
        return -1;
    }
    self->circleInstance = new Circle(radius);
    return 0;
}

static void circle_dealloc(CircleObject* self) {
    delete self->circleInstance;
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject* circle_get_radius(CircleObject* self, PyObject* args) {
    return Py_BuildValue("d", self->circleInstance->getRadius());
}

static PyObject* circle_get_diameter(CircleObject* self, PyObject* args) {
    return Py_BuildValue("d", self->circleInstance->getDiameter());
}

static PyObject* circle_get_area(CircleObject* self, PyObject* args) {
    return Py_BuildValue("d", self->circleInstance->getArea());
}

static PyObject* circle_get_circumference(CircleObject* self, PyObject* args) {
    return Py_BuildValue("d", self->circleInstance->getCircumference());
}

static PyMethodDef circle_methods[] = {
  {"__init__", (PyCFunction)circle_init, METH_VARARGS, "The initializer method for the Circle class."},
  {"get_radius", (PyCFunction)circle_get_radius, METH_NOARGS, "Get the radius of the circle."},
  {"get_diameter", (PyCFunction)circle_get_diameter, METH_NOARGS, "Get the diameter of the circle."},
  {"get_area", (PyCFunction)circle_get_area, METH_NOARGS, "Get the area of the circle."},
  {"get_circumference", (PyCFunction)circle_get_circumference, METH_NOARGS, "Get the circumference of the circle."},
  {NULL}  /* Sentinel */
};

static PyTypeObject CircleType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "geometry.Circle",            // tp_name
    sizeof(CircleObject),         // tp_basicsize
    0,                            // tp_itemsize
    (destructor)circle_dealloc,   // tp_dealloc
    0,                            // tp_print
    0,                            // tp_getattr
    0,                            // tp_setattr
    0,                            // tp_reserved
    0,                            // tp_repr
    0,                            // tp_as_number
    0,                            // tp_as_sequence
    0,                            // tp_as_mapping
    0,                            // tp_hash
    0,                            // tp_call
    0,                            // tp_str
    0,                            // tp_getattro
    0,                            // tp_setattro
    0,                            // tp_as_buffer
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,  // tp_flags
    "Circle objects",             // tp_doc
    0,                            // tp_traverse
    0,                            // tp_clear
    0,                            // tp_richcompare
    0,                            // tp_weaklistoffset
    0,                            // tp_iter
    0,                            // tp_iternext
    circle_methods,               // tp_methods
    0,                            // tp_members
    0,                            // tp_getset
    0,                            // tp_base
    0,                            // tp_dict
    0,                            // tp_descr_get
    0,                            // tp_descr_set
    0,                            // tp_dictoffset
    (initproc)circle_init,        // tp_init
    0,                            // tp_alloc
    circle_new                    // tp_new
};

/* This is the end of the Circle methods */


/* We extend the Rectangle class here */

typedef struct {
  PyObject_HEAD
  Rectangle* rectangleInstance;
} RectangleObject;

static PyObject* rectangle_new(PyTypeObject* type, PyObject* args, PyObject* kwds) {
    RectangleObject* self;
    double length;
    double width;

    if (!PyArg_ParseTuple(args, "dd", &length, &width)) {
        return NULL;
    }
    
    self = (RectangleObject*)type->tp_alloc(type, 0);
    if (self != NULL) {
      self->rectangleInstance = new Rectangle(length, width);
      PyObject_Init((PyObject*)self, type);
    }
    
    return (PyObject*)self;
}


static int rectangle_init(RectangleObject* self, PyObject* args, PyObject* kwds) {
    double length;
    double width;
    if (!PyArg_ParseTuple(args, "dd", &length, &width)) {
        return -1;
    }
    self->rectangleInstance = new Rectangle(length, width);
    return 0;
}

static void rectangle_dealloc(RectangleObject* self) {
    delete self->rectangleInstance;
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject* rectangle_get_length(RectangleObject* self, PyObject* args) {
    return Py_BuildValue("d", self->rectangleInstance->getLength());
}

static PyObject* rectangle_get_width(RectangleObject* self, PyObject* args) {
    return Py_BuildValue("d", self->rectangleInstance->getWidth());
}

static PyObject* rectangle_get_perimeter(RectangleObject* self, PyObject* args) {
    return Py_BuildValue("d", self->rectangleInstance->getPerimeter());
}

static PyObject* rectangle_get_area(RectangleObject* self, PyObject* args) {
    return Py_BuildValue("d", self->rectangleInstance->getArea());
}

static PyMethodDef rectangle_methods[] = {
  {"__init__", (PyCFunction)rectangle_init, METH_VARARGS, "The initializer method for the Rectangle class."},
  {"get_length", (PyCFunction)rectangle_get_length, METH_NOARGS, "Get the length of the rectangle."},
  {"get_width", (PyCFunction)rectangle_get_width, METH_NOARGS, "Get the width of the rectangle."},
  {"get_perimeter", (PyCFunction)rectangle_get_perimeter, METH_NOARGS, "Get the perimeter of the rectangle."},
  {"get_area", (PyCFunction)rectangle_get_area, METH_NOARGS, "Get the area of the rectangle."},
  {NULL}  /* Sentinel */
};

static PyTypeObject RectangleType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "geometry.Rectangle",         // tp_name
    sizeof(RectangleObject),      // tp_basicsize
    0,                            // tp_itemsize
    (destructor)rectangle_dealloc,// tp_dealloc
    0,                            // tp_print
    0,                            // tp_getattr
    0,                            // tp_setattr
    0,                            // tp_reserved
    0,                            // tp_repr
    0,                            // tp_as_number
    0,                            // tp_as_sequence
    0,                            // tp_as_mapping
    0,                            // tp_hash
    0,                            // tp_call
    0,                            // tp_str
    0,                            // tp_getattro
    0,                            // tp_setattro
    0,                            // tp_as_buffer
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,  // tp_flags
    "Rectangle objects",          // tp_doc
    0,                            // tp_traverse
    0,                            // tp_clear
    0,                            // tp_richcompare
    0,                            // tp_weaklistoffset
    0,                            // tp_iter
    0,                            // tp_iternext
    rectangle_methods,            // tp_methods
    0,                            // tp_members
    0,                            // tp_getset
    0,                            // tp_base
    0,                            // tp_dict
    0,                            // tp_descr_get
    0,                            // tp_descr_set
    0,                            // tp_dictoffset
    (initproc)rectangle_init,     // tp_init
    0,                            // tp_alloc
    rectangle_new                 // tp_new
};

/* This is the end of the Rectangle methods */

static struct PyModuleDef geometry_module_def = {
    PyModuleDef_HEAD_INIT,
    "geometry",  // name of the module
    NULL,        // module documentation, may be NULL
    -1,          // size of per-interpreter state of the module, or -1 if the module keeps state in global variables.
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC PyInit_geometry(void) {
    PyObject* m;

    if (PyType_Ready(&CircleType) < 0 || PyType_Ready(&RectangleType) < 0)
        return NULL;

    m = PyModule_Create(&geometry_module_def);
    if (m == NULL)
        return NULL;

    Py_INCREF(&CircleType);
    PyModule_AddObject(m, "Circle", (PyObject*)&CircleType);

    Py_INCREF(&RectangleType);
    PyModule_AddObject(m, "Rectangle", (PyObject*)&RectangleType);

    return m;
}
