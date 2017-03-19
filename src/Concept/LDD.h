#pragma once
#include "stdafx.h"

namespace concept {

typedef struct lddBrick lddBrick;
typedef struct lddGroup lddGroup;

typedef struct blsBrick blsBrick;
typedef struct blsGroup blsGroup;

struct lddBrick
{
	int designID;
	glm::mat3 scaleRotation;
	glm::vec3 translation;
	glm::vec4 rgba;
	glm::vec4 hslc;
};

struct lddGroup
{
	static lddGroup *CreateFromFile(const char *file);

	vector<lddBrick *> bricks;

	lddGroup();

	~lddGroup();
};

}