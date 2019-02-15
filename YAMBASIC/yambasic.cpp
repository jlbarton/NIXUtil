


#include <iostream>
#include <yambasic.h>

int main(int argc, char * arv[]) {


	std::cout << "Hellaaaa World!" << yambasic::gogo() << std::endl;



	return 0;
}

namespace yambasic {
int gogo(void) {
	return 301;
}
}
