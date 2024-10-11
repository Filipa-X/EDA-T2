/* implementation of the class ListOfPoint2D
 */

#include<iostream>

#include "include/image/listofpoint2d.hpp"

namespace image {

    ListOfPoint2D :: ListOfPoint2D(): headPoint2D(nullptr) {

    }

    void ListOfPoint2D :: insertFirst(Point2D point2D) {
        NodePoint2D* nodePoint2D = new NodePoint2D(point2D);
        if (headPoint2D == nullptr) {
            headPoint2D = nodePoint2D;
        } else {
            nodePoint2D -> setNext(headPoint2D);
            headPoint2D = nodePoint2D;
        }
    }

}