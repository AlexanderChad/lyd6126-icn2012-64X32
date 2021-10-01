#include "stm8s.h"

#define R1_LED 'A', 1 //Pin A1
#define G1_LED 'A', 2
#define B1_LED 'A', 3
#define R2_LED 'C', 3 //Pin C3
#define G2_LED 'C', 4
#define B2_LED 'C', 6
#define A_Line 'C', 5
#define B_Line 'C', 7
#define C_Line 'B', 4

#define CLK_LED 'D', 3 //Pin D3
#define OE_LED 'D', 4
#define LAT_LED 'D', 2


uint16_t TOnLP;
@near uint8_t RAW_DISPLAY[3][256] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 248, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 152, 0, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 248, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 152, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 32, 113, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56, 112, 17, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 124, 80, 113, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56, 112, 17, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 80, 119, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 32, 113, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56, 112, 17, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 124, 80, 113, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56, 112, 17, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 80, 119, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 113, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 112, 17, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 80, 113, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 112, 17, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 80, 119, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void delay (int us) //create delay function
{
int i =0 ;
int j=0;
for (i=0; i<=us; i++)
{
for (j=0; j<16; j++)
_asm("nop"); //Perform no operation //assembly code
}
}

void digitalWrite(char Port, uint8_t NumP, bool stat) {
switch (Port) {
case 'A':
if(stat){
GPIOA->ODR |= 1 << NumP;
}else{
GPIOA->ODR &= ~(1 << NumP);
}
  break;
case 'B':
if(stat){
GPIOB->ODR |= 1 << NumP;
}else{
GPIOB->ODR &= ~(1 << NumP);
}
  break;
case 'C':
if(stat){
GPIOC->ODR |= 1 << NumP;
}else{
GPIOC->ODR &= ~(1 << NumP);
}
  break;
case 'D':
if(stat){
GPIOD->ODR |= 1 << NumP;
}else{
GPIOD->ODR &= ~(1 << NumP);
}
  break;
}
}

void SetBrightness(uint16_t Panel_Brightness) {
  TOnLP = Panel_Brightness;
}

void LoadAndShowBufOnPanel(void) {
  uint8_t i_m;
  uint8_t bit_mask;
	uint8_t y_b;
	uint8_t x_b;
  for (y_b = 0; y_b < 8; y_b++) {
    digitalWrite(OE_LED, 1);
    digitalWrite(LAT_LED, 0);
    for (x_b = 0; x_b < 128; x_b++) {
      bit_mask = 1 << (x_b % 8);
      i_m = (y_b * 16) + (x_b / 8);
      digitalWrite(CLK_LED, 0);
      digitalWrite(R1_LED, RAW_DISPLAY[0][i_m] & bit_mask);
      digitalWrite(G1_LED, RAW_DISPLAY[1][i_m] & bit_mask);
      digitalWrite(B1_LED, RAW_DISPLAY[2][i_m] & bit_mask);
      i_m += 128;
      digitalWrite(R2_LED, RAW_DISPLAY[0][i_m] & bit_mask);
      digitalWrite(G2_LED, RAW_DISPLAY[1][i_m] & bit_mask);
      digitalWrite(B2_LED, RAW_DISPLAY[2][i_m] & bit_mask);
      digitalWrite(CLK_LED, 1);
      if (x_b == 125) {
        digitalWrite(LAT_LED, 1);
      }
    }
    digitalWrite(A_Line, (y_b & 0b1)>0);
    digitalWrite(B_Line, (y_b & 0b10)>0);
    digitalWrite(C_Line, (y_b & 0b100)>0);
    digitalWrite(OE_LED, 0);
    delay(TOnLP);
  }
}

void SetPixel(uint8_t Xp, uint8_t Yp, uint8_t Color3) {
  uint8_t adr[] = {8, 24, 40, 56, 72, 88, 104, 120, 0, 16, 32, 48, 64, 80, 96, 112};
  uint32_t Red_p = 0;
  uint32_t Green_p = 0;
  uint32_t Blue_p = 0;
  if (Yp < 16) {
    Yp = adr[Yp] + (Xp / 8);
  } else {
    Yp = adr[Yp - 16] + (Xp / 8) + 128;
  }
  Xp %= 8;
  if (Color3 & 0b100) {
    Red_p = 1 << Xp;
  }
  if (Color3 & 0b10) {
    Green_p = 1 << Xp;
  }
  if (Color3 & 0b1) {
    Blue_p = 1 << Xp;
  }
  if (!(RAW_DISPLAY[0][Yp] & Red_p)) {
    if (Red_p) {
      RAW_DISPLAY[0][Yp] |= Red_p;
    }
    else {
      RAW_DISPLAY[0][Yp] &= ~(1 << Xp);
    }
  }
  if (!(RAW_DISPLAY[1][Yp] & Green_p)) {
    if (Green_p) {
      RAW_DISPLAY[1][Yp] |= Green_p;
    }
    else {
      RAW_DISPLAY[1][Yp] &= ~(1 << Xp);
    }
  }
  if (!(RAW_DISPLAY[2][Yp] & Blue_p)) {
    if (Blue_p) {
      RAW_DISPLAY[2][Yp] |= Blue_p;
    }
    else {
      RAW_DISPLAY[2][Yp] &= ~(1 << Xp);
    }
  }
}

void main(void)
{
	GPIOA->DDR |= (1 << 1)|(1 << 2)|(1 << 3); // pins as output
	GPIOB->DDR |= (1 << 4); // pins as output
	GPIOC->DDR |= (1 << 3)|(1 << 4)|(1 << 5)|(1 << 6)|(1 << 7);
	GPIOD->DDR |= (1 << 2)|(1 << 3)|(1 << 4);//|(1 << 5)|(1 << 6);
	GPIOA->CR1 |= (1 << 1)|(1 << 2)|(1 << 3); // pins as push-pull
	GPIOB->CR1 |= (1 << 4);
	GPIOC->CR1 |= (1 << 3)|(1 << 4)|(1 << 5)|(1 << 6)|(1 << 7);
	GPIOD->CR1 |= (1 << 2)|(1 << 3)|(1 << 4);//|(1 << 5)|(1 << 6);
	GPIOA->CR2 |= (1 << 1)|(1 << 2)|(1 << 3); // pins speed 10Mhz
	GPIOB->CR2 |= (1 << 4);
	GPIOC->CR2 |= (1 << 3)|(1 << 4)|(1 << 5)|(1 << 6)|(1 << 7);
	GPIOD->CR2 |= (1 << 2)|(1 << 3)|(1 << 4);//|(1 << 5)|(1 << 6);

    CLK_DeInit();
    CLK_SYSCLKConfig(CLK_PRESCALER_HSIDIV1); // set 16 MHz for CPU
		
		SetBrightness(10); //0-255
		
		SetPixel(10, 0, 6); //x=10, y=0, color=6=0b110-RGB: R+G=Yellow
		SetPixel(11, 1, 1);
		SetPixel(12, 2, 2);
		SetPixel(13, 3, 3);
		SetPixel(14, 4, 4);
		SetPixel(15, 5, 5);
		SetPixel(16, 6, 7);
		SetPixel(17, 7, 0);

  /* Infinite loop */
  while (1)
  {
		LoadAndShowBufOnPanel();
	}
}

#ifdef USE_FULL_ASSERT
void assert_failed(u8* file, u32 line)
{ 
  while (1){}
}
#endif

