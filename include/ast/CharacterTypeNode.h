#ifndef TASTR_AST_CHARACTER_TYPE_H
#define TASTR_AST_CHARACTER_TYPE_H

#include "ScalarTypeNode.h"

namespace tastr::ast {

class CharacterTypeNode final: public ScalarTypeNode {
  public:
    CharacterTypeNode(): ScalarTypeNode() {
    }

    CharacterTypeNode(const CharacterTypeNode& node): ScalarTypeNode(node) {
    }

    ~CharacterTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<CharacterTypeNode> clone() const {
        return std::unique_ptr<CharacterTypeNode>(this->clone_impl());
    }

  private:
    virtual CharacterTypeNode* clone_impl() const override final {
        return new CharacterTypeNode(*this);
    };
};

using CharacterTypeNodePtr = CharacterTypeNode*;
using CharacterTypeNodeUPtr = std::unique_ptr<CharacterTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_CHARACTER_TYPE_H */
