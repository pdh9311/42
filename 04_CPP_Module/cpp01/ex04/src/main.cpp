#include <iostream>
#include <fstream>
#include <string>

void ChangeStr1ToStr2(std::string &buf, const std::string &s1, const std::string &s2, std::string &result)
{
	std::string::size_type pos;

	while (1) {
		pos = buf.find(s1);
		if (pos == std::string::npos) {
			if (!buf.empty())
				result.append(buf);
			break ;
		}
		result.append(buf, 0, pos);
		result.append(s2);
		buf = buf.substr(pos + s1.length());
	}
}

int main(int argc, char **argv)
{
	if (argc != 4) {
		std::cout << "How to run : ./replace [filename] [string1] [string2]" << std::endl;
		return (0);
	}

	std::string filename(argv[1]);
	std::string s1(argv[2]);
	std::string s2(argv[3]);
	std::string replaced_file(filename + ".replace");
	if (filename.empty() || s1.empty() || s2.empty()) {
		std::cout << "How to run : ./replace [filename] [string1] [string2]" << std::endl;
		return (0);
	}

	std::ifstream read_file(filename, std::ios::in);
	if (!read_file.is_open()) {
		std::cout << filename << " <- File not found." << std::endl;
		return (0);
	}

	std::ofstream write_file(replaced_file, std::ios::trunc | std::ios::out);
	if (!write_file.is_open()) {
		std::cout << replaced_file << " <- The file could not be created or found." << std::endl;
		return (0);
	}

	std::string buf;
	std::string result;
	while (read_file) {
		result.clear();
		std::getline(read_file, buf);
		if (read_file.eof()) {
			ChangeStr1ToStr2(buf, s1, s2, result);
			write_file << result;
			break ;
		}
		ChangeStr1ToStr2(buf, s1, s2, result);
		write_file << result;
		write_file << std::endl;
	}
	return (0);
}