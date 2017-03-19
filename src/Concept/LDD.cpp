#include "stdafx.h"

// Concept
#include <Concept/LDD.h>
#include <Concept/BLS.h>

namespace concept {

lddGroup *lddGroup::CreateFromFile(const char *file)
{
	printf("Creating lddGroup from <%s>\n", file);
	
	// REF: http://pugixml.org/docs/quickstart.html
	pugi::xml_document doc;

	// Read file
	{
		pugi::xml_parse_result result = doc.load_file(file);
		if (result == false)
			return nullptr;
	}

	// Grab root lxfml node
	pugi::xml_node lxfml = doc.child("LXFML");
	if (lxfml == false)
		return nullptr;

	// Grab bricks
	pugi::xml_node bricks = lxfml.child("Bricks");
	if (bricks == false)
		return nullptr;

	lddGroup *group = new lddGroup();

	// Parse bricks
	const float inv255 = 1.f / 255.f;
	for (pugi::xml_node brick = bricks.child("Brick"); brick; brick = brick.next_sibling("Brick")) {
		pugi::xml_node part = brick.child("Part");
		pugi::xml_node bone = part.child("Bone");

		// This is a reference to a unique brick model
		int designID(brick.attribute("designID").as_int());
	//	printf("DesignID: %d\n", designID);
	
		// Transform
		string transformStr(bone.attribute("transformation").as_string());
		std::replace(transformStr.begin(), transformStr.end(), ',', ' ');
		glm::mat3 rotationScale;
		glm::vec3 translation;
		istringstream(transformStr)
			>> rotationScale[0][0] >> rotationScale[1][0] >> rotationScale[2][0]
			>> rotationScale[0][1] >> rotationScale[1][1] >> rotationScale[2][1]
			>> rotationScale[0][2] >> rotationScale[1][2] >> rotationScale[2][2]
			>> translation[0] >> translation[1] >> translation[2];
	//	printf("Transform: %s\n", transformStr.c_str());
	//	printf("Translation: %f %f %f\n", translation[0], translation[1], translation[2]);

		// Color
		string rgbaStr(part.attribute("RGBA").as_string());
		std::replace(rgbaStr.begin(), rgbaStr.end(), ',', ' ');
		glm::vec4 color; // rgba
		istringstream(rgbaStr) >> color[0] >> color[1] >> color[2] >> color[3];
		color[0] *= inv255; color[1] *= inv255; color[2] *= inv255;
	//	printf("RGBA: %s\n", rgbaStr.c_str());
	//	printf("RGBA: %f %f %f %f\n", color[0], color[1], color[2], color[3]);

		group->bricks.push_back(new lddBrick({ designID, rotationScale, translation, color, rgbaToHslc(color) }));
	}

	printf("    Found %lld bricks.\n", group->bricks.size());

	return group;
}

lddGroup::lddGroup()
{
	bricks.reserve(256);
}

lddGroup::~lddGroup()
{
	for (auto brick : bricks)
		delete brick;
}

}