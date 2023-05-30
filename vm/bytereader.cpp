#include <fstream>
#include <vector>
#include <iostream>
std::vector<unsigned char> readFileBytes(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary); // Open the file in binary mode
    std::vector<unsigned char> buffer;

    if (file) {
        file.seekg(0, std::ios::end); // Move the file pointer to the end
        std::streampos fileSize = file.tellg(); // Get the file size
        file.seekg(0, std::ios::beg); // Move the file pointer back to the beginning

        // Resize the buffer to the file size
        buffer.resize(fileSize);

        // Read bytes from the file into the buffer
        file.read(reinterpret_cast<char*>(buffer.data()), fileSize);
    } else {
        std::cout << "Failed to open the file." << std::endl;
    }

    file.close(); // Close the file

    return buffer;
}

void printBytes(){
    std::vector<unsigned char> bytes = readFileBytes("../program.bin");
    if (!bytes.empty()) {
        // Process the bytes as needed
        for (std::size_t i = 0; i < bytes.size(); ++i) {
            unsigned char byte = bytes[i];
            std::cout << static_cast<int>(byte) << " ";
            if((i+1)%64 ==0)
                std::cout << std::endl;
        }
    }
}