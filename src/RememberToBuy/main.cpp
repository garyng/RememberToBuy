// RememberToBuy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "App.h"

using namespace std;

int main(int argc, char* argv[])
{
	shared_ptr<App> app = make_shared<App>();
	app->Start();
}
