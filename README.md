Multitask
=========

Multitasking library for arduino

here is an example:

//======================================================================

#include<Multitask.h>

class BlinkApplication : public Application, public EventDelay
{
  const static int LED_PIN=13;
  bool led_status;
  
  public:
    void Setup()
    {
      pinMode(LED_PIN, OUTPUT); 
      led_status=false;  
    }
    
    void HandleEvent() // use non blocking functions in here
    {
      led_status=!led_status;
      digitalWrite(LED_PIN,led_status);
      SetNextEventDelay(1000); // use this instead of delay(1000)
    }
    
    bool CheckEvent() // use non blocking functions in here
    {
      return IsDelayExpired();
    }
};


class SerialEchoApplication : public Application
{ 
  public:
    void Setup()
    {
      Serial.begin(9600);  
    }
    
    void HandleEvent()
    {
      char inChar = (char)Serial.read(); 
      Serial.print(inChar);
    }
    
    bool CheckEvent()
    {
      return Serial.available();
    }
};


class BlinkApplication2 : public Application, public EventDelay
{
  const static int LED_PIN=6;
  int nextEventID;
  
  public:
    void Setup()
    {
      pinMode(LED_PIN, OUTPUT); 
      nextEventID=0;  
    }
    
    void HandleEvent()
    {
      if(nextEventID==0)
      {
        digitalWrite(LED_PIN, HIGH);
        SetNextEventDelay(200);
        nextEventID=1;
      }else
      {
        digitalWrite(LED_PIN, LOW);
        SetNextEventDelay(800);
        nextEventID=0;      
      }
    }
    
    bool CheckEvent()
    {
      return IsDelayExpired();
    }
};

LOAD_APPLICATIONS_3(BlinkApplication,SerialEchoApplication,BlinkApplication2)

