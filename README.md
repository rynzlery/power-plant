# :sunflower:Power-Plant : a connected plant
## :seedling: What is Power-Plant
Power-Plant is a project on my indoor plant, a Lemon balm. Months ago, I wanted to irrigate automatically my flowers on my balcony. But I realize that my power supply can't be all the time outside. So I decided to put one of my plants inside, to make my IoT project.
## Stuff
* Arduino Uno
* Raspberry Pi
* a pump and a flexible
* sensors (humidity)

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

## Links
link to my [tutorial](http://netwire.ddns.net/pageTutos.php#9) :fr:

## Licence

## Thanks
Many thanks to Mélissa, my Lemon balm.