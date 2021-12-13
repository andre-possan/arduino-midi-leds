# Arduino MIDI Leds

Com este código você pode conectar seu piano MIDI em seu computador para controlar portas digitais do Arduino. 

## Como usar:

- Fazer o dowload do software <a href="https://projectgus.github.io/hairless-midiserial/">Hairless MIDI</a>

- Instalar a biblioteca <a href="https://github.com/FortySevenEffects/arduino_midi_library">Arduino MIDI Library</a> em sua IDE

- Fazer o dowload deste código em seu computador e ajustar:
    - Alterar o parâmetro, static const long BaudRate = 115200; (definindo como 115200) no arquivo serialMIDI.h
    - Portas do arduino
    - O "pitch" (código identificador) das teclas
    - "velocity" parâmetro de intensidade das teclas. 



Caso você tenha alguma recomendação ou encontrou um erro não hesite em entrar em contato.  :grin:



## Resources:

- <a href="https://projectgus.github.io/hairless-midiserial/">Hairless MIDI</a>

- <a href="https://github.com/FortySevenEffects/arduino_midi_library">Arduino MIDI Library</a>
