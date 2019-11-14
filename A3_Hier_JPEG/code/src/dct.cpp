#include "dct.hpp"


DCT::DCT() {
    _dct_mat = new cv::Mat(8, 8, CV_32FC1);
    _dct_mat_t = new cv::Mat(8, 8, CV_32FC1);

    float *dct_ptr = (float *) _dct_mat->data;

    // TODO Calculate the 8x8 Matrix to be used for DCT and IDCT
    

    // TODO transpose _dct_mat and store the result in _dct_mat_t
}

DCT::~DCT() {
}

cv::Mat *DCT::do_block_dct(cv::Mat &input) {
    cv::Mat *output_dct = new cv::Mat(8, 8, CV_32FC1);
    cv::Mat input_dct(8, 8, CV_32FC1);
    input.convertTo(input_dct, CV_32FC1);

    // TODO Perform DCT, store result in output_dct and return it.

    return output_dct;
}

cv::Mat *DCT::do_block_idct(cv::Mat &input) {
    cv::Mat *output_idct = new cv::Mat(8, 8, CV_32FC1);

    // TODO Perform IDCT and return output_idct

    return output_idct;
}

