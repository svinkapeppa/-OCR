#include "Binarizer.h"

CBinarizer::CBinarizer(float t, int d) {
  std::cout << t << " " << d << std::endl;
  _t = t;
  _d = d;
}

void CBinarizer::ReadImage(std::string path) {
  _path = path;
  _image = cv::imread(path, CV_LOAD_IMAGE_GRAYSCALE);
  _processedImage = _image;
}

void CBinarizer::ProcessImage() {
  auto integralImage = std::vector<std::vector<int>>(_image.rows, std::vector<int>(_image.cols));
  for (auto i = 0; i < _image.cols; ++i) {
    int sum = 0;
    for (auto j = 0; j < _image.rows; ++j) {
      cv::Scalar brightness = _image.at<uchar>(j, i);
      sum += brightness.val[0];
      if (i == 0) {
        integralImage[j][i] = sum;
      } else {
        integralImage[j][i] = integralImage[j][i-1] + sum;
      }
    }
  }

  for (auto i = 0; i < _image.cols; ++i) {
    for (auto j = 0; j < _image.rows; ++j) {
      int frame = std::min(_image.cols, _image.rows) / (2 * _d);

      int left = i - frame;
      int right = i + frame;
      int top = j - frame;
      int bottom = j + frame;
      if (left < 0) {
        left = 0;
      }
      if (right >= _image.cols) {
        right = _image.cols - 1;
      }
      if (top < 0) {
        top = 0;
      }
      if (bottom >= _image.rows) {
        bottom = _image.rows - 1;
      }

      int square = (bottom - top) * (right - left);
      int sum = integralImage[bottom][right] - integralImage[top][right]
                - integralImage[bottom][left] + integralImage[top][left];
      cv::Scalar brightness = _image.at<uchar>(j, i);

      if (square * brightness.val[0] < sum * (1. - _t)) {
        _processedImage.at<uchar>(j, i) = 0;
      } else {
        _processedImage.at<uchar>(j, i) = 255;
      }
    }
  }
}

std::string CBinarizer::GetProcessedImagePath() {
  bool extension = true;
  std::string path;

  for (auto it = _path.rbegin(); it != _path.rend(); ++it) {
    if (*it == '.' && extension) {
      path += ".tluser_";
      extension = false;
    } else {
      path += *it;
    }
  }

  return std::string(path.rbegin(), path.rend());
}

void CBinarizer::SaveProcessedImage() {
  auto path = GetProcessedImagePath();
  cv::imwrite(path, _processedImage);
}