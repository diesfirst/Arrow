#include <vdb_tests.h>
#include <openvdb\tools\LevelSetSphere.h>

int vdb_test_1() {

	openvdb::initialize();

	//create grid with background value of 2.0
	openvdb::FloatGrid::Ptr grid = openvdb::tools::createLevelSetSphere<openvdb::FloatGrid>(
		/*radius=*/50.0, /*center=*/openvdb::Vec3f(1.5, 2, 3), /*voxel size=*/0.5, /*width=*/4.0);

	//associate metadata with grid
	grid->insertMeta("radius", openvdb::FloatMetadata(50.0));

	//name grid "levelSetSphere"
	grid->setName("levelSetSphere");

	//create VDB file opject
	openvdb::io::File file("mygrids.vdb");

	//add the grid pointer to a container
	openvdb::GridPtrVec grids;
	grids.push_back(grid);

	//write out contents of the container
	file.write(grids);
	file.close();
	
	return 0;
}