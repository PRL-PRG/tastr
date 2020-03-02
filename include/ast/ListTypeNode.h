#ifndef TASTR_AST_LIST_TYPE_H
#define TASTR_AST_LIST_TYPE_H

#include "TypeNodeSequenceNode.h"
#include "TypeNode.h"

namespace tastr::ast {

class ListTypeNode final: public TypeNode {
  public:
    explicit ListTypeNode(TypeNodeSequenceNodeUPtr sequence)
        : TypeNode(), sequence_(std::move(sequence)) {
    }

    ~ListTypeNode() {
    }

    ListTypeNode(const ListTypeNode& node)
        : TypeNode(node), sequence_(node.get_element_types().clone()) {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<ListTypeNode> clone() const {
        return std::unique_ptr<ListTypeNode>(this->clone_impl());
    }

    bool is_list_type_node() const override final {
        return true;
    }

    TypeNodeSequenceNode& get_element_types() const {
        return *sequence_.get();
    }

  private:
    virtual ListTypeNode* clone_impl() const override final {
        return new ListTypeNode(*this);
    };

    TypeNodeSequenceNodeUPtr sequence_;
};

using ListTypeNodePtr = ListTypeNode*;
using ListTypeNodeUPtr = std::unique_ptr<ListTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_LIST_TYPE_H */
