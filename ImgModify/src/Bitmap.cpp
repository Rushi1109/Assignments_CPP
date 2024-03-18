#include "../include/Bitmap.h"
#include <algorithm>
#include <execution>

bool Bitmap::readData() {
	std::ifstream file(path.lexically_normal(), std::ios::binary);
	if (!file.is_open()) {
		std::cerr << "Error opening file: " << path << std::endl;
		return false;
	}

	try {
		// Read header
		file.read(reinterpret_cast<char*>(&header), sizeof(Header));

		// Read InfoHeader
		file.read(reinterpret_cast<char*>(&infoHeader), sizeof(InfoHeader));

		if (infoHeader.getBitsPerPixel() != 24) {
			std::cerr << "Bits per pixel is not 24" << '\n';
			return false;
		}

		file.seekg(header.getOffset(), std::ios::beg);

		int pixelDataSize = infoHeader.getWidth() * infoHeader.getHeight();
		pixels.resize(pixelDataSize);

		file.read(reinterpret_cast<char*>(pixels.data()), pixelDataSize * sizeof(Pixel));
		
		file.close();
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}

bool Bitmap::writeData(std::filesystem::path outputPath) {
	std::ofstream file(outputPath.lexically_normal(), std::ios::binary);

	if (!file.is_open()) {
		std::cerr << "Error opening file for writing: " << outputPath << std::endl;
		return false;
	}

	try {
		file.write(reinterpret_cast<const char*>(&header), sizeof(Header));

		file.write(reinterpret_cast<const char*>(&infoHeader), sizeof(InfoHeader));


		file.seekp(header.getOffset(), std::ios::beg);
		file.write(reinterpret_cast<const char*>(pixels.data()), pixels.size() * sizeof(Pixel));
		
		file.close();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}

bool Bitmap::swapRedAndBlueChannel(std::filesystem::path outputPath) noexcept {
	std::for_each(std::execution::par, pixels.begin(), pixels.end(),
		[&](Pixel& pixel) {
			auto& [blue, green, red] = pixel;
			std::swap(blue, red);
		});

	writeData(outputPath);
	readData();
	return true;
}

bool Bitmap::onlyRedChannel(std::filesystem::path outputPath) noexcept {
	std::for_each(std::execution::par, pixels.begin(), pixels.end(),
		[&](Pixel& pixel) {
			auto& [blue, green, red] = pixel;
			blue = 0;
			green = 0;
		});

	writeData(outputPath);
	readData();
	return true;
}

bool Bitmap::onlyGreenChannel(std::filesystem::path outputPath) noexcept {
	std::for_each(std::execution::par, pixels.begin(), pixels.end(),
		[&](Pixel& pixel) {
			auto& [blue, green, red] = pixel;
			blue = 0;
			red = 0;
		});

	writeData(outputPath);
	readData();
	return true;
}

bool Bitmap::onlyBlueChannel(std::filesystem::path outputPath) noexcept {
	std::for_each(std::execution::par, pixels.begin(), pixels.end(),
		[&](Pixel& pixel) {
			auto& [blue, green, red] = pixel;
			red = 0;
			green = 0;
		});

	writeData(outputPath);
	readData();
	return true;
}