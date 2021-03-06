// protobuf-desc.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>

using namespace BestanDesc;
using namespace std;
using namespace bestan::common::config;

int main()
{
	vector<string> descList = {
		"索引",
		"名字",
		"技能1id",
		"技能1概率",
		"技能2id",
		"技能2概率",
		"声望概率",
		"声望id",
	};
	vector<string> nameList = {
		"id",
		"name",
		"skill#id",
		"skill#rate",
		"skill#id",
		"skill#rate",
		"repu#rate",
		"repu#id",
	};
	vector<string> typeList = {
		"INT",
		"STRING",
		"ST_ARRAY#INT$1",
		"ST_ARRAY#INT$1",
		"ST_ARRAY#INT$2",
		"ST_ARRAY#INT$2",
		"ST#FLOAT",
		"ST#INT",
	};
	vector<string> dataList = {
		"1",
		"2",
		"3",
		"4",
		"5",
		"6",
		"7.234",
		"8",
	};

	excel_table excel_table;
	ifstream inputFile("test.dat", ios::in | ios::binary);
	if (inputFile) {
		excel_table.ParseFromIstream(&inputFile);
		cout << "proto_msg_name=" << excel_table.proto_msg_name() << endl;
		for (auto& it : excel_table.table()) {
			for (auto& cell : it.second.cell_data()) {
				cout << "int=" << cell.int32_value() << ",string=" << cell.float_value() << endl;
			}
		}
	}
	inputFile.close();

	MessageStubManager::GetInstance()->Init();
	ParseManager::GetInstance().BeginParse("test.proto");
	ParseManager::GetInstance().BeginMessage("test", nameList, typeList, descList);
	ParseManager::GetInstance().AddLineData(1, dataList);
	ParseManager::GetInstance().EndMessage();

	system("PAUSE");
	return 0;
}
