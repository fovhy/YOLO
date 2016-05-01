#include "fileManager.h"

bool IOManager::readFileToBuffer(const std::string& filePath, std::vector<char>& buffer){
    std::ifstream file(filePath, std::ios::binary);
    if(file.fail()) {
        perror(filePath.c_str());
        return false;
    }
    // test how big the file is
    file.seekg(0, std::ios::beg);

    // Get the file size

    int fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    fileSize -= file.tellg();

    buffer.resize(fileSize);
    file.read(&(buffer[0]), fileSize);
    file.close();
    return true;
}
