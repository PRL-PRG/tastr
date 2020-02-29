#ifndef TASTR_AST_NODE_CHARACTER_TYPE_H
#define TASTR_AST_NODE_CHARACTER_TYPE_H

#include "ScalarType.h"

namespace tastr::ast::node {

class CharacterType final: public ScalarType {
  public:
    CharacterType(): ScalarType() {
    }

    ~CharacterType() {
    }

    void accept(tastr::ast::visitor::Visitor& visitor) const override final;
};

using CharacterTypePtr = CharacterType*;
using CharacterTypeUPtr = std::unique_ptr<CharacterType>;

} // namespace tastr::ast::node

#endif /* TASTR_AST_NODE_CHARACTER_TYPE_H */
