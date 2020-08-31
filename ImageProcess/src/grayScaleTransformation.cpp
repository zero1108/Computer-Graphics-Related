//
//  grayScaleTransformation.cpp
//  openCV
//
//  Created by tang zhongbo on 2020/08/31.
//  Copyright © 2020 zero. All rights reserved.
//

#include "grayScaleTransformation.hpp"

int imageHeight, imageWidth;

void linearTransformation(cv::Mat image, int k, int b) {
    std::cout << "******************************************" << std::endl;
    std::cout << "Grayscale linear transformation, k = " << k << ", b = " << b << std::endl;
    for(int i = 0; i < imageHeight; i++) {
        for(int j = 0; j < imageWidth; j++) {
            image.at<uchar>(i,j) = image.at<uchar>(i,j) * k + b;
        }
    }
    namedWindow("Linear Transformation",cv::WINDOW_AUTOSIZE);
    imshow("Linear Transformation", image);
    cv::waitKey(0);
    cv::destroyWindow("Linear Transformation");
}

void contrastStretchingTransformation(cv::Mat image, int p1_x, int p1_y, int p2_x, int p2_y) {
    std::cout << "******************************************" << std::endl;
    std::cout << "Contrast Stretching transformation, p1("
              << p1_x << ", " << p1_y << " p2("
              << p2_x << ", " << p2_y << std::endl;
    
    for(int i = 0; i < imageHeight; i++) {
        for(int j = 0; j < imageWidth; j++) {
            uchar x = image.at<uchar>(i,j);
            if(x < p1_x) {
                image.at<uchar>(i,j)=(p1_y / p1_x) * x;
            }
            else if(p1_x <= x && x <= p2_x) {
                image.at<uchar>(i,j)=((p2_y-p1_y)/(p2_x-p1_x)) * (x - p1_x) + p1_y;
            }
            else {
                image.at<uchar>(i,j)=((255 - p2_y)/(255 - p2_x)) * (x - p2_x) + p2_y;
            }
        }
    }
    namedWindow("Contrast Stretching transformation",cv::WINDOW_AUTOSIZE);
    imshow("Contrast Stretching transformation",image);
    cv::waitKey(0);
    cv::destroyWindow("Contrast Stretching transformation");    
}
