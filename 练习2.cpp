#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
	Mat srcMat = imread("D:\\koko\\abc.jpg",0);				//提取一个abc的图片并且转变为灰度图
	Mat result,resultad;
	threshold(srcMat, result, 100, 255, THRESH_BINARY);		//二值化函数   原图		结果图		阈值	预设满足条件的最大值	要用的二值化的算法
	adaptiveThreshold(srcMat, resultad, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 77, 10);	
	//原图		结果图		预设满足条件的最大值	自适应阈值算法	二进制阈值或反二进制阈值	局部区域的尺寸（一般为奇数）	最后一个参数和算法有关
	imshow("src", srcMat);
	imshow("result", result);
	imshow("resultad", resultad);
	waitKey(0);
}