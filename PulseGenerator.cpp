
#include <EEPROM.h>

const int D2_Mask = (2 << 0);
#define PUL_SetOut DDRD |= D2_Mask      // Устанавливаем пин D2 в режим OUTPUT
#define PUL_SetIn DDRD &= ~D2_Mask      // Устанавливаем пин D2 в режим INPUT
#define PUL_HIGH PORTD |= D2_Mask       // Устанавливаем бит отвечающий за пин D2 в HIGH, остальные пины не трогаем
#define PUL_LOW PORTD &= ~D2_Mask       // Устанавливаем бит отвечающий за пин D2 в LOW, остальные пины не трогаем
#define PUL_dRead PIND >> 2 & (1 << 0)  // Считываем бит отвечающий за пин D2, возвращает 0 или 1

const int  D3_Mask = (3 << 0);
#define DIR_SetOut DDRD |= D3_Mask      // Устанавливаем пин D3 в режим OUTPUT
#define DIR_SetIn DDRD &= ~D3_Mask      // Устанавливаем пин D3 в режим INPUT
#define DIR_HIGH PORTD |= D3_Mask       // Устанавливаем бит отвечающий за пин D3 в HIGH, остальные пины не трогаем
#define DIR_LOW PORTD &= ~D3_Mask       // Устанавливаем бит отвечающий за пин D3 в LOW, остальные пины не трогаем
#define DIR_dRead PIND >> 3 & (1 << 0)  // Считываем бит отвечающий за пин D3, возвращает 0 или 1

const int  D4_Mask = (4 << 0);
#define ENA_SetOut DDRD |= D4_Mask      // Устанавливаем пин D4 в режим OUTPUT
#define ENA_SetIn DDRD &= ~D4_Mask      // Устанавливаем пин D4 в режим INPUT
#define ENA_HIGH PORTD |= D4_Mask       // Устанавливаем бит отвечающий за пин D4 в HIGH, остальные пины не трогаем
#define ENA_LOW PORTD &= ~D4_Mask       // Устанавливаем бит отвечающий за пин D4 в LOW, остальные пины не трогаем
#define ENA_dRead PIND >> 4 & (1 << 0)  // Считываем бит отвечающий за пин D4, возвращает 0 или 1

const int  D5_Mask = (6 << 0);
#define In1_SetOut DDRC |= D5_Mask      // Устанавливаем пин D5 в режим OUTPUT
#define In1_SetIn DDRC &= ~D5_Mask      // Устанавливаем пин D5 в режим INPUT
#define In1_HIGH PORTC |= D5_Mask       // Устанавливаем бит отвечающий за пин D5 в HIGH, остальные пины не трогаем
#define In1_LOW PORTC &= ~D5_Mask       // Устанавливаем бит отвечающий за пин D5 в LOW, остальные пины не трогаем
#define In1_dRead PINC >> 6 & (1 << 0)  // Считываем бит отвечающий за пин D5, возвращает 0 или 1

const int  D6_Mask = (7 << 0);
#define upButton_SetOut DDRD |= D6_Mask      // Устанавливаем пин D6 в режим OUTPUT
#define upButton_SetIn DDRD &= ~D6_Mask      // Устанавливаем пин D6 в режим INPUT
#define upButton_HIGH PORTD |= D6_Mask       // Устанавливаем бит отвечающий за пин D6 в HIGH, остальные пины не трогаем
#define upButton_LOW PORTD &= ~D6_Mask       // Устанавливаем бит отвечающий за пин D6 в LOW, остальные пины не трогаем
#define upButton_dRead PIND >> 7 & (1 << 0)  // Считываем бит отвечающий за пин D6, возвращает 0 или 1

const int  D7_Mask = (6 << 0);
#define downButton_SetOut DDRE |= D7_Mask      // Устанавливаем пин D7 в режим OUTPUT
#define downButton_SetIn DDRE &= ~D7_Mask      // Устанавливаем пин D7 в режим INPUT
#define downButton_HIGH PORTE |= D7_Mask       // Устанавливаем бит отвечающий за пин D7 в HIGH, остальные пины не трогаем
#define downButton_LOW PORTE &= ~D7_Mask       // Устанавливаем бит отвечающий за пин D7 в LOW, остальные пины не трогаем
#define downButton_dRead PINE >> 6 & (1 << 0)  // Считываем бит отвечающий за пин D7, возвращает 0 или 1

const int  D8_Mask = (4 << 0);
#define sepButton_SetOut DDRB |= D8_Mask      // Устанавливаем пин D8 в режим OUTPUT
#define sepButton_SetIn DDRB &= ~D8_Mask      // Устанавливаем пин D8 в режим INPUT
#define sepButton_HIGH PORTB |= D8_Mask       // Устанавливаем бит отвечающий за пин D8 в HIGH, остальные пины не трогаем
#define sepButton_LOW PORTB &= ~D8_Mask       // Устанавливаем бит отвечающий за пин D8 в LOW, остальные пины не трогаем
#define sepButton_dRead PINB >> 4 & (1 << 0)  // Считываем бит отвечающий за пин D8, возвращает 0 или 1

const int  D9_Mask = (5 << 0);
#define modButton_SetOut DDRB |= D9_Mask      // Устанавливаем пин D9 в режим OUTPUT
#define modButton_SetIn DDRB &= ~D9_Mask      // Устанавливаем пин D9 в режим INPUT
#define modButton_HIGH PORTB |= D9_Mask       // Устанавливаем бит отвечающий за пин D9 в HIGH, остальные пины не трогаем
#define modButton_LOW PORTB &= ~D9_Mask       // Устанавливаем бит отвечающий за пин D9 в LOW, остальные пины не трогаем
#define modButton_dRead PINB >> 5 & (1 << 0)  // Считываем бит отвечающий за пин D9, возвращает 0 или 1

const float minDelayMs = 1.0;    //delayMicroseconds(1.0) ;
const float maxSpdMotor = 3000;  //rpm
int spd = 1;
long steps = 150000;
bool Position = 0;

void setup() {
  Serial.begin(9600);
  PUL_SetOut;
  DIR_SetOut;
  In1_SetIn;
  upButton_dRead;
  downButton_dRead;
  sepButton_dRead;
  modButton_dRead;

  //float dataF = 3.14;
  //EEPROM.put(0, dataF);
  //EEPROM.get(0, dataF_read);
}

void loop() {

  //Serial.println(In1_dRead);

  if (upButton_dRead == 1) {
    if ((spd - 1) >= minDelayMs) {
      --spd;
    }
  }
  Serial.println(spd);

  if (In1_dRead == 1) {
    if (Position == 0) {
      motorGo();
      Position = 1;
    }

  } else {
    if (Position == 1) {
      motorBack();
      Position = 0;
    }
  }
}

//Выполняет заданое количество шагов
void motorGo() {
    DIR_HIGH;
    delayMicroseconds(spd);
  for (long i = 0;i<steps;i++ ){
      PUL_HIGH; 
      delayMicroseconds(spd);
      PUL_LOW; 
      delayMicroseconds(spd);
    } 
  }
  
//Возврат в исходное состояние 
//Исходное состояние определяеться датчиком????
  void motorBack(){
    DIR_LOW;
    delayMicroseconds(spd);
   for (long i = 0;i<steps;i++ ){
      PUL_HIGH; 
      delayMicroseconds(spd);
      PUL_LOW; 
      delayMicroseconds(spd);
    } 
  }
