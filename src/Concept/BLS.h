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

void BuildConversionMapLDDToBLS();

inline glm::vec4 rgbaToHslc(glm::vec4 &rgba)
{
	glm::vec4 hslc;
	// REF: https://en.wikipedia.org/wiki/HSL_and_HSV
	float cMax = std::max(std::max(rgba.r, rgba.g), rgba.b);
	float cMin = std::min(std::min(rgba.r, rgba.g), rgba.b);

	// Chroma
	hslc.w = cMax - cMin;

	// Hue
	if (hslc.w == 0.f)
		hslc.x = 0.f;
	else if (cMax == rgba.r)
		hslc.x = fmod((rgba.g - rgba.b) / hslc.w, 6.f);
	else if (cMax == rgba.g)
		hslc.x = ((rgba.b - rgba.r) / hslc.w) + 2.f;
	else if (cMax == rgba.z)
		hslc.x = ((rgba.r - rgba.g) / hslc.w) + 4.f;

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

	float theta1 = a.x * PI / 3.f;
	pt1.x = a.w * cos(theta1);
	pt1.y = a.w * sin(theta1);
	pt1.z = a.z;

	float theta2 = b.x * PI / 3.f;
	pt2.x = b.w * cos(theta2);
	pt2.y = b.w * sin(theta2);
	pt2.z = b.z;

#if 0
	return sqrt(pow(pt1.x - pt2.x, 2.f) + pow(pt1.y - pt2.y, 2.f) + pow(pt1.z - pt2.z, 2.f));
#else
	return glm::distance(pt1, pt2);
#endif
}

inline float hslcaDif(glm::vec4 &a, float &aAlpha, glm::vec4 &b, float bAlpha)
{
	if ((aAlpha != 1.f && bAlpha == 1.f) || (aAlpha == 1.f && bAlpha != 1.f))
		return 1e16f;
	float dif = hslcDif(a, b);
	if (aAlpha != 1.f && bAlpha != 1.f)
		dif += abs(aAlpha - bAlpha) * 0.25f;
	return dif;
}

struct blsColor
{
	glm::vec4 rgba;

	glm::vec4 hslc;

	uint16_t idx;
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
	string uiName;
	glm::vec3 position;
	uint16_t angleID;
	uint16_t colorID;
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