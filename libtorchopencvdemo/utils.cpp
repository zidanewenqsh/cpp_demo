//
// Created by wen on 2020/6/24.
//

#include "utils.h"

void tensor2mat1(const torch::Tensor &tensor_data, Mat &img) {
    img.create(Size(tensor_data.size(-1), tensor_data.size(-2)), CV_32FC1);
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            img.at<float>(i, j) = tensor_data[i][j].item().toFloat();
        }
    }
}

void tensor2mat3(const torch::Tensor &tensor_data, Mat &img) {
    int nr, nl, nc;
    img.create(Size(tensor_data.size(-1), tensor_data.size(-2)), CV_32FC3);
    nr = img.rows;
    nl = img.cols;
    nc = img.channels();
    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < nl; j++) {
            for (int k = 0; k < nc; k++) {
                img.at<Vec3f>(i, j)[k] = tensor_data[k][i][j].item().toFloat();
            }
        }
    }
}


void load_module(torch::jit::script::Module &module, const string &path, torch::Device device) {
    try {
        module = torch::jit::load(path);
        module.to(device);
    }
    catch (c10::Error &e) {
        std::cerr << "error loading the model\n";
        exit(-1);
    }
}

void forward(const torch::Tensor &x, torch::Tensor &y, torch::jit::script::Module module) {
    std::vector<torch::jit::IValue> inputs;
    inputs.emplace_back(x);
    y = module.forward(inputs).toTensor();
}

void load_image(Mat &img, const string &path, int width, int height, int type) {
    img = imread(path, type > 0 ? 1 : 0);
    if (img.empty()) {
        exit(-2);
//        throw("Faild open file.");
    }
    resize(img, img, Size(width, height));
}

void mat2tensor(const Mat &img, torch::Tensor &img_tensor, torch::Device device) {
    img_tensor = torch::from_blob(img.data, {1, img.rows, img.cols, img.channels()}, torch::kByte);
    img_tensor = img_tensor.toType(torch::kFloat);
    img_tensor = img_tensor.permute({0, 3, 1, 2});
    img_tensor = img_tensor.div_(255.0);
    img_tensor = img_tensor.sub_(0.5).div_(0.5);
    img_tensor = img_tensor.to(device);
}

void print_tensor(const torch::Tensor &tensor_data, int type) {
    Mat img;
    tensor2mat(tensor_data, img);
//    Mat cv::dnn::blobFromImage(InputArrayimage,double scalefactor=1.0,constSize& size=Size(),constScalar& mean=Scalar(),bool swapRB=false,bool crop=false,int ddepth=CV_32F)
//    cv::dnn::blobFromImage(img,);
    switch (type) {
        case 0:
            cout << format(img, Formatter::FMT_PYTHON) << endl;
            break;
        case 1:
            cout << format(img, Formatter::FMT_NUMPY) << endl;
            break;
        case 2:
            cout << format(img, Formatter::FMT_MATLAB) << endl;
            break;
        case 3:
            cout << format(img, Formatter::FMT_DEFAULT) << endl;
            break;
        default:
            cout << "type error" << endl;
    }
}

void tensor2mat(const torch::Tensor &tensor_data, Mat &img) {
    torch::Tensor tensor_data_c = tensor_data.clone();
    int nr, nl, nc, dim;
    nl = tensor_data.size(-1);
    nr = tensor_data.size(-2);
    nc = 1;
    dim = tensor_data.dim();

    if (3 == dim) {
        tensor_data_c = tensor_data_c.permute({1, 2, 0});
        nc = tensor_data.size(-3);
    }

    tensor_data_c = tensor_data_c.flatten();
    tensor_data_c = tensor_data_c.contiguous();

    img.create(Size(nl, nr), CV_32FC1);
    switch (nc) {
        case 1:
            img.create(Size(nl, nr), CV_32FC1);
            break;
        case 2:
            img.create(Size(nl, nr), CV_32FC2);
            break;
        case 3:
            img.create(Size(nl, nr), CV_32FC3);
            break;
        case 4:
            img.create(Size(nl, nr), CV_32FC4);
            break;
        default:
            cout << "input error" << endl;
            break;
    }
    int n = nc * nr * nl, i = 0;
    auto p = img.ptr<float>(0);
    for (i=0;i<n;i++) {
        p[i] = tensor_data_c[i].item().toFloat();
    }
}