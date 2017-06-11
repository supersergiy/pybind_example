#include <pybind11/pybind11.h>

int add(int i, int j) {
    return i + j;
}

namespace py = pybind11;

PYBIND11_PLUGIN(func_example) {
    py::module m("func_example", "pybind11 example plugin");

    m.def("add", &add, "A function which adds two numbers");
    
    return m.ptr();
}
