/* implementation of the class ListOfPoint2D
 */

#include<iostream>
#include <vector>

#include "image/listofpoint2d.hpp"

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

    void ListOfPoint2D :: insertLast(Point2D point2D) {
        NodePoint2D* nodePoint2D = new NodePoint2D(point2D);
        if (headPoint2D == nullptr) {
            headPoint2D = nodePoint2D;
        } else {
            NodePoint2D *ptr = headPoint2D;
            while(ptr -> getNext() != nullptr) {
                ptr = ptr -> getNext();
            }
            ptr -> setNext(nodePoint2D);
        }
    }

    bool ListOfPoint2D :: isPoint2D(int i, int j, std :: vector<Point2D> points) {
        for(int k = points.size(); k > 0; k--) {
            if(points[k].getX() == i && points[k].getY() == j) {
                return true;
            }
        }
        return false;
    }

    void ListOfPoint2D :: print(int width, int height) {
        NodePoint2D* ptr = headPoint2D;
        std :: vector<Point2D> points;

        while(ptr != nullptr) {
            Point2D point2D = ptr -> getPoint2D();
            points.push_back(point2D);
            ptr = ptr -> getNext();
        }

        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j++) {
                if(isPoint2D(i, j, points)) {
                    std :: cout << "1";
                } else {
                    std :: cout << "0";
                }
            }
            std :: cout << std :: endl;
        }
    }

    ListOfPoint2D :: ~ListOfPoint2D() {

    }

}