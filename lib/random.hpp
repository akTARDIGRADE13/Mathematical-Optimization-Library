#pragma once

#include <cassert>
#include <cstdint>
#include <unordered_set>
#include <vector>

namespace akTARDIGRADE13 {

// XORSHIFT-128
std::uint_fast64_t rng() {
	static std::uint_fast64_t rx = 123456789, ry = 362436069, rz = 521288629, rw = 88675123;
	std::uint_fast64_t rt = (rx ^ (rx << 11));
	rx = ry;
	ry = rz;
	rz = rw;
	return (rw = (rw ^ (rw >> 19)) ^ (rt ^ (rt >> 8)));
}

// [l,r)の範囲の整数を一様ランダムに返す
std::int_fast64_t randint(std::int_fast64_t l, std::int_fast64_t r) {
	assert(l < r);
	return l + rng() % (r - l);
}

// [0,1]の範囲の小数を一様ランダムに返す
double rnd() { return rng() * 5.42101086242752217004e-20; }

// 配列vをシャッフル
template <typename T>
void randshf(std::vector<T>& v) {
	int n = v.size();
	for (int i = 1; i < n; i++) std::swap(v[i], v[randint(0, i + 1)]);
}

// zobristHash
struct zobristHash {
	std::vector<std::uint_fast64_t> h;
	zobristHash(int n) :h(n) {
		for (int i = 0; i <= n; ++i) h[i] = rng();
	}

  // 整数iに対応するハッシュ値を返す
	std::uint_fast64_t get_rand(int i) {
		return h[i];
	}
};

}