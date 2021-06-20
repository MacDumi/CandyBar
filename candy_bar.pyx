# distutils: language = c++
# distutils: sources = src/candybar.cpp
# cython: c_string_type=unicode, c_string_encoding=utf8

from libcpp cimport bool
from libcpp.string cimport string

cimport candy_def as cpp

# Declare the python wrapper
cdef class CandyBar:
    cdef cpp.CandyBar *thisptr
    def __cinit__(self, int total=100, str message="",
                    int width=0, bool left_justified=True):
        cdef string msg = message.encode('UTF-8')
        self.thisptr = new cpp.CandyBar(total, msg, width, left_justified)
    def __dealloc__(self):
        del self.thisptr
    def update(self, int current):
        """ Update the progress bar """
        self.thisptr.update(current)
    def set_total(self, int total):
        """ Set the total value of the progress bar (i.e. 100%) """
        self.thisptr.set_total(total)
    def set_message(self, str message):
        """ Set the message printed before the progress bar """
        cdef string msg = message.encode('UTF-8')
        self.thisptr.set_message(msg)
    def set_left_justified(self, bool lft):
        """ Change the justification of the progress bar """
        self.thisptr.set_left_justified(lft)
