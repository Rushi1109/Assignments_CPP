#ifndef __Bitmap_h__
#define __Bitmap_h__

#include <vector>
#include <filesystem>
#include <iostream>
#include <fstream>

struct Header {
	std::byte signature[2];
	std::byte fileSize[4];
	std::byte reserved[4];
	std::byte dataOffset[4];

	unsigned int getFileSize() {
		int size;
		memcpy(&size, fileSize, sizeof(int));
		return size;
	}

	unsigned int getOffset() {
		int offset;
		memcpy(&offset, dataOffset, sizeof(int));
		return offset;
	}

	void printSignature() {
		std::cout << static_cast<char>(signature[0]);
		std::cout << static_cast<char>(signature[1]) << '\n';
	}
};

struct InfoHeader{
	std::byte size[4];
	std::byte width[4];
	std::byte height[4];
	std::byte planes[2];
	std::byte bitsPerPixel[2];
	std::byte compression[4];
	std::byte imageSize[4];
	std::byte XpixelPerM[4];
	std::byte YpixelPerM[4];
	std::byte colorUsed[4];
	std::byte impColors[4];

	unsigned short getBitsPerPixel() {
		short bpp;
		memcpy(&bpp, bitsPerPixel, sizeof(unsigned short));
		return bpp;
	}

	unsigned int getWidth() {
		int imgWidth;
		memcpy(&imgWidth, width, sizeof(int));
		return imgWidth;
	}

	unsigned int getHeight() {
		int imgHeight;
		memcpy(&imgHeight, height, sizeof(int));
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
	bool swapRedAndBlueChannel();
	bool onlyRedChannel();
	bool onlyGreenChannel();
	bool onlyBlueChannel();
};

#endif // !__Bitmap_h__
