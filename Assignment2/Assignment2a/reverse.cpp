#include <iostream>
#include <fstream>
#include <string> // Include string for std::string

namespace assignment_2a {
  void reverse(){
    // Prompt for file path
    std::string inputFilePath;
    std::cout << "Path to the file: ";
    std::cin >> inputFilePath;

    // Open file in binary mode and position at the end
    std::ifstream infile(inputFilePath, std::ios::binary | std::ios::ate);
    if (!infile) {
      std::cerr << "Error: Unable to open file \"" << inputFilePath << "\"\n";
      return;
    }

    // Get file size
    std::streamsize fileSize = infile.tellg();
    std::cout << "File size: " << fileSize << " bytes\n";
    infile.seekg(0, std::ios::beg); // Go back to the beginning

    // Create buffer
    char* buffer = new char[fileSize];

    // Read file into buffer
    if (!infile.read(buffer, fileSize)) {
      std::cerr << "Error: Unable to read file \"" << inputFilePath << "\"\n";
      delete[] buffer;
      return;
    }
    infile.close();

    // Reverse the buffer
    for (std::streamsize i = 0; i < fileSize / 2; ++i) {
        std::swap(buffer[i], buffer[fileSize - 1 - i]);
    }

    // Prepare output file path
    std::string outFilePath = "out_" + inputFilePath;

    // Write reversed buffer to output file
    std::ofstream outfile(outFilePath, std::ios::binary);
    if (!outfile) {
      std::cerr << "Error: Unable to create file \"" << outFilePath << "\"\n";
      delete[] buffer;
      return;
    }
    outfile.write(buffer, fileSize);
    outfile.close();

    // Clean up
    delete[] buffer;

    std::cout << "File reversed successfully and written to \"" << outFilePath << "\"\n";
  }
}
