#include "includes.h"
#include "Floor_INIT.h"
#include "Motor_INIT.h"
#include "Delay_time.h"
#include "Door_INIT.h"
#include "Key_INIT.h"
#include "Usart.h"

void main()
{
	DOOR_INIT();
	Usart_Init();
	send_string_uart("系统已启动！\r\n");
	while(1)
	{
		Key_INIT();
		Floor_Init();
		Motor_INIT();			
	}
}