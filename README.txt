Testavimo rezultatai:

Member functions:
1) konstruktoriai (pvz iš http://www.cplusplus.com/reference/vector/vector/vector/)
    a. std::vector rezultatas:
        The contents of fifth are: 16 2 77 29
    b. Vector rezultatas:
        The contents of fifth are: 16 2 77 29
    Išvada: veikia taip pat.
2) destruktorius (http://www.cplusplus.com/reference/vector/vector/~vector/)
    Veikia taip pat, bet prieiga kitokia,
        kadangi mano Vector klasėje jis yra public priėjimo tipo
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
    a. std::vector rezultatas:
        myvector backwards: 5 4 3 2 1
    b. Vector rezultatas:
        myvector backwards: 5 4 3 2 1
    Išvada: veikia taip pat.
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
        myvector backwards: 5 4 3 2 1
    b. Vector rezultatas:
        myvector backwards: 5 4 3 2 1
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
    Išvada: veikia taip pat.

Element access:
Modifiers:
Allocator:
Non-member function overloads:
Template specializations:
