#include "header.h"
#include "utils.h"

void fun() {
	at::Tensor t1 = torch::arange(16, torch::kInt).reshape({ 4, 4 });
	at::Tensor t2 = torch::ones({ 4, 4 }, torch::kInt) * 2;
	at::Tensor t3 = torch::eye(5);
	//    tensor_operator(t1, t2);
	cout << t3 << endl;

}

int main() {
	//    fun();

	std::cout << "Hello, World!" << std::endl;

	return 0;
}
