//
//  grayScaleTransformation.hpp
//  openCV
//
//  Created by tang zhongbo on 2020/08/31.
//  Copyright © 2020 zero. All rights reserved.
//

#ifndef grayScaleTransformation_hpp
#define grayScaleTransformation_hpp

#include "basic.h"

void linearTransformation(cv::Mat image, int k, int b);
void contrastStretchingTransformation(cv::Mat image, int p1_x, int p1_y, int p2_x, int p2_y);

#endif /* grayScaleTransformation_hpp */
