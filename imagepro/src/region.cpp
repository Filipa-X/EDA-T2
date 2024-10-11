/* implementation of the class Region
 */

#include <iostream>

#include "include/image/region.hpp"

 namespace image {

    Region :: Region(): id(0), size(0), points() {

    }

    void Region :: setId(int _id) {
        id = _id;
    }

    void Region :: setSize(int _size) {
        size = _size;
    }

    int Region :: getId() {
        return id;
    }

    int Region :: getSize() {
        return size;
    }

    ListOfPoint2D Region :: getPoints() {
        //implementar funcion
    }

    Region :: ~Region() {
        
    } 

 }