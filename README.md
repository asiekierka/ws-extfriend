# ExtFriend

ExtFriend is a USB adapter for the WonderSwan's EXT port based on the RP2040 chip and the Raspberry Pi Pico board, providing the following features at a low cost:

* A USB serial port communicating with the WonderSwan at 9600, 38400 and 192000 baud,
* A USB audio device allowing digital stereo audio capture from the WonderSwan.

Both features can be active simultaneously - for example, this could allow one to control a WonderSwan as an audio synthesizer.

Special thanks to [BluRaf](https://mastodon.sdf.org/@BluRaf) for providing support and advice through my first journey into TinyUSB lands.

## Tips

* If you mute the USB audio device, the WonderSwan will consider the headphones as disconnected, re-enabling the internal speaker.
* The ExtFriend automatically rounds down your selected baud rate to the closest frequency supported by the console; for example, 19200 baud is treated as 9600 baud, 57600 baud is treated as 38400 baud, and 230400 baud is treated as 19200 baud.

### Using TransMagic with ExtFriend

#### Windows

You need to set your USB device's serial port to COM1-COM7 for compatibility with TransMagic. See [this article](https://kb.plugable.com/serial-adapter/how-to-change-the-com-port-for-a-usb-serial-adapter-on-windows-7,-8,-81,-and-10) for more information.

#### Linux

    # Install Source Han Sans font, alias it to Microsoft Japanese fonts
    $ winetricks sourcehansans fakejapanese
    
    # Connect USB ExtFriend device to Wine virtual COM1 port
    $ ln -s /dev/ttyACM0 ~/.wine/dosdevices/com1
    
    # Run TransMagic
    $ LANG=ja_JP.UTF-8 wine TransMagic.exe

## Firmware build instructions

* Copy `pico_sdk_import.cmake` from your Pico-SDK installation to the repository's root.
  * For example, `cp /usr/share/pico-sdk/external/pico_sdk_import.cmake .`
* Run `mkdir build`, `cd build`, `cmake ..`, `make`.
* To flash onto an RP2040, `picotool load extfriend.uf2`.

## Hardware build instructions (Raspberry Pi Pico)

![ExtFriend plugged into a SwanCrystal using a soldered header.](https://img.asie.pl/PTC3.jpg)

* Flash the program to the Pico: for example, `picotool load -v -x extfriend.uf2`
* Connect the Raspberry Pi Pico to [the WonderSwan's EXT port](http://daifukkat.su/docs/wsman/#pinout_extport). The default build of ExtFriend uses seven consecutive Pi Pico pins, as follows:
  * EXT GND - Pico GND (for example pin 3)
  * EXT SER_MOSI - Pico pin 2 (GP1)
  * EXT SER_MISO - Pico pin 1 (GP0)
  * If you want to use digital audio capture:
    * EXT HDPN_BCLK - Pico pin 7 (GP5)
    * EXT HDPN_LRCK - Pico pin 6 (GP4)
    * EXT HDPN_SDAT - Pico pin 5 (GP3)
    * EXT /HDPN_DETECT - Pico pin 4 (GP2)


If you don't have an EXT port plug or cable handy, you can use an HDMI breakout board. An example instruction guide is provided [here](https://twitter.com/peca_port0/status/1631569109912817667) (in Japanese), for a $2 AliExpress board.

## License

GPLv3+.
