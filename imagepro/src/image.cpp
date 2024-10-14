#include "image/image.hpp"

#include <fstream>
#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <queue>

namespace image{

    Image::Image(): width(0), height(0), th_value(120), data(nullptr) {

    }

    Image::Image(int w, int h): width(w), height(h), th_value(120),  data(nullptr) {

    }

    Image::Image(int w, int h, uchar* _data): width(w), height(h), th_value(120), data(_data) {
       threshold();
    }

    void Image::threshold(){
        if (data != nullptr) {
            for(int i = 0; i < height*width; i++){            
                if (static_cast<int>(data[i]) < th_value){
                    data[i] = static_cast<char>(0);
                }
                else{
                    data[i] = static_cast<char>(1);                    
                }
            }
        }
    }

    int Image::getValue(int row, int col){
        int pos = row*width + col;
        return static_cast<int>(data[pos]);
    }

    void Image::show(){
        std::cout << "----------------------" << std::endl;
        std::cout << "size [ (w: " << width << ") x   ( h:" << height << ")]" <<  std::endl;        
        std::cout << "---------------------" << std::endl;
        for(int i = 0 ; i < height ; i++ ){
            for(int j = 0; j < width; j++ ){
                //std::cout<< getValue(i,j) << " "; 
                if (getValue(i,j) == 0) {
                    std::cout<<" ";
                }
                else{
                    std::cout<<"*";
                }
            }
            std::cout<<std::endl;
        }
    }

    //funcion para saber si un punto ya fue visitado(previo a ser Point2D)
    //un punto es Point2D solo si su valor es 1
    bool Image :: wasVisited(int position, std :: vector<int> visited) {
        if (position < 0) {
            return true; //fuera de rango, con true no pase nada
        }
        if (position > width * height) {
            return true; //fuera de rango, con true no pase nada
        }
        for(int k = 0; k < visited.size(); k++) {
            if(visited[k] == position) {
                return true;
            }
        }
        return false;
    }

    ListOfRegion Image :: getRegions() {
        ListOfRegion regions;
        std :: vector<int> visited; //puntos que contienen 1 ya visitados
        int id = 1; //id de la region

        //recore todos los pixeles buscando 1 y no visitado
        //un 1 no visitado crea una nueva region
        //si los 1 ya fueron visitados, significa que ya son parte de una region
        for(int i = 0 ; i < height ; i++ ) {
            for(int j = 0; j < width; j++ ) {

                //creacion de nueva region
                if(getValue(i, j) == 1 && !wasVisited(i * width + j, visited)) { 
                    //creacion del primer nodo
                    Point2D point2D(i, j); //se crea el primer Point2D de ListOfPoint2D 
                    ListOfPoint2D points; //se crea ListOfPoint2D
                    points.insertFirst(point2D); //se inserta NodePoint2D en ListOfPoint2D
                    visited.push_back(i * width + j); //se marca la posicion del primer punto como visitada
                    std :: queue<Point2D> queue; //queue que ira almacenando cada NodePoint2D que pertenezca a la region
                    queue.push(point2D); //su funcion es para cada uno de sus NodePoint2D, sacar sus vecinos de region
                    int size = 1; //como se añande el primer Point2D a la lista, hay 1 punto en la region
                    
                    //creacion del resto de los nodos
                    while(!queue.empty()) { //cuando queue quede vacia, significara que no quedan nodos vecinos con 1 a la region

                        //se saca un nodo (ya añadido a ListOfPoint2D) de queue, y se añaden a queue sus nodos vecinos con valor 1
                        Point2D ptr = queue.front(); 
                        queue.pop();
                        int i = ptr.getX();
                        int j = ptr.getY();
                        
                        //segun las coordenadas del nodo sacado, se buscan valores 1 no visitados arriba de el, abajo de el, a su izquierda y a su derecha
                        //direccion hacia arriba
                        if (getValue(i, (j - 1)) == 1 && !wasVisited(i * width + (j - 1), visited)) { 
                            Point2D ptr_up(i, (j - 1)); //se crea el nodo
                            points.insertLast(ptr_up); //se añade a la lista
                            visited.push_back(i * width + (j - 1)); //se marca como visitado
                            queue.push(ptr_up); //se añande al queue para ver despues si tiene vecinos no visitados con 1
                            size++; //como se añadio un nodo a la lista, su tamaño aumenta
                        }

                        //direccion hacia abajo
                        if (getValue(i, (j + 1)) == 1 && !wasVisited(i * width + (j + 1), visited)) { 
                            Point2D ptr_down(i, (j + 1));
                            points.insertLast(ptr_down);
                            visited.push_back(i * width + (j + 1));
                            queue.push(ptr_down);
                            size++;
                        }

                        //direccion hacia la izquierda
                        if (getValue((i - 1), j) == 1 && !wasVisited((i - 1) * width + j, visited)) {
                            Point2D ptr_left((i - 1), j);
                            points.insertLast(ptr_left);
                            visited.push_back((i - 1) * width + j);
                            queue.push(ptr_left);
                            size++;
                        }

                        //direccion hacia la derecha
                        if (getValue((i + 1), j) == 1 && !wasVisited((i + 1) * width + j, visited)) {
                            Point2D ptr_right((i + 1), j);
                            points.insertLast(ptr_right);
                            visited.push_back((i + 1) * width + j);
                            queue.push(ptr_right);
                            size++;
                        }

                        //direccion diagonal arriba derecha
                        if (getValue((i + 1), (j - 1)) == 1 && !wasVisited((i + 1) * width + (j - 1), visited)) {
                            Point2D ptr_dur((i + 1), (j - 1));
                            points.insertLast(ptr_dur);
                            visited.push_back((i + 1) * width + (j - 1));
                            queue.push(ptr_dur);
                            size++;
                        }

                        //direccion diagonal abajo derecha
                        if (getValue((i + 1), (j + 1)) == 1 && !wasVisited((i + 1) * width + (j + 1), visited)) {
                            Point2D ptr_ddr((i + 1), (j + 1));
                            points.insertLast(ptr_ddr);
                            visited.push_back((i + 1) * width + (j + 1));
                            queue.push(ptr_ddr);
                            size++;
                        }

                        //direccion diagonal arriba izquierda
                        if (getValue((i - 1), (j - 1)) == 1 && !wasVisited((i - 1) * width + (j - 1), visited)) {
                            Point2D ptr_dul((i - 1), (j - 1));
                            points.insertLast(ptr_dul);
                            visited.push_back((i - 1) * width + (j - 1));
                            queue.push(ptr_dul);
                            size++;
                        }

                        //direccion diagonal abajo izquierda
                        if (getValue((i - 1), (j + 1)) == 1 && !wasVisited((i - 1) * width + (j + 1), visited)) {
                            Point2D ptr_ddl((i - 1), (j + 1));
                            points.insertLast(ptr_ddl);
                            visited.push_back((i - 1) * width + (j + 1));
                            queue.push(ptr_ddl);
                            size++;
                        }
                    }
                    //finalizada la ListOfPoint2D de la region, se crea la Region
                    Region region;
                    region.setId(id);
                    region.setSize(size); 
                    region.setPoints(points);
                    region.showRegion(); 
                    regions.insertLast(region);
                    id++; //se aumenta el id para la proxima region
                }
            }
        }
        std :: cout << "La imagen tiene " << id - 1 << " regiones." << std :: endl;
        return regions;
    }

    int Image :: getWidth() {
        return width;
    }

    int Image :: getHeight() {
        return height;
    }

    Image* Image::readImage(std::string &path){

        Image* im = nullptr;
        std::ifstream fin(path, std::ios::binary);
        char info[54];
        // read the 54-byte header

        if (!fin.is_open()) {
            std :: cerr << "Error: No se puede abrir el archivo " << path << std :: endl;
            return nullptr;
        }
        
        fin.read(info, 54);

        if (info[0] != 'B') {
            std :: cerr << "Error: El archivo no es un BMP válido" << std :: endl;
            return nullptr;
        }

        // extract image height and width from header
        int width = *(int*)&info[18];
        int height = *(int*)&info[22];
        short int planes = *(short int*)&info[26];
        short int bits = *(short int*)&info[28];
        int imagesize = *(int*)&info[34];
        int numcolors = *(int*)&info[46];

        if (bits != 8) {
            std :: cerr << "Error: Solo se admiten imagenes BMP de 8 bits" << std :: endl;
            return nullptr;
        }

        assert(info[0]=='B' && info[1] =='M');
        assert(bits == 8);
        // std::cout<< "planes " << planes << std::endl;
        // std::cout<< "bits " << bits << std::endl;
        // std::cout<< "imagesize " << imagesize << std::endl;
        // std::cout<< "numcolors " << numcolors << std::endl;
        // std::cout<< info[0] << info[1] << std::endl;
        //reading colortable
        char  colors[numcolors*4];
        fin.read(colors, numcolors*4);        
        if (imagesize == height * width) {            
            char* data = new char[imagesize];
            //read the pixel values
            fin.read(data, imagesize); 
            fin.close();
            char* ordered_data = new char[imagesize];
            //copy data in in a proper order            
            std::cout<< "----------------" <<std::endl;
            for(int i = 0; i < height ; i++){
                std::memcpy(ordered_data + width*i, data + width*(height - 1 - i ), width);
            }                    
            delete[]  data;            
            im = new Image(width, height, reinterpret_cast<uchar*>(ordered_data));        
        }
        assert(im != nullptr);
        return im;
    }

    Image :: ~Image() {

    }

}