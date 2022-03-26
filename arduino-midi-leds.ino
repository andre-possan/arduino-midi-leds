/* Codigo escrito por André, sou iniciante em C++, caso encontre um erro ou tenha uma recomendação, não hesite em mandar uma mensagem! https://github.com/andre-possan :D
  Atenção: Para este código funcionar você deve utilizar o Hairless MIDI https://projectgus.github.io/hairless-midiserial
  Utilizando o Hairless você deve alterar o arquivo serialMIDI.h dentro da pasta da biblioteca e definir a propriedade BaudRate para 115200:
  static const long BaudRate = 115200;
*/

#include <MIDI.h> // Incluindo a biblioteca que utilizaremos para receber informações MIDI.

int Leds[] = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3}; // Definindo as portas que temos leds conectados
int quatidadeDeLeds = sizeof(Leds);
MIDI_CREATE_DEFAULT_INSTANCE(); // Parâmetro da biblioteca que inicia uma instância MIDI

void setup()
{
  for (int contador = 0; contador < quatidadeDeLeds; contador++)
  { // Definindo as portas dos leds como saída
    pinMode(Leds[contador], OUTPUT);
  }

  MIDI.begin(4); // "Escutando" apenas o canal 4, para todos os canais utilize: MIDI_CHANNEL_OMNI
  Serial.begin(115200);
  MIDI.setHandleNoteOn(MyHandleNoteOn);  // Função que será executada quando uma tecla for pressionada
  MIDI.setHandleNoteOff(MyHandleNoteOn); // Função que será executada quando uma tecla parar de ser pressionada.
}

void loop()
{
  MIDI.read(); // O Arduino sempre ficara lendo informações MIDI
}

// Função que só desiliga o led se todas as teclas referentes a ele não forem mais pressionadas:
int verifica(int Led, int ligado)
{
  if (ligado > 0)
  {
    digitalWrite(Led, HIGH);
  }
  else if (ligado <= 0)
  {
    digitalWrite(Led, LOW);
  }
}
int lig1;
int lig2;
int lig3;
int lig4;
int lig5;
int lig6;
int lig7;
int lig8;
int lig9;
int lig10;
int lig11;

int ligado[] = {lig1, lig2, lig3, lig4, lig5, lig6, lig7, lig8, lig9, lig10, lig11};

/*Função que recebera os dados MIDI:
 * channel = canal MIDI,
 * pitch = número identificador da tecla,
 * velocity = a "força" com que a tecla foi pressionada varia de 0 a 127*/
void MyHandleNoteOn(byte channel, byte pitch, byte velocity)
{
  for (int contador = 0; contador < quatidadeDeLeds; contador++)
  {

    // Estabelecendo limites para cada led, Ex: teclas 36 a 40, vão ligar o Led1
    int minimo = (contador * 6) + 36;
    int maximo = minimo + 5;

    // Verificando se a tecla esta dentro dos limites
    if (pitch >= minimo && pitch <= maximo)
    {
      if (velocity > 0)
      {
        ligado[contador] = ligado[contador] + 1;
      }
      else
      {
        ligado[contador] = ligado[contador] - 1;
      }
      verifica(Leds[contador], ligado[contador]); // Chamando a função para verificar e ligar o Led
    }
  }
}
