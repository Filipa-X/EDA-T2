#include "image/image.hpp"
#include "image/listofregion.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

int main(int nargs, char** vargs){

    std :: cout << "Bienvenido a ImagePro" << std :: endl;
    std :: vector<image :: Image*> images;
    std :: map<std :: string, image :: ListOfRegion> regions;

    while(true) {
        std :: string input;
        std :: cout << ":) ";
        getline(std :: cin, input);

        if (input == "exit") {
            break;
        }

        if(input.find("read") != input.npos) {
            std :: string init_path = "../images/";
            std :: string id_new = input.substr(0, input.find("=") - 1); //algo mas
            std :: string path = init_path + input.substr(input.find("read") + 5); //algo mas

            image :: Image* image = nullptr;
            image = image :: Image :: readImage(path);
            image -> setId(id_new);
            images.push_back(image);

        } else if(input.find("getRegions") != input.npos) {
            std :: string id_getRegions = input.substr(11);
            for(int i = 0; i < images.size(); i++) {
                if(images[i] -> getId() == id_getRegions) {
                    image :: ListOfRegion listOfRegion = images[i] -> getRegions();
                    regions[id_getRegions] = listOfRegion;
                }
            }

        } else if(input.find("showRegion") != input.npos) {
            size_t start = input.find(" ") + 1;
            size_t end = input.find_last_of(" ");
            std :: string id_showRegion = input.substr(start, end - start);

            int id_region;
            std :: istringstream iss(input.substr(end + 1));
            iss >> id_region;

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

        } else if (input.find("show") != input.npos) {
            std :: string id_show = input.substr(5);
            for(int i = 0; i < images.size(); i++) {
                if(images[i] -> getId() == id_show) {
                    images[i] -> show();
                }
            }
        }
    }  
    return 0;
}