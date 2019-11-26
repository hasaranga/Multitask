
// Multitasking Library for Arduino
// (c) 2013 - 2019 CrownSoft
// http://www.crownsoft.net


#ifndef _MULTITASK_H_
#define _MULTITASK_H_

#include <Arduino.h>

class EventDelay
{
private:
	unsigned long startTime;
	unsigned long interval;    
public:

	EventDelay()
	{
		startTime = 0;
		interval = 0;   
	}

	/* 
		time - in milliseconds
		countFromHere - set to true to ignore the time consumed by the body of HandleEvent method
	*/
	void SetNextEventDelay(int time, bool countFromHere = false)
	{
		interval = time;
		if(countFromHere)
			startTime = millis();
	}

	bool IsDelayExpired()
	{
		// millis rollover-safe code
		if ( (millis() - startTime) >= interval )
		{
			startTime = millis();
			return true;
		}
		return false;   
	}
};

class Application
{
public:
	void Setup(){}
	void HandleEvent(){}
	bool CheckEvent(){return true;}
};

#define MAKE_INSTANCE1(x1) x1 _##x1;
#define MAKE_INSTANCE2(x1,x2) x1 _##x1;x2 _##x2;
#define MAKE_INSTANCE3(x1,x2,x3) x1 _##x1;x2 _##x2;x3 _##x3;
#define MAKE_INSTANCE4(x1,x2,x3,x4) x1 _##x1;x2 _##x2;x3 _##x3;x4 _##x4;
#define MAKE_INSTANCE5(x1,x2,x3,x4,x5) x1 _##x1;x2 _##x2;x3 _##x3;x4 _##x4;x5 _##x5;
#define MAKE_INSTANCE6(x1,x2,x3,x4,x5,x6) x1 _##x1;x2 _##x2;x3 _##x3;x4 _##x4;x5 _##x5;x6 _##x6;

#define SETUP_HANDLER1(x1) void setup(){_##x1.Setup();}
#define SETUP_HANDLER2(x1,x2) void setup(){_##x1.Setup();_##x2.Setup();}
#define SETUP_HANDLER3(x1,x2,x3) void setup(){_##x1.Setup();_##x2.Setup();_##x3.Setup();}
#define SETUP_HANDLER4(x1,x2,x3,x4) void setup(){_##x1.Setup();_##x2.Setup();_##x3.Setup();_##x4.Setup();}
#define SETUP_HANDLER5(x1,x2,x3,x4,x5) void setup(){_##x1.Setup();_##x2.Setup();_##x3.Setup();_##x4.Setup();_##x5.Setup();}
#define SETUP_HANDLER6(x1,x2,x3,x4,x5,x6) void setup(){_##x1.Setup();_##x2.Setup();_##x3.Setup();_##x4.Setup();_##x5.Setup();_##x6.Setup();}

#define CHECK_EVENTS1(x1) void loop(){ if(_##x1.CheckEvent()) _##x1.HandleEvent();}
#define CHECK_EVENTS2(x1,x2) void loop(){ if(_##x1.CheckEvent()) _##x1.HandleEvent();if(_##x2.CheckEvent()) _##x2.HandleEvent();}
#define CHECK_EVENTS3(x1,x2,x3) void loop(){ if(_##x1.CheckEvent()) _##x1.HandleEvent();if(_##x2.CheckEvent()) _##x2.HandleEvent();if(_##x3.CheckEvent()) _##x3.HandleEvent();}
#define CHECK_EVENTS4(x1,x2,x3,x4) void loop(){ if(_##x1.CheckEvent()) _##x1.HandleEvent();if(_##x2.CheckEvent()) _##x2.HandleEvent();if(_##x3.CheckEvent()) _##x3.HandleEvent();if(_##x4.CheckEvent()) _##x4.HandleEvent();}
#define CHECK_EVENTS5(x1,x2,x3,x4,x5) void loop(){ if(_##x1.CheckEvent()) _##x1.HandleEvent();if(_##x2.CheckEvent()) _##x2.HandleEvent();if(_##x3.CheckEvent()) _##x3.HandleEvent();if(_##x4.CheckEvent()) _##x4.HandleEvent();if(_##x5.CheckEvent()) _##x5.HandleEvent();}
#define CHECK_EVENTS6(x1,x2,x3,x4,x5,x6) void loop(){ if(_##x1.CheckEvent()) _##x1.HandleEvent();if(_##x2.CheckEvent()) _##x2.HandleEvent();if(_##x3.CheckEvent()) _##x3.HandleEvent();if(_##x4.CheckEvent()) _##x4.HandleEvent();if(_##x5.CheckEvent()) _##x5.HandleEvent();if(_##x6.CheckEvent()) _##x6.HandleEvent();}

#define LOAD_APPLICATIONS_1(x1) MAKE_INSTANCE1(x1) SETUP_HANDLER1(x1) CHECK_EVENTS1(x1)
#define LOAD_APPLICATIONS_2(x1,x2) MAKE_INSTANCE2(x1,x2) SETUP_HANDLER2(x1,x2) CHECK_EVENTS2(x1,x2)
#define LOAD_APPLICATIONS_3(x1,x2,x3) MAKE_INSTANCE3(x1,x2,x3) SETUP_HANDLER3(x1,x2,x3) CHECK_EVENTS3(x1,x2,x3)
#define LOAD_APPLICATIONS_4(x1,x2,x3,x4) MAKE_INSTANCE4(x1,x2,x3,x4) SETUP_HANDLER4(x1,x2,x3,x4) CHECK_EVENTS4(x1,x2,x3,x4)
#define LOAD_APPLICATIONS_5(x1,x2,x3,x4,x5) MAKE_INSTANCE5(x1,x2,x3,x4,x5) SETUP_HANDLER5(x1,x2,x3,x4,x5) CHECK_EVENTS5(x1,x2,x3,x4,x5)
#define LOAD_APPLICATIONS_6(x1,x2,x3,x4,x5,x6) MAKE_INSTANCE6(x1,x2,x3,x4,x5,x6) SETUP_HANDLER6(x1,x2,x3,x4,x5,x6) CHECK_EVENTS6(x1,x2,x3,x4,x5,x6)

#endif