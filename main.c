#include<KF8A200GQS.h>
#include "includes.h"
#include "PinConfig.h"
#include "SoftSpi.h"
#include "Work.h"
#include "OSC.h"
#include "GPIO.h"
void main()
{
    Init_OSC(2); //将系统时钟初始化为32M、使用外部晶振，
    Init_GPIO();
    IS31FL3265B_Init();
    Stop_Timer_Init();
    Stop_Timer_Start();
    PUIE=1; //使能外设中断
    AIE=1; //总中断开启
    PwmDetect();
    Led_Hello_Check(SearchPwmFlag());
    while(1)
    {
    	PZ_Check_Input();
    	Tail_Stop_Check_Input();
		RT_Check_Input();
    }
}
//中断函数0:0X04入口地址
void int_fun0() __interrupt (0)
{
	if(T0IF & T0IE)		//500us定时
	{
		T0IF= 0;
		Hello_Bye_Callback();
	}
	if(T1IF & T1IE)
	{
		T1IF =0;
		STOP_PWM_Callback();
	}
	if(INT0IE && INT0IF) //INT1中断的响应
	{
		INT0IF=0;
		PwmFromInteruppt();
	}
}

//中断函数1:0x14入口地址
void int_fun1() __interrupt (1)
{

}

