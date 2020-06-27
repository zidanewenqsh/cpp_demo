//
// Created by wen on 2020/6/15.
//

#include "utils.h"
void tensor_property(const torch::Tensor &tensor_data) {
    cout << "dtype() " << tensor_data.dtype() << endl;
    cout << "device() " << tensor_data.device() << endl;
    cout << "numel() " << tensor_data.numel() << endl;
    cout << "ndimension() " << tensor_data.ndimension() << endl;
    cout << "dim() " << tensor_data.dim() << endl;
    cout << "sizes() " << tensor_data.sizes() << endl;
    cout << "size(0) " << tensor_data.size(0) << endl;
    cout << "numpy_T() " << tensor_data.numpy_T().sizes() << endl;
    if (2 == tensor_data.dim()) {
        cout << "t() " << tensor_data.reshape({6, 4}).t().sizes() << endl;
    }
    cout << "tensor_data" << tensor_data << endl;
}

void tensor_operator(torch::Tensor &t1, torch::Tensor &t2) {
    cout << "t1" << endl << t1 << endl;
    cout << "t2" << endl << t2 << endl;
    cout << "+" << endl << t1 + t2 << endl;
    cout << "-" << endl << t1 - t2 << endl;
    cout << "*" << endl << t1 + t2 << endl;
    cout << "/" << endl << t1 / t2 << endl;
    cout << "add" << endl << t1.add(t2) << endl;
    cout << "sub" << endl << t1.sub(t2) << endl;
    cout << "mul" << endl << t1.mul(t2) << endl;
    cout << "div" << endl << t1.div(t2) << endl;
    cout << "true_divide" << endl << t1.true_divide(t2) << endl;
    cout << "floor_divide" << endl << t1.floor_divide(t2) << endl;
    cout << "matmul" << endl << t1.matmul(t2) << endl;
    cout << "mm" << endl << t1.mm(t2) << endl;
}
