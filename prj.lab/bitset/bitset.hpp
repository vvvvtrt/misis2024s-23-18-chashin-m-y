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

	[[nodiscard]] bool operator==(const BitSet& rhs) const noexcept;

	[[nodiscard]] bool operator!=(const BitSet& rhs) const noexcept;

	int32_t Size() const noexcept { return size_; }
	uint32_t GetSize() const noexcept;
	void Resize(const uint32_t& n);
	bool Get(const uint32_t& n);
	void Set(const uint32_t& n, const bool b);
	void Fill(const bool& b);
	

	[[nodiscard]] BitSet& operator&=(const BitSet& rhs);

	[[nodiscard]] BitSet& operator|=(const BitSet& rhs);

	[[nodiscard]] BitSet& operator^=(const BitSet& rhs);

	[[nodiscard]] BitSet& operator~ = ();
	
private:
	vector<uint32_t> bitset;

};

#endif // !BITSET_HPP
