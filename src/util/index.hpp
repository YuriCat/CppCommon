/*
 index.hpp
 Katsuki Ohto
 */

#ifndef UTIL_INDEX_HPP_
#define UTIL_INDEX_HPP_

// インデックス付け
template<int D>
struct TensorIndex{
    std::array<int, D> size_;
    
    template<typename ... args_t>
    TensorIndex(args_t ... args)
    :size_(){
        fill(args...);
    }
    
    constexpr void fill_sub(int d, int n){
        size_[d] = n;
    }
    template<typename ... args_t>
    void fill_sub(int d, int n, args_t ... args){
        fill_sub(d + 1, args...);
        size_[d] = size_[d + 1] * n;
    }
    template<typename ... args_t>
    void fill(args_t ... args){
        fill_sub(0, args...);
    }
    
    constexpr int get_sub(int d, int i){
        return i;
    }
    template<typename ... args_t>
    int get_sub(int d, int i, args_t ... args){
        return get_sub(d + 1, args...) + i * size_[d];
    }
    template<typename ... args_t>
    int get(args_t ... args){
        return get_sub(1, args...);
    }
};

#endif // UTIL_INDEX_HPP_