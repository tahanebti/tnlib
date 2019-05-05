#pragma once

#include <memory>
#include <type_traits>


namespace detail
{
    template <size_t...> struct max_size;

    template <size_t s>
    struct max_size<s>
    {
        static constexpr size_t value = s;
    };

    template <size_t s1, size_t s2, size_t... sizes>
    struct max_size<s1, s2, sizes...>
    {
        static constexpr size_t value =
            s1 > s2 ?
            max_size<s1, sizes...>::value :
            max_size<s2, sizes...>::value;
    };


    /* to control the instantiation of variant_allocate class template
     * we unpack the package 3 elements each time
     */

    template <typename... Args> struct variant_allocate;

    template <typename Arg1, typename Arg2, typename Arg3, typename... Args>
    struct variant_allocate<Arg1, Arg2, Arg3, Args...>
    {
        static void destroy(size_t id, void* data)
        {
            if (id == typeid(Arg1).hash_code())
                reinterpret_cast<Arg1*>(data)->~Arg1();
            else if (id == typeid(Arg2).hash_code())
                reinterpret_cast<Arg2*>(data)->~Arg2();
            else if (id == typeid(Arg3).hash_code())
                reinterpret_cast<Arg3*>(data)->~Arg3();
            else
                variant_allocate<Args...>::destroy(id, data);
        }

        static void move(size_t var_t, void* var_v, void* this_v)
        {
            if (var_t == typeid(Arg1).hash_code())
                new (this_v) Arg1(std::move(*reinterpret_cast<Arg1*>(var_v)));
            else if (var_t == typeid(Arg2).hash_code())
                new (this_v) Arg2(std::move(*reinterpret_cast<Arg2*>(var_v)));
            else if (var_t == typeid(Arg3).hash_code())
                new (this_v) Arg3(std::move(*reinterpret_cast<Arg3*>(var_v)));
            else
                variant_allocate<Args...>::move(var_t, var_v, this_v);
        }

        static void copy(size_t var_t, const void* var_v, void* this_v)
        {
            if (var_t == typeid(Arg1).hash_code())
                new (this_v) Arg1(*reinterpret_cast<const Arg1*>(var_v));
            else if (var_t == typeid(Arg2).hash_code())
                new (this_v) Arg2(*reinterpret_cast<const Arg2*>(var_v));
            else if (var_t == typeid(Arg3).hash_code())
                new (this_v) Arg3(*reinterpret_cast<const Arg3*>(var_v));
            else
                variant_allocate<Args...>::copy(var_t, var_v, this_v);
        }
    };

    template <typename Arg1, typename Arg2>
    struct variant_allocate<Arg1, Arg2>
    {
        static void destroy(size_t id, void* data)
        {
            if (id == typeid(Arg1).hash_code())
                reinterpret_cast<Arg1*>(data)->~Arg1();
            else if (id == typeid(Arg2).hash_code())
                reinterpret_cast<Arg2*>(data)->~Arg2();
            else if(id != typeid(void).hash_code())
                throw std::bad_cast();
        }

        static void move(size_t var_t, void* var_v, void* this_v)
        {
            if (var_t == typeid(Arg1).hash_code())
                new (this_v) Arg1(std::move(*reinterpret_cast<Arg1*>(var_v)));
            else if (var_t == typeid(Arg2).hash_code())
                new (this_v) Arg2(std::move(*reinterpret_cast<Arg2*>(var_v)));
            else if(var_t != typeid(void).hash_code())
                throw std::bad_cast();      
        }

        static void copy(size_t var_t, const void* var_v, void* this_v)
        {
            if (var_t == typeid(Arg1).hash_code())
                new (this_v) Arg1(*reinterpret_cast<const Arg1*>(var_v));
            else if(var_t == typeid(Arg2).hash_code())
                new (this_v) Arg2(*reinterpret_cast<const Arg2*>(var_v));
            else if(var_t != typeid(void).hash_code())
                throw std::bad_cast();
        }
    };

    template <typename Arg>
    struct variant_allocate<Arg>
    {
        static void destroy(size_t id, void* data) 
        {
            if (id == typeid(Arg).hash_code())
                reinterpret_cast<Arg*>(data)->~Arg();
            else if(id != typeid(void).hash_code())
                throw std::bad_cast();
        }

        static void move(size_t var_t, void* var_v, void* this_v)
        {
            if (var_t == typeid(Arg).hash_code())
                new (this_v) Arg(std::move(*reinterpret_cast<Arg*>(var_v)));
            else if(var_t != typeid(void).hash_code())
                throw std::bad_cast();
        }
        
        static void copy(size_t var_t, const void* var_v, void* this_v) 
        {
            if (var_t == typeid(Arg).hash_code())
                new (this_v) Arg(*reinterpret_cast<const Arg*>(var_v));
            else if(var_t != typeid(void).hash_code())
                throw std::bad_cast();
        }
    };

    template<>
    struct variant_allocate<>
    {
        static void destroy(size_t id, void*) 
        {
            if(id != typeid(void).hash_code())
                throw std::bad_cast(); 
        }
        
        static void move(size_t var_t, void*, void*) 
        {
            if(var_t != typeid(void).hash_code())
                throw std::bad_cast(); 
        }
        
        static void copy(size_t var_t, const void*, void*) 
        {
            if(var_t != typeid(void).hash_code())
                throw std::bad_cast(); 
        }
    };
}


template<typename... Args> struct variant;


template <typename T> struct not_variant { using type = void; };
template <typename... Args> struct not_variant<variant<Args...>> {};


template <typename T>
concept bool NotVariant = requires { typename not_variant<T>::type; };


template<typename... Args>
struct variant
{
private:
    static const size_t data_size = detail::max_size<sizeof(Args)...>::value;
    static const size_t data_align = detail::max_size<alignof(Args)...>::value;

    using aligned_type = typename std::aligned_storage<data_size, data_align>::type;
    using allocator = detail::variant_allocate<Args...>;

    static inline size_t invalid_type() 
    {
        return typeid(void).hash_code();
    }

    size_t id;
    aligned_type data;

public:
    variant() : id(invalid_type()) {}

    variant(const variant<Args...>& var) : id(var.id)
    {
        allocator::copy(var.id, std::addressof(var.data), std::addressof(data));
    }

    variant(variant<Args...>&& var) : id(var.id)
    {
        allocator::move(var.id, std::addressof(var.data), std::addressof(data));
    }

    variant<Args...>& operator=(variant<Args...> var)
    {
        std::swap(id, var.id);
        std::swap(data, var.data);

        return *this;
    }

    template <NotVariant T>
    variant<Args...>& operator=(T&& t)
    {
        this->set(std::forward<T>(t));
        return *this;
    }

    template<NotVariant T>
    bool is() 
    {
        return (id == typeid(T).hash_code());
    }

    bool valid() 
    {
        return (id != invalid_type());
    }

    template<NotVariant T>
    void set(T&& t)
    {  
        allocator::destroy(id, std::addressof(data));
        new (std::addressof(data)) typename std::decay<T>::type(std::forward<T>(t));
        id = typeid(T).hash_code();
    }

    template<NotVariant T>
    T& get()
    {
        if (id == typeid(T).hash_code())
            return *reinterpret_cast<T*>(std::addressof(data));
        else
            throw std::bad_cast();
    }

    ~variant() 
    {
        allocator::destroy(id, std::addressof(data));
    }
};


