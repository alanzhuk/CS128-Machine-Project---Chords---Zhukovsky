#include "cord_utilities.hpp"

SharedPointer<Cord> ConcatCords(const SharedPointer<Cord>& left_cord,
                                const SharedPointer<Cord>& right_cord) {
    if (left_cord.Get() == nullptr || right_cord.Get() == nullptr) {
        throw std::invalid_argument("");
    }
    Cord* node = new Cord();
    node->length_ = left_cord->length_ + right_cord->length_;
    node->right_ = right_cord;
    node->left_ = left_cord;
    SharedPointer<Cord> ret(node, kSharedPointerType::kObject);
    return ret;
}

SharedPointer<Cord> SubString(SharedPointer<Cord> curr_cord,
                              unsigned int lower_idx,
                              unsigned int upper_idx) {
    if (lower_idx >= upper_idx || lower_idx < 0 || upper_idx > curr_cord.Get() -> Length()) {
        throw std::invalid_argument("");
    }
    if (curr_cord -> Length() == upper_idx - lower_idx) {
        return curr_cord;
    }
    if (!(curr_cord.Get() == nullptr)) { //.Data() == nullptr
        auto hold = curr_cord -> Data().substr(lower_idx, (upper_idx - lower_idx)); 
        Cord* ret_cord = new Cord(hold);
        SharedPointer<Cord> ret = SharedPointer(ret_cord);
        return ret;
    }
    if (upper_idx <= curr_cord->Left()->Length()){
        return SubString(curr_cord -> Left(), lower_idx, upper_idx); 
    }
    if (lower_idx >= curr_cord->Left()->Length()) {
        return SubString(curr_cord -> Left(), lower_idx - curr_cord -> Left() -> Length(), upper_idx - curr_cord -> Left() -> Length()); 
    }
    SharedPointer<Cord> l = SubString(curr_cord -> Left(), lower_idx, curr_cord -> Left() -> Length());
    SharedPointer<Cord> r = SubString(curr_cord -> Right(), 0, upper_idx - curr_cord -> Left() -> Length());
    return ConcatCords(l,r);
} 