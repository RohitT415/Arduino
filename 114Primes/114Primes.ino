#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_KBV.h> //Hardware-specific library

LCDWIKI_KBV mylcd(ILI9486,A3,A2,A1,A0,A4);

//define some colour values
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

void setup() {
Serial.begin(9600);
mylcd.Init_LCD();
Serial.println(mylcd.Read_ID(), HEX);
mylcd.Fill_Screen(BLACK);

  for(long i = 3;i <= 619;i += 2) //the loop goes until 619 because 619 is the 144th prime number.
  {
    long y = 0;
    int x = sqrt(i);    
    for(long j = 3;j <= x;j += 2)    
    {
      if((i % j) < 1)       
      {
        y = 1;                 
        j = x;          
      }                    
    }
    if(y < 1)           
    {
      String message = String(i);
      mylcd.Set_Text_colour(WHITE);
      mylcd.Set_Text_Size(3);
      mylcd.Print_String(message, 0, 0);
      delay(1000);    
      mylcd.Fill_Screen(BLACK);
    } 
  }
}
void loop() {

}
