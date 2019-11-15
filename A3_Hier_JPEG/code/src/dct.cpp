#include "dct.hpp"


DCT::DCT() {
    _dct_mat = new cv::Mat(8, 8, CV_32FC1);
    _dct_mat_t = new cv::Mat(8, 8, CV_32FC1);

    float *dct_ptr = (float *) _dct_mat->data;

    // TODO Calculate the 8x8 Matrix to be used for DCT and IDCT
    float firstRowVal = 1/sqrt(8);
    for (int i=0; i < 8; i++)
        _dct_mat->at<float>(0,i) = firstRowVal;
    for (int i =1; i < 8; i++){
        for (int j = 0; j < 8; j++){
            _dct_mat->at<float>(i,j) = sqrt(2/8)* cos(PI*(2*j + 1)*i / (2*8));
            std::cout << _dct_mat->at<float>(i,j);
        }
    }

    // TODO transpose _dct_mat and store the result in _dct_mat_t
    for (int i = 0; i < 8; i++){
        for (int j =0; j < 8; j++){
            _dct_mat_t->at<float>(i,j) = _dct_mat->at<float>(j,i);
        }
    } 
}

DCT::~DCT() {
}

cv::Mat *DCT::do_block_dct(cv::Mat &input) {
    cv::Mat *output_dct = new cv::Mat(8, 8, CV_32FC1);
    cv::Mat input_dct(8, 8, CV_32FC1);
    input.convertTo(input_dct, CV_32FC1);

    // TODO Perform DCT, store result in output_dct and return it.
    cv::Mat temp(8, 8, CV_32FC1);
    for (int i = 0; i < 8; i++){
        for (int j =0; j < 8; j++){
            for (int k = 0; k < 8; k++){
                temp.at<float>(i,j) += _dct_mat->at<float>(i,k) * input_dct.at<float>(k,j);
            }
        }
    }
    for (int i = 0; i < 8; i++){
        for (int j =0; j < 8; j++){
            for (int k = 0; k < 8; k++){
                output_dct->at<float>(i,j) += temp.at<float>(i,k) * _dct_mat_t->at<float>(k,j);
            }
        }
    }

    return output_dct;
}

cv::Mat *DCT::do_block_idct(cv::Mat &input) {
    cv::Mat *output_idct = new cv::Mat(8, 8, CV_32FC1);
    cv::Mat input_dct(8, 8, CV_32FC1);
    input.convertTo(input_dct, CV_32FC1);
    // TODO Perform IDCT and return output_idct
    cv::Mat temp(8, 8, CV_32FC1);
    for (int i = 0; i < 8; i++){
        for (int j =0; j < 8; j++){
            for (int k = 0; k < 8; k++){
                temp.at<float>(i,j) += _dct_mat_t->at<float>(i,k) * input_dct.at<float>(k,j);
            }
        }
    }
    for (int i = 0; i < 8; i++){
        for (int j =0; j < 8; j++){
            for (int k = 0; k < 8; k++){
                output_idct->at<float>(i,j) += temp.at<float>(i,k) * _dct_mat->at<float>(k,j);
            }
        }
    }

    return output_idct;
}

