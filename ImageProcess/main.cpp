//
//  main.cpp
//  openCV
//
//  Created by tang zhongbo on 2020/08/31.
//  Copyright © 2020 zero. All rights reserved.
//

#include <opencv2/opencv.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "grayScaleTransformation.hpp"
#include "histogram.hpp"

using namespace cv;
using namespace std;

void showRawImage(Mat image) {
    cout << "******************************************" << endl;
    cout << "displaying raw image..." << endl;
    namedWindow("Raw image",WINDOW_AUTOSIZE);
    imshow("Raw image",image);
    waitKey(0);
    destroyWindow("Raw image");
}

int main()
{
    string imagePath = "assets/lena.bmp";
    
    Mat image = imread(imagePath, IMREAD_GRAYSCALE);
    int channels = image.channels();
    imageWidth = image.cols*channels;
    imageHeight = image.rows;

    //show raw image
    showRawImage(image);
    
    //linear transformation
    linearTransformation(image, 1, 10);
    image = imread(imagePath, IMREAD_GRAYSCALE);
    linearTransformation(image, 1, 30);
    image = imread(imagePath, IMREAD_GRAYSCALE);
    linearTransformation(image, 1, 50);
    
    
    //contrast stretching
    image = imread(imagePath, IMREAD_GRAYSCALE);
    contrastStretchingTransformation(image, 10, 10, 100, 200);
    image = imread(imagePath, IMREAD_GRAYSCALE);
    contrastStretchingTransformation(image, 10, 50, 100, 200);
    image = imread(imagePath, IMREAD_GRAYSCALE);
    contrastStretchingTransformation(image, 50, 50, 100, 200);

    //GrayScale Histogram
    image = imread(imagePath, IMREAD_GRAYSCALE);
    histogram(image);
    
    //Image after histogram equalization
    equalization(image);
    
    system("pause");
}
