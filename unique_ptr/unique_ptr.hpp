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

    unique_ptr(unique_ptr&& other) noexcept
        : pointer_(other.pointer_) {
        other.pointer_ = nullptr;
    }

    unique_ptr& operator=(unique_ptr&& other) noexcept {
        if (this != &other) {
            delete pointer_;

            pointer_ = other.pointer_;
            other.pointer_ = nullptr;
        }

        return *this;
    }

    T *get() const noexcept {
        return pointer_;
    }
};