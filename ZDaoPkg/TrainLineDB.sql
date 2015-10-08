DROP TABLE IF EXISTS tb_lines_info;
CREATE TABLE tb_lines_info (
          line_id INTEGER   PRIMARY KEY AUTOINCREMENT,
          line_name vachar2(50) NOT NULL UNIQUE,
          start_station_id INTEGER,
          end_station_id INTEGER);

DROP TABLE IF EXISTS tb_station_info;
CREATE TABLE tb_station_info (
          station_id  INTEGER    PRIMARY KEY AUTOINCREMENT,
          line_id   INTEGER,
          station_name_en VARCHAR2(50),
          station_name_th VARCHAR2(50),
          start_time VARCHAR2(10),
          arrive_time VARCHAR2(10),
          lat   REAL,
          lng   REAL);

