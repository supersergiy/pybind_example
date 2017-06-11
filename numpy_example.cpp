#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <iostream>

namespace py = pybind11;

void twice(py::array_t<float> &xs) {
    py::buffer_info info = xs.request();
    auto ptr = static_cast<float *>(info.ptr);

    int n = 1;
    for (auto r: info.shape) {
      n *= r;
    }

    for (int i = 0; i <n; i++) {
        *ptr++ *= 2;
    }
}

void make_8(py::array_t<float, py::array::c_style | py::array::forcecast> &x)
{
    py::buffer_info info = x.request();
    auto ptr = static_cast<float *>(info.ptr);

    int n = 1;
    for (auto r: info.shape) {
      n *= r;
    }

    for (int i = 0; i < n; i++) {
        ptr[i] = 8;
        std::cout << ptr[i] << std::endl;
    }

}


PYBIND11_MODULE(numpy_example, m) {
    m.def("make_8", &make_8, "A function which makes it 8");
    m.def("twice", &twice, "A function which makes it twice");
}
   
