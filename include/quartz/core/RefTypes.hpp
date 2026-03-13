#pragma once

#define $quartz_create_type_ref(TYPE, DEFAULT_VAL)\
    class TYPE##_ref\
    {\
    public:\
        explicit TYPE##_ref(TYPE* ptr) : m_val(ptr) {}\
        ~TYPE##_ref() = default;\
        inline TYPE get() const\
        {\
            return m_val ? *m_val : DEFAULT_VAL;\
        }\
        inline void set(TYPE val)\
        {\
            if (m_val)\
            {\
                *m_val = val;\
            }\
        }\
    private:\
        TYPE* m_val = nullptr;\
    }

namespace quartz
{
$quartz_create_type_ref(int, 0);
$quartz_create_type_ref(float, 0.f);
$quartz_create_type_ref(double, 0.0);
$quartz_create_type_ref(bool, false);
} // quartz