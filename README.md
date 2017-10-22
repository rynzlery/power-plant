# :sunflower: Power-Plant : a connected plant
## :seedling: What is Power-Plant
Power-Plant is a project for my indoor plant, a Lemon balm. Months ago, I wanted to irrigate automatically my flowers on my balcony. But I realized that my power supply couldn't be all the time outside. So I decided to put one of my plants inside, to make my IoT project.

I use Arduino and Raspberry Pi boards. The Arduino board stand for acquiring the sensors values and send them to the Raspberry Pi in JSON format by serial link. The Raspberry Pi run the web server and a Python script run continually to store values in database.
## Stuff
* Arduino Uno
* Raspberry Pi
* a pump and a flexible
* sensors (humidity and temperature)

## Schematic
![fritzing schematic](http://netwire.ddns.net/images/tutos/fritzing.PNG)

## Install
1) Create a `env.py` file with the following variables :
```
db_address="localhost"
db_user=[YOUR USER NAME]
db_password=[YOUR USER PASSWORD]
db_database=[YOUR DATABASE NAME]
db_table="powerplant"

arduino_port="COM3"
arduino_baudrate="9600"
```
2) Create a new database in MySQL.
3) Execute `src/core/db-create.py` script to generate the table.

The moisture sensor is activated once every 30 seconds. It allows to avoid electrode corrosion. The range of the sensor can also be decreased by setting a resistor (270 ohms, so in water the value is close to the max) on the digital 7 Pin.

The temperature scale is improved by setting the `analogReference(INTERNAL);`

A water pump is connected to the motor shield. The power supply is only connected to the motor shield which is supplying the Arduino board.

## Links
link to my [tutorial](http://netwire.ddns.net/pageTutos.php#9) :fr:

## Licence
Beerware :beer:

## Thanks
Many thanks to Mélissa, my Lemon balm.