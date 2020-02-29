#ifndef TASTR_AST_LANGUAGE_TYPE_H
#define TASTR_AST_LANGUAGE_TYPE_H

#include "Type.h"

namespace tastr::ast {

class LanguageType final: public Type {
  public:
    LanguageType(): Type() {
    }

    ~LanguageType() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;
};

using LanguageTypePtr = LanguageType*;
using LanguageTypeUPtr = std::unique_ptr<LanguageType>;

} // namespace tastr::ast

#endif /* TASTR_AST_LANGUAGE_TYPE_H */
