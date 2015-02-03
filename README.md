# Arduino Trigger Platform

Arduino Trigger Platform is an Arduino-based device designed for triggering cameras and flashes using a push button or a light-dependent resistor. Arduino Trigger Platform supports wired and IR camera connections.

## Rationale

The original idea was to build an Arduino-powered optical slave for an external flash, so it could be triggered from camera without a hot shoe (e.g., SONY NEX-3N). In the process, I decided to extend the scope of the project and add other useful features.

## Usage Scenarios

* IR remote shutter trigger
* Wired shutter trigger (e.g., for use with film SLR cameras)
* Intervalometer
* Lightning trigger for capturing photos of lightnings
* Universal optical slave adapter

## Tested Hardware

Nikon D90
Nikon F-301
Nikon FE with MD-12 motor drive
Yongnuo RF-600TX wireless trigger
Yongnuo SC-28A flash cable
Osram VS 280 Studio
Metz 44 AF-1

## Notes

When using the push button to trigger the camera and/or flash, make sure that the light-dependent resistor is disabled (e.g., put a black cap on it).
