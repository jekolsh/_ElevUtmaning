#include "LED.h" //Inkluderar header filen för att även denna fil skall känna till de olika LED-beteckningarna och funktioner

//Konstruktorn för LED-lamporna
void Led_ctor(Led_Type * const me, LedColor_Type _color, LedState_Type _state){

  me->color = _color;
  me->state = _state;
  
  //Enablea klockan för LED-porten (GPIOB)
  RCC->AHB1ENR |= LED_PORT_CLOCK;
  
  //Konfigurera LED-pinsen baserad på deras färg och status
  switch(_color){
  
    case RED: //Sätta portläget för LED-konfigurationen till output
      LED_PORT->MODER |= LED_RED_MODE_BIT;
      if(me->state == ON){
        //Stänga på LED
        LED_PORT->ODR |= LED_RED_PIN;
        printf("RED LED ON n\r\");
      }
      else{
        //Stänga av LED
        LED_PORT->ODR &= ~LED_RED_PIN;
        printf("RED LED OFF n\r\");
      }
      break;
     
      case YELLOW: //Sätta portläget för LED-konfigurationen till output
      LED_PORT->MODER |= LED_YELLOW_MODE_BIT;
      if(me->state == ON){
        //Stänga på LED
        LED_PORT->ODR |= LED_YELLOW_PIN;
        printf("YELLOW LED ON n\r\");
      }
      else{
        //Stänga av LED
        LED_PORT->ODR &= ~LED_YELLOW_PIN;
        printf("YELLOW LED OFF n\r\");
      }
      break;
         
      case BLUE: //Sätta portläget för LED-konfigurationen till output
      LED_PORT->MODER |= LED_BLUE_MODE_BIT;
      if(me->state == ON){
        //Stänga på LED
        LED_PORT->ODR |= LED_BLUE_PIN;
        printf("BLUE LED ON n\r\");
      }
      else{
        //Stänga av LED
        LED_PORT->ODR &= ~LED_BLUE_PIN;
        printf("BLUE LED OFF n\r\");
      }
      break;
               
      case GREEN: //Sätta portläget för LED-konfigurationen till output
      LED_PORT->MODER |= LED_GREEN_MODE_BIT;
      if(me->state == ON){
        //Stänga på LED
        LED_PORT->ODR |= LED_GREEN_PIN;
        printf("GREEN LED ON n\r\");
      }
      else{
        //Stänga av LED
        LED_PORT->ODR &= ~LED_GREEN_PIN;
        printf("GREEN LED OFF n\r\");
      }
      break;
  
  }
  
  
}
               
void Led_setState(Led_Type * const me, LedState_Type _state){

  //Sätta statusen av LED:n
  me->state = _state;
  
  //Kolla färgen på LED för att veta att korrekt LED manipuleras
  switch(me->color){
  
      //om LED Röd
    case RED:
      //sätta pin till outputläge
      LED_PORT->MODER |= LED_RED_MODE_BIT;
      //Om önskad status är ON
      if(me->state == ON){
        //Definerar pinensouput till aktiv
        LED_PORT->ODR |= LED_RED_PIN;
        printf("RED LED ON n\r\");
      }
      else{
        //Definerar pin output till inaktiv
        LED_PORT->ODR &= ~LED_RED_PIN;
        printf("RED LED OFF n\r\");
      }
      break;
            
      case YELLOW:
      //sätta pin till outputläge
      LED_PORT->MODER |= LED_YELLOW_MODE_BIT;
      //Om önskad status är ON
      if(me->state == ON){
        //Definerar pinensouput till aktiv
        LED_PORT->ODR |= LED_YELLOW_PIN;
        printf("YELLOW LED ON n\r\");
      }
      else{
        //Definerar pin output till inaktiv
        LED_PORT->ODR &= ~LED_YELLOW_PIN;
        printf("YELLOW LED OFF n\r\");
      }
      break;
               
      case BLUE:
      //sätta pin till outputläge
      LED_PORT->MODER |= LED_BLUE_MODE_BIT;
      //Om önskad status är ON
      if(me->state == ON){
        //Definerar pinensouput till aktiv
        LED_PORT->ODR |= LED_BLUE_PIN;
        printf("BLUE LED ON n\r\");
      }
      else{
        //Definerar pin output till inaktiv
        LED_PORT->ODR &= ~LED_BLUE_PIN;
        printf("BLUE LED OFF n\r\");
      }
      break;
               
      case GREEN:
      //sätta pin till outputläge
      LED_PORT->MODER |= LED_GREEN_MODE_BIT;
      //Om önskad status är ON
      if(me->state == ON){
        //Definerar pinensouput till aktiv
        LED_PORT->ODR |= LED_GREEN_PIN;
        printf("GREEN LED ON n\r\");
      }
      else{
        //Definerar pin output till inaktiv
        LED_PORT->ODR &= ~LED_GREEN_PIN;
        printf("GREEN LED OFF n\r\");
      }
      break;
  }

}

LedState_Type Led_getState(Led_Type * const me){

  //Kontrollera färgen av den LED som efterfrågas, printa sedan statusen
  switch(me->color){
  
    case RED:
      printf("RED LED %d n\r\",me->state);
      break;
             
    case YELLOW:
      printf("YELLOW LED %d n\r\",me->state);
      break;
             
    case BLUE:
      printf("BLUE LED %d n\r\",me->state);
      break;
             
    case GREEN:
      printf("GREEN LED %d n\r\",me->state);
      break;
  }
             //Returnerar LED-lampans status av vald färg
             return me->state;
}
