//
// Created by wen on 2020/6/27.
//

#include "demo.h"
void ptr_demo(){
    auto t1 = torch::arange(9).reshape({ 3, 3 });
    torch::Tensor* p1 = &t1;
    cout << *p1 << endl;
    auto t2 = torch::tensor({ 1,2,3 }, torch::kFloat);
    auto t3 = torch::tensor({ 1,2,3,4 }, torch::kFloat).reshape({2,2});
    torch::Tensor* p2, *p3;
    p2 = new torch::Tensor(t2);
    p3 = new torch::Tensor;
//	p3 = &t3;
    *p3 = t3;
    cout << *p2 << endl;
    cout << *p3 << endl;
    delete p2;
    delete p3;
    p2 = nullptr;
    p3 = nullptr;
}