//
// Created by wen on 2020/6/25.
//

#include "utils.h"

void print_mat1c(const Mat &img) {
    int i, j;
    for (i = 0; i < img.rows; i++) {
        for (j = 0; j < img.cols; j++) {
            cout << static_cast<float>(img.at<uchar>(i, j)) << endl;
        }
    }
}

void print_mat3c(const Mat &img) {
    int i, j, k;
    for (i = 0; i < img.rows; i++) {
        for (j = 0; j < img.cols; j++) {
            for (k = 0; k < img.channels(); k++) {
                cout << static_cast<float>(img.at<Vec3b>(i, j)[k]) << endl;
            }
        }
    }
}
//减色算法
//方法1：使用整数除法
void colorReduce1(Mat &img, int div) {
    int nr = img.rows;
    int nl = img.cols * img.channels();
    int i, j;
    for (i = 0; i < nr; i++) {
        auto data = img.ptr<uchar>(i);
        for(j=0;j<nl;j++){
            data[j] = data[j]/div*div+div/2;
        }
    }
}
//方法2：使用取模运算符方法
void colorReduce2(Mat &img, int div){
    int nr = img.rows;
    int nl = img.cols * img.channels();
    int i, j;
    for (i = 0; i < nr; i++) {
        auto data = img.ptr<uchar>(i);
        for(j=0;j<nl;j++){
            data[j] = data[j]-data[j]%div+div/2;
        }
    }
}

//方法3：使用位运算符方法
void colorReduce3(Mat &img, int n){
    int div = pow(2, n);
    int nr = img.rows;
    int nl = img.cols * img.channels();
    int i, j;
    uchar mask = 0xFF<<n;
//    unsigned char mask = 0xFF << n;
    for (i = 0; i < nr; i++) {
        auto data = img.ptr<uchar>(i);
        for(j=0;j<nl;j++){
            *data &= mask;
            *data++ += div>>1;
        }
    }
}

//方法四：使用整数除法非就地处理方法
void colorReduce4(const Mat &src, Mat &dst, int div){
    dst.create(src.size(), src.type());
    int nr = src.rows;
    int nl = src.cols * src.channels();
    int i, j;
    for (i = 0; i < nr; i++) {
        auto data_src = src.ptr<uchar>(i);
        auto data_dst = dst.ptr<uchar>(i);
        for(j=0;j<nl;j++){
            data_dst[j] = data_src[j]/div*div+div/2;
        }
    }
}
//方法五：使用整数除法和迭代器方法
void colorReduce5(Mat &img, int div) {
    cv::MatIterator_<Vec3b> it = img.begin<Vec3b>();
    cv::MatIterator_<Vec3b> it_end = img.end<Vec3b>();

    int k;
    for(;it!=it_end;it++){
        for(k=0;k<img.channels();k++){
            (*it)[k] = (*it)[k]/div*div+div/2;
        }
    }
}
void colorReduce5_2(Mat &img, int div) {
    Mat_<Vec3b>::iterator it;
    int k;
    for(it=img.begin<Vec3b>();it!=img.end<Vec3b>();it++){
        for(k=0;k<img.channels();k++){
            (*it)[k] = (*it)[k]/div*div+div/2;
        }
    }
}
//方法六：使用整数除法，按一维数组处理
void colorReduce6(Mat &img, int div){
    int nr = img.rows;
    int nl = img.cols*img.channels();
    int i,j;
    if(img.isContinuous()){
        nl *= nr;
        nr = 1;
    }
//    cout<<"nr"<<nr<<endl;
    for(i=0;i<nr;i++){
        auto p = img.ptr<uchar>(i);
        for(j=0;j<nl;j++){
            p[j] = p[j]/div*div+div/2;
        }
    }
}
//方法七：普通方法
void colorReduce7(Mat &img, int div){
    int nr = img.rows;
    int nl = img.cols;
    int nc = img.channels();
    int i,j,k;
    for(i=0;i<nr;i++){
        for(j=0;j<nl;j++){
            for(k=0;k<nc;k++){
                img.at<Vec3b>(i,j)[k] = img.at<Vec3b>(i,j)[k]/div*div+div/2;
            }
        }
    }
}