#include "includes.h"
#include "Floor_INIT.h"
#include "Motor_INIT.h"
#include "Door_INIT.h"
#include "Key_INIT.h"
#include "Person_Check.h"
#include "Usart.h"

INT8U Stastu = 0;			 //KEY_IN电梯按键指示，Stastu 电梯所在楼层标志位
/******************
*******	函数名称： Floor_Init（）
*******	函数功能： 电梯驱动初始化函数
*******	返回值  ： NULL
******************/
void Floor_Init()
{
	Person_Check();
	if(UP_Flag == 0){		// person in 0f
		
		switch(Stastu)
		{
			case 0:        // IN 0f 
			 send_string_uart("**************8！\r\n");
			if(KEY_IN() == 0)			//go 0f
			{
				Stastu = 0;
				send_string_uart("您当前处于0层，请重新选择！\r\n");
			}else if(KEY_IN() == 1)	//go 1f 
			{			  
				DOOR_Open();		//open the door
				if(Check_Flag == 1)
				{
					DOOR_Close();  // close the door
					Motor_UP_INIT();
					send_string_uart("您已到达1层！\r\n");
					DOOR_Open();   // open the door
					Stastu = 1;
				}
			}else if(KEY_IN() == 2)	//go 2f
			{			  
				DOOR_Open();	//open the door
				if(Check_Flag == 1)
				{
					DOOR_Close();	// close the door
					Motor_UP_INIT();
					send_string_uart("您已到达2层！\r\n");
					DOOR_Open();	// open the door
					Stastu = 3;
				}
			}
			break;
			case 1:        // IN 1 floor 
			if(KEY_IN() == 0)			//go 0f
			{		  
				Motor_DOWN_INIT();
				DOOR_Open();		//open the door
				if(Check_Flag == 1)
				{
					DOOR_Close();  // close the door
					send_string_uart("您当前处于0层，请重新选择！\r\n");
					Stastu = 0;
				}
			}else if(KEY_IN() == 1)	//go 1f 
			{			  				
				Motor_DOWN_INIT();
				DOOR_Open();		//open the door
				if(Check_Flag == 1)
				{
					DOOR_Close();  // close the door
					Motor_UP_INIT();
					send_string_uart("您已到达1层！\r\n");
					DOOR_Open();   // open the door
					Stastu = 1;
				}
			}else if(KEY_IN() == 2)	//go 2f
			{			  				
				Motor_DOWN_INIT();
				DOOR_Open();	//open the door
				if(Check_Flag == 1)
				{
					DOOR_Close();	// close the door
					Motor_UP_INIT();
					send_string_uart("您已到达2层！\r\n");
					DOOR_Open();	// open the door
					Stastu = 2;
				}
			}
			break;
			case 2:        // IN 2 floor 
			if(KEY_IN() == 0)			//go 0f
			{			  
				Motor_DOWN_INIT();
				DOOR_Open();		//open the door
				if(Check_Flag == 1)
				{
					DOOR_Close();  // close the door
					send_string_uart("您当前处于0层，请重新选择！\r\n");
					Stastu = 0;
				}
			}else if(KEY_IN() == 1)	//go 1f 
			{			  				
				Motor_DOWN_INIT();
				DOOR_Open();		//open the door
				if(Check_Flag == 1)
				{
					DOOR_Close();  // close the door
					Motor_UP_INIT();
					send_string_uart("您已到达1层！\r\n");
					DOOR_Open();   // open the door
					Stastu = 1;
				}
			}else if(KEY_IN() == 2)	//go 2f
			{			  				
				Motor_DOWN_INIT();
				DOOR_Open();	//open the door
				if(Check_Flag == 1)
				{
					DOOR_Close();	// close the door
					Motor_UP_INIT();
					send_string_uart("您已到达2层！\r\n");
					DOOR_Open();	// open the door
					Stastu = 2;
				}
			}
			break;
			default:
			break;
	 	}
	}
	if((UP_Flag == 1) || (Down_Flag == 1)){		// person in 1F
		switch(Stastu)
		{
			case 0:        // floor IN 0F 
			if(KEY_IN() == 0)			//go 0f
			{			  			
				Motor_UP_INIT();
				DOOR_Open();		//open the door
				if(Check_Flag == 1)
				{
					DOOR_Close();  // close the door
					Motor_DOWN_INIT();
					send_string_uart("您已到达0层！\r\n");
					DOOR_Open();   // open the door
					Stastu = 1;
				}
			}else if(KEY_IN() == 1)	//go 1f 
			{			  
				Motor_UP_INIT();
				DOOR_Open();		//open the door
				if(Check_Flag == 1)
				{
					DOOR_Close();  // close the door
					send_string_uart("您当前处于1层，请重新选择！\r\n");
					Stastu = 1;
				}
			}else if(KEY_IN() == 2)	//go 2f
			{			  
				Motor_UP_INIT();
				DOOR_Open();	//open the door
				if(Check_Flag == 1)
				{
					DOOR_Close();	// close the door
					Motor_UP_INIT();
					send_string_uart("您已到达2层！\r\n");
					DOOR_Open();	// open the door
					Stastu = 3;
				}
			}
			break;
			case 1:        // floor IN 1F
			if(KEY_IN() == 0)			//go 0f
			{			  
				DOOR_Open();		//open the door
				if(Check_Flag == 1)
				{
					DOOR_Close();  // close the door
					Motor_DOWN_INIT();
					send_string_uart("您已到达0层！\r\n");
					Stastu = 0;
				}
			}else if(KEY_IN() == 1)	//go 1f 
			{			  		
				DOOR_Open();		//open the door
				if(Check_Flag == 1)
				{
					DOOR_Close();  // close the door
					send_string_uart("您当前处于1层，请重新选择！\r\n");
					Stastu = 1;
				}
			}else if(KEY_IN() == 2)	//go 2f
			{		  	
				DOOR_Open();	//open the door
				if(Check_Flag == 1)
				{
					DOOR_Close();	// close the door
					Motor_UP_INIT();
					send_string_uart("您已到达2层！\r\n");
					DOOR_Open();	// open the door
					Stastu = 2;
				}
			}
			break;
			case 2:        // floor IN 2F 
			if(KEY_IN() == 0)			//go 0f
			{			  
				Motor_DOWN_INIT();
				DOOR_Open();		//open the door
				if(Check_Flag == 1)
				{
					DOOR_Close();  // close the door
					Motor_DOWN_INIT();
					send_string_uart("您已到达0层！\r\n");
					Stastu = 0;
				}
			}else if(KEY_IN() == 1)	//go 1f 
			{			  				
				Motor_DOWN_INIT();
				DOOR_Open();		//open the door
				if(Check_Flag == 1)
				{
					DOOR_Close();  // close the door
					send_string_uart("您当前处于1层，请重新选择！\r\n");
					Stastu = 1;
				}
			}else if(KEY_IN() == 2)	//go 2f
			{			  				
				Motor_DOWN_INIT();
				DOOR_Open();	//open the door
				if(Check_Flag == 1)
				{
					DOOR_Close();	// close the door
					Motor_UP_INIT();
					send_string_uart("您已到达2层！\r\n");
					DOOR_Open();	// open the door
					Stastu = 2;
				}
			}
			 break;
			 default:
			 break;
	 	}
	}
	if(Down_Flag == 2){		// person in 2F
		switch(Stastu)
		{
			case 0:        // floor IN 0F 
			if(KEY_IN() == 0)			//go 0f
			{			  			
				Motor_UP_INIT();
				DOOR_Open();		//open the door
				if(Check_Flag == 1)
				{
					DOOR_Close();  // close the door
					Motor_DOWN_INIT();
					send_string_uart("您已到达0层！\r\n");
					DOOR_Open();   // open the door
					Stastu = 1;
				}
			}else if(KEY_IN() == 1)	//go 1f 
			{			  
				Motor_UP_INIT();
				DOOR_Open();		//open the door
				if(Check_Flag == 1)
				{
					DOOR_Close();  // close the door
					Motor_DOWN_INIT();
					send_string_uart("您已到达1层！\r\n");
					Stastu = 1;
				}
			}else if(KEY_IN() == 2)	//go 2f
			{			  
				Motor_UP_INIT();
				DOOR_Open();	//open the door
				if(Check_Flag == 1)
				{
					DOOR_Close();	// close the door
					send_string_uart("您当前处于2层，请重新选择！\r\n");
					Stastu = 2;
				}
			}
			break;
			case 1:        // floor IN 1F
			if(KEY_IN() == 0)			//go 0f
			{			  
				Motor_UP_INIT();
				DOOR_Open();		//open the door
				if(Check_Flag == 1)
				{
					DOOR_Close();  // close the door
					Motor_DOWN_INIT();
					send_string_uart("您已到达0层！\r\n");
					Stastu = 0;
				}
			}else if(KEY_IN() == 1)	//go 1f 
			{			  	
				Motor_UP_INIT();
				DOOR_Open();		//open the door
				if(Check_Flag == 1)
				{
					DOOR_Close();  // close the door
					Motor_DOWN_INIT();
					send_string_uart("您已到达1层！\r\n");
					Stastu = 1;
				}
			}else if(KEY_IN() == 2)	//go 2f
			{			  
				Motor_UP_INIT();
				DOOR_Open();	//open the door
				if(Check_Flag == 1)
				{
					DOOR_Close();	// close the door
					send_string_uart("您当前处于2层，请重新选择！\r\n");
					Stastu = 2;
				}
			}
			break;
			case 2:        // floor IN 2F 
			if(KEY_IN() == 0)			//go 0f
			{		  
				DOOR_Open();		//open the door
				if(Check_Flag == 1)
				{
					DOOR_Close();  // close the door
					Motor_DOWN_INIT();
					send_string_uart("您已到达0层！\r\n");
					Stastu = 0;
				}
			}else if(KEY_IN() == 1)	//go 1f 
			{		  		
				DOOR_Open();		//open the door
				if(Check_Flag == 1)
				{
					DOOR_Close();  // close the door
					Motor_DOWN_INIT();
					send_string_uart("您已到达1层！\r\n");
					Stastu = 1;
				}
			}else if(KEY_IN() == 2)	//go 2f
			{			  		
				DOOR_Open();	//open the door
				if(Check_Flag == 1)
				{
					DOOR_Close();	// close the door
					send_string_uart("您当前处于2层，请重新选择！\r\n");
					Stastu = 2;
				}
			}
			break;
			default:
			break;			
	 	}
	}
}

		
