#ifndef TASTR_AST_IDENTIFIER_H
#define TASTR_AST_IDENTIFIER_H

#include "ast/Node.h"

#include <iostream>

namespace tastr::ast {

class IdentifierNode final: public Node {
  public:
    explicit IdentifierNode(const std::string& name): Node(), name_(name) {
    }

    ~IdentifierNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    const std::string& get_name() const {
        return name_;
    }

  private:
    std::string name_;
};

using IdentifierNodePtr = IdentifierNode*;
using IdentifierNodeUPtr = std::unique_ptr<IdentifierNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_IDENTIFIER_H */
