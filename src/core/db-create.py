import MySQLdb
import env

con = MySQLdb.connect(env.db_address, env.db_user, env.db_password, env.db_database)

cursor = con.cursor()
cursor.execute("CREATE TABLE IF NOT EXISTS sensors ("
               "id int(11) PRIMARY KEY NOT NULL AUTO_INCREMENT,"
               "humidity int(11) NOT NULL,"
               "temperature float(11) NOT NULL,"
               "created_at timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP"
               ") ENGINE=MyISAM DEFAULT CHARSET=latin1;")

con.close()