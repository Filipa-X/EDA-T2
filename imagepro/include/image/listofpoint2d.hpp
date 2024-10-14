/*
 Class ListOfPoint2D
*/

#include <vector>

#ifndef LISTOFPOINT2D_HPP_
#define LISTOFPOINT2D_HPP_

#include "image/nodepoint2d.hpp"

namespace image {
	class ListOfPoint2D{
	private:
		NodePoint2D* headPoint2D;		
	public:
		ListOfPoint2D();

		void insertFirst(Point2D point2D);
		void insertLast(Point2D point2D);
		bool isPoint2D(int i, int j, std :: vector<Point2D> points);
		void print();

		virtual ~ListOfPoint2D();		
	};
}

#endif