#include "zigzag_scanner.hpp"


ZigZagScanner::ZigZagScanner() {
   

}

ZigZagScanner::~ZigZagScanner() {
}

std::vector<float> *ZigZagScanner::scan(cv::Mat &input) {
    std::vector<float> *output = new std::vector<float>();
    // TODO Traverse the input in a zigzag scan, and store the result in output
    int x = 0; 
    int y = 1;
    
    
    output->push_back(input.at<float>(0,0));
    while (y < 7){
        int temp = y;
        while (x <= temp){
            output->push_back(input.at<float>(x,y));
            x++;
            y--;
        }
        y++;
        if (y == 7)
            break;
        temp = x; 
        while (y <= temp){
            output->push_back(input.at<float>(x,y));
            x--;
            y++;
        }
        x++;
    }
    while (x < 7){
        while (x < 7){
            output->push_back(input.at<float>(x,y));
            y--;
            x++;
        }
        output->push_back(input.at<float>(x,y));
        if (x == 7 && y == 6)
            break;
        y++;
        int temp = y;
        while (x > temp){
            output->push_back(input.at<float>(x,y));
            x--;
            y++;
        }
        output->push_back(input.at<float>(x,y));
        x++;
    }
    output->push_back(input.at<float>(x,y+1));
    
    // for (int i =0; i < output->size(); i++)
    //     std::cout << output->at(i) << "\t";
    // std::cout << output->size() << std::endl;
    // std::cout << x << std::endl;
    // std::cout << y << std::endl;
    return output;
}

cv::Mat *ZigZagScanner::descan(const std::vector<float> &input) {
    cv::Mat *output = new cv::Mat(8, 8, CV_32FC1);
    float *output_ptr = (float *) output->data;
    // TODO Perform the opposite of a Zigzag Scan
    //  Map the input vector to an 8x8 matrix, and store the result in output
    
    return output;
}
