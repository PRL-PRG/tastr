#ifndef R_TYPE_AST_NODE_SEQUENCE_TYPE_H
#define R_TYPE_AST_NODE_SEQUENCE_TYPE_H

#include "CompositeType.h"

#include <memory>
#include <vector>

namespace rtype::ast::node {

template <typename T>
class SequenceType: public CompositeType {
  public:
    typedef typename std::vector<std::unique_ptr<T>>::iterator iterator;

    typedef typename std::vector<std::unique_ptr<T>>::reverse_iterator
        reverse_iterator;

    typedef
        typename std::vector<std::unique_ptr<T>>::const_iterator const_iterator;

    typedef typename std::vector<std::unique_ptr<T>>::const_reverse_iterator
        const_reverse_iterator;

    explicit SequenceType(
        std::unique_ptr<std::vector<std::unique_ptr<T>>> sequence)
        : CompositeType(), sequence_(std::move(sequence)) {
    }

    virtual ~SequenceType() {
    }

    virtual void accept(rtype::ast::visitor::TypeVisitor& visitor) const = 0;

    void push_back(std::unique_ptr<Type> type) {
        sequence_->push_back(std::move(type));
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

} // namespace rtype::ast::node

#endif /* R_TYPE_AST_NODE_TYPE_SEQUENCE_H */
