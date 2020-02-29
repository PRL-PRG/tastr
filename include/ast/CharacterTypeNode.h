#ifndef TASTR_AST_CHARACTER_TYPE_H
#define TASTR_AST_CHARACTER_TYPE_H

#include "ScalarTypeNode.h"

namespace tastr::ast {

class CharacterTypeNode final: public ScalarTypeNode {
  public:
    CharacterTypeNode(): ScalarTypeNode() {
    }

    ~CharacterTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;
};

using CharacterTypeNodePtr = CharacterTypeNode*;
using CharacterTypeNodeUPtr = std::unique_ptr<CharacterTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_CHARACTER_TYPE_H */
