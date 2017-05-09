//
// Created by mrozolga on 09.05.17.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H


#include <iostream>
#include <string>
#include <vector>
#include <ostream>
#include <initializer_list>

namespace academia {
    using namespace std;

    class Serializer;

    class Serializable {
    public:
        virtual void Serialize(Serializer *serializer) const;


    };

    class Serializer {
    public:
        Serializer(ostream *);

        virtual void IntegerField(const std::string &field_name, int value)=0;

        virtual void DoubleField(const std::string &field_name, double value)=0;

        virtual void StringField(const std::string &field_name, const std::string &value)=0;

        virtual void BooleanField(const std::string &field_name, bool value)=0;

        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value)=0;

        virtual void ArrayField(const std::string &field_name,
                                const vector<reference_wrapper<const academia::Serializable>> &value) =0;

        virtual void Header(const std::string &object_name) =0;

        virtual void Footer(const std::string &object_name) =0;


    protected:
        ostream *out_;

    };

    class Room : public Serializable {
    public:

        enum class Type {
            COMPUTER_LAB
        };

        Room(int a, const string &b, Type t);

        void Serialize(Serializer *serializer) const override;

        string NewEnumerableTypeToString(Type type) const {
            switch (type) {
                case Type::COMPUTER_LAB:
                    return "COMPUTER_LAB";
            }
        }

    private:
        int a_;
        string b_;
        Type t_;

    };

};


#endif //JIMP_EXERCISES_SERIALIZATION_H
