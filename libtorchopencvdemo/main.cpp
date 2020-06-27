#include "header.h"
#include "utils.h"

void fun() {
    at::Tensor t1 = torch::arange(9, torch::kInt).reshape({3, 3});
    at::Tensor t2 = torch::ones({3, 3}, torch::kInt)*2;
    tensor_operator(t1, t2);

}

int main() {
    fun();
    std::cout << "Hello, World!" << std::endl;

    return 0;
}
