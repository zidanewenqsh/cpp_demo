//
// Created by wen on 2020/6/29.
//

#include "demo.h"
void func01(){
    cv::Mat img = cv::imread(imgpath);
    cv::Mat M = (cv::Mat_<double>(2, 3) << 0.5, 0.5, 30, -0.5, 0.5, 196.7);
    cv::Mat M1 = cv::getRotationMatrix2D(cv::Point(img.cols / 2, img.rows / 2), 45, 0.7);
    cout << M1 << endl;
    cv::Mat dst_img;
    cv::warpAffine(img, dst_img, M, img.size());
    cv::imshow("dstimg", dst_img);
}