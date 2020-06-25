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

void net(const torch::Tensor& x, torch::Tensor &y, torch::jit::script::Module module);