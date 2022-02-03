#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

string exec(const char* cmd) {
    char buffer[128];
    string result = "";
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

vector<string> text_spliter(const string data, string delimiter, int limit = 0){
  vector<string> data_list;
  string temp = "";
  int line_counter = 0;

	for ( int i = 0; i < data.length(); ++i ){
    if (limit && line_counter > limit) break;
    string ch;
    ch.push_back(data[i]);
		if ( ch == delimiter ) {
			data_list.push_back(temp);
			temp = "";
      line_counter++;
		}
		else {
			temp.push_back(data[i]);
		}
	}
  return data_list;
}

string CollectVasaProviderVersion(const string result){
  vector<string> vasa_provider_info_list = text_spliter(result, "\n", 2);

  string vasa_provider_version_line = vasa_provider_info_list[2];

  vector<string> vasa_provider_version_list = text_spliter(vasa_provider_version_line, "/");

	return vasa_provider_version_list[3];
}

int main(int argc, char const *argv[]) {
  string result = exec("cat testfile.service");

  cout << CollectVasaProviderVersion(result) << endl;

  return 0;
}

/*
new-build-vasa-2.10.102
*/
