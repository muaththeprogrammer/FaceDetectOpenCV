#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace std;
using namespace cv;

/*   Image read and output
void main() {
	string path = "image01.jpg";
	Mat img = imread(path);
	imshow("Frame", img);
	waitKey(0);
}
*/

void main() {
	VideoCapture video(0);
	CascadeClassifier facedetect;
	Mat img;

	facedetect.load("haarcascade_frontalface_default.xml");


	


	
	while (true) {
		video.read(img);
		vector<Rect> faces;

		facedetect.detectMultiScale(img, faces, 1.3, 5);
		cout << faces.size() << endl;

		for (int i = 0; i < faces.size(); i++) {
			rectangle(img, faces.at(i).tl(), faces.at(i).br(), Scalar(0, 0, 0), 3);
			rectangle(img, Point(0,0), Point(250,70), Scalar(0, 0, 0), FILLED);
			putText(img, to_string(faces.size())+" FACE(S) FOUND", Point(10, 40), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 204, 102), 1);
		}
		
		imshow("Frame", img);
		waitKey(25);

	}
}