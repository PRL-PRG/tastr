#ifndef TASTR_AST_SEQUENCE_TYPE_H
#define TASTR_AST_SEQUENCE_TYPE_H

#include "CompositeTypeNode.h"

#include <memory>
#include <vector>

namespace tastr::ast {

template <typename T>
using sequence_t = std::vector<std::unique_ptr<T>>;

template <typename T>
using sequence_ptr_t = std::vector<std::unique_ptr<T>>*;

template <typename T>
using sequence_uptr_t = std::unique_ptr<std::vector<std::unique_ptr<T>>>;

template <typename T>
class SequenceTypeNode: public CompositeTypeNode {
  public:
    typedef typename std::vector<std::unique_ptr<T>>::iterator iterator;

    typedef typename std::vector<std::unique_ptr<T>>::reverse_iterator
        reverse_iterator;

    typedef
        typename std::vector<std::unique_ptr<T>>::const_iterator const_iterator;

    typedef typename std::vector<std::unique_ptr<T>>::const_reverse_iterator
        const_reverse_iterator;

    explicit SequenceTypeNode()
        : CompositeTypeNode()
        , sequence_(new std::vector<std::unique_ptr<T>>()) {
    }

    explicit SequenceTypeNode(
        std::unique_ptr<std::vector<std::unique_ptr<T>>> sequence)
        : CompositeTypeNode(), sequence_(std::move(sequence)) {
    }

    virtual ~SequenceTypeNode() {
    }

    virtual void accept(tastr::visitor::Visitor& visitor) const = 0;

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

  private:
    std::unique_ptr<std::vector<std::unique_ptr<T>>> sequence_;
};

template <typename T>
using SequenceTypeNodePtr = SequenceTypeNode<T>*;

template <typename T>
using SequenceTypeNodeUPtr = std::unique_ptr<SequenceTypeNode<T>>;

} // namespace tastr::ast

#endif /* TASTR_AST_TYPE_SEQUENCE_H */
