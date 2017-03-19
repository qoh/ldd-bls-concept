#include "stdafx.h"

// Concept
#include <Concept/BLS.h>
#include <Concept/LDD.h>

namespace concept {
		
blsGroup *blsGroup::CreateFromLDDGroup(lddGroup *sourceGroup, blsColorset *colorset)
{
	blsGroup *group = new blsGroup();

	return group;
}

void blsGroup::WriteToFile(const char *file)
{
}

blsGroup::blsGroup()
{
	bricks.reserve(256);
}

blsGroup::~blsGroup()
{
	for (auto brick : bricks)
		delete brick;
}


//------------------------------------------------------------------


blsColorset *blsColorset::CreateFromFile(const char *file)
{
	return nullptr;
}

blsColorset::blsColorset()
{
}

blsColorset::~blsColorset()
{
}

}