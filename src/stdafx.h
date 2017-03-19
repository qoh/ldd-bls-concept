#ifdef _WIN32
#include <Windows.h>
#endif

#define USE_EASTL 0

// Standard Library
#include <cassert>
#include <inttypes.h>

#include <iomanip>
#include <fstream>
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <sstream>

#if USE_EASTL
// EASTL
#include <EASTL/string.h>
#include <EASTL/deque.h>
#include <EASTL/map.h>
#include <EASTL/queue.h>
#include <EASTL/memory.h>
#include <EASTL/vector.h>
#include <EASTL/chrono.h>

using namespace eastl;
#else
// Standard Library
#include <algorithm>
#include <string>
#include <deque>
#include <map>
#include <queue>
#include <memory>
#include <vector>
#include <chrono>

using namespace std;
#endif

// GLM
#include <glm/glm.hpp>

// pugixml
#include <pugixml.hpp>