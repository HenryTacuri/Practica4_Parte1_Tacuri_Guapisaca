


#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

#include "YOLO11.hpp" // Ensure YOLO11.hpp or other version is in your include path


int main()
{
    // Configuration parameters
    //const std::string labelsPath = "models/coco.names";       // Path to class labels
    //const std::string modelPath  = "models/yolo11n.onnx";     // Path to YOLO11 model
    const std::string labelsPath = "models/cards.names";
    const std::string modelPath = "models/best.onnx"; 
    //const std::string imagePath  = "data/carta.jpg";           // Path to input image
    bool isGPU = true;                                           // Set to false for CPU processing

    //Initialize the YOLO11 detector
    YOLO11Detector detector(modelPath, labelsPath, isGPU);

    // Load an image
    //cv::Mat image = cv::imread(imagePath);

    //Perform object detection to get bboxs
    std::vector<Detection> detections;

    // Draw bounding boxes on the image
    //detector.drawBoundingBoxMask(image, detections);

    // Display the annotated image
   // cv::imshow("YOLO11 Detections", image);
    //cv::waitKey(0); // Wait indefinitely until a key is pressed

    //cv::destroyAllWindows();

    cv::Mat frame;

    //cv::VideoCapture video("data/One_minute_Moscow.mp4");
    cv::VideoCapture video("/dev/video0");

    double prevFrameTime = 0; 

    if (video.isOpened()){
        cv::namedWindow("Video", cv::WINDOW_AUTOSIZE);

        while(3==3){
            video >> frame;

            cv::flip(frame, frame, 1);

            if(frame.empty()){
                break;
            }

            // Calcular el tiempo actual
            double currentTime = (double)cv::getTickCount(); //

            detections = detector.detect(frame);
            detector.drawBoundingBoxMask(frame, detections);            


            // Calcular los FPS
            double fps = cv::getTickFrequency() / (currentTime - prevFrameTime); //
            prevFrameTime = currentTime; //

            std::string fpsString = std::to_string(fps); //
            cv::putText(frame, "FPS: " + fpsString, cv::Point(10, 30), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 255, 0), 2); //

            cv::imshow("Video", frame);

            if(cv::waitKey(23)==27){
                break;
            }
        }

        video.release();
        cv::destroyAllWindows();

    }

    return 0;
}