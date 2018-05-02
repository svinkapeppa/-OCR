#include "Binarizer.h"

void CBinarizer::ReadImage(std::string path) {
  _path = path;
  _image = cv::imread(path, CV_LOAD_IMAGE_GRAYSCALE);
}

void CBinarizer::ProcessImage() {

}

std::string CBinarizer::GetProcessedImagePath() {
  bool extension = true;
  std::string path;

  for (auto it = _path.rbegin(); it != _path.rend(); ++it) {
    if (*it == '.' && extension) {
      path += ".yarg_";
      extension = false;
    } else {
      path += *it;
    }
  }

  return std::string(path.rbegin(), path.rend());
}

void CBinarizer::SaveProcessedImage() {
  auto path = GetProcessedImagePath();
  cv::imwrite(path, _image);
}