#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace cv;
using namespace std;

//Creation of Mats and default threshold value for the trackbar
Mat src, gray, small, srcclone;
int threshval = 25;

int current = 0;

// Create a function that allows us to mark-off the leukemia cells based on our trackbar (as it controls the thresholds)
static void on_trackbar(int, void*) {
	// Create a Mat object and have it grayed
	Mat bw = threshval < 128 ? (gray < threshval) : (gray > threshval);
	//imshow( "threshold", bw );
	// Make two vectors to store the contour points and image information
	vector<Vec4i> hierarchy;
	vector<vector<Point> > contours;
	// Find the contours in the image 
	findContours(bw, contours, hierarchy, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE);
	// Have srcclone set to be a clone of src
	srcclone = src.clone();

	// Create a Mini Rect called minRect to use for leukemia marking
	Rect minRect;
	

	// Loop for when i is less than the size of the contours Vector
	for (size_t i = 0; i < contours.size(); ++i)
	{
		// Calculate the area of each contour
		double area = contourArea(contours[i]);
		
		// Ignore contours that are too small or too large
		// if (area < 1e2 || 1e5 < area) continue;

		// Set minRect to boundingRect for each of the contours
		minRect = boundingRect(Mat(contours[i]));

		
		if (minRect.height < 20) continue;
		// Create a color that is Green
		Scalar color = Scalar(0, 255, 0);
	
		// If the rectangle ........
		if (minRect.height < 50 | minRect.height > minRect.width * 2) {
			color = Scalar(0, 0, 255);		
			//cout << "This is B 244";
		}
		// Mark the leukemia blood cells with a bounding rectangle
		rectangle(srcclone, minRect, color, 2, 8);
		// Current increments everytime there is a bounding rectangle. Since new bounding rectangles are made with every
		// trackbar increase/decrease, current will be a large number.
		// This is done because there is not count() or size() function for Rects in the OpenCV library.
		current++;
		
		// Draw each contour only for visualization purposes
		//  drawContours(srcclone, contours, static_cast<int>(i), Scalar(0, 0, 255), 2, 8, hierarchy, 0);
		// Find the orientation of each shape
	}
	
	//cout << contours.size();
	//cout << " ";
	imwrite("result.jpg", srcclone);
	resize(srcclone, small, Size(src.cols / 2, src.rows / 2));
	imshow("Connected Components", small);
	// Since current incremented everytime we made a new rectangle, we have to take the difference of the last two numbers 
	// for our cell count.
	
	cout << current;
	cout << "\n";
}


int main(int argc, const char** argv)
{
	src = imread("Leukemia eh.jpg");
	if (src.empty())
	{
		cout << "Could not read input image file: " << endl;
		return -1;
	}
	

	cvtColor(src, gray, COLOR_BGR2GRAY);


	// you can try different values below
	GaussianBlur(gray, gray, Size(5, 5), 1, 1);
	Mat kernel = Mat::ones(3, 3, CV_8UC1);
	dilate(gray, gray, kernel);


	namedWindow("Connected Components", 1);
	createTrackbar("Threshold", "Connected Components", &threshval, 127, on_trackbar);
	on_trackbar(threshval, 0);	

	


	waitKey(0);
	return 0;
}