#ifndef TASTR_AST_LANGUAGE_TYPE_H
#define TASTR_AST_LANGUAGE_TYPE_H

#include "TypeNode.h"

namespace tastr::ast {

class LanguageTypeNode final: public TypeNode {
  public:
    LanguageTypeNode(): TypeNode() {
    }

    LanguageTypeNode(const LanguageTypeNode& node): TypeNode(node) {
    }

    ~LanguageTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<LanguageTypeNode> clone() const {
        return std::unique_ptr<LanguageTypeNode>(this->clone_impl());
    }

  private:
    virtual LanguageTypeNode* clone_impl() const override final {
        return new LanguageTypeNode(*this);
    };
};

using LanguageTypeNodePtr = LanguageTypeNode*;
using LanguageTypeNodeUPtr = std::unique_ptr<LanguageTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_LANGUAGE_TYPE_H */
