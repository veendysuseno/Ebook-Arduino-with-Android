<?php
  include_once("koneksidb.php");
  
  $ok = true;
  if (! isset($_GET['suhu']))
    $ok = false;
  
  if (! isset($_GET['kelembaban']))
    $ok = false;
  
  if (! $ok)
  {
     print("Salah penggunaan!");
     exit();
  }
  
  $waktu = date("Y-m-d H:i:s");
  $suhu = $_GET['suhu'];
  $kelembaban = $_GET['kelembaban'];
  
  $sql = "INSERT INTO logsensor (WAKTU, SUHU, KELEMBABAN) " .
         "VALUES ('" .  $waktu. "','" . $suhu . "','" . $kelembaban . "');";
		 
  $hasil = mysqli_query($dbc, $sql);
  if ($hasil)
    print("Data berhasil disimpan");
  else
	print("Data gagal disimpan");  

  exit();
?>