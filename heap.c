#include <Python.h>

typedef struct {
    PyObject_HEAD
    /* Type-specific fields go here. */
} heap_HeapObject;

static PyTypeObject heap_BinaryHeapType = {
    /* Everything about object */
    PyVarObject_HEAD_INIT(NULL, 0)
    "heap.BinaryHeap",             /* tp_name */
    sizeof(heap_HeapObject), /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    0,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    0,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,        /* tp_flags */
    "Binary heap objects",           /* tp_doc: heap.BinaryHeap.__doc__ */
};

static PyModuleDef heap_module = {
    /* Info about module */
    PyModuleDef_HEAD_INIT,
    "heap", /* __name__ */
    "Module implements different heaps", /* __doc__ */
    -1, /* methods are here */
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL
};

PyMODINIT_FUNC PyInit_heap(void)
{
    PyObject* m;

    heap_BinaryHeapType.tp_new = PyType_GenericNew;
    if (PyType_Ready(&heap_BinaryHeapType) < 0)
        return NULL;

    m = PyModule_Create(&heap_module);
    if (m == NULL)
        return NULL;

    Py_INCREF(&heap_BinaryHeapType);
    // BinaryHeap - what we should type to create a object of this type
    PyModule_AddObject(m, "BinaryHeap", (PyObject *)&heap_BinaryHeapType);
    return m;
}
