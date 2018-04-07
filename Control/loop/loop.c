#include "loop.h"

static short cnt_200Hz,cnt_100Hz,cnt_50Hz,cnt_20Hz,cnt_10Hz;
int cnt_MS5837;

void loop_cnt(void)
{
	cnt_200Hz++;
	cnt_100Hz++;
	cnt_50Hz++;
	cnt_20Hz++;
	cnt_10Hz++;
	cnt_MS5837++;
}	

//���´������洢����
static void Loop_200Hz(void)
{
	Usart_SendString( NEO_USARTx, "200Hz");
}

//��̬�ڻ�����
static void Loop_100Hz(void)
{
	Inner_Loop();
}

//��̬�⻷����
static void Loop_50Hz(void)
{
	Outer_Loop();
}

//���˻����ݷ����Լ��Լ�
static void Loop_20Hz(void)
{
	Usart_SendString( NEO_USARTx, "20Hz\n");
}

static void Loop_10Hz(void)
{
	MS5837_Read_From_Part();
}

void ROV_Loop(void)
{
	if( cnt_200Hz >= 5 )
	{
		Loop_200Hz();
		cnt_200Hz = 0;
	}
	
	if( cnt_100Hz >= 10 )
	{
		Loop_100Hz();
		cnt_100Hz = 0;
	}
	
	if( cnt_50Hz >= 20 )
	{
		Loop_50Hz();
		cnt_50Hz = 0;
	}
	
	if( cnt_20Hz >= 50 )
	{
		Loop_20Hz();
		cnt_20Hz = 0;
	}
	
	if( cnt_10Hz >= 100 )
	{
		Loop_10Hz();
		cnt_10Hz = 0;
	}
}


void cnt_init(void)
{
	cnt_200Hz = 0;
	cnt_100Hz = 0;
	cnt_50Hz = 0;
	cnt_20Hz = 0;
	cnt_10Hz = 0;
	cnt_MS5837 = 0;
}

