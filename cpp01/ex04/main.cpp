#include "textReplace.hpp"

int main(int argc, char** argv)
{
    if (argc != 4)
    {
        std::cout << "Usage: " << argv[0] << " <filename> <old_str> <new_str>" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string oldStr = argv[2];
    std::string newStr = argv[3];

    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open input file\n";
        return 1;
    }

    std::ofstream outputFile(filename + ".replace");
    if (!outputFile.is_open()) {
        std::cerr << "Error: could not create output file\n";
        return 1;
    }

    std::string Result = textReplace(inputFile, oldStr, newStr);
    outputFile << Result;
    outputFile.close();
    inputFile.close();

    return 0;
}