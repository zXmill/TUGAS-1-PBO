/* Kelas Lingkaran (Semua kode sumber dalam satu berkas) (LingkaranAIO.cpp) */
#include <iostream>    // menggunakan fungsi-fungsi IO
#include <string>      // menggunakan string
using namespace std;
 
class Lingkaran {
private:
   double jari_jari;  // Anggota data (Variabel)
   string warna;      // Anggota data (Variabel)
 
public:
   // Konstruktor dengan nilai default untuk anggota data
   Lingkaran(double r = 1.0, string c = "merah") {
      jari_jari = r;
      warna = c;
   }
 
   double dapatkanJariJari() {  // Fungsi anggota (Getter)
      return jari_jari;
   }
 
   string dapatkanWarna() {   // Fungsi anggota (Getter)
      return warna;
   }
 
   double dapatkanLuas() {    // Fungsi anggota
      return jari_jari * jari_jari * 3.1416;
   }
};   // perlu mengakhiri deklarasi kelas dengan tanda titik koma
 
// Fungsi pengujian program
int main() {
   // Membuat sebuah instance Lingkaran
   Lingkaran l1(1.2, "biru");
   cout << "Jari-jari = " << l1.dapatkanJariJari() << ", Luas = " << l1.dapatkanLuas()
        << ", Warna = " << l1.dapatkanWarna() << endl;
 
   // Membuat instance Lingkaran lain
   Lingkaran l2(3.4); // warna default
   cout << "Jari-jari = " << l2.dapatkanJariJari() << ", Luas = " << l2.dapatkanLuas()
        << ", Warna = " << l2.dapatkanWarna() << endl;
 
   // Membuat instance Lingkaran menggunakan konstruktor default tanpa argumen
   Lingkaran l3;      // jari-jari dan warna default
   cout << "Jari-jari = " << l3.dapatkanJariJari() << ", Luas = " << l3.dapatkanLuas()
        << ", Warna = " << l3.dapatkanWarna() << endl;
   return 0;
}
