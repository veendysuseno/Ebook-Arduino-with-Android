<?php
  include_once("koneksidb.php");
  
  $ok = true;
  if (! isset($_POST['suhu']))
    $ok = false;
  
  if (! isset($_POST['kelembaban']))
    $ok = false;
  
  if (! $ok)
  {
     print("Salah penggunaan!");
     exit();
  }
  
  $waktu = date("Y-m-d H:i:s");
  $suhu = $_POST['suhu'];
  $kelembaban = $_POST['kelembaban'];
  
  $sql = "INSERT INTO logsensor (WAKTU, SUHU, KELEMBABAN) " .
         "VALUES ('" .  $waktu. "','" . $suhu . "','" . $kelembaban . "');";
		 
  $hasil = mysqli_query($dbc, $sql);
  if ($hasil)
    print("Data berhasil disimpan");
  else
	print("Data gagal disimpan");  

  exit();
?>