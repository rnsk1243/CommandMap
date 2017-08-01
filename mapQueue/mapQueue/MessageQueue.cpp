#include "MessageQueue.h"



CMessageQueue::CMessageQueue()
{
}


CMessageQueue::~CMessageQueue()
{
}

void CMessageQueue::PushMessage(const string& message)
{
	ScopeLock<MUTEX> MU(mRAII_MESSAGEMUTEX); // lock // PushMessage�Լ��� main�����常 ����ϴµ��� ���� �ɾ�� �ұ��?
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
		//cout << "message ����" << endl;
		return "message ����";
	}
	else
	{
		// empty()�Լ� ȣ��� ���� �����̳��� ������ �����״� ���⼭ lock�� �ɾ��µ� ������ ����� ť�� ������ ���α׷� ����...
		string message(mMessageQueue.front());
		mMessageQueue.pop();
		return message;
	}
}
