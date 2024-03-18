#ifndef __Bitmap_h__
#define __Bitmap_h__

#include <vector>
#include <array>
#include <filesystem>
#include <iostream>
#include <fstream>

struct Header {
	std::array<std::byte, 2> signature;
	std::array<std::byte, 4> fileSize;
	std::array<std::byte, 4> reserved;
	std::array<std::byte, 4> dataOffset;

	unsigned int getFileSize() {
		int size;
		memcpy(&size, fileSize.data(), sizeof(int));
		return size;
	}

	unsigned int getOffset() {
		int offset;
		memcpy(&offset, dataOffset.data(), sizeof(int));
		return offset;
	}

	void printSignature() {
		std::cout << static_cast<char>(signature[0]);
		std::cout << static_cast<char>(signature[1]) << '\n';
	}
};

struct InfoHeader{
	std::array<std::byte, 4> size;
	std::array<std::byte, 4> width;
	std::array<std::byte, 4> height;
	std::array<std::byte, 2> planes;
	std::array<std::byte, 2> bitsPerPixel;
	std::array<std::byte, 4> compression;
	std::array<std::byte, 4> imageSize;
	std::array<std::byte, 4> XpixelPerM;
	std::array<std::byte, 4> YpixelPerM;
	std::array<std::byte, 4> colorUsed;
	std::array<std::byte, 4> impColors;

	unsigned short getBitsPerPixel() {
		short bpp;
		memcpy(&bpp, bitsPerPixel.data(), sizeof(unsigned short));
		return bpp;
	}

	unsigned int getWidth() {
		int imgWidth;
		memcpy(&imgWidth, width.data(), sizeof(int));
		return imgWidth;
	}

	unsigned int getHeight() {
		int imgHeight;
		memcpy(&imgHeight, height.data(), sizeof(int));
		return imgHeight;
	}
};

struct Pixel {
	unsigned char blue;
	unsigned char green;
	unsigned char red;
};

class Bitmap {
public:
	Header header;
	InfoHeader infoHeader;
	std::filesystem::path path;
	std::vector<Pixel> pixels;

	bool readData();
	bool writeData(std::filesystem::path outputPath);
	bool swapRedAndBlueChannel(std::filesystem::path outputPath) noexcept;
	bool onlyRedChannel(std::filesystem::path outputPath) noexcept;
	bool onlyGreenChannel(std::filesystem::path outputPath) noexcept;
	bool onlyBlueChannel(std::filesystem::path outputPath) noexcept;
};

#endif // !__Bitmap_h__
