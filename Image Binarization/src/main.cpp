#include "Binarizer.h"

int main(int argc, char **argv) {
  CBinarizer binarizer;

  binarizer.ReadImage(argv[1]);
  binarizer.ProcessImage();
  binarizer.SaveProcessedImage();

  return 0;
}