#include "image/image.hpp"
#include "image/listofregion.hpp"
//#include "image/region.hpp"
#include <iostream>
#include <string>
#include <vector>

int main(int nargs, char** vargs){
    std::string filename("../images/image_5.bmp");
    std::cout << filename << std::endl;
    image::Image* im = nullptr;
    im = image::Image::readImage(filename);
    im->show();



    std :: cout << "Bienvenido a ImagePro" << std :: endl;
    
    //vector para guardar imagenes
    std :: vector<image :: Image*> images;
    //read
    std :: string id_new, filename;
    image :: Image* image = nullptr;
    image = image :: Image :: readImage(filename);
    image -> setId(id_new);
    images.push_back(image);

    //show
    std :: string id_show;
    for(int i = 0; i < images.size(); i++) {
        if(images[i] -> getId() == id_show) {
            images[i] -> show();
        }
    }

    //getRegions
    std :: string id_getRegions;
    for(int i = 0; i < images.size(); i++) {
        if(images[i] -> getId() == id_getRegions) {
            images[i] -> getRegions();
        }
    }

    image :: ListOfRegion regions = im -> getRegions();
    //showRegion
    std :: string id_showRegion;
    int id_region;
    for(int i = 0; i < images.size(); i++) {
        if(images[i] -> getId() == id_showRegion) {
            int width = images[i] -> getWidth();
            int height = images[i] -> getHeight();

            image :: Region region = regions.find(id_region);
            region.showRegion(width, height);

            images[i] -> getRegions();
        }
    }







    /************* 
    std :: string input1, input2, command1, command2, filename1, filename2;

    std :: cout << "im1 = ";
    std :: cin >> input1;
    **************/
    return 0;
}