//
//  main.cpp
//  opencv_test
//
//  Created by Francisco Diaz on 3/5/17.
//  Copyright © 2017 Francisco Diaz. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>



using namespace cv;
int main() {
    VideoCapture cap(0);
    if(!(cap.isOpened())){
        std::cout<<"Webcam is not opened"<<std::endl;
    }
    while(true){
    
        Mat image;
        Mat imageHSV;
        Mat processedImage;
        cap.read(image); // assigs matrix image to the raw webcam footage
        //imshow("Test", image);
        cvtColor(image,imageHSV,CV_BGR2HSV); // converst mat to hsv
        inRange(imageHSV,Scalar(0,0,0), Scalar(100,100,100), processedImage);
        int numberOfPixels = countNonZero(processedImage);
        std::cout<<numberOfPixels<<std::endl;
        imshow("Original", image);
        imshow("Processed", processedImage);
        waitKey(1);
    }
    return 0;
}
