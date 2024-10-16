#include "image/image.hpp"
#include "image/listofregion.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <map>

int main(int nargs, char** vargs){
    /*
    std::string filename("../images/image_5.bmp");
    std::cout << filename << std::endl;
    image::Image* im = nullptr;
    im = image::Image::readImage(filename);
    im->show();
    */


    std :: cout << "Bienvenido a ImagePro" << std :: endl;
    //vector para guardar imagenes
    std :: vector<image :: Image*> images;
    std :: map<std :: string, image :: ListOfRegion> regions;
    

    //read
    std :: string id_new;
    
    id_new = "1";
    std :: string filename("../images/image_3.bmp");

    image :: Image* image = nullptr;
    image = image :: Image :: readImage(filename);
    image -> setId(id_new);
    images.push_back(image);

    //show
    std :: string id_show;

    id_show = "1";

    for(int i = 0; i < images.size(); i++) {
        if(images[i] -> getId() == id_show) {
            images[i] -> show();
        }
    }

    //getRegions
    std :: string id_getRegions;

    id_getRegions = "1";

    for(int i = 0; i < images.size(); i++) {
        if(images[i] -> getId() == id_getRegions) {
            image :: ListOfRegion listOfRegion = images[i] -> getRegions();
            regions[id_getRegions] = listOfRegion;
        }
    }

    //showRegion
    std :: string id_showRegion;
    int id_region;

    id_showRegion = "1";
    id_region = 2;

    if(regions.find(id_showRegion) != regions.end()) {
        image :: ListOfRegion listOfRegion = regions[id_showRegion];
    
        for(int i = 0; i < images.size(); i++) {
            if(images[i] -> getId() == id_showRegion) {
                int width = images[i] -> getWidth();
                int height = images[i] -> getHeight();

                image :: Region region = listOfRegion.find(id_region);
                region.showRegion(width, height);
            }
        }
    }
    


    return 0;
}