//
// Created by mrozolga on 25.04.17.
//

#include "Pesel.h"

namespace academia {

    Pesel::Pesel(const char *a) {
        validatePESEL(a);
        _a = a;

    }

    void Pesel::checksum(const char *a) {
        int tab[] = {9, 7, 3, 1, 9, 7, 3, 1, 9, 7};
        int n = strlen(a);
        int licznik = 0;
        for (int i = 0; i < n; i++) {
            licznik += tab[i] * (a[i] - '0');
        }
        if (a[n - 1] - '0' != licznik % 10) throw InvalidPeselChecksum(a, licznik);
    }

    void Pesel::Length(const char *a) {
        int n = strlen(a);
        if (n != 11) throw InvalidPeselLength(a, n);
    }

    void Pesel::Char(const char *a) {
        bool b = true;
        int n = strlen(a);
        for (int i = 0; i < n; i++) {
            if (!isdigit(a[i])) {
                b = false;
                break;
            }
        }
        if (b == false) throw InvalidPeselCharacter(a);
    }


    void Pesel::validatePESEL(const char *a) {
        Length(a);
        Char(a);
        checksum(a);

    }

    Pesel::~Pesel() {

    }

    AcademiaDataValidationError::AcademiaDataValidationError(const string &__arg) : runtime_error(__arg) {}

    InvalidPeselChecksum::InvalidPeselChecksum(const string &__arg, int computed_checksum)
            : AcademiaDataValidationError("Invalid " + __arg + " checksum: " + std::to_string(computed_checksum)) {}

    InvalidPeselCharacter::InvalidPeselCharacter(const string &__arg) : AcademiaDataValidationError(
            "Invalid " + __arg + " character set") {}

    InvalidPeselLength::InvalidPeselLength(const string &__arg, int number) : AcademiaDataValidationError(
            "Invalid " + __arg + " length: " + std::to_string(number)) {}
}