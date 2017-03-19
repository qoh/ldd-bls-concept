#include "stdafx.h"

// Concept
#include <Concept/BLS.h>
#include <Concept/LDD.h>

namespace concept {
		
blsGroup *blsGroup::CreateFromLDDGroup(std::shared_ptr<lddGroup> sourceGroup, std::shared_ptr<blsColorset> colorset)
{
	blsGroup *group = new blsGroup();
	group->colorset = colorset;

	return group;
}

void blsGroup::WriteToFile(const char *file)
{
	ofstream outFile(file, std::ios::out | std::ios::binary);
	outFile << "This is a Blockland save file.  You probably shouldn't modify it cause you'll screw it up." << std::endl;
	outFile << "1" << std::endl << std::endl;

	// Output colorset
	outFile << std::setprecision(6) << std::fixed;
	for (auto &color : colorset->colors)
		outFile << color->rgba[0] << " " << color->rgba[1] << " "<< color->rgba[2] << " " << color->rgba[3] << std::endl;
	outFile << 1.f << " " << 0.f << " "<< 1.f << " " << 0.f << std::endl;

	// Output bricks
	outFile << "Linecount " << bricks.size() << std::endl;
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
	printf("Creating blsColorset from <%s>\n", file);
	blsColorset *colorset = new blsColorset();
	ifstream inFile(file, std::ios::in | std::ios::binary);
	string line;
	const float inv255 = 1.f / 255.f;
	uint32_t idx = 0;
	while (getline(inFile, line)) {
		if (line.empty() || isdigit(line[0]) == false)
			continue;
		glm::vec4 color;
		istringstream(line) >> color[0] >> color[1] >> color[2] >> color[3];
		if (color[0] > 1.f || color[1] > 1.f || color[2] > 1.f || color[3] > 1.f) {
			color[0] *= inv255;
			color[1] *= inv255;
			color[2] *= inv255;
			color[3] *= inv255;
		}

		colorset->colors.push_back(new blsColor({ color, rgbaToHslc(color), idx }));
		++idx;
	}

	printf("    Found %lld colors.\n", colorset->colors.size());

	return colorset;
}

blsColorset::blsColorset()
{
	colors.reserve(256);
}

blsColorset::~blsColorset()
{
	for (auto color : colors)
		delete color;
}

}