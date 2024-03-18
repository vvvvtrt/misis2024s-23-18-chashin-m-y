#ifndef BITSET_HPP
#define BITSET_HPP

#include <iostream>
#include <vector>

class BitSet {
public:
	[[nodiscard]] BitSet() = default;
	[[nodiscard]] BitSet(const BitSet& src);
	[[nodiscard]] BitSet(BitSet&& src);

	BitSet& operator=(const BitSet& src) noexcept;
	BitSet& operator=(BitSet&& src) noexcept;

	~BitSet() = default;

	uint32_t GetSize() const noexcept;
	void Resize(const uint32_t& n);
	bool Get(const uint32_t& n);
	void Set(const uint32_t& n, const bool b);
	void Fill(const bool& b);
	
private:
	vector<uint32_t> bitset;

};

#endif // !BITSET_HPP
