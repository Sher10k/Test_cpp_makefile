#include <utility>

#include <vector>
#include <iostream>
#include <zcm/zcm-cpp.hpp>
#include "zcm_types/camera_basler/cpp_types/ZcmCameraBaslerJpegFrame.hpp"

#include <opencv2/core.hpp>        // Basic OpenCV structures (cv::Mat)
#include <opencv2/highgui.hpp>  // Video write
//#include <opencv2/imgcodecs.hpp>


class VideoParser {

private:
    std::vector<cv::Mat> images_;
    zcm::LogFile *zcm_log_;
    std::string output_filename_;

public:
    VideoParser(const std::string & input_filename, std::string  output_filename)
        : output_filename_{std::move(output_filename)}
    {
        zcm_log_ = new zcm::LogFile(input_filename, "r");
        if (!zcm_log_->good())
        {
            std::cout << "Bad zcm log: " << input_filename << std::endl;
            exit(0);
        }
    }

    void Run()
    {
        while (1)
        {
            const zcm::LogEvent* event = zcm_log_->readNextEvent();
            if (!event)
                break;
            if (event->channel == "FLZcmCameraBaslerJpegFrame")
            {
                ZcmCameraBaslerJpegFrame zcm_msg;
                zcm_msg.decode(event->data, 0, event->datalen);
                images_.push_back(cv::imdecode(zcm_msg.jpeg, cv::IMREAD_COLOR));	// old - CV_LOAD_IMAGE_COLOR
            }


        }

        bool isColor = (images_[0].type() == CV_8UC3);
//        int codec = CV_FOURCC('X', '2', '6', '4');		- old cv
	int codec = cv::VideoWriter::fourcc('X', '2', '6', '4');
        cv::VideoWriter writer;
        writer.open(output_filename_, codec, 8, images_[0].size(), isColor);

        if (!writer.isOpened()) {
            std::cout << "Could not open the output video file for write!" << std::endl;
            exit(0);
        }

        for (unsigned i=0; i < images_.size(); i++){
            writer << images_[i];
        }

        std::cout << "Finished writing" << std::endl;

    }
};
