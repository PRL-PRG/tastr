#ifndef TASTR_AST_IDENTIFIER_H
#define TASTR_AST_IDENTIFIER_H

#include "ast/Node.h"

#include <iostream>

namespace tastr::ast {

class IdentifierNode final: public Node {
  public:
    explicit IdentifierNode(const std::string& name): Node(), name_(name) {
    }

    IdentifierNode(const IdentifierNode& node): Node(node) {
    }

    ~IdentifierNode() {
    }

    std::unique_ptr<IdentifierNode> clone() const {
        return std::unique_ptr<IdentifierNode>(this->clone_impl());
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    const std::string& get_name() const {
        return name_;
    }

  private:
    virtual IdentifierNode* clone_impl() const override final {
        return new IdentifierNode(*this);
    };

    std::string name_;
};

using IdentifierNodePtr = IdentifierNode*;
using IdentifierNodeUPtr = std::unique_ptr<IdentifierNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_IDENTIFIER_H */
