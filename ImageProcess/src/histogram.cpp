//
//  histogram.cpp
//  openCV
//
//  Created by tang zhongbo on 2020/08/31.
//  Copyright © 2020 zero. All rights reserved.
//

#include "histogram.hpp"
#include "grayScaleTransformation.hpp"

void normalization(int &sum, int & max) {
    for(int i = 0; i < SIZE; i++) {
        if(count[i] > max) {
            max = count[i];
        }
        sum += count[i];
    }
    for(int i = 0; i < SIZE; i++) {
        count[i] /= sum;
        std::cout << count[i] << std::endl;
    }
}

void calculateEqHisto() {
    s_count[0] = count[0];
    for(int i = 1; i < SIZE; i++) {
        s_count[i] = s_count[i-1] + count[i];
    }
}

void histogram(cv::Mat image) {
    int start = 0, end = MAX_V;
    int sum = 0, max = 0;
    
    std::cout << "******************************************" << std::endl;
    std::cout << "Grayscale historgram" << std::endl;
    
    for(int i = 0; i < imageHeight; i++) {
        for(int j = 0; j < imageWidth; j++) {
            count[image.at<uchar>(i,j)]++;
        }
    }
    
    //normalization
    normalization(sum, max);
    cv::Mat histImage(SIZE, SIZE, CV_8UC3, cv::Scalar(MAX_V, MAX_V, MAX_V));
    
    for (int i = start; i <= end; i++) {
        cv::line(histImage, cv::Point(i, MAX_V), cv::Point(i, (MAX_V - count[i] * sum / max * MAX_V)), cv::Scalar(0, 0, 0));
    }
    
    namedWindow("Grayscale Histogram",cv::WINDOW_AUTOSIZE);
    imshow("Grayscale Histogram", histImage);
    cv::waitKey(0);
    cv::destroyWindow("Grayscale Histogram");

}

void equalization(cv::Mat image) {
    calculateEqHisto();
    std::vector<int> final_count(SIZE, 0);
    for(int i = 0; i < SIZE; i++) {
        final_count[i] = (int)((MAX_V) * s_count[i] + 0.5);
    }
    for(int i = 0; i < imageHeight; i++) {
        for(int j = 0; j < imageWidth; j++) {
            image.at<uchar>(i, j) = (uchar)final_count[image.at<uchar>(i, j)];
        }
    }
    namedWindow("Histogram Equalization",cv::WINDOW_AUTOSIZE);
    imshow("Histogram Equalization", image);
    cv::waitKey(0);
    cv::destroyWindow("Histogram Equalization");

}
