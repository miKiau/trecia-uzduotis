//
// Created by tipovitch on 2020-06-13.
//

#ifndef UNTITLED2_VECTOR_H
#define UNTITLED2_VECTOR_H

#include <iostream>
#include <memory>
#include <algorithm>
#include <cmath>

//template<class T> class allocator {
//public:
//    T* allocate(size_t);            // išskirti `raw` atmintį
//    void deallocate(T*, size_t);    // atlaisvinti atmintį
//    void construct(T*, const T&);   // sukonstruoti 1 objektą
//    void destroy(T*);               // sunaikinti 1 objektą
//};

template <class T> class Vector {
public:
    // Member types
    typedef T                                               value_type;
    typedef std::allocator<value_type>                      allocator_type;
    typedef value_type&                                     reference;
    typedef const value_type&                               const_reference;
    typedef value_type*                                     pointer;
    typedef const value_type*                               const_pointer;
    typedef value_type*                                     iterator;
    typedef const value_type*                               const_iterator;
    typedef std::reverse_iterator<iterator>                 reverse_iterator;
    typedef const std::reverse_iterator<const_iterator>     const_reverse_iterator;
    typedef ptrdiff_t                                       difference_type;
    typedef size_t                                          size_type;

    // Member functions
    Vector() { create(); }
    explicit Vector(const allocator_type& alloc) : alloc{alloc} { create();}
    explicit Vector(size_type n, const allocator_type& alloc = allocator_type()) : alloc{alloc} { create(n);}
    Vector(size_type n, const value_type& val, const allocator_type& alloc = allocator_type()) : alloc{alloc} { create(n, val);}

    template <class InputIterator>
    Vector (InputIterator first, InputIterator last,
            const allocator_type& alloc = allocator_type()) : alloc{alloc} { create(first, last);}

    Vector(const Vector& v) { create(v.begin(), v.end()); }
    Vector(const Vector& x, const allocator_type& alloc) : alloc {alloc} { create(x.begin(), x.end()); }

    Vector(Vector&& x) noexcept { create(x.begin(), x.end()); }
    Vector(Vector&& x, const allocator_type& alloc) : alloc {*alloc} { create(x.begin(), x.end()); }

    Vector(std::initializer_list<value_type> il, const allocator_type& alloc = allocator_type()) : alloc {alloc}
    { create(il.begin(), il.end()); }

    ~Vector(){ uncreate(); }
    Vector& operator=(const Vector&);
    Vector& operator=(Vector&& x);
    Vector& operator=(std::initializer_list<value_type> il);

    // Iterators
    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;
    reverse_iterator rbegin() noexcept;
    const_reverse_iterator rbegin() const noexcept;
    reverse_iterator rend() noexcept;
    const_reverse_iterator rend() const noexcept;
    const_iterator cbegin() const noexcept;
    const_iterator cend() const noexcept;
    const_reverse_iterator crbegin() const noexcept;
    const_reverse_iterator crend() const noexcept;

    // Capacity
    size_type size() const noexcept;
    size_type max_size() const noexcept;
    void resize(size_type n);
    void resize(size_type n, const value_type& val);
    size_type capacity() const noexcept;
    bool empty() const noexcept;
    void reserve(size_type n);
    void shrink_to_fit();

    // Element access
    reference operator[](size_type i);
    const_reference operator[](size_type i) const;
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
    void push_back(const value_type& t);
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
    allocator_type get_allocator() const noexcept;

    // Non-member function overloads
    bool operator== (const Vector<T>& rhs);
    bool operator!= (const Vector<T>& rhs);
    bool operator<  (const Vector<T>& rhs);
    bool operator<= (const Vector<T>& rhs);
    bool operator>  (const Vector<T>& rhs);
    bool operator>= (const Vector<T>& rhs);
    void swap (Vector<T>& x, Vector<T>& y);

    // likusi interfeiso realizacija
private:
    // rodyklė į pirmo elemento adresą arba nullptr
    iterator start;
    // rodyklė į pirmąjį po paskutiniojo inicializuoto Vector elemento adresą
    iterator avail;
    // rodyklė į po paskutinio paskirto, bet neinicializuoto ele. adresą
    iterator limit;
    // objektas atminties valdymui
    allocator_type alloc;

    // išskirti atmintį (array) ir ją inicializuoti
    void create();
    void create(size_type n);
    void create(size_type, const T&);
    void create(const_iterator, const_iterator);
    // sunaikinti elementus array ir atlaisvinti atmintį
    void uncreate();
    // pagalbinės funkcijos push_back realizacijai
    // Padidina per vieną elementą
    void grow();
    // Padidina per vieną elementą, bet nepatikrina
    void unchecked_append(const T&);
    void unchecked_append(const T&& val);
};
//----------------------------------------------------------------------------------------------
// Member functions
// priskyrimo operatoriaus realizacija
template <class T>
    Vector<T>& Vector<T>::operator=(const Vector& rhs) {
        if (&rhs != this) {
            uncreate();
            create(rhs.begin(), rhs.end());
        }
        return *this;
    }
template <class T>
    Vector<T>& Vector<T>::operator=(Vector<T>&& x) {
        if (this != &x) {
            uncreate();
            create(x.begin(), x.end());
        }
        return *this;
    }
template <class T>
    Vector<T>& Vector<T>::operator=(std::initializer_list<value_type> il) {
        uncreate();
        create(il.begin(), il.end());
        return *this;
    }
//----------------------------------------------------------------------------------------------
// Iterators
template <class T>
    T* Vector<T>::begin() { return start; }

template <class T>
    const T*  Vector<T>::begin() const { return start; }

template <class T>
    T* Vector<T>::end() { return avail; }

template <class T>
    const T*  Vector<T>::end() const { return avail; }

template <class T>
    std::reverse_iterator<T*> Vector<T>::rbegin() noexcept {
        return (std::reverse_iterator<T*>)avail;
    }

template <class T>
const std::reverse_iterator<const T*> Vector<T>::rbegin() const noexcept {
    return (std::reverse_iterator<const T*>)avail;
}

template <class T>
std::reverse_iterator<T*> Vector<T>::rend() noexcept {
    return (std::reverse_iterator<T*>)start;
}

template <class T>
const std::reverse_iterator<const T*> Vector<T>::rend() const noexcept {
    return (std::reverse_iterator<const T*>)start;
}

template <class T>
const T*  Vector<T>::cbegin() const noexcept { return start; }

template <class T>
const T*  Vector<T>::cend() const noexcept { return avail; }

template <class T>
const std::reverse_iterator<const T*> Vector<T>::crbegin() const noexcept {
    return (std::reverse_iterator<const T*>)avail;
}

template <class T>
const std::reverse_iterator<const T*> Vector<T>::crend() const noexcept {
    return (std::reverse_iterator<const T*>)start;
}
//----------------------------------------------------------------------------------------------
// Capacity
template <class T>
    size_t Vector<T>::size() const noexcept {
        return avail - start;
    }
template <class T>
    size_t Vector<T>::max_size() const noexcept {
        return (pow(2, sizeof(T*)*8)) / sizeof(T) - 1;
    }
template <class T>
    void Vector<T>::resize(size_type n) {
        this->resize(n, 0);
    }
template <class T>
    void Vector<T>::resize(size_type n, const value_type& val) {
        if (n > this->size() && n > this->capacity()) {
            size_type new_size = n;
            iterator new_start = alloc.allocate(new_size);
            // perkopijuoja ir atiduota rodyklę į adresą po masyvo paskutinio inicia. ele.
            iterator new_avail = std::uninitialized_copy(start, avail, new_start);
            uncreate();

            start = new_start;
            avail = new_avail;
            limit = new_start + new_size;
            // tiek elementų reikia dar papildomai inicializuoti
            for (int i = 0, until = n - this->size(); i < until; ++i)
                unchecked_append(val);
        }
        else if (n > this->size()) {
            auto it = start + n;
            while (avail != it) {
                unchecked_append(val);
            }
        }
        else if (n < this->size()) {
            size_type new_size = n;
            iterator new_start = alloc.allocate(new_size);
            // kiek reikia nukopijuoti
            size_type copy_until = this->size() - n;
            iterator new_avail = std::uninitialized_copy(start, avail - copy_until, new_start);
            uncreate();
            start = new_start;
            avail = new_avail;
            limit = start + new_size;
//            limit = avail;
//            size_type difference = this->size() - n + 1;
//            iterator current = avail = start + difference;
//            std::cout << "start reiksme10: " << *start << " " << this->size() << " " << this->capacity() << '\n';
//            while (current != limit)
//                alloc.destroy(++current);
//            std::cout << difference << ' ';
//            alloc.deallocate(avail, 10);
//            limit = avail;
//            std::cout << "HOORAHHH\n";

//            // sunaikinti (atbuline tvarka) sukonstruotus elementus
//            iterator it = avail;
//            while (it != start)
//                alloc.destroy(--it);
//            // atlaisvinti išskirtą atmintį. Turi būti data != nullptr
//            alloc.deallocate(start, limit - start);
        }
    }
template <class T>
    size_t Vector<T>::capacity() const noexcept {
        return limit - start;
    }
template <class T>
    bool Vector<T>::empty() const noexcept {
        return start != nullptr;
    }
template <class T>
    void Vector<T>::reserve(size_type n) {
        if (n > this->capacity()) {
            size_type new_size = n;
            // išskirti naują vietą
            iterator new_start = alloc.allocate(new_size);
            // perkopijuoja ir atiduota rodyklę į adresą po masyvo paskutinio inicia. ele.
            iterator new_avail = std::uninitialized_copy(start, avail, new_start);
            // atlaisvina seną vietą
            uncreate();
            // reset'int rodykles į naujai išskirtą vietą
            start = new_start;
            avail = new_avail;
            limit = start + new_size;
        }
    }
template <class T>
    void Vector<T>::shrink_to_fit() {
        if (avail != limit) limit = avail;
    }
//----------------------------------------------------------------------------------------------
// Element access
template <class T>
    T& Vector<T>::operator[](size_type i) { return start[i]; }
template <class T>
    const T& Vector<T>::operator[](size_type i) const { return start[i]; }
template <class T>
    T& Vector<T>::at(size_type n) {
        if (n >= this->capacity())
            throw std::out_of_range("Vector klasės elementas bando paimti elementą už apibrėžtos ribos");
        return start[n];
    }
template <class T>
    const T& Vector<T>::at(size_type n) const {
        if (n >= this->capacity())
            throw std::out_of_range("Vector klasės elementas bando paimti elementą už apibrėžtos ribos");
        else start[n];
    }
template <class T>
    T& Vector<T>::front() {return &start;}
template <class T>
    const T& Vector<T>::front() const {return &start;}
template <class T>
    T& Vector<T>::back() {return &(avail - 1);}
template <class T>
    const T& Vector<T>::back() const {return &(avail - 1);}
template <class T>
    T* Vector<T>::data() noexcept {return start;}
template <class T>
    const T* Vector<T>::data() const noexcept {return start;}
//----------------------------------------------------------------------------------------------
// Modifiers
template <class T>
template <class InputIterator>
    void Vector<T>::assign(InputIterator first, InputIterator last) {
        uncreate();
        create(first, last);
    }
template <class T>
    void Vector<T>::assign(size_type n, const value_type& val) {
        uncreate();
        create(n, val);
    }
template <class T>
    void Vector<T>::assign(std::initializer_list<value_type> il) {
        uncreate();
        create(il.begin(), il.end());
    }
template <class T>
    void Vector<T>::push_back(const value_type& t) {
        if (avail == limit)
            grow();
        unchecked_append(t);
    }
template <class T>
    void Vector<T>::push_back(value_type&& val) {
        if (avail == limit)
            grow();
        unchecked_append(std::move(val));
    }
template <class T>
    void Vector<T>::pop_back() {
        if (start) {
            size_type tmp = this->capacity();
            alloc.destroy(--avail);
        }
    }
template <class T>
    T* Vector<T>::insert (const_iterator position, const value_type& val) {
        iterator return_position;
        if (position >= start && position <= limit) {
            if (limit != avail) {
                iterator it = avail;
                while (position != it) {
                    --it;
                    *(it+1) = *it;
                }
                *position = val;
            }
            else {
                Vector<T> tmp(this->start, min(position, avail));
                return_position = tmp.avail;
                tmp.push_back(val);
                for (iterator it = position; it < avail; ++it)
                    tmp.push_back(*it);
                uncreate();

                this->start = tmp.begin();
                this->avail = tmp.end();
                this->limit = tmp.end();
                this->alloc = tmp.get_allocator();
            }
        } else throw std::runtime_error("Wrong iterator in Vector::insert function");
        return return_position;
    }

template <class T>
    T* Vector<T>::insert (const_iterator position, size_type n, const value_type& val) {
        iterator current = insert(position, val);
        for (int i = 0; i < n - 1; ++i) {
            ++current;
            current = insert(current, val);
        }
        return current;
    }
template <class T>
template <class InputIterator>
    T* Vector<T>::insert (const_iterator position, InputIterator first, InputIterator last) {
        iterator current;
        while (first != last)
            current++ = insert(position, *first++);
}

template <class T>
    T* Vector<T>::insert (const_iterator position, value_type&& val) {
        return insert(position, std::move(val));
    }

template <class T>
    T* Vector<T>::insert (const_iterator position, std::initializer_list<value_type> il) {
        return insert(position, il.begin(), il.end());
    }

template <class T>
    T* Vector<T>::erase (const_iterator position) {}

template <class T>
    T* Vector<T>::erase (const_iterator first, const_iterator last) {}

template <class T>
    void Vector<T>::swap (Vector& x) {
        iterator new_start = start,
                 new_avail = avail;
        allocator_type new_alloc = alloc;
        size_type n_this = this->capacity(),
                  n_x = x.capacity();

        create(x.begin(), x.end());
        this->reserve(n_x);
        x.~Vector();

        Vector<T> tmp(new_start, new_avail, new_alloc);
        tmp.reserve(n_this);
        x = tmp;
    }

template <class T>
    void Vector<T>::clear() noexcept {}

template <class T>
template <class... Args>
    T* Vector<T>::emplace (const_iterator position, Args&&... args)  {}

template <class T>
template <class... Args>
    void Vector<T>::emplace_back (Args&&... args) {}

//-------------------------------------------------------------------
// Allocator
template<class T>
    std::allocator<T> Vector<T>::get_allocator() const noexcept {
        return alloc;
    }
//-------------------------------------------------------------------
template <class T>
    bool Vector<T>::operator== (const Vector<T>& rhs) {
        if (this->size() == rhs.size() && this->capacity() == rhs.capacity()) {
            iterator it = start;
            for (const auto& e : rhs) {
                if (e != *it) return false;
                ++it;
            }
            return true;
        }
        return NULL;
    }
template <class T>
    bool Vector<T>::operator!= (const Vector<T>& rhs) {
    if (this->size() == rhs.size() && this->capacity() == rhs.capacity()) {
        iterator it = start;
        for (const auto& e : rhs) {
            if (e == *it) return false;
            ++it;
        }
        return true;
    }
    return NULL;
}
template <class T>
    bool Vector<T>::operator<  (const Vector<T>& rhs) {
    if (this->size() == rhs.size() && this->capacity() == rhs.capacity()) {
        iterator it = start;
        for (const auto& e : rhs) {
            if (e <= *it) return false;
            ++it;
        }
        return true;
    }
    return NULL;
}
template <class T>
    bool Vector<T>::operator<= (const Vector<T>& rhs) {
    if (this->size() == rhs.size() && this->capacity() == rhs.capacity()) {
        iterator it = start;
        for (const auto& e : rhs) {
            if (*it > e) return false;
            ++it;
        }
        return true;
    }
    return NULL;
}
template <class T>
    bool Vector<T>::operator>  (const Vector<T>& rhs) {
    if (this->size() == rhs.size() && this->capacity() == rhs.capacity()) {
        iterator it = start;
        for (const auto& e : rhs) {
            if (*it <= e) return false;
            ++it;
        }
        return true;
    }
    return NULL;
}
template <class T>
    bool Vector<T>::operator>= (const Vector<T>& rhs) {
    if (this->size() == rhs.size() && this->capacity() == rhs.capacity()) {
        iterator it = start;
        for (const auto& e : rhs) {
            if (*it < e) return false;
            ++it;
        }
        return true;
    }
    return NULL;
}
template <class T>
    void Vector<T>::swap (Vector<T>& x, Vector<T>& y) {
        Vector<T> tmp = x;
        x = y;
        y = tmp;
    }

// Pagalbinės funkcijos
template <class T>
    void Vector<T>::create() {
        start = avail = limit = nullptr;
    }
template <class T>
    void Vector<T>::create(size_type n) {
        // apibrėžia n vietų masyvą ir grąžina ptr į pirmą elementą
        start = alloc.allocate(n);
        limit = avail = start + n; // sustato rodykles į vietas
    }
template <class T>
    void Vector<T>::create(size_type n, const T& val) {
        // apibrėžia n vietų masyvą ir grąžina ptr į pirmą elementą
        start = alloc.allocate(n);
        limit = avail = start + n; // sustato rodykles į vietas
        std::uninitialized_fill(start, limit, val); // inicializuoja elementus val reikšme
    }
template <class T>
    void Vector<T>::create(const_iterator i, const_iterator j) {
        start = alloc.allocate(j - i); // išskirti vietos j-i elementams
        limit = avail = std::uninitialized_copy(i, j, start); // nukopijuoja elementus iš intervalo
    }

template <class T>
    void Vector<T>::uncreate() {
        if (start) {
            // sunaikinti (atbuline tvarka) sukonstruotus elementus
            iterator it = avail;
            while (it != start)
                alloc.destroy(--it);
            // atlaisvinti išskirtą atmintį. Turi būti data != nullptr
            alloc.deallocate(start, limit - start);
        }
        // reset'inam pointer'iuss - Vector'ius tuščias
        start = limit = avail = nullptr;
    }

template <class T>
    void Vector<T>::grow() {
        // dvigubai daugiau vietos, nei buvo
        size_type new_size = std::max(2 * (limit - start), difference_type(1));
        // išskirti naują vietą
        iterator new_start = alloc.allocate(new_size);
        // perkopijuoja ir atiduota rodyklę į adresą po paskutinio inicializuoto ele.
        iterator new_avail = std::uninitialized_copy(start, avail, new_start);
        // atlaisvinti seną vietą
        uncreate();
        // reset'int rodykles į naujai išskirtą vietą
        start = new_start;
        avail = new_avail;
        limit = start + new_size;
    }
// tariame, kad `avail` point'ina į išskirtą, bet neinicializuotą vietą
template <class T>
    void Vector<T>::unchecked_append(const T& val) {
        alloc.construct(avail++, val);
    }

template <class T>
    void Vector<T>::unchecked_append(const T&& val) {
        alloc.construct(avail++, val);
    }
//----------------------------------------------------------------------------------------------
// template specializations are gone
//----------------------------------------------------------------------------------------------

#endif //UNTITLED2_VECTOR_H
