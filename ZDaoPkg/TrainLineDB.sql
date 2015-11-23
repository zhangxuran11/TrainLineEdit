DROP TABLE IF EXISTS tb_lines_info;
CREATE TABLE tb_lines_info (
          line_id INTEGER   PRIMARY KEY AUTOINCREMENT,
          line_name vachar2(50) NOT NULL UNIQUE,
          start_station_id INTEGER,
          end_station_id INTEGER,
          train_id INTEGER);

DROP TABLE IF EXISTS tb_station_info;
CREATE TABLE tb_station_info (
          station_id  INTEGER    PRIMARY KEY AUTOINCREMENT,
          line_id   INTEGER,
          station_name_en VARCHAR2(50),
          station_name_th VARCHAR2(50),
          start_time VARCHAR2(10),
          arrive_time VARCHAR2(10),
          lat   REAL,
          lng   REAL,
		  sea_level REAL);

DROP TABLE IF EXISTS tb_railway_info;
CREATE TABLE tb_railway_info (
          sample_id INTEGER   PRIMARY KEY AUTOINCREMENT,
          line_id INTEGER NOT NULL,
          lng real NOT NULL,
          lat real NOT NULL,
          sea_level real);

insert into tb_lines_info (line_id,line_name,start_station_id,end_station_id,train_id) values (1,'testline',1,8,23);

insert into tb_station_info (line_id,station_name_en,station_name_th,start_time,arrive_time,lat,lng,sea_level) 
	values (1,'Babg Sue','บางชื่อ','12:04','14:08',1350.266592,10033.34141,11);
insert into tb_station_info (line_id,station_name_en,station_name_th,start_time,arrive_time,lat,lng,sea_level) 
	values (1,'Bang Khen','บางเขน','14:12','15:00',1350.808224,10033.63237,14.1);
insert into tb_station_info (line_id,station_name_en,station_name_th,start_time,arrive_time,lat,lng,sea_level) 
	values (1,'Slak si','หลักสี่','15:04','16:32',1353.023753,10034.84347,11.4);
insert into tb_station_info (line_id,station_name_en,station_name_th,start_time,arrive_time,lat,lng,sea_level) 
	values (1,'Don Muang','ดอนเมือง','16:39','17:55',1355.187499,10036.05915,15.8);
insert into tb_station_info (line_id,station_name_en,station_name_th,start_time,arrive_time,lat,lng,sea_level) 
	values (1,'Slak Huk','หลักหก','18:02','18:35',1358.031571,10036.30055,8.2);
insert into tb_station_info (line_id,station_name_en,station_name_th,start_time,arrive_time,lat,lng,sea_level) 
	values (1,'Khlong Rang Sit','คลองรังสิต','18:41','20:08',1358.458624,10036.24761,7.1);
insert into tb_station_info (line_id,station_name_en,station_name_th,start_time,arrive_time,lat,lng,sea_level) 
	values (1,'Rang Sit','รังสิต','20:14','21:34',1359.409117,10036.12695,-4.2);
insert into tb_station_info (line_id,station_name_en,station_name_th,start_time,arrive_time,lat,lng,sea_level) 
	values (1,'Khlong Nueng','คลองหนึ่ง','21:38','22:03',141.387118,10035.88993,0.2);
