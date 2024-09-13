<?php
  DEFINE ('DBUSER', 'a5101371_ard');
  DEFINE ('DBPW',   'my12345');
  DEFINE ('DBHOST', 'mysql11.000webhost.com'); // disesuaikan dengan milik Anda (email)
  DEFINE ('DBNAME', 'a5101371_arduino');
 		
  $dbc = mysqli_connect(DBHOST,DBUSER,DBPW);
  if (!$dbc) 
  {
    die("Koneksi ke database gagal dilakukan: " . mysqli_error($dbc));
    exit();
  }
	 
  $dbs = mysqli_select_db($dbc, DBNAME);
  if (!$dbs) 
  {
    die("Nama database tidak dikenal: " . mysqli_error($dbc));
    exit();
  }
?>
