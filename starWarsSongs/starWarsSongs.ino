//declarando variaveis e recebendo os pinos onde os leds são conectado aos pinos 11, 12 e 13 da placa arduino
int ledPin11 = 11;
int ledPin12 = 12;
int ledPin13 = 13;
 
//buzzer conectado ao pino 10
int speakerPin = 10;

//definicões de notas e frequencias
#define c 261
#define d 294
#define e 329
#define f 349
#define g 392
#define gS 415
#define a 440
#define aS 455
#define b 466
#define cH 523
#define cSH 554
#define dH 587
#define dSH 622
#define eH 659
#define fH 698
#define fSH 740
#define gH 784
#define gSH 830
#define aH 880

//---- Prototipos das Funções Auxiliares ----
void march(char oitava);
void beep (unsigned char speakerPin, int frequencyInHertz, long timeInMilliseconds);

//setup de inicio rodar somente uma vez
void setup()
{
  //setando os pinos dos leds como saida
   pinMode(ledPin11, OUTPUT);
   pinMode(ledPin12, OUTPUT);
   pinMode(ledPin13, OUTPUT);
  
  //setando o pino do buzzer como saida
  pinMode(speakerPin, OUTPUT);
}
 
//loop infinito
void loop()
{
  //inicia os leds em sequencia
  digitalWrite(ledPin11, HIGH); //liga o led do pino 11 (HIGH = LIGADO OU NIVEL LÓGICO 1 OU 5v)
  delay(150); //fica ligado por 150 milissegundos
  digitalWrite(ledPin11, LOW); // desliga o led do pino 11 (LOW = DESLIGADO OU NIVEL LÓGICO 0 OU 0v)
  delay(150);

  digitalWrite(ledPin12, HIGH);
  delay(150);
  digitalWrite(ledPin12, LOW);
  delay(150);

  digitalWrite(ledPin13, HIGH);
  delay(150);
  digitalWrite(ledPin13, LOW);
  delay(150);

/*para mudança da oitava, quando oitava  march = 1 toca normal
 quando oitava march = 2 toca mais agudo, MUDA O TOM CONFORME A
 PASSADA EM QUE MARCH SE ENCONTRA*/
  march(1);
  march(2);
  march(4);  
} //end loop
 
void beep (unsigned char speakerPin, int frequencyInHertz, long timeInMilliseconds)
{
    //INICIANDO OS LEDS
    digitalWrite(ledPin11, HIGH);
    delay(10);
    digitalWrite(ledPin12, HIGH);
    delay(10);
    digitalWrite(ledPin13, HIGH);
    delay(10);
    
    int x;    
    long delayAmount = (long)(1000000/frequencyInHertz);
    long loopTime = (long)((timeInMilliseconds*1000)/(delayAmount*2));
    for (x=0;x<loopTime;x++)
    {  
        digitalWrite(speakerPin,HIGH); //liga Buzzer
        delayMicroseconds(delayAmount);
        digitalWrite(speakerPin,LOW); //desliga o buzzer
        delayMicroseconds(delayAmount);
    }

    digitalWrite(ledPin11, LOW);
    digitalWrite(ledPin12, LOW);
    digitalWrite(ledPin13, LOW);
    //set led back to low
    
    delay(20);
    //a little delay to make all notes sound separate
}
 
void march(char oitava)
{
    // esta é apenas uma tradução da referida partição para frequências / tempo em ms
    // usou 500 ms por um quarto de nota * a oitava
 
    beep(speakerPin, oitava*a, 500);
    beep(speakerPin, oitava*a, 500);
    beep(speakerPin, oitava*a, 500);
    beep(speakerPin, oitava*f, 350);
    beep(speakerPin, oitava*cH, 150);
 
    beep(speakerPin, oitava*a, 500);
    beep(speakerPin, oitava*f, 350);
    beep(speakerPin, oitava*cH, 150);
    beep(speakerPin, oitava*a, 1000);
    //first bit
 
    beep(speakerPin, oitava*eH, 500);
    beep(speakerPin, oitava*eH, 500);
    beep(speakerPin, oitava*eH, 500);
    beep(speakerPin, oitava*fH, 350);
    beep(speakerPin, oitava*cH, 150);
 
    beep(speakerPin, oitava*gS, 500);
    beep(speakerPin, oitava*f, 350);
    beep(speakerPin, oitava*cH, 150);
    beep(speakerPin, oitava*a, 1000);
    //second bit...
 
    beep(speakerPin, oitava*aH, 500);
    beep(speakerPin, oitava*a, 350);
    beep(speakerPin, oitava*a, 150);
    beep(speakerPin, oitava*aH, 500);
    beep(speakerPin, oitava*gSH, 250);
    beep(speakerPin, oitava*gH, 250);
 
    beep(speakerPin, oitava*fSH, 125);
    beep(speakerPin, oitava*fH, 125);
    beep(speakerPin, oitava*fSH, 250);
    delay(250);
    beep(speakerPin, oitava*aS, 250);
    beep(speakerPin, oitava*dSH, 500);
    beep(speakerPin, oitava*dH, 250);
    beep(speakerPin, oitava*cSH, 250);
    //start of the interesting bit
 
    beep(speakerPin, oitava*cH, 125);
    beep(speakerPin, oitava*b, 125);
    beep(speakerPin, oitava*cH, 250);
    delay(250);
    beep(speakerPin, oitava*f, 125);
    beep(speakerPin, oitava*gS, 500);
    beep(speakerPin, oitava*f, 375);
    beep(speakerPin, oitava*a, 125);
 
    beep(speakerPin, oitava*cH, 500);
    beep(speakerPin, oitava*a, 375);
    beep(speakerPin, oitava*cH, 125);
    beep(speakerPin, oitava*eH, 1000);
    //more interesting stuff (this doesn't quite get it right somehow)
 
    beep(speakerPin, oitava*aH, 500);
    beep(speakerPin, oitava*a, 350);
    beep(speakerPin, oitava*a, 150);
    beep(speakerPin, oitava*aH, 500);
    beep(speakerPin, oitava*gSH, 250);
    beep(speakerPin, oitava*gH, 250);
 
    beep(speakerPin, oitava*fSH, 125);
    beep(speakerPin, oitava*fH, 125);
    beep(speakerPin, oitava*fSH, 250);
    delay(250);
    beep(speakerPin, oitava*aS, 250);
    beep(speakerPin, oitava*dSH, 500);
    beep(speakerPin, oitava*dH, 250);
    beep(speakerPin, oitava*cSH, 250);
    //repeat... repeat
 
    beep(speakerPin, oitava*cH, 125);
    beep(speakerPin, oitava*b, 125);
    beep(speakerPin, oitava*cH, 250);
    delay(250);
    beep(speakerPin, oitava*f, 250);
    beep(speakerPin, oitava*gS, 500);
    beep(speakerPin, oitava*f, 375);
    beep(speakerPin, oitava*cH, 125);
 
    beep(speakerPin, oitava*a, 500);
    beep(speakerPin, oitava*f, 375);
    beep(speakerPin, oitava*c, 125);
    beep(speakerPin, oitava*a, 1000);
}
