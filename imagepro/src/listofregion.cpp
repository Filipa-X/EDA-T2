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

    Region ListOfRegion :: find(int id) {
        NodeRegion *ptr = headRegion;
        Region region = ptr -> getRegion();
        while(ptr -> getRegion().getId() != id) {
            ptr = ptr -> getNext();
        }
        return ptr -> getRegion();


    }

    ListOfRegion :: ~ListOfRegion() {

    }


}