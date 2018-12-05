#include "prosecutor.h"

int main(int argc, char** argv) {
	std::cout << "prcutor::detect_num_vm()" << std::endl;
	prcutor::detect_num_vm();
	std::cout << "prcutor::detect_timing_()" <<std::endl;
	prcutor::detect_timing_();
	std::cout << "prcutor::detect_sleeping_pass()" << std::endl;
	prcutor::detect_sleeping_pass();
	std::cout << "prcutor::detect_mouse_siat()" << std::endl;
	prcutor::detect_mouse_siat();
	std::cout << "prcutor::detect_freespace()" << std::endl;

	prcutor::detect_freespace();

	system("pause");
	return 0;
}