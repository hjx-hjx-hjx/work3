#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
	VideoCapture cap(0);				//打开摄像头
	double scale = 0.5;					//缩放倍数

	double i_minH = 0;					//HSV三值的范围
	double i_maxH = 20;

	double i_minS = 43;
	double i_maxS = 255;

	double i_minV = 55;
	double i_maxV = 255;

	while (1) {
		Mat frame;						
		Mat hsvMat;
		Mat detectMat;

		cap >> frame;					//将摄像头获取到的图片给frame
		Size ResImgSiz = Size(frame.cols * scale, frame.rows * scale);	//对图像进行缩放
		Mat rFrame = Mat(ResImgSiz, frame.type());
		resize(frame, rFrame, ResImgSiz, INTER_LINEAR);
		cvtColor(rFrame, hsvMat, COLOR_BGR2HSV);						//将图像转变为HSV格式
		rFrame.copyTo(detectMat);										//深复制
		cv::inRange(hsvMat, Scalar(i_minH, i_minS, i_minV), Scalar(i_maxH, i_maxS, i_maxV), detectMat);//查找在两个Scalar数组中的数据，形成二值化图片
		//原图		下限值		上限值		结果保存
		imshow("while:in the range", detectMat);
		imshow("frame", rFrame);
		waitKey(0);
	}
}