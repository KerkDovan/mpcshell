#include <functional>
#include <iostream>

#include "filesystem.hpp"

using namespace std;
namespace fs = std::experimental::filesystem;

int main(int argc, char** argv) {

	Filesystem fs(argc == 1 ? argv[0] : argv[1]);

	std::experimental::filesystem::path p = argv[0];

	auto str = [](const fs::path& f) { return f.generic_string() + "\n"; };

	cout <<
		str(p) <<
		str(p.native()) <<
		str(fs::path(p).remove_filename()) <<
		str(fs::path(p).remove_filename().remove_filename()) <<
		str(p.root_directory()) <<
		str(p.root_name()) <<
		str(p.root_path()) << 
		str(p.relative_path()) <<
		str(p.stem()) <<
		str(p.parent_path()) <<
	"";

	getchar();
	return 0;
}
