//
//  histogram.hpp
//  openCV
//
//  Created by tang zhongbo on 2020/08/31.
//  Copyright © 2020 zero. All rights reserved.
//

#ifndef histogram_hpp
#define histogram_hpp

#include "basic.h"
#include <vector>

const int SIZE = 256, MAX_V = 255;

static std::vector<float> count(SIZE, 0);
static std::vector<float> s_count(SIZE, 0);

void histogram(cv::Mat image);
void equalization(cv::Mat image);
#endif /* histogram_hpp */
