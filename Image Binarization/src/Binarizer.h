#ifndef IMAGEBINARIZATION_BINARIZER_H
#define IMAGEBINARIZATION_BINARIZER_H

#include <string>
#include <opencv2/opencv.hpp>

class CBinarizer {
public:
  explicit CBinarizer(float t = 0.15, int d = 8);
  void ReadImage(std::string path);
  void ProcessImage();
  std::string GetProcessedImagePath();
  void SaveProcessedImage();
private:
  std::string _path;
  cv::Mat _image;
  cv::Mat _processedImage;
  float _t;
  int _d;
};

#endif //IMAGEBINARIZATION_BINARIZER_H