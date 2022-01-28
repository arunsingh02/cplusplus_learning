#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include<vector>

using namespace std;

std::string exec(const char* cmd) {
    char buffer[128];
    std::string result = "";
    FILE* pipe = popen(cmd, "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    try {
        while (fgets(buffer, sizeof buffer, pipe) != NULL) {
            result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;
}

string CollectVasaProviderVersion(const string result){
	std::vector<string> vasa_provider_info_list;
	std::string temp = "";
  int line_counter = 0;

	for ( int i = 0; i < result.length(); ++i ){
    if (line_counter > 2) break;
		if ( result[i] == '\n' ) {
			vasa_provider_info_list.push_back(temp);
			temp = "";
      line_counter++;
		}
		else {
			temp.push_back(result[i]);
		}
	}

  std::string delimiter = "build-vasa";
  std::string vasa_provider_version;

  for ( int i = 0; i < vasa_provider_info_list.size(); ++i ) {
    std::string line = vasa_provider_info_list[i];

    std::size_t found = line.find(delimiter);
    if (found != std::string::npos ) {
      int start = found + delimiter.length() + 1;
      vasa_provider_version = line.substr(start, 8);
      break;
    }
  }
	return vasa_provider_version;
}

int main(int argc, char const *argv[]) {
  std::string result = exec("cat testfile.service");

  cout << CollectVasaProviderVersion(result) << endl;

  return 0;
}
