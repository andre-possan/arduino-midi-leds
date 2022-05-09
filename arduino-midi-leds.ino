#include <MIDI.h>

int Leds[] = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3};
int quatidadeDeLeds = sizeof(Leds);
MIDI_CREATE_DEFAULT_INSTANCE();

void setup()
{
  for (int contador = 0; contador < quatidadeDeLeds; contador++)
  {
    pinMode(Leds[contador], OUTPUT);
  }

  MIDI.begin(4); // "Escutando" apenas o canal 4, para todos os canais utilize: MIDI_CHANNEL_OMNI
  Serial.begin(115200);
  MIDI.setHandleNoteOn(MyHandleNoteOn);
  MIDI.setHandleNoteOff(MyHandleNoteOn);
}

void loop()
{
  MIDI.read();
}

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
      verifica(Leds[contador], ligado[contador]);
    }
  }
}
