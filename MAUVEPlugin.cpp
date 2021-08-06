#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "MAUVEPlugin.h"

void MAUVEPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string filename;
   ifile >> filename;
   if (filename.length() != 0)
   fastaFiles.push_back(filename);
 }
}

void MAUVEPlugin::run() {
   
}

void MAUVEPlugin::output(std::string file) {
	std::string command;
   command = "progressiveMauve ";
   for (int i = 0; i < fastaFiles.size(); i++) 
      command += std::string(PluginManager::prefix())+"/"+fastaFiles[i]+" ";
   command += "--output="+file;
 std::cout << command << std::endl;

 system(command.c_str());
}

PluginProxy<MAUVEPlugin> MAUVEPluginProxy = PluginProxy<MAUVEPlugin>("MAUVE", PluginManager::getInstance());
