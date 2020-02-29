#ifndef TASTR_AST_IDENTIFIER_H
#define TASTR_AST_IDENTIFIER_H

#include "ast/Node.h"

#include <iostream>

namespace tastr::ast {

class Identifier final: public Node {
  public:
    explicit Identifier(const std::string& name): Node(), name_(name) {
    }

    ~Identifier() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    const std::string& get_name() const {
        return name_;
    }

  private:
    std::string name_;
};

using IdentifierPtr = Identifier*;
using IdentifierUPtr = std::unique_ptr<Identifier>;

} // namespace tastr::ast

#endif /* TASTR_AST_IDENTIFIER_H */
