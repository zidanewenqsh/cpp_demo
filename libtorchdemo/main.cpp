#include "header.h"

int main() {
    torch::Tensor t = torch::tensor({1, 2, 3, 4}).reshape({1, 2, 2, 1});
    cout << t << endl;
    torch::Tensor *p = &t;
//    for (int i = 0; i < 3; i++) {
//        cout << (t[i].item()) << endl;
//    }
//    cout<<(sizeof(t)/ sizeof(t[0]))<<endl; //8
    cout << sizeof(t.data()) << endl;
    cout << t.sum() << endl;
    cout << t.flatten().sizes()[0] << endl;
    cout << t.numel() << endl;
//    torch::TensorOptions option(torch::kFloat32);
//    torch::Tensor t1 = torch::tensor({1, 2, 3, 4}, option);
    torch::Tensor t1 = torch::tensor({1, 2, 3, 4}, torch::kFloat);
    cout << t1 << endl;
    auto p1 = t1[0].data_ptr();
    auto p2 = t1[1].data_ptr();

    cout << p1 << endl;
    cout << p2 << endl;

//    cout << *p1 << endl;
//    vector<>
    std::cout << "Hello, World!" << std::endl;

    return 0;
}
