#include <iostream>
#include <Windows.h>

using namespace std;

class MiniApps
{
public:
	MiniApps();
	virtual ~MiniApps();
	static void keepCounting();
	static void numberConversion();
	static void upcConverter();
	static void upcChecker();
};
