#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;


int main(int argc, char** argv){
	int kernel_size = 3; // a 3x3 kernel_size for noise reduction.

	int thresh = 200;

	VideoCapture cap(0); // Get webcam access
	if( !cap.open(0) ){
		std::cerr << "Webcam data empty." << std::endl;
		std::cerr << "is the webcam connected." << std::endl;
		return -1;
	}

	Mat originalFrame; // Creates header for image support
	Mat frame_gray; 	 // Creates header for gray scale version of the original frame
	Mat frame_blured;  // Creates header for image
										 // You cannot overwrite the image
										 // Because the math depends on the previus pixel
	Mat frame_canny;
	Mat frame_harris;
	Mat result;

	Mat dst, dst_norm, dst_norm_scaled;
	dst = Mat::zeros( originalFrame.size(), CV_32FC1 );

	/// Detector parameters
	int blockSize = 2;
	int apertureSize = 3;
	double k = 0.04;


	while(1){
		cap >> originalFrame;

		cvtColor(originalFrame, frame_gray, cv::COLOR_RGB2GRAY); // Apply gray scale filter
    GaussianBlur(frame_gray, frame_blured, Size(kernel_size, kernel_size), 0, 0); // Apply Gaussian Blur

		cornerHarris(frame_blured, frame_harris, blockSize, apertureSize, k, BORDER_DEFAULT );

		/// Normalizing
		// normalize( frame_harris, dst_norm, 0, 255, NORM_MINMAX, CV_32FC1, Mat() );
		// convertScaleAbs( dst_norm, dst_norm_scaled );

		// std::vector<cv::Point2f> corners;
		Mat corners;
		goodFeaturesToTrack(frame_harris, corners, 1000000, 0.1, 20);


 		if( originalFrame.empty() ){
 			std::cout << "No data to be displayed" << std::endl;
 			break; // end of video stream
 		}

		// std::cout << corners.size() << std::endl;
		imshow("Rubiks Cube Computer Vision", frame_harris); // Shows the webcam image
		if( waitKey(10) == 27 ) break;
	}

	return 0;
}
