#include <filesystem> // if fails to compile, try <experimental/filesystem> or compile with -lstdc++fs
#include <stack>
#include <string>

class Filesystem {

public:

	// Constructor
	Filesystem(const std::string& p);

	// Change directory
	std::string cd(const std::string& p);

	// Create directory
	std::string md(const std::string& p) const;

	// View current directory
	std::string pwd() const;

	// View root directory
	std::string root() const;

	// View directories stack
	std::string dirs() const;

	// Swap two directories at the top of the stack
	std::string pushd();

	// Push directory to the stack
	std::string pushd(const std::string& p);

	// Pop directory from the stack
	std::string popd();

	// Open directory in the default file manager
	std::string explorer() const;

private:
	std::experimental::filesystem::path _root;
	std::experimental::filesystem::path _path;
	std::stack<std::experimental::filesystem::path> _stack;

};
