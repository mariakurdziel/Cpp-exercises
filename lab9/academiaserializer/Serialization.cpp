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


    void academia::Room::Serialize(academia::Serializer *serializer) const {
        serializer->Header("Room");
        serializer->IntegerField("a", a_);
        serializer->StringField("b", b_);
        string s = NewEnumerableTypeToString(t_);
        serializer->StringField("t", s);
        serializer->Footer("Room");

    }

    academia::Room::Room(int a, const string &b, Type t) {
        a_ = a;
        b_ = b;
        t_ = t;

    }
}
