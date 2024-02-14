#include "opencv2/opencv.hpp"
#include <iostream>
#include <Windows.h>
#include <mutex>

using namespace cv;
using namespace std;

int main() {
    // Open a video file
    VideoCapture cap("C:\\Users\\yazan\\Documents\\Hack_Project3.0.mp4"); // Replace with your video file path

    // Check if the video file is opened successfully
    if (!cap.isOpened()) {
        cout << "Error: Cannot open the video file." << endl;
        return -1;
    }

    // Create a window to display the video in full screen
    namedWindow("Display Video", WINDOW_NORMAL);
    setWindowProperty("Display Video", WND_PROP_FULLSCREEN, WINDOW_FULLSCREEN);

    while (true) {
        Mat frame;
        // Read a frame from the video
        if (!cap.read(frame)) {
            // Reset the video to the beginning to loop
            cap.set(CAP_PROP_POS_FRAMES, 0);
            continue;
        }

        // Display the frame in the window
        imshow("Display Video", frame);

        // Wait for 30 milliseconds and check for 'q' key press to exit
        if (waitKey(30) == 'q') {
            break;
        }
    }

    // Release the VideoCapture and destroy the window
    cap.release();
    destroyAllWindows();

    return 0;
}
