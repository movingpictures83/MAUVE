#ifndef MAUVEPLUGIN_H
#define MAUVEPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>
#include <vector>

class MAUVEPlugin : public Plugin
{
public: 
 std::string toString() {return "MAUVE";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
 std::vector<std::string> fastaFiles;
};

#endif
