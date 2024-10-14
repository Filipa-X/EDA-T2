#include "image/image.hpp"
#include "image/listofregion.hpp"
#include <iostream>
#include <string>

int main(int nargs, char** vargs){
    std::string filename("../images/image_4.bmp");
    std::cout << filename << std::endl;
    image::Image* im = nullptr;
    im = image::Image::readImage(filename);

    im->show();
    im->getRegions();

    /************* 
    //../images/image_2.bmp
    std :: string input1, input2, command1, command2, filename1, filename2;
    std :: cout << "Bienvenido a ImagePro" << std :: endl;
    std :: cout << "im1 = ";
    std :: cin >> input1;
    std :: cout << "im2 = ";
    std :: cin >> input2;

    image :: Image* im1 = nullptr;
    im1 = image :: Image  :: readImage(input1);
    image :: Image* im2 = nullptr;
    im2 = image :: Image :: readImage(input2);

    im1 -> show();
    im2 -> show();

    image :: ListOfRegion regions1 = im1 -> getRegions();
    image :: ListOfRegion regions2 = im2 -> getRegions();
    **************/
    return 0;
}