#ifndef TASTR_AST_TYPE_H
#define TASTR_AST_TYPE_H

#include "ast/Node.h"

namespace tastr::ast {

class Type: public Node {
  public:
    Type(): Node() {
    }

    virtual ~Type() {
    }

    virtual void accept(tastr::visitor::Visitor& visitor) const = 0;
};

using TypePtr = Type*;
using TypeUPtr = std::unique_ptr<Type>;

} // namespace tastr::ast

#endif /* TASTR_AST_TYPE_H */
