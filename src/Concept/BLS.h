#pragma once
#include "stdafx.h"

namespace concept {
	
typedef struct blsColorset blsColorset;
typedef struct blsBrick blsBrick;
typedef struct blsGroup blsGroup;

typedef struct lddBrick lddBrick;
typedef struct lddGroup lddGroup;

struct blsColorset
{
	static blsColorset *CreateFromFile(const char *file);

	blsColorset();

	~blsColorset();
};

struct blsBrick
{
};

struct blsGroup
{
	static blsGroup *CreateFromLDDGroup(lddGroup *sourceGroup, blsColorset *colorset);

	vector<blsBrick *> bricks;

	blsGroup();

	~blsGroup();

	void WriteToFile(const char *file);
};

}