/*
 Class NodeRegion
*/

#ifndef NODEREGION_HPP_
#define NODEREGION_HPP_

#include "include/image/region.hpp"

namespace image {
	class NodeRegion{
	private:
		Region region;	
		NodeRegion* nextRegion;	
	public:		
		NodeRegion();
		NodeRegion(Region _region, NodeRegion* _nextRegion = nullptr);

		void setRegion(Region _region);
		void setNext(NodeRegion* _nextRegion);
		Region getRegion();
		NodeRegion* getNext();

		virtual ~NodeRegion();
	};
}

#endif