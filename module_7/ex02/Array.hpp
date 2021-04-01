//
//                                       ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣠⣴⣖⣁⣀⣀⡄⠀⠀⠀
//                                       ⠀⠀⠀⠀⠀⠀⢀⣀⣠⣴⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⣤⣄⣀⣀
//                                      ⠀⠀⠀⠀⠀⠀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠛⠁
//                                      ⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠛⠁⠀
//                                      ⠀⠀⠀⠀⠀⣼⣿⡟⠀⢠⡲⠖⠀⣿⣿⣿⣿⣿⣿⣿⣉⠁⠀⠀⠀
//  ╱╱╱╱╭━╮╭╮                               ⣼⣿⣿⡷⢤⠤⠤⣥⡤⣿⠿⣿⣿⣿⡿⣿⣿⣷⡀
//  ╱╱╱╱┃╭╯┃┃                           ⠀⣀⣠⣼⣿⣿⣿⣧⠑⠟⠀⠈⠙⠱⢦⣿⣿⣿⠁⣸⣿⣿⣇⠀
//  ╭━━┳╯╰┳┫┃╭━━╮                       ⠊⠉⠉⠉⠉⠩⠞⠁⠀⠀⠄⠀⠀⡴⣿⣿⣿⠗⣵⣿⠡⠉⠉⠁⠀
//  ┃╭╮┣╮╭╋┫┃┃┃━┫                              ⠀⢡⠀⠀⠀⢈⣾⣟⣵⣯⣼⣿⣬⣄⣀⠀⠀
//  ┃╰╯┃┃┃┃┃╰┫┃━┫                           ⠀⠀⣶⣶⣶⣾⣥⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀
//  ┃╭━╯╰╯╰┻━┻━━╯                           ⠀⢺⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⡄
//  ┃┃                                     ⢠⢤⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⣿⣿⣿⡄
//  ╰╯                                  ⠀⠠⣰⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠇⠀
// 10.03.2021⠀⠀⠀⠀
//

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include "iter.hpp"

template<typename X>
void    out(X& val)
{
    std::cout << std::setiosflags(std::ios::fixed) << val << std::endl;
}

template< class S >
class Array {

public:

    Array<S>( void ) : _len(0)
    {
        _arr = nullptr;
    };
    Array<S>( unsigned int k ) : _len(k) {
        _arr = new S[k];
        iter<S>( this->_arr, (int)k, def<S>);
    };

    Array<S>( Array<S> const &src ) {
        this->_arr = src.getArr();
        this->_len = src.size();
    };

    ~Array<S>( void ) {
        delete [] _arr;
    };

    Array<S> &operator=( Array<S> const &rhs ) {
        delete [] this->_arr;
        this->_arr = rhs.getArr();
        this->_len = rhs.size();
        return *this;
    };

    S *getArr() const {
        S   *ret = new S[this->size()];
        for (unsigned int i = 0;i < this->_len;i++)
        {
            ret[i] = this->_arr[i];
        }
        return ret;
    };

    unsigned int size() const;

    S const&  operator[]( const int ind ) const {
        if (ind >= (int)this->size() or ind < 0)
            throw std::exception();
        return this->_arr[ind];
    };

private:
    S               *_arr;
    unsigned int    _len;
};

template<typename T>
std::ostream &  operator<<(std::ostream & o, Array<T> const & arr)
{
    T *tmp;
    tmp = arr.getArr();
    o << "arr: size - " << arr.size() << " elements: - " << std::endl;
    iter(tmp, arr.size(), out);
    delete tmp;
    return o;
}

template <typename S>
unsigned int Array<S>::size() const {
    return this->_len;
};

#endif
