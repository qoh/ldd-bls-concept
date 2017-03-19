#include "stdafx.h"

// Concept
#include <Concept/BLS.h>
#include <Concept/LDD.h>

namespace concept {
	
typedef struct blsFromLdd blsFromLdd;

struct blsFromLdd
{
	string uiName;
	uint16_t angleIdOffset;
	glm::vec3 extent;
};

map<int, blsFromLdd> g_lddDesignIDToblsUIName = map<int, blsFromLdd>();
void BuildConversionMapLDDToBLS()
{
	//--------------- Bricks -------------
	
	g_lddDesignIDToblsUIName[3005] = { "1x1", 1, glm::vec3(0.5f, 0.5f, 0.6f) }; // 1x1 Brick
	g_lddDesignIDToblsUIName[3062] = { "1x1 Round", 1, glm::vec3(0.5f, 0.5f, 0.6f) }; // 1x1 Round Brick
	g_lddDesignIDToblsUIName[3004] = { "1x2", 1, glm::vec3(0.5f, 1.f, 0.6f) }; // 1x2 Brick
	g_lddDesignIDToblsUIName[98283] = { "1x2", 1, glm::vec3(0.5f, 1.f, 0.6f) }; // 1x2 Masonry Brick

	g_lddDesignIDToblsUIName[3003] = { "2x2", 1, glm::vec3(1.f, 1.f, 0.6f) }; // 2x2 Brick
	g_lddDesignIDToblsUIName[3001] = { "2x4", 1, glm::vec3(1.f, 2.f, 0.6f) }; // 2x4 Brick
	g_lddDesignIDToblsUIName[2877] = { "1x2", 1, glm::vec3(0.5f, 1.f, 0.6f) }; // 1x2 Grill Brick
	g_lddDesignIDToblsUIName[30136] = { "1x2", 1, glm::vec3(0.5f, 1.f, 0.6f) }; // 1x2 Palisade Brick
	
	g_lddDesignIDToblsUIName[4216] = { "1x2", 1, glm::vec3(0.5f, 1.f, 0.6f) }; // 1x2 Grooved Brick
	g_lddDesignIDToblsUIName[3622] = { "1x3", 1, glm::vec3(0.5f, 1.5f, 0.6f) }; // 1x3 Brick
	g_lddDesignIDToblsUIName[3010] = { "1x4", 1, glm::vec3(0.5f, 2.f, 0.6f) }; // 1x4 Brick
	g_lddDesignIDToblsUIName[15533] = { "1x4", 1, glm::vec3(0.5f, 2.f, 0.6f) }; // 1x4 Masonry Brick
	
	g_lddDesignIDToblsUIName[30137] = { "1x4", 1, glm::vec3(0.5f, 2.f, 0.6f) }; // 1x4 Palisade Brick
	g_lddDesignIDToblsUIName[2653] = { "1x4", 1, glm::vec3(0.5f, 2.f, 0.6f) }; // 1x4 Sliding Piece
	g_lddDesignIDToblsUIName[3009] = { "1x6", 1, glm::vec3(0.5f, 3.f, 0.6f) }; // 1x6 Brick
	g_lddDesignIDToblsUIName[3008] = { "1x8", 1, glm::vec3(0.5f, 4.f, 0.6f) }; // 1x8 Brick
	
	g_lddDesignIDToblsUIName[6111] = { "1x10", 1, glm::vec3(0.5f, 5.f, 0.6f) }; // 1x10 Brick
	g_lddDesignIDToblsUIName[6112] = { "1x12", 1, glm::vec3(0.5f, 6.f, 0.6f) }; // 1x12 Brick
	g_lddDesignIDToblsUIName[90258] = { "2x2", 1, glm::vec3(1.f, 1.f, 0.6f) }; // 2x2 Grooved Brick
	g_lddDesignIDToblsUIName[6143] = { "2x2 Round", 1, glm::vec3(1.f, 1.f, 0.6f) }; // 2x2 Round Cross Brick
	
	g_lddDesignIDToblsUIName[92947] = { "2x2 Round", 1, glm::vec3(1.f, 1.f, 0.6f) }; // 2x2 Profile Brick
	g_lddDesignIDToblsUIName[3002] = { "2x3", 1, glm::vec3(1.f, 1.5f, 0.6f) }; // 2x3 Brick
//	g_lddDesignIDToblsUIName[6565] = { "2x3", 1, glm::vec3(1.f, 1.5f, 0.6f) }; // 2x3 Left Roof Tile
//	g_lddDesignIDToblsUIName[6564] = { "2x3", 1, glm::vec3(1.f, 1.5f, 0.6f) }; // 2x3 Right Roof Tile

//	g_lddDesignIDToblsUIName[41768] = { "2x4", 1, glm::vec3(1.f, 2.f, 0.6f) }; // 2x4 Angle Brick (Left)
//	g_lddDesignIDToblsUIName[41767] = { "2x4", 1, glm::vec3(1.f, 2.f, 0.6f) }; // 2x4 Angle Brick (Right)
	g_lddDesignIDToblsUIName[44237] = { "2x6", 1, glm::vec3(1.f, 3.f, 0.6f) }; // 2x6 Brick
	g_lddDesignIDToblsUIName[3007] = { "2x8", 1, glm::vec3(1.f, 4.f, 0.6f) }; // 2x8 Brick
	
	g_lddDesignIDToblsUIName[3006] = { "2x10", 1, glm::vec3(1.f, 5.f, 0.6f) }; // 2x10 Brick
//	g_lddDesignIDToblsUIName[30505] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 3x3 Corner Brick
//	g_lddDesignIDToblsUIName[2577] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 4x4 Quarter Circle Brick
//	g_lddDesignIDToblsUIName[87081] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 4x4 Round Brick

	g_lddDesignIDToblsUIName[44042] = { "4x6", 1, glm::vec3(2.f, 3.f, 0.6f) }; // 4x6 Brick
	g_lddDesignIDToblsUIName[6212] = { "4x10", 1, glm::vec3(2.f, 5.f, 0.6f) }; // 4x10 Brick
	g_lddDesignIDToblsUIName[60033] = { "4x12", 1, glm::vec3(2.f, 6.f, 0.6f) }; // 4x12 Brick
//	g_lddDesignIDToblsUIName[30400] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 4x18 Brick

	g_lddDesignIDToblsUIName[43802] = { "8x8", 1, glm::vec3(4.f, 4.f, 0.6f) }; // 8x8 Brick
	g_lddDesignIDToblsUIName[44041] = { "8x16", 1, glm::vec3(4.f, 8.f, 0.6f) }; // 8x16 Brick
//	g_lddDesignIDToblsUIName[23945] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 1x1 Hourglass Brick
//	g_lddDesignIDToblsUIName[3245] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 1x2x2 Brick
	
	g_lddDesignIDToblsUIName[15332] = { "1x4x2 Bars", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 1x4x2 Fence Brick
//	g_lddDesignIDToblsUIName[3940] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 2x2 Undercarriage Brick
//	g_lddDesignIDToblsUIName[14716] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 1x1x3 Brick
	g_lddDesignIDToblsUIName[30145] = { "2x2x3", 1, glm::vec3(1.f, 1.f, 1.8f) }; // 2x2x3 Brick
	
//	g_lddDesignIDToblsUIName[6037] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 2x2 Octogonal Tower
	g_lddDesignIDToblsUIName[2453] = { "1x1x5", 1, glm::vec3(0.5f, 0.5f, 3.f) }; // 1x1x5 Brick
	g_lddDesignIDToblsUIName[2454] = { "1x2x5", 1, glm::vec3(0.5f, 1.f, 3.f) }; // 1x2x5 Brick
	g_lddDesignIDToblsUIName[3754] = { "1x6x5", 1, glm::vec3(0.5f, 3.f, 3.f) }; // 1x6x5 Brick

	g_lddDesignIDToblsUIName[74573] = { "2x2x5 Lattice", 1, glm::vec3(1.f, 1.f, 3.f) }; // 2x2x5 Lattice Tower
//	g_lddDesignIDToblsUIName[30517] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 2x2x10 Lattice Tower


	//-------------- Plates --------------
	
	g_lddDesignIDToblsUIName[3024] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 1x1 Plate
	g_lddDesignIDToblsUIName[6141] = { "1x1F Round", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 1x1 Round Plate
	g_lddDesignIDToblsUIName[33291] = { "1x1F Round", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 1x1 Flower Plate
	g_lddDesignIDToblsUIName[3022] = { "2x2F", 1, glm::vec3(1.f, 1.f, 0.2f) }; // 2x2 Plate

	g_lddDesignIDToblsUIName[4032] = { "2x2F Round", 1, glm::vec3(1.f, 1.f, 0.2f) }; // 2x2 Round Plate
	g_lddDesignIDToblsUIName[3020] = { "2x4F", 1, glm::vec3(1.f, 2.f, 0.2f) }; // 2x4 Plate
	g_lddDesignIDToblsUIName[3023] = { "1x2F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 1x2 Plate
	g_lddDesignIDToblsUIName[3623] = { "1x3F", 1, glm::vec3(0.5f, 1.5f, 0.2f) }; // 1x3 Plate

	g_lddDesignIDToblsUIName[3710] = { "1x4F", 1, glm::vec3(0.5f, 2.f, 0.2f) }; // 1x4 Plate
	g_lddDesignIDToblsUIName[3666] = { "1x6F", 1, glm::vec3(0.5f, 3.f, 0.2f) }; // 1x6 Plate
	g_lddDesignIDToblsUIName[3460] = { "1x8F", 1, glm::vec3(0.5f, 4.f, 0.2f) }; // 1x8 Plate
	g_lddDesignIDToblsUIName[4477] = { "1x10F", 1, glm::vec3(0.5f, 5.f, 0.2f) }; // 1x10 Plate

	g_lddDesignIDToblsUIName[60479] = { "1x12F", 1, glm::vec3(0.5f, 6.f, 0.2f) }; // 1x12 Plate
	g_lddDesignIDToblsUIName[3021] = { "2x3F", 1, glm::vec3(1.f, 1.5f, 0.2f) }; // 2x3 Plate
	g_lddDesignIDToblsUIName[3795] = { "2x6F", 1, glm::vec3(1.f, 3.f, 0.2f) }; // 2x6 Plate
	g_lddDesignIDToblsUIName[3034] = { "2x8F", 1, glm::vec3(1.f, 4.f, 0.2f) }; // 2x8 Plate

	g_lddDesignIDToblsUIName[3832] = { "2x10F", 1, glm::vec3(1.f, 5.f, 0.2f) }; // 2x10 Plate
//	g_lddDesignIDToblsUIName[2445] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 2x12 Plate
//	g_lddDesignIDToblsUIName[91988] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 2x14 Plate
//	g_lddDesignIDToblsUIName[4282] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 2x16 Plate

//	g_lddDesignIDToblsUIName[24299] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 2x2 Left Plate
//	g_lddDesignIDToblsUIName[24307] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 2x2 Right Plate
//	g_lddDesignIDToblsUIName[43723] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 2x3 Angle Plate (Left)
//	g_lddDesignIDToblsUIName[43722] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 2x3 Angle Plate (Right)

//	g_lddDesignIDToblsUIName[41770] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 2x4 Angle Plate (Left)
//	g_lddDesignIDToblsUIName[41769] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 2x4 Angle Plate (Right)
//	g_lddDesignIDToblsUIName[11212] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 3x3 Plate
//	g_lddDesignIDToblsUIName[30357] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 3x3 Quarter Circle Plate

//	g_lddDesignIDToblsUIName[2450] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 3x3 Corner Plate
//	g_lddDesignIDToblsUIName[47397] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 3x12 Left Plate
//	g_lddDesignIDToblsUIName[47398] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 3x12 Right Plate
	g_lddDesignIDToblsUIName[3031] = { "4x4F", 1, glm::vec3(2.f, 2.f, 0.2f) }; // 4x4 Plate

//	g_lddDesignIDToblsUIName[60474] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 4x4 Round Plate
//	g_lddDesignIDToblsUIName[30565] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 4x4 Quater Circle Plate
//	g_lddDesignIDToblsUIName[30503] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 4x4 Corner Plate
	g_lddDesignIDToblsUIName[3032] = { "4x6F", 1, glm::vec3(2.f, 3.f, 0.2f) }; // 4x6 Plate

	g_lddDesignIDToblsUIName[3035] = { "4x8F", 1, glm::vec3(2.f, 4.f, 0.2f) }; // 4x8 Plate
	g_lddDesignIDToblsUIName[3030] = { "4x10F", 1, glm::vec3(2.f, 5.f, 0.2f) }; // 4x10 Plate
	g_lddDesignIDToblsUIName[3029] = { "4x12F", 1, glm::vec3(2.f, 6.f, 0.2f) }; // 4x12 Plate
	g_lddDesignIDToblsUIName[3958] = { "6x6F", 1, glm::vec3(3.f, 3.f, 0.2f) }; // 6x6 Plate

//	g_lddDesignIDToblsUIName[6106] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 6x6 Corner Plate
	g_lddDesignIDToblsUIName[3036] = { "6x8F", 1, glm::vec3(3.f, 4.f, 0.2f) }; // 6x8 Plate
	g_lddDesignIDToblsUIName[3028] = { "6x12F", 1, glm::vec3(3.f, 6.f, 0.2f) }; // 6x12 Plate
//	g_lddDesignIDToblsUIName[3456] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 6x14 Plate

	g_lddDesignIDToblsUIName[3027] = { "6x16F", 1, glm::vec3(3.f, 8.f, 0.2f) }; // 6x16 Plate
	g_lddDesignIDToblsUIName[41539] = { "8x8F", 1, glm::vec3(4.f, 4.f, 0.2f) }; // 8x8 Plate
//	g_lddDesignIDToblsUIName[30504] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 8x8 Corner Plate
	g_lddDesignIDToblsUIName[92438] = { "8x16F", 1, glm::vec3(4.f, 8.f, 0.2f) }; // 8x16 Plate

	g_lddDesignIDToblsUIName[91405] = { "16x16F", 1, glm::vec3(8.f, 8.f, 0.2f) }; // 16x16 Plate
//	g_lddDesignIDToblsUIName[44336] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // Straight Road Plate
//	g_lddDesignIDToblsUIName[44342] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // Curved Road Plate
//	g_lddDesignIDToblsUIName[44343] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // Crossroad Plate

//	g_lddDesignIDToblsUIName[44341] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // T-Junction Road Plate
//	g_lddDesignIDToblsUIName[239298] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // Straight Street Plate
//	g_lddDesignIDToblsUIName[239898] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // Curved Street Plate
//	g_lddDesignIDToblsUIName[239998] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // Crossing Street Plate

//	g_lddDesignIDToblsUIName[239798] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // T-Junction Street Plate
//	g_lddDesignIDToblsUIName[239299] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // Straight Dirt Road Plate
//	g_lddDesignIDToblsUIName[239899] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // Curved Dirt Road Plate
//	g_lddDesignIDToblsUIName[239999] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // Dirt Crossroad Plate

//	g_lddDesignIDToblsUIName[239799] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // T-Junction Dirt Road Plate
//	g_lddDesignIDToblsUIName[239300] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // Straight Mud Road Plate
//	g_lddDesignIDToblsUIName[239900] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // Curved Mud Road Plate
//	g_lddDesignIDToblsUIName[240000] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // Mud Crossroad Plate

//	g_lddDesignIDToblsUIName[239800] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // T-Junction Mud Road Plate

	//------------ Tiles -----------------

	g_lddDesignIDToblsUIName[3070] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 1x1 Flat Tile
	g_lddDesignIDToblsUIName[98138] = { "1x1F Round", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 1x1 Round Flat Tile
	g_lddDesignIDToblsUIName[24246] = { "1x1F Round", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 1x1 Half Circle Tile
	g_lddDesignIDToblsUIName[25269] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 1x1 Quarter Circle Tile

	g_lddDesignIDToblsUIName[3069] = { "1x2F", 1, glm::vec3(0.5f, 1.f, 0.2f) }; // 1x2 Flat Tile
	g_lddDesignIDToblsUIName[96910] = { "1x2F", 1, glm::vec3(0.5f, 1.f, 0.2f) }; // 1x2 Ingot Tile
	g_lddDesignIDToblsUIName[2412] = { "1x2F", 1, glm::vec3(0.5f, 1.f, 0.2f) }; // 1x2 Radiator Grille
	g_lddDesignIDToblsUIName[63864] = { "1x3F", 1, glm::vec3(0.5f, 1.5f, 0.2f) }; // 1x3 Flat Tile

	g_lddDesignIDToblsUIName[2431] = { "1x4F", 1, glm::vec3(0.5f, 2.f, 0.2f) }; // 1x4 Flat Tile
	g_lddDesignIDToblsUIName[6636] = { "1x6F", 1, glm::vec3(0.5f, 3.f, 0.2f) }; // 1x6 Flat Tile
	g_lddDesignIDToblsUIName[4162] = { "1x8F", 1, glm::vec3(0.5f, 4.f, 0.2f) }; // 1x8 Flat Tile
	g_lddDesignIDToblsUIName[3068] = { "2x2F", 1, glm::vec3(1.f, 1.f, 0.2f) }; // 2x2 Flat Tile

	g_lddDesignIDToblsUIName[14769] = { "2x2F Round", 1, glm::vec3(1.f, 1.f, 0.2f) }; // 2x2 Round Flat Tile
	g_lddDesignIDToblsUIName[22385] = { "2x3F", 1, glm::vec3(1.f, 1.5f, 0.2f) }; // 2x3 Pointed Tile
	g_lddDesignIDToblsUIName[87079] = { "2x4F", 1, glm::vec3(1.f, 2.f, 0.2f) }; // 2x4 Flat Tile
	g_lddDesignIDToblsUIName[10202] = { "6x6F", 1, glm::vec3(3.f, 3.f, 0.2f) }; // 6x6 Flat Tile

	g_lddDesignIDToblsUIName[48288] = { "8x16F", 1, glm::vec3(4.f, 8.f, 0.2f) }; // 8x16 Flat Tile

	
	//------------------- Slopes -----------------
	
//	g_lddDesignIDToblsUIName[50746] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 1x1 Wedge
//	g_lddDesignIDToblsUIName[22388] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 1x1 Pyramid
//	g_lddDesignIDToblsUIName[85984] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 1x2 Wedge
	g_lddDesignIDToblsUIName[3040] = { "45° Ramp 1x", 2, glm::vec3(0.5f, 1.f, 0.6f) }; // 1x2 Slope
	
	g_lddDesignIDToblsUIName[3665] = { "-45° Ramp 1x", 2, glm::vec3(0.5f, 1.f, 0.6f) }; // 1x2 Inverted Slope
	g_lddDesignIDToblsUIName[3039] = { "45° Ramp 2x", 2, glm::vec3(1.f, 1.f, 0.6f) }; // 2x2 Slope
	g_lddDesignIDToblsUIName[3044] = { "45° Crest 1x", 2, glm::vec3(0.5f, 1.f, 0.6f) }; // 1x2 Roof Tile
	g_lddDesignIDToblsUIName[3048] = { "45° Crest End", 2, glm::vec3(0.5f, 1.f, 0.6f) }; // 1x2 End Ridged Tile

//	g_lddDesignIDToblsUIName[61409] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 1x2 Lattice Roof Tile
	g_lddDesignIDToblsUIName[4286] = { "25° Ramp 1x", 2, glm::vec3(0.5f, 1.5f, 0.6f) }; // 1x3 Slope
	g_lddDesignIDToblsUIName[4287] = { "-25° Ramp 1x", 2, glm::vec3(0.5f, 1.5f, 0.6f) }; // 1x3 Inverted Slope
//	g_lddDesignIDToblsUIName[18759] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 1x3 Double Inverted Roof Tile
	
//	g_lddDesignIDToblsUIName[60477] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 1x4 Slope
//	g_lddDesignIDToblsUIName[41762] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 1x6 Brick with Bow
//	g_lddDesignIDToblsUIName[41855] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 2x2 Angled Slope
//	g_lddDesignIDToblsUIName[47457] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 2x2 Curved Slope
	
	g_lddDesignIDToblsUIName[3300] = { "25° Crest 2x", 2, glm::vec3(1.f, 1.f, 0.4f) }; // 2x2x1 Roof Tile
	g_lddDesignIDToblsUIName[3043] = { "45° Crest 2x", 2, glm::vec3(1.f, 1.f, 0.6f) }; // 2x2x2 Roof Tile
	g_lddDesignIDToblsUIName[3045] = { "45° Ramp Corner", 2, glm::vec3(1.f, 1.f, 0.6f) }; // 2x2 Corner Brick
	g_lddDesignIDToblsUIName[3676] = { "-45° Ramp Corner", 2, glm::vec3(1.f, 1.f, 0.6f) }; // 2x2 Inverted Roof Tile Corner
	
//	g_lddDesignIDToblsUIName[13548] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 2x2x1 Roof Tile
//	g_lddDesignIDToblsUIName[3046] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 2x2 Inverted Corner Brick
	g_lddDesignIDToblsUIName[3660] = { "-45° Ramp 2x", 2, glm::vec3(1.f, 1.f, 0.6f) }; // 2x2 Inverted Slope
	g_lddDesignIDToblsUIName[4589] = { "1x1 Cone", 1, glm::vec3(0.5f, 0.5f, 0.6f) }; // 1x1 Small Nose Cone
	
//	g_lddDesignIDToblsUIName[3038] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 2x3 Slope
	g_lddDesignIDToblsUIName[3037] = { "45° Ramp 4x", 2, glm::vec3(1.f, 2.f, 0.6f) }; // 2x4 Slope
//	g_lddDesignIDToblsUIName[43721] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 2x4 Angle Brick with Bow (Left)
//	g_lddDesignIDToblsUIName[43720] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 2x4 Angle Brick with Bow (Right)
	
	g_lddDesignIDToblsUIName[3299] = { "25° Crest 4x", 2, glm::vec3(1.f, 2.f, 0.4f) }; // 2x4x1 Roof Tile
	g_lddDesignIDToblsUIName[3041] = { "45° Crest 4x", 2, glm::vec3(1.f, 2.f, 0.6f) }; // 2x4x2 Roof Tile
//	g_lddDesignIDToblsUIName[88930] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 2x4 Plate with Bow
//	g_lddDesignIDToblsUIName[6191] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 1x4 Curved Brick
	
//	g_lddDesignIDToblsUIName[6192] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 2x4x1 Bowed Roof Ridge
//	g_lddDesignIDToblsUIName[4445] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 2x8 Slope
	g_lddDesignIDToblsUIName[3298] = { "25° Ramp 2x", 2, glm::vec3(1.f, 1.5f, 0.6f) }; // 2x3 Slope
	g_lddDesignIDToblsUIName[3747] = { "-25° Ramp 2x", 2, glm::vec3(1.f, 1.5f, 0.6f) }; // 2x3 Inverted Slope
	
//	g_lddDesignIDToblsUIName[6215] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 2x3 Brick with Arch
//	g_lddDesignIDToblsUIName[43710] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 2x4 Left Roof Tile
//	g_lddDesignIDToblsUIName[43711] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 2x4 Right Roof Tile
//	g_lddDesignIDToblsUIName[4161] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 3x3 Slope
	
	g_lddDesignIDToblsUIName[3675] = { "25° Ramp Corner", 2, glm::vec3(1.5f, 1.5f, 0.6f) }; // 3x3 Corner Brick
//	g_lddDesignIDToblsUIName[99301] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 3x3 Inverted Corner Brick
//	g_lddDesignIDToblsUIName[3297] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 3x4 Slope
//	g_lddDesignIDToblsUIName[30363] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 2x4 Slope
	
//	g_lddDesignIDToblsUIName[43708] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 4x4 Tilted Corner
//	g_lddDesignIDToblsUIName[44126] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 2x6 Brick with Bow
//	g_lddDesignIDToblsUIName[41748] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 2x6 Angle Shell with Bow (Left)
//	g_lddDesignIDToblsUIName[41747] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 2x6 Angle Shell with Bow (Right)
	
//	g_lddDesignIDToblsUIName[60481] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 2x1x2 Slope
//	g_lddDesignIDToblsUIName[3678] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 2x2x2 Slope
//	g_lddDesignIDToblsUIName[33243] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 1x3x2 Bow Brick
//	g_lddDesignIDToblsUIName[88293] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 3x3x2 Arch Brick
	
//	g_lddDesignIDToblsUIName[4744] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 2x4x2 Arch
//	g_lddDesignIDToblsUIName[6216] = { "1x1F", 1, glm::vec3(0.5f, 0.5f, 0.2f) }; // 2x4x2 Top
	g_lddDesignIDToblsUIName[4460] = { "72° Ramp 1x", 2, glm::vec3(0.5f, 1.f, 1.8f) }; // 1x2x3 Slope
	g_lddDesignIDToblsUIName[30499] = { "72° Ramp 2x", 2, glm::vec3(1.f, 1.f, 1.8f) }; // 2x2x3 Slope
	
	g_lddDesignIDToblsUIName[2449] = { "-72° Ramp 1x", 2, glm::vec3(0.5f, 1.f, 1.8f) }; // 1x2x3 Inverted Slope
	g_lddDesignIDToblsUIName[3685] = { "72° Ramp Corner", 2, glm::vec3(1.f, 1.f, 1.8f) }; // 2x2x3 Corner Brick
}

blsGroup *blsGroup::CreateFromLDDGroup(std::shared_ptr<lddGroup> sourceGroup, std::shared_ptr<blsColorset> colorset)
{
	blsGroup *group = new blsGroup();
	group->colorset = colorset;

	// Convert bricks
	for (auto sourceBrick : sourceGroup->bricks) {
		if (g_lddDesignIDToblsUIName.find(sourceBrick->designID) == g_lddDesignIDToblsUIName.end())
			continue;

		// Convert position
		glm::vec3 outPos;
		// Note: This appears to be the bottom left
		glm::vec3 &inPos = sourceBrick->translation;
		outPos.x = inPos.x / 0.8f * 0.5f;// - 0.25f;
		outPos.y = -inPos.z / 0.8f * 0.5f;// - 0.25f;
		outPos.z = inPos.y / 0.32f * 0.2f;// - 0.1f;
//		std::cout << std::setprecision(2) << std::fixed << inPos.x << " " << inPos.y << " " << inPos.z << " -> " << outPos.x << " " << outPos.y << " " << outPos.z << std::endl;
//		printf("%f %f %f -> %f %f %f\n", inPos.x, inPos.y, inPos.z, outPos.x, outPos.y, outPos.z);

		// Color
		size_t numColors = colorset->colors.size();
		size_t colorIdx = numColors;
		float closestColorDist = 1e16f;
		// Determine closest color
		for (size_t a = 0; a < numColors; ++a) {
			if (colorset->colors[a]->rgba.a < 1.f)
				continue;
			float dist = hslcDif(colorset->colors[a]->hslc, sourceBrick->hslc);
			if (dist < closestColorDist) {
				closestColorDist = dist;
				colorIdx = a;
			}
		}

		// Detect angleID
//		if (sourceBrick->designID != 3005)
//			outPos.z += 0.6f;
		uint16_t angleID;
		if (sourceBrick->scaleRotation[0][0] == 1.f)
			angleID = 0;
		else if (sourceBrick->scaleRotation[2][0] == 1.f)
			angleID = 1;
		else if (sourceBrick->scaleRotation[0][0] == -1.f)
			angleID = 2;
		else if (sourceBrick->scaleRotation[2][0] == -1.f)
			angleID = 3;
		else
			angleID = 0;



		blsBrick *brick = new blsBrick();
		group->bricks.push_back(brick);

		auto &profile = g_lddDesignIDToblsUIName[sourceBrick->designID];
		brick->angleID = (profile.angleIdOffset + angleID) % 4;
		brick->colorID = (uint16_t)colorIdx;
		brick->uiName = profile.uiName;
//			brick->colorID = brick->angleID;

		// Adjust position
//		glm::vec3 ext(profile.extent.x, profile.extent.z, profile.extent.y);
//		glm::vec3 m = sourceBrick->scaleRotation * ext;
#if 1
#if 1
//		outPos.x -= ext.x * 0.5f;
//		outPos.y += ext.z * 0.5f;
		switch (brick->angleID) {
		case 1:
			outPos.x = floor(outPos.x * 2.f + 0.25f) * 0.5f + (profile.extent.y * 0.5f);
			outPos.y = floor(outPos.y * 2.f + 0.25f) * 0.5f + (profile.extent.x * 0.5f);
			break;
		case 3:
			outPos.x = floor(outPos.x * 2.f + 0.25f) * 0.5f - (profile.extent.y * 0.5f) + 0.5f;
			outPos.y = floor(outPos.y * 2.f + 0.25f) * 0.5f - (profile.extent.x * 0.5f) + 0.5f;
			break;
		case 0:
			outPos.x = floor(outPos.x * 2.f + 0.25f) * 0.5f + (profile.extent.x * 0.5f) - 0.25f;
			outPos.y = floor(outPos.y * 2.f + 0.25f) * 0.5f + (profile.extent.y * 0.5f);
			break;
		case 2:
//			if (sourceBrick->designID == 4286)
//				printf("");
			outPos.x = floor(outPos.x * 2.f + 0.25f) * 0.5f + (profile.extent.x * 0.5f);
			outPos.y = floor(outPos.y * 2.f + 0.25f) * 0.5f - (profile.extent.y * 0.5f) + 0.5f;
//			printf("");
			break;
		}
		outPos.z += profile.extent.z * 0.5f;
/*		switch (brick->angleID) {
		case 1:
			outPos.x += profile.extent.y * 0.5f;
			outPos.y += profile.extent.x * 0.5f;
			break;
		case 3:
			outPos.x -= profile.extent.y * 0.5f - 0.5f;
			outPos.y -= profile.extent.x * 0.5f - 0.5f;
			break;
		case 0:
			outPos.x += profile.extent.x * 0.5f - 0.5f;
			outPos.y += profile.extent.y * 0.5f;
			break;
		case 2:
			outPos.x -= profile.extent.x * 0.5f - 1.f;
			outPos.y -= profile.extent.y * 0.5f - 0.5f;
			break;
		}*/
#else
		switch (brick->angleID) {
		case 0:
			outPos.x = outPos.x - profile.extent.x * 0.5f - 0.25f;
			outPos.y = outPos.y + profile.extent.y * 0.5f - 0.25f;
			break;
		case 1:
			outPos.x = outPos.x + profile.extent.y * 0.5f - 0.5f;
			outPos.y = outPos.y + profile.extent.x * 0.5f - 0.25f;
			break;
		case 2:
			outPos.x = outPos.x - profile.extent.x * 0.5f + 0.25f;
			outPos.y = outPos.y - profile.extent.y * 0.5f + 0.5f;
			break;
		case 3:
			outPos.x = outPos.x - profile.extent.y * 0.5f - 0.25f;
			outPos.y = outPos.y + profile.extent.x * 0.5f - 0.5f;
			break;
		}
#endif
#endif

		// TEMP
//		outPos.z -= 0.6f;

		brick->position = outPos;

//		printf("%f %f %f -> %lld %f (%f %f %f)\n", sourceBrick->rgba.r, sourceBrick->rgba.g, sourceBrick->rgba.b, colorIdx, closestColorDist, colorset->colors[colorIdx]->rgba.r, colorset->colors[colorIdx]->rgba.g, colorset->colors[colorIdx]->rgba.b);
	}
	printf("Converted %lld bricks\n", group->bricks.size());

	return group;
}

void blsGroup::WriteToFile(const char *file)
{
	ofstream outFile(file, std::ios::out | std::ios::binary);
	outFile << "This is a Blockland save file.  You probably shouldn't modify it cause you'll screw it up." << std::endl;
	outFile << "1" << std::endl << std::endl;

	// Output colorset
	outFile << std::setprecision(6) << std::fixed;
	uint32_t numColorEntries = 0;
	for (auto &color : colorset->colors) {
		outFile << color->rgba[0] << " " << color->rgba[1] << " "<< color->rgba[2] << " " << color->rgba[3] << std::endl;
		++numColorEntries;
	}
	while (numColorEntries < 64) {
		outFile << 1.f << " " << 0.f << " "<< 1.f << " " << 0.f << std::endl;
		++numColorEntries;
	}

	// Output bricks
	outFile << "Linecount " << bricks.size() << std::endl;
	for (auto brick : bricks) {
		outFile << brick->uiName << "\" ";
		outFile << std::setprecision(2) << std::fixed << brick->position.x << " " << brick->position.y << " " << brick->position.z << " ";
		outFile << brick->angleID << " 1 " << brick->colorID << "  0 0 1 1 1" << std::endl;
	}
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
	uint16_t idx = 0;
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