#include "MessageQueue.h"



CMessageQueue::CMessageQueue()
{
}


CMessageQueue::~CMessageQueue()
{
}

void CMessageQueue::PushMessage(const string& message)
{
	ScopeLock<MUTEX> MU(mRAII_MESSAGEMUTEX); // lock // PushMessage함수는 main스레드만 사용하는데도 락을 걸어야 할까요?
	mMessageQueue.push(message);
}

bool CMessageQueue::IsEmpty()
{
	return mMessageQueue.empty();
}

string CMessageQueue::PopMessage()
{
	ScopeLock<MUTEX> MU(mRAII_MESSAGEMUTEX); // lock
	if (true == mMessageQueue.empty())
	{
		//cout << "message 없음" << endl;
		return "message 없음";
	}
	else
	{
		// empty()함수 호출로 인해 컨테이너의 변경은 없을테니 여기서 lock을 걸었는데 빠르게 명령을 큐에 담으면 프로그램 죽음...
		string message(mMessageQueue.front());
		mMessageQueue.pop();
		return message;
	}
}
