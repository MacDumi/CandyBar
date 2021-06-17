#include "candybar.h"
#include <pybind11/pybind11.h>
namespace py = pybind11;

PYBIND11_MODULE(candy_bar, m) {
    py::class_<CandyBar>(m, "CandyBar")
        .def(py::init<int, std::string, int, bool>(), "Create a progress bar",
                            py::arg("total")=100, py::arg("message")="",
                            py::arg("width")=0, py::arg("left_justified")=true)
        .def("update", &CandyBar::update, "Update the progress bar",
                            py::arg("current"))
        .def("set_left_justified", &CandyBar::set_left_justified,
                "Change the justification fo the progress bar",
                py::arg("left_justified")=true)
        .def("set_total", &CandyBar::set_total,
                "Set the max value of the progress bar", py::arg("total"))
        .def("set_message", &CandyBar::set_message,
                       "Set the message displayed before the progress bar",
                             py::arg("message"));
#ifdef VERSION_INFO
    m.attr("__version__") = Py_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
