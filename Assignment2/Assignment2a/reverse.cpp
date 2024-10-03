#include <iostream>
#include <fstream>
#include <filesystem>
#include "stdio.h"

namespace assignment_2a {
  void reverse(){
    // Print file size
    std::string inputFilePath;
    printf("Path to the file: ");
    std::cin >> inputFilePath;
    std::filesystem::path filePath(inputFilePath);
    std::uintmax_t fileSize = std::filesystem::file_size(filePath);
    printf("File size: %d byte\n", fileSize);
    //Open file
    std::ifstream infile(inputFilePath, std::ios::binary | std::ios::in);

    // Create array
    char* buffer = new char[fileSize];

    // Write file to array
    infile.read(buffer, fileSize);
    infile.close();

    // Reverse array
    for (std::uintmax_t i = 0; i < fileSize / 2; ++i) {
        std::swap(buffer[i], buffer[fileSize - 1 - i]);
    }
    std::string outFilePath = "out_"+inputFilePath;
    // Create output file
    std::ofstream outfile(outFilePath, std::ios::binary | std::ios::out);

    // Write reversed array to file
    outfile.write(buffer, fileSize);
    outfile.close();

    // Clean memory
    delete[] buffer;

    printf("File reversed succesfully and writed to %s\n", outFilePath.c_str());
  }
}
