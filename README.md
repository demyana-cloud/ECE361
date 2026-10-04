# ECE361

Demyana Fransis


## Homework 1

### Build and Test

To build Homework 1:

`cd hw01`

`make`

To run the tests:

`make test`

To remove generated build files:

`make clean`

### Input Ranges

Valid `width` values are 1 through 32.

Valid `pos` values are 0 through 31.

For `get_field()` and `set_field()`, `pos + width` must not exceed 32.

### Out-of-Range Behavior

For invalid arguments, `get_field()` returns 0.

For invalid arguments, `set_field()` returns the original word unchanged.

For invalid thermostat MODE values 5-7, `status_unpack()` treats the mode as OFF (0).