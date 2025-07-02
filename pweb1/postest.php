<!DOCTYPE html>
<html>
<head>
    <title>Form Biodata Basic</title>
</head>
<body>
    <h2>Form Biodata</h2>

    <!-- Form input, data dikirim dengan metode POST -->
    <form method="post">
        <!-- Input nama -->
        Nama: <input type="text" name="nama"><br><br>

        <!-- Input umur -->
        Kelas: <input type="huruf" name="Kelas"><br><br>


        <!-- Pilihan jurusan dengan radio button -->
        Identitas:<br>
        <input type="radio" name="jurusan" value="Informatika" id="jurusan_informatika" 
        <label for="jurusan_informatika">Mahasiswa</label><br>

        <input type="radio" name="jurusan" value="Kedokteran" id="jurusan_kedokteran">
        <label for="jurusan_kedokteran">Mahasiswi</label><br>

        <input type="radio" name="jurusan" value="Lainnya" id="jurusan_lainnya">
        <label for="jurusan_lainnya">Sigma</label><br><br>

        <input type="radio" name="jurusan" value="Lainnya" id="jurusan_lainnya">
        <label for="jurusan_lainnya">Jawa</label><br><br>

        <!-- Tombol kirim -->
        <input type="submit" value="Kirim">
    </form>
   switch ($jurusan) {
    case "Kedokteran":
        echo "Kamu ambil jurusan Kedokteran\n";
        break;
    case "Informatika":
        echo "Kamu ambil jurusan Informatika\n";
        break;
    default:
        echo "Jurusan tidak diketahui\n";
        break;
}

    <?php
    // Mengecek apakah form sudah disubmit
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        // Menyimpan input dari form ke dalam variabel
        $nama = $_POST["nama"];
        $kelas = (int)$_POST["kelas"];
        
        // Mengubah nilai isMahasiswa menjadi teks "Ya" atau "Tidak"
        $isMahasiswa = $_POST["isMahasiswa"] == "1" ? "Ya" : "Tidak";


        // Menyimpan pilihan jurusan
        $jurusan = $_POST["jurusan"];

        // Menampilkan hasil input
        echo "<hr><h3>Hasil Input:</h3>";
        echo "Nama: $nama<br>";
        echo "Kelas: $kelas <br>";
       

    }
    ?>
</body>
</html>