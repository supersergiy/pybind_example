#include <pybind11/pybind11.h>
#include "znet.hpp"

namespace py = pybind11;

PYBIND11_MODULE(znet, m) {
    py::class_<znn::phi::Znet>(m, "znet")
        .def(py::init<>())
        .def("forward", &znn::phi::Znet::forward);
}

