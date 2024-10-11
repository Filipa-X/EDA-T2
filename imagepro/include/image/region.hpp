/*
 Class Region
*/

#ifndef REGION_HPP_
#define REGION_HPP_

#include "include/image/listofpoint2d.hpp"

namespace image {
	class Region{
	private:
		int id;
		int size;
		ListOfPoint2D points;		
	public:
		Region();
		void setId(int _id);
		void setSize(int _size);
		int getId();
		int getSize();
		ListOfPoint2D getPoints();
		void showRegion();
        virtual ~Region(); 		
	};
}

#endif