#include "cord.hpp"

#include <stdexcept>

#include "cord_utilities.hpp"
/*
SharedPointer<Cord> left_;
  SharedPointer<Cord> right_;
  char* data_ = nullptr;
  unsigned int length_ = 0;
*/
Cord::Cord(std::string_view sv) {
    if (sv.empty()) {
        throw std::invalid_argument("");
    }
    data_ = new char[sv.size() + 1];
    for (unsigned int i = 0; i < sv.size(); i++) {
        data_[i] = sv[i];
    }
    data_[sv.size()] = '\0';
    length_ = sv.size();
}
Cord::~Cord() {
    delete[] data_;

}
SharedPointer<char> Cord::ToString() const {
    if (data_ != nullptr) {
        char* hold = new char[Length() + 1];
        for (unsigned int i = 0; i < Length() + 1; i++) {
            hold[i] = data_[i];
        }
        hold[Length()] = '\0';
        SharedPointer<char> ret = SharedPointer<char>(hold,kSharedPointerType::kArray);
        return ret;
    }
    SharedPointer<char> left = left_.Get()->ToString();
    SharedPointer<char> right = right_.Get()->ToString();
    unsigned int l = left_.Get()->Length();
    unsigned int r = right_.Get()->Length();
    unsigned int len = l + r + 1;
    char* ret = new char[len];
    for (unsigned int i = 0; i < l; i++) {
        ret[i] = left.Get()[i];
    }
    for (unsigned int i = 0; i < r; i++) {
        ret[l + i] = right.Get()[i];
    }
    ret[len - 1] = '\0';
    SharedPointer<char> final_ret = SharedPointer<char>(ret,kSharedPointerType::kArray);
    return final_ret;
}