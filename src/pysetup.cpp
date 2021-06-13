#include "candybar.h"
#include <pybind11/pybind11.h>
namespace py = pybind11;

PYBIND11_MODULE(candybar, m) {
    py::class_<CandyBar>(m, "CandyBar")
        .def(py::init<int, std::string, int>(), "Create a progress bar",
                py::arg("total"), py::arg("message")="", py::arg("width")=0)
        .def("update", &CandyBar::update, "Update the progress bar",
                        py::arg("current"));
#ifdef VERSION_INFO
    m.attr("__version__") = Py_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
