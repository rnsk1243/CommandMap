#pragma once
#include<WinSock2.h>
#include<mutex>
#include<iostream>
using namespace std;

class MUTEX
{
private:
	mutex mMutex;
public:
	MUTEX(){}
	~MUTEX(){}
	void lock()
	{
		mMutex.lock();
	}
	void unLock()
	{
		mMutex.unlock();
	}
};

class CRITICALSECTION
{
private:
	CRITICAL_SECTION mCS;
public:
	CRITICALSECTION()
	{
		InitializeCriticalSection(&mCS);
	}
	~CRITICALSECTION()
	{
		DeleteCriticalSection(&mCS);
	}
	void lock()
	{
		EnterCriticalSection(&mCS);
	}
	void unLock()
	{
		LeaveCriticalSection(&mCS);
	}
};

template<typename T> class ScopeLock
{
	T& obj;
public:
	ScopeLock(T* o) : obj(o)
	{
		obj.lock();
	}
	ScopeLock(T& o) : obj(o)
	{
		obj.lock();
	}
	~ScopeLock()
	{
		obj.unLock();
	}
};