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
// 14.03.2021⠀⠀⠀⠀
//

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>
# include <iostream>

template<class T>
class MutantStack : public std::stack<T> {

public:
    class iterable {
    public:
        iterable()
        {
            this->_next = new iterable(this);
            this->_prev = 0;
            this->is_last = 0;
        }
        iterable(MutantStack::iterable *first)
        {
            first->_next = this;
            this->_prev = first;
            this->_next = 0;
            this->is_last = 1;
        }
        iterable(T &val, MutantStack::iterable *prev, MutantStack::iterable *last)
        {
            this->_val = val;
            this->_prev = prev;
            this->_next = last;
            last->_prev = this;
            this->is_last = 0;
        }
        void    addBack(T &val, MutantStack::iterable *first)
        {
            MutantStack::iterable *tmp = first;
            while (!tmp->_next->is_last)
            {
                tmp = tmp->_next;
            }
            tmp->_next = new iterable(val, tmp, tmp->_next);
        }
        ~iterable(void)
        {
        };
        void    setVal(T & val)
        {
            this->_val = val;
        }
        void   delBack(MutantStack::iterable *first)
        {

            MutantStack::iterable *tmp = first;
            while (!tmp->_next->is_last)
            {
                tmp = tmp->_next;
            }
            tmp->_prev->_next = tmp->_next;
            tmp->_next->_prev = tmp->_prev;
            delete tmp;
        }
        MutantStack::iterable    *_next;
        MutantStack::iterable    *_prev;
        T                        _val;
        bool                    is_last;
    private:
    };
    class iterator
    {
    public:
        iterator(void)
        {
            this->tmp = 0;
        }
        iterator(MutantStack::iterable *_able)
        {
            this->tmp = _able;
        }
        void    operator++()
        {
            if (!tmp->_next)
                throw std::exception();
            tmp = tmp->_next;
        }
        void    operator--()
        {
            if (!tmp->_prev)
                throw std::exception();
            tmp = tmp->_prev;
        }
        T &   operator*(void)
        {
            return tmp->_val;
        }
        void    setTmp(MutantStack::iterable *_able)
        {
            this->tmp = _able;
        }
        bool    operator!=(MutantStack::iterator& it)
        {
            return this->tmp != it.tmp;
        }
        MutantStack::iterable   *tmp;
    private:
    };
    MutantStack( void )
    {
        this->_it.setTmp(&_able);
        this->_ite.setTmp(_able._next);
    }
    ~MutantStack( void )
    {
        MutantStack::iterable*  tmp = _able._next;
        MutantStack::iterable*  tmp2;
        while (!tmp->is_last)
        {
            tmp2 = tmp->_next;
            delete tmp;
            tmp = tmp2;
        }
        delete tmp;
    }
    MutantStack::iterator& begin()
    {
        return _it;
    }
    MutantStack::iterator& end()
    {
        return _ite;
    }
    void    push(T val)
    {
        if ( this->empty())
            _able.setVal(val);
        else
        {
            _able.addBack(val, &_able);
        }
        std::stack<T>::push(val);
    }
    void    pop(void)
    {
        _able.delBack(&_able);
    }
private:
    MutantStack::iterable   _able;
    MutantStack::iterator   _it;
    MutantStack::iterator   _ite;
};

#endif
