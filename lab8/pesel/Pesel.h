//
// Created by mrozolga on 25.04.17.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

namespace academia {
    class AcademiaDataValidationError : public std::runtime_error {
    public:
        AcademiaDataValidationError(const string &__arg);
    };

    class InvalidPeselChecksum : public AcademiaDataValidationError {
    public:
        InvalidPeselChecksum(const string &__arg, int computed_checksum);
    };

    class InvalidPeselLength : public AcademiaDataValidationError {
    public:
        InvalidPeselLength(const string &__arg, int number);
    };

    class InvalidPeselCharacter : public AcademiaDataValidationError {
    public:
        InvalidPeselCharacter(const string &__arg);
    };


    class Pesel {
    public:

        Pesel(const char *a);

        ~Pesel();

        void checksum(const char *a);

        void Char(const char *a);

        void Length(const char *a);

        void validatePESEL(const char *);

    private:
        const char *_a;

    };

}

#endif //JIMP_EXERCISES_PESEL_H
