#include <MIDI.h>

#define LED 13
#define LED2 12
#define LED3 11
#define LED4 10
#define LED5 9
#define LED6 8
#define LED7 7
#define LED8 6
#define LED9 5
#define LED10 4
#define LED11 3

MIDI_CREATE_DEFAULT_INSTANCE();

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
  pinMode(LED9, OUTPUT);
  pinMode(LED10, OUTPUT);
  pinMode(LED11, OUTPUT);
  MIDI.begin(4); // MIDI_CHANNEL_OMNI
  Serial.begin(115200);
  MIDI.setHandleNoteOn(MyHandleNoteOn);
  MIDI.setHandleNoteOff(MyHandleNoteOff);
}

void loop()
{
  MIDI.read();
}

int ligado;
int ligado2;
int ligado3;
int ligado4;
int ligado5;
int ligado6;
int ligado7;
int ligado8;
int ligado9;
int ligado10;
int ligado11;

int verifica(int onLed, int ligado)
{
  if (ligado > 0)
  {
    digitalWrite(onLed, HIGH);
  }
  else if (ligado <= 0)
  {
    digitalWrite(onLed, LOW);
  }
}

void MyHandleNoteOn(byte channel, byte pitch, byte velocity)
{
  if (pitch >= 36 && pitch <= 41 && velocity > 0)
  {
    ligado = ligado + 1;
  }
  verifica(LED, ligado);

  if (pitch >= 42 && pitch <= 47 && velocity > 0)
  {
    ligado2 = ligado2 + 1;
  }
  verifica(LED2, ligado2);

  if (pitch >= 48 && pitch <= 53 && velocity > 0)
  {
    ligado3 = ligado3 + 1;
  }
  verifica(LED3, ligado3);

  if (pitch >= 54 && pitch <= 59 && velocity > 0)
  {
    ligado4 = ligado4 + 1;
  }
  verifica(LED4, ligado4);

  if (pitch >= 60 && pitch <= 65 && velocity > 0)
  {
    ligado5 = ligado5 + 1;
  }
  verifica(LED5, ligado5);

  if (pitch >= 66 && pitch <= 71 && velocity > 0)
  {
    ligado6 = ligado6 + 1;
  }
  verifica(LED6, ligado6);

  if (pitch >= 72 && pitch <= 77 && velocity > 0)
  {
    ligado7 = ligado7 + 1;
  }
  verifica(LED7, ligado7);

  if (pitch >= 78 && pitch <= 83 && velocity > 0)
  {
    ligado8 = ligado8 + 1;
  }
  verifica(LED8, ligado8);

  if (pitch >= 84 && pitch <= 89 && velocity > 0)
  {
    ligado9 = ligado9 + 1;
  }
  verifica(LED9, ligado9);

  if (pitch >= 90 && pitch <= 95 && velocity > 0)
  {
    ligado10 = ligado10 + 1;
  }
  verifica(LED10, ligado10);

  if (pitch >= 96 && pitch <= 97 && velocity > 0)
  {
    ligado11 = ligado11 + 1;
  }
  verifica(LED11, ligado11);
}
void MyHandleNoteOff(byte channel, byte pitch, byte velocity)
{
  if (pitch >= 36 && pitch <= 41 && velocity == 0)
  {
    ligado = ligado - 1;
  }
  verifica(LED, ligado);

  if (pitch >= 42 && pitch <= 47 && velocity == 0)
  {
    ligado2 = ligado2 - 1;
  }
  verifica(LED2, ligado2);

  if (pitch >= 48 && pitch <= 53 && velocity == 0)
  {
    ligado3 = ligado3 - 1;
  }
  verifica(LED3, ligado3);

  if (pitch >= 54 && pitch <= 59 && velocity == 0)
  {
    ligado4 = ligado4 - 1;
  }
  verifica(LED4, ligado4);

  if (pitch >= 60 && pitch <= 65 && velocity == 0)
  {
    ligado5 = ligado5 - 1;
  }
  verifica(LED5, ligado5);

  if (pitch >= 66 && pitch <= 71 && velocity == 0)
  {
    ligado6 = ligado6 - 1;
  }
  verifica(LED6, ligado6);

  if (pitch >= 72 && pitch <= 77 && velocity == 0)
  {
    ligado7 = ligado7 - 1;
  }
  verifica(LED7, ligado7);

  if (pitch >= 78 && pitch <= 83 && velocity == 0)
  {
    ligado8 = ligado8 - 1;
  }
  verifica(LED8, ligado8);

  if (pitch >= 84 && pitch <= 89 && velocity == 0)
  {
    ligado9 = ligado9 - 1;
  }
  verifica(LED9, ligado9);

  if (pitch >= 90 && pitch <= 95 && velocity == 0)
  {
    ligado10 = ligado10 - 1;
  }
  verifica(LED10, ligado10);

  if (pitch >= 96 && pitch <= 97 && velocity == 0)
  {
    ligado11 = ligado11 - 1;
  }
  verifica(LED11, ligado11);
}