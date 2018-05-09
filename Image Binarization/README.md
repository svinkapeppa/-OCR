# Image Binarization

## Task
Implement one of the binarization algorithms and test it on the given set of pictures.

## Solution
I've chosen to implement ![Bradley's algorithm](http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.420.7883).

## Prerequisites
OpenCV - used to perform basic operations with images.

## Implementation
There is a special class ![CBinarizer](/src/Binarizer.h), which performs the binarization.

## Usage
There is a special ![script](src/test), which applies algorithm to every image, located in the ![img](img/) folder.
Results are placed in the same folder with `_result` ending.

If you would like to use custom settings / input, then you need to follow these steps:
1. Clone the repository
2. In `src/` folder do following:
   - cmake .
   - make
3. After that you can use it as `./ImageBinarization [input]`

## Notes
1. Quality
   - As can be seen algorithm shows good results, but still there are some cases when it encounters some problems:
      * Kernel must be choosed correctly (helps not to confuse foreground and background pixels)
      * Low contrast may decrease the accuracy of the binarization
2. Perfomance
   - Approximate speed of the algorithm is .0000002678 sec/px