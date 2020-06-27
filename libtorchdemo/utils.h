//
// Created by wen on 2020/6/15.
//
#pragma once
#ifndef LIBTORCHDEMO_UTILS_H
#define LIBTORCHDEMO_UTILS_H

#endif //LIBTORCHDEMO_UTILS_H
#include <torch/torch.h>
#include <torch/script.h>
//#include <opencv2/opencv.hpp>
using namespace std;
//using namespace cv;

void tensor_property(const torch::Tensor &tensor_data);
void tensor_operator(torch::Tensor &t1, torch::Tensor &t2);
template<typename T>
void getTime(T (*fun)()) {
    clock_t start, end;
    double endtime;
    start = clock();
    fun();
    end = clock();
    endtime = (double) (end - start) / CLOCKS_PER_SEC;
    cout << "endtime: " << endtime << endl;
}