Laiko testavimo rezultatai:

Elementų skaičius: 100000 -> 10^5
std::vector užtruko: 0.00299163s
Vector užtruko: 0.00307284s
Skirtumas: 8.1214e-05s

Elementų skaičius: 1000000 -> 10^6
std::vector užtruko: 0.0247323s
Vector užtruko: 0.0221908s
Skirtumas: -0.00254154s

Elementų skaičius: 10000000 -> 10^7
std::vector užtruko: 0.216725s
Vector užtruko: 0.239996s
Skirtumas: 0.0232714s

Elementų skaičius: 100000000 -> 10^8
std::vector užtruko: 2.02915s
Vector užtruko: 2.21573s
Skirtumas: 0.186574s

std::vector atliko perskirstymų: 134217728
Vector atliko perskirstymų: 134217728


Tapatumo tikrinimas:

Member functions:
1) konstruktoriai (pvz iš http://www.cplusplus.com/reference/vector/vector/vector/)
    a. std::vector rezultatas:
        The contents of fifth are: 16 2 77 29
    b. Vector rezultatas:
        The contents of fifth are: 16 2 77 29
    Išvada: veikia taip pat.
2) destruktorius (http://www.cplusplus.com/reference/vector/vector/~vector/)
    Veikia taip pat, bet prieiga kitokia, kadangi mano Vector klasėje jis yra public priėjimo tipo
3) operator= (http://www.cplusplus.com/reference/vector/vector/operator=/)
    a. std::vector rezultatas:
        Size of foo: 0
        Size of bar: 3
    b. Vector rezultatas:
        Size of foo: 0
        Size of bar: 3
    Išvada: veikia taip pat.

Iterators:
1) begin() (pvz iš http://www.cplusplus.com/reference/vector/vector/begin/)
    a. std::vector rezultatas:
        myvector contains: 1 2 3 4 5
    b. Vector rezultatas:
        myvector contains: 1 2 3 4 5
    Išvada: veikia taip pat.

2) end() (pvz iš http://www.cplusplus.com/reference/vector/vector/end/)
    a. std::vector rezultatas:
        myvector contains: 1 2 3 4 5
    b. Vector rezultatas:
        myvector contains: 1 2 3 4 5
    Išvada: veikia taip pat.

3) rbegin() (pvz iš http://www.cplusplus.com/reference/vector/vector/rbegin/)
    a. std::vector rezultatas:
        myvector contains: 5 4 3 2 1
    b. Vector rezultatas:
        myvector contains: 5 4 3 2 1
    Išvada: veikia taip pat.

4) rend() (pvz iš http://www.cplusplus.com/reference/vector/vector/rend/)
    a. std::vector rezultatas:
        myvector contains: 5 4 3 2 1
    b. Vector rezultatas:
        myvector contains: 5 4 3 2 1
    Išvada: veikia taip pat.

5) cbegin() (pvz iš http://www.cplusplus.com/reference/vector/vector/cbegin/)
    a. std::vector rezultatas:
        myvector contains: 10 20 30 40 50
    b. Vector rezultatas: nepilnai padaryti konstruktoriai
        myvector contains: 10 20 30 40 50
    Išvada: veikia taip pat.

6) cend() (pvz iš http://www.cplusplus.com/reference/vector/vector/cend/)
    a. std::vector rezultatas:
        myvector contains: 10 20 30 40 50
    b. Vector rezultatas:
        myvector contains: 10 20 30 40 50
    Išvada: veikia taip pat.

7) crbegin() (pvz iš http://www.cplusplus.com/reference/vector/vector/crbegin/)
    a. std::vector rezultatas:
        myvector backwards: 5 4 3 2 1
    b. Vector rezultatas:
        myvector backwards: 5 4 3 2 1
    Išvada: veikia taip pat.

8) crend() (pvz iš http://www.cplusplus.com/reference/vector/vector/crend/)
    a. std::vector rezultatas:
        myvector backwards: 5 4 3 2 1
    b. Vector rezultatas:
        myvector backwards: 5 4 3 2 1
    Išvada: veikia taip pat.

Capacity:
1) size() (pvz iš http://www.cplusplus.com/reference/vector/vector/size/)
   negali atlikti pavyzdžio
2) max_size() (pvz iš http://www.cplusplus.com/reference/vector/vector/max_size/)
    a. std::vector rezultatas:
        size: 100
        capacity: 128
        max_size: 4611686018427387903
    b. Vector rezultatas:
        size: 100
        capacity: 128
        max_size: 4611686018427387904
    Išvada: skiriasi per 1.
3) resize() (pvz iš http://www.cplusplus.com/reference/vector/vector/resize/)
    a. std::vector rezultatas:
        myvector contains: 1 2 3 4 5 100 100 100 0 0 0 0
    b. Vector rezultatas:
        myvector contains: 1 2 3 4 5 100 100 100 0 0 0 0
    Išvada: veikia taip pat.
4) capacity() (pvz iš http://www.cplusplus.com/reference/vector/vector/capacity/)
    a. std::vector rezultatas:
        size: 100
        capacity: 128
        max_size: 4611686018427387903
    b. Vector rezultatas:
        size: 100
        capacity: 128
        max_size: 4611686018427387904
    Išvada: veikia taip pat.
5) empty() (pvz iš http://www.cplusplus.com/reference/vector/vector/empty/)
    a. std::vector rezultatas:
        total: 55
    b. Vector rezultatas:
        total: 55
    Išvada: veikia taip pat.
6) reserve() (pvz iš http://www.cplusplus.com/reference/vector/vector/reserve/)
    a. std::vector rezultatas:
        making foo grow:
        capacity changed: 1
        capacity changed: 2
        capacity changed: 4
        capacity changed: 8
        capacity changed: 16
        capacity changed: 32
        capacity changed: 64
        capacity changed: 128
        making bar grow:
        capacity changed: 100
    b. Vector rezultatas:
        making foo grow:
        capacity changed: 1
        capacity changed: 2
        capacity changed: 4
        capacity changed: 8
        capacity changed: 16
        capacity changed: 32
        capacity changed: 64
        capacity changed: 128
        making bar grow:
        capacity changed: 100
    Išvada: veikia taip pat.
7) shrink_to_fit() (pvz iš http://www.cplusplus.com/reference/vector/vector/shrink_to_fit/)
    a. std::vector rezultatas:
        1. capacity of myvector: 100
        2. capacity of myvector: 100
        3. capacity of myvector: 10
    b. Vector rezultatas:
        1. capacity of myvector: 100
        2. capacity of myvector: 10
        3. capacity of myvector: 10
    Išvada: skirtingas atlikimas, nes mano resize() funkcija nukerpa ir pernaujo perskirsto

Element access:
1) operator[] (pvz iš http://www.cplusplus.com/reference/vector/vector/operator[]/)
    a. std::vector rezultatas:
        myvector contains: 9 8 7 6 5 4 3 2 1 0
    b. Vector rezultatas:
        myvector contains: 9 8 7 6 5 4 3 2 1 0
    Išvada: veikia taip pat.
2) at() (pvz iš http://www.cplusplus.com/reference/vector/vector/at/)
    a. std::vector rezultatas:
        myvector contains: 0 1 2 3 4 5 6 7 8 9
    b. Vector rezultatas:
        myvector contains: 0 1 2 3 4 5 6 7 8 9
    Išvada: veikia taip pat.
3) front() (pvz iš http://www.cplusplus.com/reference/vector/vector/shrink_to_fit/)
    negali atlikti pavyzdžio
4) back() (pvz iš http://www.cplusplus.com/reference/vector/vector/shrink_to_fit/)
    negali atlikti pavyzdžio
5) data() (pvz iš http://www.cplusplus.com/reference/vector/vector/data/)
    a. std::vector rezultatas:
        myvector contains: 10 20 0 100 0
    b. Vector rezultatas:
        myvector contains: 10 20 0 100 0
    Išvada: veikia taip pat.


Modifiers:
1) assign (pvz iš http://www.cplusplus.com/reference/vector/vector/assign/)
    a. std::vector rezultatas:
        Size of first: 7
        Size of second: 5
        Size of third: 3
    b. Vector rezultatas:
        Size of first: 7
        Size of second: 5
        Size of third: 3
    Išvada: veikia taip pat.
2) push_back (pvz iš http://www.cplusplus.com/reference/vector/vector/push_back/)
    a. std::vector rezultatas:
        input: 5 6 8 9 1 0 -> output: myvector stores 6 numbers.
    b. Vector rezultatas:
        input: 5 6 8 9 1 0 -> output: myvector stores 6 numbers.
    Išvada: veikia taip pat.
3) pop_back (pvz iš http://www.cplusplus.com/reference/vector/vector/pop_back/)
    neveikia
4) insert (pvz iš http://www.cplusplus.com/reference/vector/vector/insert/)
    neveikia
5) erase (pvz iš http://www.cplusplus.com/reference/vector/vector/erase/)
    neveikia
6) swap (pvz iš http://www.cplusplus.com/reference/vector/vector/swap/)
    a. std::vector rezultatas:
        foo contains: 200 200 200 200 200
        bar contains: 100 100 100
    b. Vector rezultatas:
        foo contains: 200 200 200 200 200
        bar contains: 100 100 100
    Išvada: veikia taip pat.
7) clear (pvz iš http://www.cplusplus.com/reference/vector/vector/clear/)
    neveikia
8) emplace (pvz iš http://www.cplusplus.com/reference/vector/vector/emplace/)
    neveikia
9) emplace_back (pvz iš http://www.cplusplus.com/reference/vector/vector/emplace_back/)
    neveikia

Allocator:
1) get_allocator (pvz iš http://www.cplusplus.com/reference/vector/vector/get_allocator/)
    a. std::vector rezultatas:
        The allocated array contains: 0 1 2 3 4
    b. Vector rezultatas:
        The allocated array contains: 0 1 2 3 4
    Išvada: veikia taip pat.

Non-member function overloads:
1) relational operators (pvz iš http://www.cplusplus.com/reference/vector/vector/operators/)
    neveikia
2) swap() (pvz iš http://www.cplusplus.com/reference/vector/vector/swap-free/)
    a. std::vector rezultatas:
        foo contains: 200 200 200 200 200
        bar contains: 100 100 100
    b. Vector rezultatas:
        foo contains: 200 200 200 200 200
        bar contains: 100 100 100
    Išvada: veikia taip pat.

Template specializations
    nėra