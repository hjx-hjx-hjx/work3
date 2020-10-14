#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
	Mat srcMat = imread("D:\\koko\\abc.jpg",0);
	Mat result,resultad;
	threshold(srcMat, result, 100, 255, THRESH_BINARY);
	adaptiveThreshold(srcMat, resultad, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 77, 10);
	imshow("src", srcMat);
	imshow("result", result);
	imshow("resultad", resultad);
	waitKey(0);
}