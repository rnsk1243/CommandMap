#include "CommandMap.h"


void CCommandMap::Start()
{
	cout << "Start 함수 포인터 호출" << endl;
}

void CCommandMap::Join()
{
	cout << "Join 함수 포인터 호출" << endl;
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
		cout << "함수가 없습니다." << endl;
	}
}