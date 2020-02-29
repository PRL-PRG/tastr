#ifndef TASTR_AST_LANGUAGE_TYPE_H
#define TASTR_AST_LANGUAGE_TYPE_H

#include "TypeNode.h"

namespace tastr::ast {

class LanguageTypeNode final: public TypeNode {
  public:
    LanguageTypeNode(): TypeNode() {
    }

    ~LanguageTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;
};

using LanguageTypeNodePtr = LanguageTypeNode*;
using LanguageTypeNodeUPtr = std::unique_ptr<LanguageTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_LANGUAGE_TYPE_H */
