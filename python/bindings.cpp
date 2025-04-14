#include <pybind11/pybind11.h>  
#include "inference.cpp"  

PYBIND11_MODULE(cpp_inference, m) {  
  m.def("run_inference", &run_inference, "Run ONNX model in C++");  
}  