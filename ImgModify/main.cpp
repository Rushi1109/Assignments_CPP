#include "./include/Bitmap.h"

int main() {
	Bitmap image;
	image.path = "./sample/sample_1280×853.bmp";

	image.readData();

	image.header.printSignature();

	std::cout << image.header.getFileSize() << '\n';
	std::cout << image.header.getOffset() << '\n';
	std::cout << image.infoHeader.getBitsPerPixel() << '\n';
	std::cout << image.infoHeader.getHeight() << '\n';
	std::cout << image.infoHeader.getWidth() << '\n';

	image.swapRedAndBlueChannel();
	bool result = image.writeData("./sample/output1.bmp");
}