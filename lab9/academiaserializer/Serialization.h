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
#include <vector>
#include <functional>
#include <experimental/optional>

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

        Serializer();
        virtual ~Serializer();

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
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };

        Room(int a, const string &b, Type t);
        virtual ~Room();
        void Serialize(Serializer *serializer) const override;

        string NewEnumerableTypeToString(Type type) const {
            switch (type) {
                case Type::COMPUTER_LAB:
                    return "COMPUTER_LAB";
                case Type::LECTURE_HALL:
                    return "LECTURE_HALL";
                case Type::CLASSROOM:
                    return "CLASSROOM";
            }
        }

    private:
        int a_;
        string b_;
        Type t_;

    };

    class Building : public Serializable
    {
    public:
        Building (int a, string b, vector<Room> t);
        void Serialize(Serializer *serializer) const override;
        virtual ~Building();
        int Id;

    private:
        int a_;
        string b_;
        vector<Room> t_;



    };
    class JsonSerializer : public Serializer
    {
    public:
        JsonSerializer();
        JsonSerializer (ostream *out):Serializer(out){};
        void IntegerField(const std::string &field_name, int value) override;

         void DoubleField(const std::string &field_name, double value) override;

         void StringField(const std::string &field_name, const std::string &value) override;

         void BooleanField(const std::string &field_name, bool value) override;

         void SerializableField(const std::string &field_name, const academia::Serializable &value) override;

         void ArrayField(const std::string &field_name,
                                const vector<reference_wrapper<const academia::Serializable>> &value) override;

         void Header(const std::string &object_name) override;

         void Footer(const std::string &object_name) override;
    };

    class XmlSerializer : public Serializer
    {
    public:
        XmlSerializer();

        XmlSerializer (ostream *out):Serializer(out){};
        void IntegerField(const std::string &field_name, int value) override;

        void DoubleField(const std::string &field_name, double value) override ;

        void StringField(const std::string &field_name, const std::string &value) override;

        void BooleanField(const std::string &field_name, bool value) override;

        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;

        void ArrayField(const std::string &field_name,
                        const vector<reference_wrapper<const academia::Serializable>> &value) override;

        void Header(const std::string &object_name) override;

        void Footer(const std::string &object_name) override;
    };

    class BuildingRepository : public Serializable
    {
    public:
        BuildingRepository(){};
        BuildingRepository(const initializer_list<Building> &building);
        void StoreAll(Serializer *serializer) const;
        void Add (Building building);
        std::experimental::optional<Building> operator[](int index) const;
        int Id();
    private:
        vector<Building> buildings_;

    };


};


#endif //JIMP_EXERCISES_SERIALIZATION_H
