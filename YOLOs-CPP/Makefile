all:
	g++ Test.cpp -std=c++17 -I/home/henry/opencv_build/opencv/install/include/opencv4/ -I/home/henry/onnxruntime-linux-x64-gpu-1.19.2/include -I/home/henry/Escritorio/Ejemplo-Código-12-YOLOs-CPP/YOLOs-CPP/include -L/home/henry/opencv_build/opencv/install/lib -L/home/henry/onnxruntime-linux-x64-gpu-1.19.2/lib -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc -lopencv_video -lopencv_videoio -lonnxruntime_providers_shared -lonnxruntime  -o vision.bin
run:
	./vision.bin