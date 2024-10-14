/* implementation of the class ListOfRegion
 */

#include<iostream>

#include "image/listofregion.hpp"

namespace image {

    ListOfRegion :: ListOfRegion(): headRegion(nullptr) {

    }

    void ListOfRegion :: insertFirst(Region region) {
        NodeRegion* nodeRegion = new NodeRegion(region);
        if (headRegion == nullptr) {
            headRegion = nodeRegion;
        } else {
            nodeRegion -> setNext(headRegion);
            headRegion = nodeRegion;
        }
    }

    void ListOfRegion :: insertLast(Region region) {
        NodeRegion* nodeRegion = new NodeRegion(region);
        if (headRegion == nullptr) {
            headRegion = nodeRegion;
        } else {
            NodeRegion *ptr = headRegion;
            while(ptr -> getNext() != nullptr) {
                ptr = ptr -> getNext();
            }
            ptr -> setNext(nodeRegion);
        }
    }

    ListOfRegion :: ~ListOfRegion() {

    }


}