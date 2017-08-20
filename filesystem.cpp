#include <cstdlib>

#include "filesystem.hpp"

using namespace std;
using namespace std::experimental::filesystem;

Filesystem::Filesystem(const string& p) {
	_root = canonical(path(p));
	if (!is_directory(_root))
		_root.remove_filename();
	_path = _root / "projects";
}

string Filesystem::cd(const string& p) {
	path tmp = canonical(_path / p);
	if (exists(tmp))
		if (is_directory(tmp))
			_path = tmp;
		else
			return "It is not directory: " + tmp.string();
	else
		return "No such directory: " + tmp.string();
	return pwd();
}

string Filesystem::md(const string& p) const {
	path tmp = _path / p;
	if (exists(tmp))
		return "Directory already exists: " + tmp.string();
	return "Created directory: " + tmp.string();
}

string Filesystem::pwd() const {
	return _path.generic_string();
}

string Filesystem::root() const {
	return _root.generic_string();
}

string Filesystem::dirs() const {
	return "";
}

string Filesystem::pushd() {
	if (_stack.size() != 0)
		swap(_path, _stack.top());
	return dirs();
}

string Filesystem::pushd(const string& p) {

	return dirs();
}

string Filesystem::popd() {
	if (_stack.size() > 1)
		_stack.pop();
	else
		return "Directory stack empty";
	return dirs();
}

string Filesystem::explorer() const {
	string program;
#ifdef _WIN32
	program = "explorer";
#elif __linux__
	program = "xdg-open";
#else
	program = "open";
#endif
	system((program + pwd()).c_str());
	return "Opened " + pwd();
}
