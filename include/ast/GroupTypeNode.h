#ifndef TASTR_AST_GROUP_TYPE_H
#define TASTR_AST_GROUP_TYPE_H

#include "CompositeTypeNode.h"
#include <memory>

namespace tastr::ast {

class GroupTypeNode final: public CompositeTypeNode {
  public:
    explicit GroupTypeNode(std::unique_ptr<TypeNode> inner_type)
        : CompositeTypeNode(), inner_type_(std::move(inner_type)) {
    }

    ~GroupTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    const tastr::ast::TypeNode& get_inner_type() const {
        return *inner_type_.get();
    }

  private:
    std::unique_ptr<TypeNode> inner_type_;
};

using GroupTypeNodePtr = GroupTypeNode*;
using GroupTypeNodeUPtr = std::unique_ptr<GroupTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_GROUP_TYPE_H */
