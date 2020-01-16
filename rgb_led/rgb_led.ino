const int RED_LED = 3;
const int GREEN_LED = 5;
const int BLUE_LED = 6;

int loopCounter = 0; 
uint32_t colors [] = {
    0xFF9900, // Yellow
    0x6A0DAD, // Purple
    0x33FFFF, // Cyan
    0xFF5000, // Orange
    0xE5CCFF  // Lavender
  };
int colorCount = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int r = 0; r < 256; r++) {
    writeColor((uint32_t)r << 16 | 0x00FF00);
    delay(50);  
  }
  
  for (int g = 255; g > 0; g--) {
    writeColor(0xFF0000 | (g << 8));
    delay(50);
  }

  for (int flash = 0; flash < 25; flash++) {
    if (flash % 2 == 0) {
      writeColor(0x000000);
    } else {
      writeColor(0xFF0000);
    }
    delay(200);
  }
//  writeColor(colors[loopCounter]);
//  loopCounter = (loopCounter + 1) % colorCount;
  
//  delay(5000);  
}

void writeColor(uint32_t color) {
    int red = (color >> 16) & 0xFF;
    int green = (color >> 8) & 0xFF;
    int blue = color & 0xFF;

//    Serial.print(red);
//    Serial.print(", ");
//    Serial.println(green);
//    Serial.print(", ");
//    Serial.println(blue);
    
    analogWrite(RED_LED, red);
    analogWrite(GREEN_LED, green);
    analogWrite(BLUE_LED, blue);
}
