#pragma once
#include "stdafx.h"

namespace concept {
	
typedef struct blsColor blsColor;
typedef struct blsColorset blsColorset;
typedef struct blsBrick blsBrick;
typedef struct blsGroup blsGroup;

typedef struct lddBrick lddBrick;
typedef struct lddGroup lddGroup;

#define PI 3.14159265359f

inline glm::vec4 rgbaToHslc(glm::vec4 &rgba)
{
	glm::vec4 hslc;
	// REF: https://en.wikipedia.org/wiki/HSL_and_HSV
	float cMax = std::max(std::max(rgba.x, rgba.y), rgba.z);
	float cMin = std::min(std::min(rgba.x, rgba.y), rgba.z);

	// Chroma
	hslc.w = cMax - cMin;

	// Hue
	if (hslc.w == 0.f)
		hslc.x = 0.f;
	else if (cMax == rgba.x)
		hslc.x = fmod((rgba.y - rgba.z) / hslc.w, 6.f);
	else if (cMax == rgba.y)
		hslc.x = ((rgba.z - rgba.x) / hslc.w) + 2.f;
	else if (cMax == rgba.z)
		hslc.x = ((rgba.x - rgba.y) / hslc.w) + 4.f;

	// Lightness
	hslc.z = 0.5f * (cMax + cMin);

	// Saturation
	if (hslc.z == 1.f)
		hslc.y = 0.f;
	else
		hslc.y = hslc.w / (1.f - abs(2.f * hslc.z - 1.f));
	return hslc;
}

inline float hslcDif(glm::vec4 &a, glm::vec4 &b)
{
	// REF: http://stackoverflow.com/questions/4057475/rounding-colour-values-to-the-nearest-of-a-small-set-of-colours

	glm::vec3 pt1, pt2;
	pt1.z = a.z;
	pt2.z = b.z;

	float theta1 = a.x * PI;
	pt1.x = a.w * cos(theta1);
	pt1.y = a.w * sin(theta1);

	float theta2 = b.x * PI;
	pt2.x = b.w * cos(theta2);
	pt2.y = b.w * sin(theta2);

	return (pt1 - pt2).length();
}



struct blsColor
{
	glm::vec4 rgba;

	glm::vec4 hslc;

	uint32_t idx;
};

struct blsColorset
{
	static blsColorset *CreateFromFile(const char *file);

	vector<blsColor *> colors;

	blsColorset();

	~blsColorset();
};

struct blsBrick
{
};

struct blsGroup
{
	static blsGroup *CreateFromLDDGroup(std::shared_ptr<lddGroup> sourceGroup, std::shared_ptr<blsColorset> colorset);

	vector<blsBrick *> bricks;

	std::shared_ptr<blsColorset> colorset;

	blsGroup();

	~blsGroup();

	void WriteToFile(const char *file);
};

}