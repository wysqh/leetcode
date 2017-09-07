#include "deploy.h"
#include "lib_io.h"
#include "lib_time.h"
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include "interface.h"
using namespace std;

extern Console console;
template<class _Ty>
	struct remove_reference1
	{	// remove reference
	typedef _Ty type;
	};

void deploy_server(char* inLines[MAX_IN_NUM], int inLineNum, const char * const filename)
{
	//¿ØÖÆ½á¹¹
	Console console(inLines, inLineNum);
	//console.debug_print();
	
	MinInfo minInfo;
	console.localOptimalSearch(minInfo);
	std::string res;
    write_result(res.c_str(), filename);
}
