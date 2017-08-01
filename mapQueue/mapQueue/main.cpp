#include<iostream>
#include<thread>
#include<vector>
#include<memory>
#include"CommandMap.h"
#include"MessageQueue.h"
using namespace std;
const int ThreadAmount = 5;
const int ThreadSleepMilliseconds = 1000;

struct threadPara
{
	CCommandMap* pCM;
	CMessageQueue* pMQ;
	threadPara(CCommandMap* cm, CMessageQueue* mq):pCM(cm),pMQ(mq)
	{
	}
};

void CommandHandlingFunc(threadPara& para)
{
	CCommandMap* commandMap = para.pCM;
	CMessageQueue* messageQueue = para.pMQ;
	while (true)
	{
		if (false == messageQueue->IsEmpty())
		{
			commandMap->Call(string(messageQueue->PopMessage()));
		}
		this_thread::sleep_for(chrono::milliseconds(ThreadSleepMilliseconds));
	}
}

typedef vector<shared_ptr<thread>> thVector;

void main()
{
	CCommandMap CMap;
	//CM.Call(string("Join"));
	CMessageQueue MQueue;
	threadPara thPara(&CMap, &MQueue);

	thVector threadVec;
	threadVec.reserve(ThreadAmount); 
	
	for (int i = 0; i < ThreadAmount; ++i)
	{
		thread* newThread = new thread(&CommandHandlingFunc, thPara);
		//newThread->join(); // join()하면 main스레드 멈춤
		shared_ptr<thread> sharedThread(newThread);
		threadVec.push_back(sharedThread);
	}
	cout << "thread 생성 완료" << endl;
	
	while (true)
	{
		string message;
		cin >> message;
		MQueue.PushMessage(message);
	}
}