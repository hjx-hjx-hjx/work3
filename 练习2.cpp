#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
	Mat srcMat = imread("D:\\koko\\abc.jpg",0);				//��ȡһ��abc��ͼƬ����ת��Ϊ�Ҷ�ͼ
	Mat result,resultad;
	threshold(srcMat, result, 100, 255, THRESH_BINARY);		//��ֵ������   ԭͼ		���ͼ		��ֵ	Ԥ���������������ֵ	Ҫ�õĶ�ֵ�����㷨
	adaptiveThreshold(srcMat, resultad, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 77, 10);	
	//ԭͼ		���ͼ		Ԥ���������������ֵ	����Ӧ��ֵ�㷨	��������ֵ�򷴶�������ֵ	�ֲ�����ĳߴ磨һ��Ϊ������	���һ���������㷨�й�
	imshow("src", srcMat);
	imshow("result", result);
	imshow("resultad", resultad);
	waitKey(0);
}