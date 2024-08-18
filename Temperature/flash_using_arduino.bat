@echo off
pause
avrdude -c avrisp -P COM4 -b 19200 -p m48pa -e -U lfuse:w:0xf7:m -U hfuse:w:0xdf:m -U efuse:w:0xff:m -U flash:w:LevelAVR.ino_atmega48p_16000000L.hex
pause