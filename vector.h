//
// Created by tipovitch on 2020-06-13.
//

#ifndef UNTITLED2_VECTOR_H
#define UNTITLED2_VECTOR_H

#include <iostream>
#include <memory>
#include <algorithm>

template <class T>
class Vector {
public:
    // Member types
    typedef T                                       value_type;
    typedef std::allocator<value_type>              allocator_type;
    typedef value_type&                             reference;
    typedef const value_type&                       const_reference;
    typedef value_type*                             pointer;
    typedef const value_type*                       const_pointer;
    typedef value_type*                             iterator;
    typedef const value_type*                       const_iterator;
    typedef std::reverse_iterator<iterator>         reverse_iterator;
    typedef const std::reverse_iterator<iterator>   const_reverse_iterator;
    typedef ptrdiff_t                               difference_type;
    typedef size_t                                  size_type;

    // Member functions
    // rule of three
    Vector() { create(); }
    explicit Vector(size_type n, const T& t = T{}) { create(n, t); }
    Vector(const Vector& v) { create(v.begin(), v.end()); }
    Vector& operator=(const Vector&);
    ~Vector() { uncreate(); }
    // Iterators
    iterator begin() { return array; }
    const_iterator begin() const { return array; }
    iterator end() { return array; }
    const_iterator end() const { return array; }
    reverse_iterator rbegin() noexcept;
    const_reverse_iterator rbegin() const noexcept;
    reverse_iterator rend() noexcept;
    const_reverse_iterator rend() const noexcept;
    const_iterator cbegin() const noexcept;
    const_iterator cend() const noexcept;
    const_reverse_iterator crbegin() const noexcept;
    const_reverse_iterator crend() const noexcept;
    // Capacity
    size_type size() const noexcept { return avail - array; }
    size_type max_size() const noexcept;
    void resize (size_type n);
    void resize (size_type n, const value_type& val);
    size_type capacity() const noexcept { return limit - array; }
    bool empty() const noexcept;
    void reserve (size_type n);
    void shrink_to_fit();
    // Element access
    reference operator[](size_type i) { return array[i]; }
    const_reference operator[](size_type i) const { return array[i]; }
    reference at (size_type n);
    const_reference at (size_type n) const;
    reference front();
    const_reference front() const;
    reference back();
    const_reference back() const;
    value_type* data() noexcept;
    const value_type* data() const noexcept;
    // Modifiers
    template <class InputIterator>
    void assign (InputIterator first, InputIterator last);
    void assign (size_type n, const value_type& val);
    void assign (std::initializer_list<value_type> il);
    // cia skliaustuose pagal reference buvo const value_type& va
    void push_back(const T& t) {
        if (avail == limit)
            grow();
        unchecked_append(t);
    }
    void push_back (value_type&& val);
    void pop_back();
    iterator insert (const_iterator position, const value_type& val);
    iterator insert (const_iterator position, size_type n, const value_type& val);
    template <class InputIterator>
        iterator insert (const_iterator position, InputIterator first, InputIterator last);
    iterator insert (const_iterator position, value_type&& val);
    iterator insert (const_iterator position, std::initializer_list<value_type> il);
    iterator erase (const_iterator position);
    iterator erase (const_iterator first, const_iterator last);
    void swap (Vector& x);
    void clear() noexcept;
    template <class... Args>
        iterator emplace (const_iterator position, Args&&... args);
    template <class... Args>
        void emplace_back (Args&&... args);
    // Allocator
//    allocator_type get_allocator() const noexcept;
    // Non-member function overloads
//    template <class T, class Alloc>
//        bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
//    template <class T, class Alloc>
//        bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
//    template <class T, class Alloc>
//        bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
//    template <class T, class Alloc>
//        bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
//    template <class T, class Alloc>
//        bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
//    template <class T, class Alloc>
//        bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
//    template <class T, class Alloc>
//        void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
    // Template specializations
//    template < class T, class Alloc = allocator<T> > class vector; // generic template
//    template <class Alloc> class vector<bool,Alloc>;               // bool specialization
    // likusi interfeiso realizacija
private:
    iterator array;  // pakeista iš T* į iterator
    iterator avail; // pirmasis po paskutiniojo sukonstruoto Vector elementas
    iterator limit; // pakeista iš T* į iterator

    // atminties išskyrimo valdymui
    std::allocator<T> alloc; // objektas atminties valdymui
    // išskirti atmintį (array) ir ją inicializuoti
    void create();
    void create(size_type, const T&);
    void create(const_iterator, const_iterator);
    // sunaikinti elementus array ir atlaisvinti atmintį
    void uncreate();
    // pagalbinės funkcijos push_back realizacijai
    void grow();
    void unchecked_append(const T&);
};

template <class T>
    void Vector<T>::create() {
        array = avail = limit = nullptr;
    }
template <class T>
    void Vector<T>::create(size_type n, const T& val) {
        array = alloc.allocate(n); // grąžina ptr į array pirmą elementą
        limit = avail = array + n; // sustato rodykles į vietas
        std::uninitialized_fill(array, limit, val); // inicializuoja elementus val reikšme
    }
template <class T>
    void Vector<T>::create(const_iterator i, const_iterator j) {
        array = alloc.allocate(j - i); // išskirti vietos j-i elementams
        limit = avail = std::uninitialized_copy(i, j, array); // nukopijuoja elementus iš intervalo
    }

template <class T>
    void Vector<T>::uncreate() {
        if (array) {
            // sunaikinti (atbuline tvarka) sukonstruotus elementus
            iterator it = avail;
            while (it != array)
                alloc.destroy(--it);
            // atlaisvinti išskirtą atmintį. Turi būti data != nullptr
            alloc.deallocate(array, limit - array);
        }
        // reset'inam pointer'iuss - Vector'ius tuščias
        array = limit = avail = nullptr;
    }

template <class T>
    void Vector<T>::grow() {
        // dvigubai daugiau vietos, nei buvo
        size_type new_size = std::max(2 * (limit - array), ptrdiff_t(1));
        // išskirti naują vietą ir perkopijuoti egzistuojančius elementus
        iterator new_data = alloc.allocate(new_size);
        iterator new_avail = std::uninitialized_copy(array, avail, new_data);
        // atlaisvinti seną vietą
        uncreate();
        // reset'int rodykles į naujai išskirtą vietą
        array = new_data;
        avail = new_avail;
        limit = array + new_size;
    }
// tariame, kad `avail` point'ina į išskirtą, bet neinicializuotą vietą
template <class T>
    void Vector<T>::unchecked_append(const T& val) {
        alloc.construct(avail++, val);
    }

// priskyrimo operatoriaus realizacija
template <class T>
    Vector<T>& Vector<T>::operator=(const Vector& rhs) {
        // patikriname ar ne lygu
        if (&rhs != this) {
            // atlaisviname seną this objekto atmintį
            uncreate();
            // perkopijuojame elementus iš rhs į lhs (this)
            create(rhs.begin(), rhs.end());
        }
        return *this;
    }

template<class T> class allocator {
public:
    T* allocate(size_t);            // išskirti `raw` atmintį
    void deallocate(T*, size_t);    // atlaisvinti atmintį
    void construct(T*, const T&);   // sukonstruoti 1 objektą
    void destroy(T*);               // sunaikinti 1 objektą
};







#endif //UNTITLED2_VECTOR_H
