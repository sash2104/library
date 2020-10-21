// @title 完備辞書の簡易的なテスト
// dummy problem
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <cassert>
#include <iostream>
#include "../../../datastructure/wavelet/succinct-indexable-dictionary.hpp"
using namespace std;

void test_set_access() {
    SuccinctIndexableDictionary sid(2000);
    sid.set(3);
    sid.set(4);
    for (int i = 0; i < sid.length; ++i) {
        if (i == 3 || i == 4) { assert(sid[i] == 1); }
        else { assert(sid[i] == 0); }
    }
}

void test_rank() {
    SuccinctIndexableDictionary sid(2000);
    for (int i = 1000; i < 1500; ++i) {
        if (i % 2 == 0) sid.set(i);
    }
    sid.build();
    assert(sid.rank(0) == 0);
    assert(sid.rank(1000) == 0);
    assert(sid.rank(1001) == 1);
    assert(sid.rank(1002) == 1);
    assert(sid.rank(1498) == 249);
    assert(sid.rank(1499) == 250);
    assert(sid.rank(1500) == 250);
    assert(sid.rank(2000) == 250);
}

void test_select() {
    SuccinctIndexableDictionary sid(2000);
    for (int i = 1000; i < 1500; ++i) {
        if (i % 2 == 0) sid.set(i);
    }
    sid.build();
    assert(sid.select(0) == 0);
    assert(sid.select(1) == 1001);
    assert(sid.select(250) == 1499);
    assert(sid.select(251) == -1);
}

int main() {
    test_set_access();
    test_rank();
    test_select();

    // dummy output
    cout << "Hello World" << endl;
}