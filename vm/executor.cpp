#include "bytereader.cpp"
#include "exec.cpp"
int main(int argc, char *argv[]){
    std::vector<unsigned char> bytes = readFileBytes(argv[1]);
    int a[bytes.size()];
    for (std::size_t i = 0; i < bytes.size(); ++i) {
        unsigned char byte = bytes[i];
        //std::cout << 
        a[i] = static_cast<int>(byte);
    }
    Execute(a,bytes.size());
}