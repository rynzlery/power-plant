import MySQLdb
import serial
import json
import env

arduino = serial.Serial(env.arduino_port, env.arduino_baudrate, timeout=.1)

con = MySQLdb.connect(env.db_address, env.db_user, env.db_password, env.db_database)

while True:
    data = arduino.readline()[:-2]  # the last bit gets rid of the new-line chars
    if data:
        print(data.decode('utf-8'))
        data_ser = json.loads(data)
        humidity = str(data_ser['humidity'])
        temperature = str(data_ser['temperature'])

        try:
            cursor = con.cursor()
            query = "INSERT INTO "+env.db_table+"(humidity, temperature) VALUES("+humidity+", "+temperature+");"
            cursor.execute(query)
        except Exception:
            print("db insertion error")
            print(Exception)
        finally:
            cursor.close()

con.close()