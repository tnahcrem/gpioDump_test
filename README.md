# gpioDump_test
Simple utility library to dump bytes/memory physically on a GPIO by bit banging it.
Simple start and stop bit and bit banging of GPIO.
Useful for crash dump scenarios when transport is dead.
The rate of bit bangign depends on CPU clock.
The output can be decoded by any PC based logic analyser.
I used USBEE DX.
