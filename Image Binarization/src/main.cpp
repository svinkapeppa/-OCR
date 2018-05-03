#include "Binarizer.h"

int GetType(std::string str);

int main(int argc, char **argv) {
  if (argc == 2) {
    CBinarizer binarizer;
    binarizer.ReadImage(argv[1]);
    binarizer.ProcessImage();
    binarizer.SaveProcessedImage();
  } else if (argc == 5) {
    auto type = GetType(argv[2]);
    CBinarizer binarizer(atof(argv[3]), atoi(argv[4]), type);
    binarizer.ReadImage(argv[1]);
    binarizer.ProcessImage();
    binarizer.SaveProcessedImage();
  } else {
    std::cout << "Usage: ./ImageBinarization pathToImage [type: {Bradley, } <string>] [t <float>] [d <int>]"
              << std::endl;
    exit(42);
  }
  return 0;
}

int GetType(std::string str) {
  if (str == "Bradley") {
    return 0;
  } else {
    std::cout << "Unknown algorithm: Choices are {Bradley, }" << std::endl;
    exit(42);
  }
}