/*
 * @Descripttion: 
 * @version: 
 * @Author: QsWen
 * @Date: 2020-06-24 20:26:15
 * @LastEditors: QsWen
 * @LastEditTime: 2020-07-15 21:32:25
 */ 
//
// Created by wen on 2020/6/24.
//
#pragma once
#ifdef  DLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

#ifndef LIBTORCHOPENCVDEMO_UTILS_H
#define LIBTORCHOPENCVDEMO_UTILS_H

#include <iostream>
#include <torch/torch.h>
#include <torch/script.h>
#include <opencv2/opencv.hpp>


//#include "opencv2/imgproc.hpp"
//#include "opencv2/imgcodecs.hpp"
//#include "opencv2/highgui.hpp"
using namespace std;
using namespace cv;

DLL_API void
load_module(torch::jit::script::Module &module, const string &path, torch::Device device = torch::Device(torch::kCPU));

DLL_API void forward(const torch::Tensor &x, torch::Tensor &y, torch::jit::script::Module module);

DLL_API void load_image(Mat &img, const string &path, int width = 28, int height = 28, int type = 0);

DLL_API void mat2tensor(const Mat &img, torch::Tensor &img_tensor, torch::Device device = torch::Device(torch::kCPU));

DLL_API void tensor2mat1(const torch::Tensor &tensor_data, Mat &img);

DLL_API void tensor2mat3(const torch::Tensor &tensor_data, Mat &img);

DLL_API void print_tensor(const torch::Tensor &tensor_data, int type = 0);

DLL_API void tensor2mat(const torch::Tensor &tensor_data, Mat &img);
DLL_API void tensor_property(const torch::Tensor &tensor_data);
DLL_API void tensor_operator(torch::Tensor &t1, torch::Tensor &t2);

//DLL_API
//template<typename T>
//void getTime(T (*fun)()) {
//    clock_t start, end;
//    double endtime;
//    start = clock();
//    fun();
//    end = clock();
//    endtime = (double) (end - start) / CLOCKS_PER_SEC;
//    cout << "endtime: " << endtime << endl;
//}

#endif //LIBTORCHOPENCVDEMO_UTILS_H