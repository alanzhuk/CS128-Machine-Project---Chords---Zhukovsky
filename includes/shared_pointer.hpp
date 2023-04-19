#ifndef SHARED_POINTER_HPP
#define SHARED_POINTER_HPP

#include <iostream>

enum class kSharedPointerType { kArray, kObject };

template <typename T>
class SharedPointer {
public:
  // SharedPointer(T* address,
  //               kSharedPointerType type = kSharedPointerType::kObject);
  // ~SharedPointer();
  // SharedPointer(const SharedPointer<T>& source);
  // SharedPointer<T>& operator=(const SharedPointer<T>& source);

  // Provided, do not modify!
  SharedPointer() = default;
  T& operator*() { return *holder_; }
  T* operator->() { return holder_; }
  const T* operator->() const { return holder_; }
  T* Get() { return holder_; }
  const T* Get() const { return holder_; }
  unsigned int UseCount() const {
    return (ref_count_ != nullptr) ? *ref_count_ : 0;
  }

private:
  T* holder_ = nullptr;
  kSharedPointerType type_ = kSharedPointerType::kObject;
  unsigned int* ref_count_ = nullptr;
};

// non-member helper function declarations

// non-member helper function definitions

// member function definitions

#endif