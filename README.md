# TAS6422-AMP-Project
![TAS6422 AMPLIFIER](https://raw.githubusercontent.com/CyberPit/TAS6422-AMP-Project/master/Photo/FrontSideView.jpg?raw=true)  
2.1MHz switching Class-D Audio Amplifier Project  
This project started as a CyberPit personal Interest project in 2020.    

- Main project web page located at https://cyberpithilo.web.fc2.com/audio/tas6422amp/index.html
- The top page of CyberPit https://cyberpithilo.web.fc2.com/
- Yandex Machine translation link https://translate.yandex.com/translate?url=https%3A%2F%2Fcyberpithilo.web.fc2.com%2Faudio%2Ftas6422amp%2Findex.html&lang=ja-en
- Google Machine translation link https://translate.google.com/translate?hl=ja&sl=ja&tl=en&u=https%3A%2F%2Fcyberpithilo.web.fc2.com%2Faudio%2Ftas6422amp%2Findex.html&sandbox=1

  
## Features
- TI PCM9211 and TAS6422 Fully digital connected I2S audio signal path.
- Super high-speed(2.1MHz) swithcing PWM processing power amplifier output.
- GUSTARD U12 and WADIA Compatible LVDS(HDMI Connector Used)I2S Input
- Optical S/PDIF Input and Output
- Coaxial S/PDIF Input
- RCA-pin 24bit Analog Stereo Signal Input
- Rotally Encorder for 0.5dB step Volume and paramenter control.
- 3 digits LED Display
- Last volume setting memory
- Selectable 6db/oct HPF Frequency(can be bypassed by setting)
- Selectable Output Phase (IN/OUT)
- J8 header for instant standby/mute operation
- Split-able Control part PCB
- Single Power Supply

    


## Hardware Key-parts Information

- Texas Instrument TAS6422-Q1 (Class-D Amp)
- Texas Instrument PCM9211 (ADC/DIR/DIT/I2S Matrix)
- Microchip PIC16F1829 or PIC16F18346 (MCU)
- Texas Instrument DS90LV048ATMX (LVDS Reciever)

## Tools Used
- Schematic & Board Design Tool: Ki-CAD
- MCU Software Development Tool: MPLAB X

## License
This work and all other materials are licensed under a Creative Commons Attribution Share-Alike 4.0 license. This allows for both personal and commercial derivative works, as long as they credit "Designed by CyberPit HILO" and release their designs under the same license.

# Wanted
IR Remote receiver had embedded in this design. But I don't have enough time to develop. I hope someone will fork this project and give me a pull request.
Nice to have support for Apple Remote MM4T2AM/A, etc...

