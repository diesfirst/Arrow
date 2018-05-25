#include <vdb_tests.h>

using namespace openvdb;

int vdb_test_0() {

	initialize();
	
	FloatGrid::Ptr grid = FloatGrid::create();
	FloatGrid::Accessor accessor = grid->getAccessor();

	Coord xyz(1, 0, 0);
	Coord abc(11, 0, 0);

	accessor.setValue(xyz, 1.0);

	std::cout << "Grid" << abc << " = " << accessor.getValue(abc) << std::endl;

	

	return 0;
	
}