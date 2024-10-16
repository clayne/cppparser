// Copyright (C) 2022 Satya Das and CppParser contributors
// SPDX-License-Identifier: MIT

#ifndef B3AB0DD0_7FBB_4455_8B74_3DB850581596
#define B3AB0DD0_7FBB_4455_8B74_3DB850581596

#include <type_traits>

namespace cppast::helper {

/**
 * @brief A convinient class to work with CppEntity derived classes.
 *
 * @note Its not an RAII class and takes no responsibility of life cycle management.
 *
 * @tparam T CppEntity derived class.
 */
template <typename T>
class CppEntityPtr
{
public:
  CppEntityPtr(T* ptr)
    : ptr_(ptr)
  {
  }

  CppEntityPtr(CppEntity* entityPtr)
    : ptr_(dynamic_cast<T*>(entityPtr))
  {
  }

  CppEntityPtr(const CppEntity* entityPtr)
    : ptr_(std::is_const_v<T> ? dynamic_cast<T*>(entityPtr) : nullptr)
  {
  }

  template <typename U>
  CppEntityPtr(const CppEntityPtr<U>& other)
    : CppEntityPtr(other.get())
  {
  }
  //*/
  T* operator->() const
  {
    return ptr_;
  }

  operator bool() const
  {
    return ptr_ != nullptr;
  }

  operator T*() const
  {
    return ptr_;
  }

  operator CppEntity*() const
  {
    return ptr_;
  }

  operator const CppEntity*() const
  {
    return ptr_;
  }

  T& operator*() const
  {
    return *ptr_;
  }

  T* get() const
  {
    return ptr_;
  }

private:
  T* ptr_;
};

} // namespace cppast::helper

#endif /* B3AB0DD0_7FBB_4455_8B74_3DB850581596 */
