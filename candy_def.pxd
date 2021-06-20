# distutils: language = c++
# distutils: sources = src/candybar.cpp
# cython: c_string_type=unicode, c_string_encoding=utf8

# Declare the class with cdef
from libcpp cimport bool
from libcpp.string cimport string
cdef extern from "include/candybar.h":
    cdef cppclass CandyBar:
        CandyBar(int, string, int, bool) except +
        void update(int)
        void set_total(int)
        void set_message(string)
        void set_left_justified(bool)
