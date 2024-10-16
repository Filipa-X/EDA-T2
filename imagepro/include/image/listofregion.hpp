/*
 Class ListOfRegion
*/

#ifndef LISTOFREGION_HPP_
#define LISTOFREGION_HPP_

#include "image/noderegion.hpp"

namespace image {
	class ListOfRegion{
	private:
		NodeRegion* headRegion;		
	public:
		ListOfRegion();

		void insertFirst(Region region);
		void insertLast(Region region);
		Region find(int id);

		virtual ~ListOfRegion();		
	};
}

#endif