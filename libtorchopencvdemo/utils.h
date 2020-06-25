//
// Created by wen on 2020/6/24.
//

#ifndef LIBTORCHOPENCVDEMO_UTILS_H
#define LIBTORCHOPENCVDEMO_UTILS_H

#endif //LIBTORCHOPENCVDEMO_UTILS_H

#include <iostream>
#include <torch/torch.h>
#include <torch/script.h>
#include <opencv2/opencv.hpp>


//#include "opencv2/imgproc.hpp"
//#include "opencv2/imgcodecs.hpp"
//#include "opencv2/highgui.hpp"
using namespace std;
using namespace cv;

void
load_module(torch::jit::script::Module &module, const string &path, torch::Device device = torch::Device(torch::kCPU));

void forward(const torch::Tensor &x, torch::Tensor &y, torch::jit::script::Module module);

void load_image(Mat &img, const string &path, int width = 28, int height = 28, int type = 0);

void mat2tensor(const Mat &img, torch::Tensor &img_tensor, torch::Device device = torch::Device(torch::kCPU));

void tensor2mat1(const torch::Tensor &tensor_data, Mat &img);

void tensor2mat3(const torch::Tensor &tensor_data, Mat &img);

void print_tensor(const torch::Tensor &tensor_data, int type = 0);

void tensor2mat(const torch::Tensor &tensor_data, Mat &img);

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