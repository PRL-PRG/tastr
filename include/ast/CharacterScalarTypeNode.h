#ifndef TASTR_AST_CHARACTER_TYPE_H
#define TASTR_AST_CHARACTER_TYPE_H

#include "ScalarTypeNode.h"

namespace tastr::ast {

class CharacterScalarTypeNode final: public ScalarTypeNode {
  public:
    CharacterScalarTypeNode(): ScalarTypeNode() {
    }

    CharacterScalarTypeNode(const CharacterScalarTypeNode& node)
        : ScalarTypeNode(node) {
    }

    ~CharacterScalarTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<CharacterScalarTypeNode> clone() const {
        return std::unique_ptr<CharacterScalarTypeNode>(this->clone_impl());
    }

  private:
    virtual CharacterScalarTypeNode* clone_impl() const override final {
        return new CharacterScalarTypeNode(*this);
    };
};

using CharacterScalarTypeNodePtr = CharacterScalarTypeNode*;
using CharacterScalarTypeNodeUPtr = std::unique_ptr<CharacterScalarTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_CHARACTER_TYPE_H */
