/*
 Class Region
*/

#ifndef REGION_HPP_
#define REGION_HPP_

#include "image/listofpoint2d.hpp"

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
		void setPoints(ListOfPoint2D _points);
		int getId();
		int getSize();
		void showRegion();
        virtual ~Region(); 		
	};
}

#endif