#include "bitset.hpp"

bool BitSet::operator==(const BitSet& rhs) const noexcept {
    return ((bits_ == rhs.bits_) && (size_ == rhs.size_));
}

bool BitSet::operator!=(const BitSet& rhs) const noexcept {
    return !((bits_ == rhs.bits_) && (size_ == rhs.size_));
}

void BitSet::Resize(const std::int32_t size) {
    if (size <= 0) {
        throw std::invalid_argument("The size must be greater than zero");
    }
    else if (size_ != size) {
        size_ = size;
        bits_.resize(size);
    }
}

bool BitSet::Get(const std::int32_t idx) const {
    if (idx >= 0 && idx < size_) {
        return bits_[idx];
    }
    else {
        throw std::out_of_range("Not correct index");
    }
}

void BitSet::Set(const int32_t idx, const bool val) {
    if (idx >= 0 && idx < size_) {
        bits_[idx] = val;
    }
    else {
        throw std::out_of_range("Not correct index");
    }
}

void BitSet::Fill(const bool val) noexcept {
    bits_ = std::vector<std::uint32_t>(size_, val);
}

BitSet BitSet::operator~() {
    BitSet otr(size_);
    for (std::size_t i = 0; i < size_; ++i) {
        otr.bits_[i] = !bits_[i];
    }
    return otr;
}

std::vector<std::uint32_t> BitSet::same_size(const BitSet& v1, const BitSet& v2) {
    std::ptrdiff_t max_len = std::max(v1.size_, v2.size_);
    std::vector<std::uint32_t> data(max_len - v1.size_, 0);
    data.insert(data.end(), v1.bits_.begin(), v1.bits_.end());
    return data;
}

BitSet& BitSet::operator|=(const BitSet& rhs) {
    std::vector<std::uint32_t> data1 = same_size(*this, rhs);
    std::vector<std::uint32_t> data2 = same_size(rhs, *this);
    this->Resize(data1.size());
    for (std::size_t i = 0; i < data1.size(); ++i) {
        bits_[i] = (data1[i] | data2[i]);
    }
    return *this;
}

BitSet operator|(const BitSet& lhs, const BitSet& rhs) {
    BitSet result(lhs);
    result |= rhs;
    return result;
}

BitSet& BitSet::operator&=(const BitSet& rhs) {
    std::vector<std::uint32_t> data1 = same_size(*this, rhs);
    std::vector<std::uint32_t> data2 = same_size(rhs, *this);
    this->Resize(data1.size());
    for (std::size_t i = 0; i < data1.size(); ++i) {
        bits_[i] = (data1[i] & data2[i]);
    }
    return *this;
}

BitSet operator&(const BitSet& lhs, const BitSet& rhs) {
    BitSet result(lhs);
    result &= rhs;
    return result;
}

BitSet& BitSet::operator^=(const BitSet& rhs) {
    std::vector<std::uint32_t> data1 = same_size(*this, rhs);
    std::vector<std::uint32_t> data2 = same_size(rhs, *this);
    this->Resize(data1.size());
    for (std::size_t i = 0; i < data1.size(); ++i) {
        bits_[i] = (data1[i] ^ data2[i]);
    }
    return *this;
}

BitSet operator^(const BitSet& lhs, const BitSet& rhs) {
    BitSet result(lhs);
    result ^= rhs;
    return result;
}