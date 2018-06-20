#include "Keyboard.h"

void setup() {
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  pinMode(5,INPUT_PULLUP);
  pinMode(6,INPUT_PULLUP);
  pinMode(7,INPUT_PULLUP);
  pinMode(8,INPUT_PULLUP);
  pinMode(10,INPUT_PULLUP);
  pinMode(16,INPUT_PULLUP);
  //pinMode(3,OUTPUT);
  Serial.begin(9600);
}

boolean grabar = false;

void loop() {

  /*
   * Boton 1
   */
  if(digitalRead(4) == LOW) {
    Keyboard.begin();
    Keyboard.println("Boton 1");
    Keyboard.println("");
    Keyboard.releaseAll();
    delay(500);
  }

  /*
   * Boton 2
   */
  if(digitalRead(2) == LOW) {
    Keyboard.begin();
    Keyboard.println("Boton 2");
    Keyboard.println("");
    Keyboard.releaseAll();
    delay(500);
  }
  
  /*
   * Boton 3
   */
  if(digitalRead(5) == LOW) {
    Keyboard.begin();
    Keyboard.println("Boton 3");
    Keyboard.println("");
    Keyboard.releaseAll();
    delay(500);
  }  

 
  /*
   * Boton 4
   */
  if(digitalRead(3) == LOW) {
    Keyboard.begin();
    Keyboard.println("Boton 4");
    Keyboard.println("");
    Keyboard.releaseAll();
    delay(500);
  }


  /*
   * Boton 9
   */
  if(digitalRead(16) == LOW) {
    Keyboard.begin();
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('r');
    Keyboard.releaseAll();
    delay(200);
    Keyboard.println("notepad");
    Keyboard.println("");
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    /*
    key_press(KEY_RETURN)
delay(30)
key_release(KEY_RETURN)
*/
  }

  /*
   * Boton 10
   */
  if(digitalRead(10) == LOW) {
    accionGrabar();
  }  
}


boolean grabando = false;

void accionGrabar() {
  if(grabando) {
    accion('d');
    grabando = false;
  } else {
    accion('g');
    grabando = true;
  }
}

void accion(char accion) {
  Keyboard.begin();
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(accion);
  delay(100);
  Keyboard.releaseAll();
  // wait for new window to open:
  delay(1000);
  //Keyboard.close();  
}

