#ifndef TASTR_AST_UNION_TYPE_H
#define TASTR_AST_UNION_TYPE_H

#include "TypeNode.h"

#include <memory>

namespace tastr::ast {

class UnionTypeNode final: public TypeNode {
  public:
    UnionTypeNode(std::unique_ptr<TypeNode> first_type,
                  std::unique_ptr<TypeNode> second_type)
        : TypeNode()
        , first_type_(std::move(first_type))
        , second_type_(std::move(second_type)) {
    }

    UnionTypeNode(const UnionTypeNode& node)
        : TypeNode(node)
        , first_type_(node.get_first_type().clone())
        , second_type_(node.get_second_type().clone()) {
    }

    ~UnionTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<UnionTypeNode> clone() const {
        return std::unique_ptr<UnionTypeNode>(this->clone_impl());
    }

    const tastr::ast::TypeNode& get_first_type() const {
        return *first_type_.get();
    }

    const tastr::ast::TypeNode& get_second_type() const {
        return *second_type_.get();
    }

    bool is_union_type_node() const override final {
        return true;
    }

  private:
    virtual UnionTypeNode* clone_impl() const override final {
        return new UnionTypeNode(*this);
    }

    std::unique_ptr<TypeNode> first_type_;
    std::unique_ptr<TypeNode> second_type_;
};

using UnionTypeNodePtr = UnionTypeNode*;
using UnionTypeNodeUPtr = std::unique_ptr<UnionTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_UNION_TYPE_H */
