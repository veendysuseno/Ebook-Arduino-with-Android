 <?php
  include_once("koneksidb.php");
	 
  $hasil = mysqli_query($dbc, "SELECT * FROM logsensor");
  while ($baris = mysqli_fetch_row($hasil)) 
  {    
    $id_data    = $baris[0];
    $waktu      = $baris[1];  
    $suhu       = $baris[2];
    $kelembaban = $baris[3];

    print("$id_data, $waktu, $suhu, $kelembaban<br>");
  }

  exit();
?>