// test.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	//int value = 10;
	string value = "aa";
	char str[4];
	memcpy(str, value.c_str(), sizeof(str));
	for (int i = 0; i < 4; ++i) {
		cout << (int)str[i] << endl;
	}
	system("PAUSE");
    return 0;
}

