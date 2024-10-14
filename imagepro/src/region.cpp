/* implementation of the class Region
 */

#include <iostream>

#include "image/region.hpp"

 namespace image {

    Region :: Region(): id(0), size(0), points() {

    }

    void Region :: setId(int _id) {
        id = _id;
    }

    void Region :: setSize(int _size) {
        size = _size;
    }

	void Region :: setPoints(ListOfPoint2D _points) {
        points = _points;
    }

    int Region :: getId() {
        return id;
    }

    int Region :: getSize() {
        return size;
    }

    void Region :: showRegion() {
        points.print();
    }

    Region :: ~Region() {
        
    } 

 }