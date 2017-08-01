#pragma once
#include<queue>
#include<string>
#include<iostream>
#include"RAII.h"
using namespace std;


class CMessageQueue
{
	typedef queue<string> StringQueue;
	StringQueue mMessageQueue;
	MUTEX mRAII_MESSAGEMUTEX;
public:
	CMessageQueue();
	~CMessageQueue();
	void PushMessage(const string& message);
	bool IsEmpty();
	string PopMessage();
};

