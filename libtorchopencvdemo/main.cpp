#include "header.h"
#include "utils.h"

void fun() {
    at::Tensor t = torch::arange(24, torch::kFloat).reshape({1, 2, 3, 4});

//    cout << "t.dtype() " << t.dtype() << endl;
//    cout << "t.device() " << t.device() << endl;
//    cout << "t.numel() " << t.numel() << endl;
//    cout << "t.ndimension() " << t.ndimension() << endl;
//    cout << "t.dim() " << t.dim() << endl;
//    cout << "t.sizes() " << t.sizes() << endl;
//    cout << "t.size(0) " << t.size(0) << endl;
//    cout << "t.numpy_T() " << t.numpy_T().sizes() << endl;
    cout << "t.numpy_T() " <<   << endl;
    cout<<"" << t << endl;
}

int main() {
    fun();
    std::cout << "Hello, World!" << std::endl;

    return 0;
}
