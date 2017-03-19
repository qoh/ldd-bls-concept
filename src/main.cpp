#include "stdafx.h"

// Concept
#include <Concept/BLS.h>
#include <Concept/LDD.h>

using namespace concept;

int main(int argc, char *argv[])
{
	string inputFile;
	string inputColorsetFile;
	string outputFile;
	if (argc <= 4) {
		inputFile = string(argv[1]);
		outputFile = string(argv[2]);
		inputColorsetFile = string(argv[3]);
	} else
		return 0;
//	printf("[%s] -> [%s]\n", inputFile.c_str(), outputFile.c_str());

	//----------- Begin ----------

	std::shared_ptr<lddGroup> inputGroup(lddGroup::CreateFromFile(inputFile.c_str()));
	std::shared_ptr<blsColorset> inputColorset(blsColorset::CreateFromFile(inputColorsetFile.c_str()));
	std::shared_ptr<blsGroup> outputGroup(blsGroup::CreateFromLDDGroup(inputGroup.get(), inputColorset.get()));







	//---------- End ------------

	printf("Press enter to continue...\n");
	std::cin.get();
	return 0;
}