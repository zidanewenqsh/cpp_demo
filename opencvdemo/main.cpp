#include "header.h"
#include "utils.h"
#define imgpath "D:\\CLionProjects\\opencvdemo\\build\\Release\\cat.jpg"

int main() {
    cv::Mat img = cv::imread(imgpath);
    cv::Mat img1;
    int div = 32;
    cv::imshow("img", img);
    colorReduce7(img, div);
//    colorReduce4(img, img1, 32);
    cv::imshow("img1", img);

    cv::waitKey(0);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
