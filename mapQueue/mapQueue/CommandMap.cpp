#include "CommandMap.h"


void CCommandMap::Start()
{
	cout << "Start �Լ� ������ ȣ��" << endl;
}

void CCommandMap::Join()
{
	cout << "Join �Լ� ������ ȣ��" << endl;
}

CCommandMap::CCommandMap()
{
	mMapFunc.insert(make_pair("Start", &CCommandMap::Start));
	mMapFunc.insert(make_pair("Join", &CCommandMap::Join));
}


CCommandMap::~CCommandMap()
{
}

void CCommandMap::Call(const string& funcName)
{
	MAP_FUNC::iterator iterBegin = mMapFunc.begin();
	iterBegin = mMapFunc.find(funcName);
	if (iterBegin != mMapFunc.end())
	{
		//cout << &((*iterBegin).second) << endl;
		pf p((*iterBegin).second);
		(this->*p)();
	}
	else
	{
		cout << "�Լ��� �����ϴ�." << endl;
	}
}