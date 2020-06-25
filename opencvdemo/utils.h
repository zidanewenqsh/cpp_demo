//
// Created by wen on 2020/6/25.
//
#pragma once
#ifndef OPENCVDEMO_UTILS_H
#define OPENCVDEMO_UTILS_H

#endif //OPENCVDEMO_UTILS_H

#include <iostream>
#include <opencv2/opencv.hpp>

//#include "opencv2/imgproc.hpp"
//#include "opencv2/imgcodecs.hpp"
//#include "opencv2/highgui.hpp"
using namespace std;
using namespace cv;

void print_mat1c(const Mat &img);

void print_mat3c(const Mat &img);
//减色算法
void colorReduce1(Mat &img, int div);
void colorReduce2(Mat &img, int div);
void colorReduce3(Mat &img, int n);
void colorReduce4(const Mat &src, Mat &dst, int div);
void colorReduce5(Mat &img, int div);
void colorReduce5_2(Mat &img, int div);
void colorReduce6(Mat &img, int div);
void colorReduce7(Mat &img, int div);