#ifndef R_TYPE_AST_NODE_LANGUAGE_TYPE_H
#define R_TYPE_AST_NODE_LANGUAGE_TYPE_H

#include "Type.h"

namespace rtype::ast::node {

class LanguageType final: public Type {
  public:
    LanguageType(): Type() {
    }

    ~LanguageType() {
    }

    void accept(rtype::ast::visitor::Visitor& visitor) const override final;
};

using LanguageTypePtr = LanguageType*;
using LanguageTypeUPtr = std::unique_ptr<LanguageType>;

} // namespace rtype::ast::node

#endif /* R_TYPE_AST_NODE_LANGUAGE_TYPE_H */
