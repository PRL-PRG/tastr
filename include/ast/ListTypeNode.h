#ifndef TASTR_AST_LIST_TYPE_H
#define TASTR_AST_LIST_TYPE_H

#include "CompositeTypeNode.h"
#include "Sequence.h"

namespace tastr::ast {

class ListTypeNode final
    : public CompositeTypeNode
    , public TypeNodeSequence {
  public:
    explicit ListTypeNode(TypeNodeSequence sequence)
        : CompositeTypeNode(), TypeNodeSequence(std::move(sequence)) {
        // TODO: should I call the move constructor above?
    }

    ~ListTypeNode() {
    }

    ListTypeNode(const ListTypeNode& node)
        : CompositeTypeNode(node), TypeNodeSequence(node) {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<ListTypeNode> clone() const {
        return std::unique_ptr<ListTypeNode>(this->clone_impl());
    }

    bool is_list_type_node() const override final {
        return true;
    }

  private:
    virtual ListTypeNode* clone_impl() const override final {
        return new ListTypeNode(*this);
    };
};

using ListTypeNodePtr = ListTypeNode*;
using ListTypeNodeUPtr = std::unique_ptr<ListTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_LIST_TYPE_H */
