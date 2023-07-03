// @title Posクラスの簡易的なテスト
// dummy problem
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <cassert>
#include <iostream>
#include <set>
#include "../../util/marathon/pos.hpp"
using namespace std;

void test_operator() {
    {
        Pos p;
        assert (p == pos::nullpos);
    }
    {
        Pos p1(1,2);
        Pos p2(1,-2);
        assert (p1 != p2);
        p1.y = -2;
        assert (p1 == p2);
    }
}

void test_to() {
    Pos p(0,0);
    assert (p.to(pos::UP) == Pos(0,-1));
    assert (p.to(pos::RIGHT) == Pos(1,0));
    assert (p.to(pos::DOWN) == Pos(0,1));
    assert (p.to(pos::LEFT) == Pos(-1,0));
}

void test_id() {
    pos::W = 3;
    pos::H = 5;
    std::set<int> ids;
    for (int x = 0; x < pos::W; ++x) {
        for (int y = 0; y < pos::H; ++y) {
            Pos p(x,y);
            int id = p.id();
            // 同じidは登場しない
            assert (ids.count(id) == 0);
            ids.insert(id);
            Pos np(id);
            // idからPosを復元できる
            assert (p == np);
        }
    }
}

void test_outside() {
    pos::W = 3;
    pos::H = 5;
    Pos ul(0, 0);
    Pos ur(pos::W-1, 0);
    Pos dr(pos::W-1, pos::H-1);
    Pos dl(0, pos::H-1);
    assert (!ul.outside());
    assert (!ur.outside());
    assert (!dr.outside());
    assert (!dl.outside());
    assert (ul.to(pos::UP).outside());
    assert (ul.to(pos::LEFT).outside());
    assert (ur.to(pos::UP).outside());
    assert (ur.to(pos::RIGHT).outside());
    assert (dr.to(pos::DOWN).outside());
    assert (dr.to(pos::RIGHT).outside());
    assert (dr.to(pos::DOWN).outside());
    assert (dl.to(pos::LEFT).outside());
}

int main() {
    test_operator();
    test_to();
    test_id();
    test_outside();

    // dummy output
    cout << "Hello World" << endl;
}