#ifndef R_TYPE_AST_NODE_IDENTIFIER_H
#define R_TYPE_AST_NODE_IDENTIFIER_H

#include "ast/node/Node.h"

#include <iostream>

namespace rtype::ast::node {

class Identifier final: public Node {
  public:
    explicit Identifier(const std::string& name): Node(), name_(name) {
    }

    ~Identifier() {
    }

    void accept(rtype::ast::visitor::Visitor& visitor) const override final;

    const std::string& get_name() const {
        return name_;
    }

  private:
    std::string name_;
};

using IdentifierPtr = Identifier*;
using IdentifierUPtr = std::unique_ptr<Identifier>;

} // namespace rtype::ast::node

#endif /* R_TYPE_AST_NODE_IDENTIFIER_H */
