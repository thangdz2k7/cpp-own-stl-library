#pragma once 
#include <utility>

template <typename T> 
class unique_ptr {
private:
    T* pointer_;

public:
    explicit unique_ptr(T* pointer = nullptr) noexcept 
        : pointer_(pointer) {

    }

    ~unique_ptr() {
        delete pointer_;
    }

    unique_ptr(const unique_ptr&) = delete;

    unique_ptr& operator=(const unique_ptr&) = delete;
};