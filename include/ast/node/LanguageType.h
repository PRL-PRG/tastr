#ifndef TASTR_AST_NODE_LANGUAGE_TYPE_H
#define TASTR_AST_NODE_LANGUAGE_TYPE_H

#include "Type.h"

namespace tastr::ast::node {

class LanguageType final: public Type {
  public:
    LanguageType(): Type() {
    }

    ~LanguageType() {
    }

    void accept(tastr::ast::visitor::Visitor& visitor) const override final;
};

using LanguageTypePtr = LanguageType*;
using LanguageTypeUPtr = std::unique_ptr<LanguageType>;

} // namespace tastr::ast::node

#endif /* TASTR_AST_NODE_LANGUAGE_TYPE_H */
