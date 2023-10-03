#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

class Rekening {
private:
    int nomor;
    double saldo;

public:
    Rekening(int nomor) {
        this->nomor = nomor;
        this->saldo = 0.0;
    }

    Rekening(int nomor, double saldo) {
        this->nomor = nomor;
        this->saldo = saldo;
    }

    int dapatkanNomor() {
        return this->nomor;
    }

    double dapatkanSaldo() {
        return this->saldo;
    }

    string toString() {
        ostringstream stream;
        stream << "Rekening[nomor=" << nomor << ",saldo=Rp" << fixed << setprecision(2) << saldo << "]";
        return stream.str();
    }

    void kredit(double jumlah) {
        saldo += jumlah;
    }

    void debet(double jumlah) {
        if (saldo >= jumlah) {
            saldo -= jumlah;
        }
        else {
            cout << "Jumlah melebihi saldo" << endl;
        }
    }

    void transferKe(double jumlah, Rekening& lain) {
        if (saldo >= jumlah) {
            saldo -= jumlah;
            lain.kredit(jumlah);
        }
        else {
            cout << "Jumlah melebihi saldo" << endl;
        }
    }
};

int main() {
    // Uji Konstruktor dan toString()
    Rekening rekening1(5566);
    cout << rekening1.toString() << endl;
    // Rekening[nomor=5566,saldo=Rp0.00]

    Rekening rekening2(1234, 999000.0); // 999,000 Rupiah
    cout << rekening2.toString() << endl;
    // Rekening[nomor=1234,saldo=Rp999000.00]

    // Uji getter
    cout << "Nomor rekening adalah: " << rekening2.dapatkanNomor() << endl;
    // Nomor rekening adalah: 1234
    cout << "Saldo adalah: Rp" << fixed << setprecision(2) << rekening2.dapatkanSaldo() << endl;
    // Saldo adalah: Rp999000.00

    // Uji kredit(), debet(), dan transferKe()
    rekening1.kredit(11100.0); // 11,100 Rupiah
    cout << rekening1.toString() << endl;
    // Rekening[nomor=5566,saldo=Rp11100.00]

    rekening1.debet(5500.0); // 5,500 Rupiah
    cout << rekening1.toString() << endl;
    // Rekening[nomor=5566,saldo=Rp5600.00]

    rekening1.debet(500000.0); // Uji kesalahan debet() - Jumlah melebihi saldo
    // Jumlah melebihi saldo
    cout << rekening1.toString() << endl;
    // Rekening[nomor=5566,saldo=Rp5600.00]

    rekening2.transferKe(10000.0, rekening1); // 10,000 Rupiah
    cout << rekening1.toString() << endl;
    // Rekening[nomor=5566,saldo=Rp15600.00]

    cout << rekening2.toString() << endl;
    // Rekening[nomor=1234,saldo=Rp989000.00]

    return 0;
}
