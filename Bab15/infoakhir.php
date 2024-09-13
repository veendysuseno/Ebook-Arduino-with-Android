<?php
  include_once("koneksidb.php");
 
  $sql = "SELECT * FROM logsensor ORDER BY WAKTU DESC LIMIT 1";
  $hasil = mysqli_query($dbc, $sql);
  $baris = mysqli_fetch_row($hasil);
  if ($baris) 
  {    
    $id_data    = $baris[0];
    $waktu      = $baris[1];  
    $suhu       = $baris[2];
    $kelembaban = $baris[3];
 
    print("waktu,$waktu\n");
    print("suhu,$suhu\n");
    print("kelembaban,$kelembaban\n");
  }
  else
    print("error,Not found\n");

  exit;
?>
