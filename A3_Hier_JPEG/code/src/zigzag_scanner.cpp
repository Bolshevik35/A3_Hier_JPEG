#include "zigzag_scanner.hpp"


ZigZagScanner::ZigZagScanner() {
   

}

ZigZagScanner::~ZigZagScanner() {
}

int zig_zag_value(int i, int j){
    if ((i + j) >= 8)
        return 8*8 - 1 - zig_zag_value(8-1-i, 8-1-j);
    int k = floor((i+j)*(i+j+1)/2);
    if ((k + i) == 1)
        return k +i ;
    else
        return k + j;
    
}

std::vector<float> *ZigZagScanner::scan(cv::Mat &input) {
    std::vector<float> *output = new std::vector<float>();
    // TODO Traverse the input in a zigzag scan, and store the result in output
    std::unordered_map<int, std::pair<int,int>> mymap; 
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            std::pair<int,int> temp (i,j);
            mymap[zig_zag_value(i,j)] = temp; 
        }
    }
    for (int i =0; i < 64; i++){
        std::pair<int,int> temp = mymap.at(i);
        output->push_back(input.at<float>(temp.first, temp.second));
    } 
    return output;
}

cv::Mat *ZigZagScanner::descan(const std::vector<float> &input) {
    cv::Mat *output = new cv::Mat(8, 8, CV_32FC1);
    float *output_ptr = (float *) output->data;
    // TODO Perform the opposite of a Zigzag Scan
    //  Map the input vector to an 8x8 matrix, and store the result in output
    std::unordered_map<int, std::pair<int,int>> mymap; 
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            std::pair<int,int> temp (i,j);
            mymap[zig_zag_value(i,j)] = temp; 
        }
    }
    for (int i =0; i < 64; i++){
        std::pair<int,int> temp = mymap.at(i);
        output->at<float>(temp.first, temp.second) = input[i];
    }
    return output;
}
