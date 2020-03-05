#ifndef TASTR_AST_SEQUENCE_HPP
#define TASTR_AST_SEQUENCE_HPP

#include "Node.hpp"
#include "TagTypePairNode.hpp"
#include "TypeNode.hpp"

#include <memory>
#include <type_traits>
#include <vector>

namespace tastr::ast {

template <typename T, typename = std::enable_if_t<std::is_base_of_v<Node, T>>>
class Sequence {
  public:
    typedef std::vector<std::unique_ptr<T>> sequence_t;

    typedef sequence_t* sequence_ptr_t;

    typedef std::unique_ptr<sequence_t> sequence_uptr_t;

    typedef typename sequence_t::iterator iterator;

    typedef typename sequence_t::reverse_iterator reverse_iterator;

    typedef typename sequence_t::const_iterator const_iterator;

    typedef typename sequence_t::const_reverse_iterator const_reverse_iterator;

    Sequence() {
    }

    ~Sequence() = default;

    Sequence(const Sequence<T>& sequence) {
        for (auto node = sequence.cbegin(); node != sequence.cend(); ++node) {
            sequence_.push_back((**node).clone());
        }
    }

    Sequence(Sequence<T>&& sequence): sequence_(std::move(sequence.sequence_)) {
    }

    Sequence& operator=(const Sequence& sequence) {
        if (&sequence == this) {
            return *this;
        }
        for (auto node = sequence.cbegin(); node != sequence.cend(); ++node) {
            sequence_.push_back((**node).clone());
        }
        return *this;
    }

    Sequence& operator=(Sequence&& sequence) {
        sequence_ = std::move(sequence.sequence_);
        return *this;
    }

    void push_back(std::unique_ptr<T> value) {
        sequence_.push_back(std::move(value));
    }

    size_t size() const {
        return sequence_.size();
    }

    bool is_empty() const {
        return sequence_.empty();
    }

    iterator begin() {
        return sequence_.begin();
    }

    iterator end() {
        return sequence_.end();
    }

    reverse_iterator rbegin() {
        return sequence_.rbegin();
    }

    reverse_iterator rend() {
        return sequence_.rend();
    }

    const_iterator cbegin() const {
        return sequence_.cbegin();
    }

    const_iterator cend() const {
        return sequence_.cend();
    }

    const_reverse_iterator crbegin() const {
        return sequence_.crbegin();
    }

    const_reverse_iterator crend() const {
        return sequence_.crend();
    }

    std::unique_ptr<Sequence<T>> clone() const {
        return std::unique_ptr<Sequence<T>>(this->clone_impl());
    }

  private:
    virtual Sequence<T>* clone_impl() const {
        return new Sequence<T>(*this);
    }

    sequence_t sequence_;
};

template <typename T>
using SequencePtr = Sequence<T>*;

template <typename T>
using SequenceNodeUPtr = std::unique_ptr<Sequence<T>>;

} // namespace tastr::ast

#endif /* TASTR_AST_SEQUENCE_HPP */
