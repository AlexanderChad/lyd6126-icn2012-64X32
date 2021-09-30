#define R1_LED 2
#define G1_LED 3
#define B1_LED 4
#define R2_LED 5
#define G2_LED 6
#define B2_LED 7

#define A_Line 14
#define B_Line 15
#define C_Line 16

#define CLK_LED 8
#define OE_LED 9
#define LAT_LED 10


uint16_t TOnLP;
uint8_t RAW_DISPLAY[3][256] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 248, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 152, 0, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 248, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 152, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 32, 113, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56, 112, 17, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 124, 80, 113, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56, 112, 17, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 80, 119, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 32, 113, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56, 112, 17, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 124, 80, 113, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56, 112, 17, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 80, 119, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 113, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 112, 17, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 80, 113, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 112, 17, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 80, 119, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
                              };

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
    Red_p = 1uL << Xp;
  }
  if (Color3 & 0b10) {
    Green_p = 1uL << Xp;
  }
  if (Color3 & 0b1) {
    Blue_p = 1uL << Xp;
  }
  if (!(RAW_DISPLAY[0][Yp] & Red_p)) {
    if (Red_p) {
      RAW_DISPLAY[0][Yp] |= Red_p;
    }
    else {
      RAW_DISPLAY[0][Yp] &= ~(1uL << Xp);
    }
  }
  if (!(RAW_DISPLAY[1][Yp] & Green_p)) {
    if (Green_p) {
      RAW_DISPLAY[1][Yp] |= Green_p;
    }
    else {
      RAW_DISPLAY[1][Yp] &= ~(1uL << Xp);
    }
  }
  if (!(RAW_DISPLAY[2][Yp] & Blue_p)) {
    if (Blue_p) {
      RAW_DISPLAY[2][Yp] |= Blue_p;
    }
    else {
      RAW_DISPLAY[2][Yp] &= ~(1uL << Xp);
    }
  }
}

void setup() {
  //Serial.begin(2000000);
  //Serial.println("Started");

  DDRD = 0xFF;
  DDRC = 0xFF;
  DDRB = 0xFF;

  SetBrightness(5); //0-65535

  SetPixel(15, 15, 0);
  SetPixel(16, 16, 1);
  SetPixel(17, 17, 2);
  SetPixel(18, 18, 3);
  SetPixel(19, 19, 4);
  SetPixel(20, 20, 5);
  SetPixel(21, 21, 6);
  SetPixel(22, 22, 7);

}

void loop() {
  LoadAndShowBufOnPanel();

}

void SetBrightness(uint16_t Panel_Brightness) {
  TOnLP = Panel_Brightness;
}

void LoadAndShowBufOnPanel() {
  uint8_t i_m;
  uint8_t bit_mask;
  for (uint8_t y_b = 0; y_b < 8; y_b++) {
    digitalWrite(OE_LED, 1);
    digitalWrite(LAT_LED, 0);
    for (uint8_t x_b = 0; x_b < 128; x_b++) {
      bit_mask = 1UL << (x_b % 8);
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
    digitalWrite(A_Line, y_b & 0b1);
    digitalWrite(B_Line, y_b & 0b10);
    digitalWrite(C_Line, y_b & 0b100);
    digitalWrite(OE_LED, 0);
    delayMicroseconds(TOnLP);
  }
}
