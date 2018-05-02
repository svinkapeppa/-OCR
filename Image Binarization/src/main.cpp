#include "Binarizer.h"

int main(int argc, char **argv) {
  if (argc == 2) {
    CBinarizer binarizer;
    binarizer.ReadImage(argv[1]);
    binarizer.ProcessImage();
    binarizer.SaveProcessedImage();
  } else if (argc == 4) {
    CBinarizer binarizer(atof(argv[2]), atoi(argv[3]));
    binarizer.ReadImage(argv[1]);
    binarizer.ProcessImage();
    binarizer.SaveProcessedImage();
  } else {
    std::cout << "Usage: ./ImageBinarization pathToImage [t <float>] [d <int>]" << std::endl;
  }

  return 0;
}