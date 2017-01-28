#include <Python.h>
#include <stdio.h>
#include <string.h>

static PyObject *reverse_string(PyObject *self, PyObject *args) {
    const char *string;
    // cделать тайминг быстро реверса стандартного и этого?
    if (!PyArg_ParseTuple(args, "s", &string)) {
        return NULL;
    }

    /* get range */
    char *start = string;
    char *end = start + strlen(string) - 1; /* -1 for \0 */
    char temp;

    /* reverse */
    while (end > start)
    {
        /* swap */
        temp = *start;
        *start = *end;
        *end = temp;

        /* move */
        ++start;
        --end;
    }

    return Py_BuildValue("s", string);
    //Py_RETURN_NONE;
}

static PyMethodDef ownmod_methods[] = {
    { 
        "reverse_string", // name of function in python interpreter
        reverse_string, // function declaration
        METH_VARARGS, // special macros about function arguments
        "function, that reverse strings" // doc for function in python interpreter
    },
    { NULL, NULL, 0, NULL }
};

static PyModuleDef simple_module = {
    /* Info about module */
    PyModuleDef_HEAD_INIT,
    "sequences", // simple.__name__ 
    "Module for working with sequences", // simple.__doc__ 
    -1, 
    ownmod_methods, // methods are here 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL
};

PyMODINIT_FUNC PyInit_sequences(void)
{
    PyObject* m;
    // creating module object
    m = PyModule_Create(&simple_module);
    if (m == NULL)
        return NULL;

    return m;
}
