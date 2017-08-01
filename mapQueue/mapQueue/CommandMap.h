#pragma once
#include<map>
#include<string>
#include<iostream>
using namespace std;

class CCommandMap
{
	typedef void(CCommandMap::*pf)();
	typedef map<string, pf> MAP_FUNC;

	MAP_FUNC mMapFunc;
	void Start();
	void Join();
public:
	CCommandMap();
	~CCommandMap();
	void Call(const string& funcName);
};

