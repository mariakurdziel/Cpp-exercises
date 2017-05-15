//
// Created by mrozolga on 09.05.17.
//

#include "Serialization.h"

namespace academia {


    void academia::Serializable::Serialize(academia::Serializer *serializer) const {

    }

    Serializer::Serializer(ostream *out) {
        out_ = out;
    }

    Serializer::Serializer() {}

    Serializer::~Serializer() {

    }


    void academia::Room::Serialize(academia::Serializer *serializer) const {
        serializer->Header("room");
        serializer->IntegerField("id", a_);
        serializer->StringField("name", b_);
        string s = NewEnumerableTypeToString(t_);
        serializer->StringField("type", s);
        serializer->Footer("room");

    }

    academia::Room::Room(int a, const string &b, Type t) {
        a_ = a;
        b_ = b;
        t_ = t;

    }

    Room::~Room() {

    }

    void JsonSerializer::IntegerField(const std::string &field_name, int value) {
        *out_<<"\""<<field_name<<"\""<<": "<<value<<", ";
    }

    void JsonSerializer::DoubleField(const std::string &field_name, double value) {
        *out_<<"\""<<field_name<<"\""<<": "<<value<<", ";
    }

    void JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
        *out_<<"\""<<field_name<<"\""<<": \""<<value<<"\"";
        if (field_name!="type")
            *out_<<", ";
    }

    void JsonSerializer::BooleanField(const std::string &field_name, bool value) {
        *out_<<"\""<<field_name<<"\""<<": "<<value<<", ";
    }

    void JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
        *out_<<field_name;
    }

    void JsonSerializer::ArrayField(const std::string &field_name,
                                    const vector<reference_wrapper<const Serializable>> &value) {
        if (value.empty())
            *out_<<"\""<<field_name<<"\": "<<"[]";
        else {
            *out_<<"\""<<field_name<<"\": ";
            *out_ << "[";
            int size = value.size(), i = 0;
            for (const Serializable &n:value) {
                i++;
                JsonSerializer thing{out_};
                n.Serialize(&thing);
                if (i != size)
                    *out_ << ", ";
            }
            *out_ << "]";
        }
    }

    void JsonSerializer::Header(const std::string &object_name) {
        *out_<<"{";
    }

    void JsonSerializer::Footer(const std::string &object_name) {
        *out_<<"}";
    }

    JsonSerializer::JsonSerializer() {

    }



Building::Building(int a, string b, vector<Room> t) {
        a_ = a;
        b_ = b;
        t_ = t;
        Id=0;
    }

    void Building::Serialize(Serializer *serializer) const {
        serializer->Header("building");
        serializer->IntegerField("id", a_);
        serializer->StringField("name", b_);
        std::vector<std::reference_wrapper<const Serializable>> t2;
        for (const Serializable &n:t_)
        {
            t2.emplace_back(n);
        }
        serializer->ArrayField("rooms", t2);
        serializer->Footer("building");
    }

    Building::~Building() {
    }



    void XmlSerializer::IntegerField(const std::string &field_name, int value) {
        *out_<<"<"<<field_name<<">"<<value<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::DoubleField(const std::string &field_name, double value) {
        *out_<<"<"<<field_name<<">"<<value<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
        *out_<<"<"<<field_name<<">"<<value<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::BooleanField(const std::string &field_name, bool value) {
        *out_<<"<"<<field_name<<">"<<value<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
        *out_<<"<"<<field_name<<">";
    }

    void XmlSerializer::ArrayField(const std::string &field_name,
                                    const vector<reference_wrapper<const Serializable>> &value) {
        if (value.empty())
            *out_<<"<"<<field_name<<"><\\"<<field_name<<">";
        else {
            *out_<<"<"<<field_name<<">";


            for (const Serializable &n:value) {

                XmlSerializer thing{out_};
                n.Serialize(&thing);

            }
            *out_<<"<\\"<<field_name<<">";
        }
    }

    void XmlSerializer::Header(const std::string &object_name) {
        *out_<<"<"<<object_name<<">";
    }

    void XmlSerializer::Footer(const std::string &object_name) {
        *out_<<"<\\"<<object_name<<">";
    }

    XmlSerializer::XmlSerializer() {
    }

    BuildingRepository::BuildingRepository(const std::initializer_list<Building> &building) {
        for (const auto &n:building)
        {
            Add(n);

        }
    }

    void BuildingRepository::StoreAll(Serializer *serializer) const {

    }

    void BuildingRepository::Add(Building building) {
        building.Id++;
        buildings_.emplace_back(building);

    }

    experimental::optional<Building> BuildingRepository::operator[](int index) const {
        experimental::optional<Building> bulding;
        return bulding;
    }

    int BuildingRepository::Id() {
        return buildings_.Id;
    }


}


