//include de biblioteca do arduino
#include <Password.h>
#include <Keypad.h>
//OBS: PODE HAVER GRAVAÇÃO DE SENHA NA EPROM, COM OUTRA PROGRAMÇÃO
Password password = Password("1234"); //senha declarada para digitação
const byte ROWS = 4; //4 linhas do teclado
const byte COLS = 4; //4 colunas do teclado
//utilizando o teclado como caractere e indicando suas teclas como char, não como uma matriz.
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'}, 
  {'*','0','#','D'}
};
//dando nome aos pinos e indicando seu caminho do teclado referente a linhas e colunas
byte rowPins[ROWS] = {2,3,4,5};
byte colPins[COLS] = {6,7,8,9};
//declarando pinos
int buzzer = 10;
int led1 = 11;
int led2 = 12;
int led3 = 13;
Keypad keypad = Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);
void setup() {
  // put your setup code here, to run once:
  //setando pinos como saida
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  keypad.addEventListener(keypadEvent); // adionar um ouvinte de eventos para o telcado
}
void loop() {
  // put your main code here, to run repeatedly:
  keypad.getKey();
}
//tratamento para os eventos 
void keypadEvent(KeypadEvent eKey) {
  switch (keypad.getState()){
    case PRESSED:
      Serial.print("Password: "); //pede para digitar a senha
      Serial.println(eKey); //lê a senha digitada
    digitalWrite(buzzer, HIGH); // liga o buzzer
    delay(8); //buzzer ligado por 8 milissegundos
    digitalWrite(buzzer, LOW); //desliga o buzzer
      switch (eKey){
        case '*': checkPassword(); break; //funciona como ENTER checa se a senha digitada é correta, seria a tecla CONFIRMAR
        case '#': password.reset(); //reinicia para digitar novamente
   digitalWrite(led3, HIGH); // para resetar o led amarelo (led 3) fica acesso os demais desligado
   digitalWrite(led1, LOW);
   digitalWrite(led2, LOW);
   break; //sai sintaxe passando para próximo
    default: password.append(eKey);
      }
  }
}
//SE A SENHA FOR DIGITADA CORRETAMENTE
void checkPassword(){
  if (password.evaluate()){
    Serial.println("##SUCESSO##"); //mensagem exibita no monitor serial
    alert();//emite um alerta de que a senha foi digitado corretamente
    digitalWrite(led1,HIGH); //liga o led 1 (VERDE) QUANDO A SENHA DIGITADA CORRETAMENTE e desliga os demais
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  else{
    Serial.println("SENHA INVÁLIDA, RESE (#) E TENTE OUTRA VEZ!!");//MENSAGEM DE SENHA DIGITADA ERRADA
    digitalWrite(led3 ,LOW);
    digitalWrite(led2, HIGH); //liga o led 2 (vermelho) e desliga os demais
    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(buzzer, LOW);
    digitalWrite(led1, LOW);
  }
}
void alert(){
  digitalWrite(buzzer, HIGH);
  delay(50);
  digitalWrite(buzzer, LOW);
  delay(50);
  digitalWrite(buzzer, HIGH);
  delay(50);
  digitalWrite(buzzer, LOW);
  delay(50);
  digitalWrite(buzzer, HIGH);
  delay(50);
  digitalWrite(buzzer,LOW);
  delay(10);
}

