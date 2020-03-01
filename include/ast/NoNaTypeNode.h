#ifndef TASTR_AST_NO_NA_TYPE_H
#define TASTR_AST_NO_NA_TYPE_H

#include "CompositeTypeNode.h"
#include "VectorTypeNode.h"

#include <memory>

namespace tastr::ast {

class NoNaTypeNode final: public CompositeTypeNode {
  public:
    NoNaTypeNode(std::unique_ptr<VectorTypeNode> inner_type)
        : CompositeTypeNode(), inner_type_(std::move(inner_type)) {
    }

    ~NoNaTypeNode() {
    }

    NoNaTypeNode(const NoNaTypeNode& node)
        : CompositeTypeNode(node), inner_type_(node.get_inner_type().clone()) {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    const tastr::ast::VectorTypeNode& get_inner_type() const {
        return *inner_type_.get();
    }

    std::unique_ptr<NoNaTypeNode> clone() const {
        return std::unique_ptr<NoNaTypeNode>(this->clone_impl());
    }

    bool is_no_na_type_node() const override final {
        return true;
    }

  private:
    virtual NoNaTypeNode* clone_impl() const override final {
        return new NoNaTypeNode(*this);
    };

    std::unique_ptr<tastr::ast::VectorTypeNode> inner_type_;
};

using NoNaTypeNodePtr = NoNaTypeNode*;
using NoNaTypeNodeUPtr = std::unique_ptr<NoNaTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_NO_NA_TYPE_H */
