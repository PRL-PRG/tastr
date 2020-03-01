#ifndef TASTR_AST_SEQUENCE_TYPE_H
#define TASTR_AST_SEQUENCE_TYPE_H

#include "TaggedTypeNode.h"
#include "TypeNode.h"

#include <memory>
#include <type_traits>
#include <vector>

namespace tastr::ast {

template <typename T>
using sequence_t = std::vector<std::unique_ptr<T>>;

template <typename T>
using sequence_ptr_t = std::vector<std::unique_ptr<T>>*;

template <typename T>
using sequence_uptr_t = std::unique_ptr<std::vector<std::unique_ptr<T>>>;

template <typename T, typename = std::enable_if_t<std::is_base_of_v<Node, T>>>
class Sequence {
  public:
    typedef typename sequence_t<T>::iterator iterator;

    typedef typename sequence_t<T>::reverse_iterator reverse_iterator;

    typedef typename sequence_t<T>::const_iterator const_iterator;

    typedef
        typename sequence_t<T>::const_reverse_iterator const_reverse_iterator;

    explicit Sequence(): sequence_(new sequence_t<T>()) {
    }

    explicit Sequence(sequence_uptr_t<T> sequence)
        : sequence_(std::move(sequence)) {
    }

    Sequence(Sequence<T>&& sequence): sequence_(std::move(sequence.sequence_)) {
    }

    Sequence(const Sequence<T>& sequence) {
        for (auto node = sequence.cbegin(); node != sequence.cend(); ++node) {
            sequence_->push_back((**node).clone());
        }
    };

    ~Sequence() = default;

    void push_back(std::unique_ptr<T> value) {
        sequence_->push_back(std::move(value));
    }

    size_t size() const {
        return sequence_->size();
    }

    bool is_empty() const {
        return sequence_->empty();
    }

    iterator begin() {
        return sequence_->begin();
    }

    iterator end() {
        return sequence_->end();
    }

    reverse_iterator rbegin() {
        return sequence_->rbegin();
    }

    reverse_iterator rend() {
        return sequence_->rend();
    }

    const_iterator cbegin() const {
        return sequence_->cbegin();
    }

    const_iterator cend() const {
        return sequence_->cend();
    }

    const_reverse_iterator crbegin() const {
        return sequence_->crbegin();
    }

    const_reverse_iterator crend() const {
        return sequence_->crend();
    }

    std::unique_ptr<Sequence<T>> clone() const {
        return std::unique_ptr<Sequence<T>>(this->clone_impl());
    }

  private:
    virtual Sequence<T>* clone_impl() const {
        return new Sequence<T>(*this);
    }

    std::unique_ptr<std::vector<std::unique_ptr<T>>> sequence_;
};

template <typename T>
using SequencePtr = Sequence<T>*;

template <typename T>
using SequenceUPtr = std::unique_ptr<Sequence<T>>;

using TypeNodeSequence = Sequence<TypeNode>;
using TypeNodeSequencePtr = TypeNodeSequence*;
using TypeNodeSequenceUPtr = std::unique_ptr<TypeNodeSequence>;

using TaggedTypeNodeSequence = Sequence<TaggedTypeNode>;
using TaggedTypeNodeSequencePtr = TaggedTypeNodeSequence*;
using TaggedTypeNodeSequenceUPtr = std::unique_ptr<TaggedTypeNodeSequence>;

} // namespace tastr::ast

#endif /* TASTR_AST_TYPE_SEQUENCE_H */
