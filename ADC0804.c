#include <REGX51.H>
#include <Thu_Vien_LCD.h>

#define CS P3_0
#define RD P3_1
#define WR P3_2
#define INTR P3_3
#define Data P2

int kq; 
unsigned char ADC_Read();

void delay(long time)
{
	time = time * 25;
	while(time--) {}
}

void main()
{
	LCD_Init();
	LCD_Gotoxy(1,1);
	LCD_Puts("Nguyen Duong K22-D");
	
	while(1)
	{
		kq = ADC_Read();
		kq = kq / 0.512; // suy ra do C doc duoc
		LCD_Gotoxy(1,2);
		LCD_PutNumber(kq);
	}
}

unsigned char ADC_Read()
{
	unsigned char ketqua;
	
	// chon chip
	CS = 0;
	
	// Tao xung (bat dau chuyen doi)
	WR = 0;
	WR = 1;
	
	// Doi cho den khi chuyen doi xong
	while(INTR);
	
	//Doc gia tri sau khi chuyen doi
	RD = 0;
	ketqua = Data;
	RD = 1;
	
	return ketqua;
}
