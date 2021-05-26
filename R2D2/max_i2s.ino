/*
For my WAVE file that I use in this tutorial we already know the following variables:

Sample rate: 44.1 kHz
Bits per channel: 16
Number of channels: 2
Therefore the serial clock has the frequency of 44.1 kHz * 16 * 2 = 1.411 MHz.

The second line of the I2S communication protocol is the Word Select (WS) or Frame Select (FS) wire that differentiate between the left or the right channel.

If WS = 0 → Channel 1 (left channel) is used
If WS = 1 → Channel 2 (right channel) is used
The last wire is the Serial Data (SD) line where the payload is transmitted in 2 complements. It is important that the most significant bit is transferred fist (MSB first), because transmitter and receiver may have different word lengths. Therefore the transmitter nor the receiver have to know how many bits are transferred. But what happened if the word length between transmitter and receiver does not match?

If WS of receiver > WS transmitter → word is truncated (least significant data bits are set to 0)
If WS of receiver < WS transmitter → bits after the LSB are ignored
*/

// play di un file dalla memoria

#include "AudioGeneratorAAC.h"
#include "AudioOutputI2S.h"
#include "AudioFileSourcePROGMEM.h"
#include "sampleaac.h"

AudioFileSourcePROGMEM *in;
AudioGeneratorAAC *aac;
AudioOutputI2S *out;

void setup(){
  Serial.begin(115200);

  in = new AudioFileSourcePROGMEM(sampleaac, sizeof(sampleaac));
  aac = new AudioGeneratorAAC();
  out = new AudioOutputI2S();
  out -> SetGain(0.125);
  out -> SetPinout(26,25,22);
  aac->begin(in, out);
}

void loop(){
  if (aac->isRunning()) {
    aac->loop();
  } else {
    aac -> stop();
    Serial.printf("Sound Generator\n");
    delay(1000);
  }
}
