#ifndef TASTR_AST_CHARACTER_TYPE_H
#define TASTR_AST_CHARACTER_TYPE_H

#include "ScalarType.h"

namespace tastr::ast {

class CharacterType final: public ScalarType {
  public:
    CharacterType(): ScalarType() {
    }

    ~CharacterType() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;
};

using CharacterTypePtr = CharacterType*;
using CharacterTypeUPtr = std::unique_ptr<CharacterType>;

} // namespace tastr::ast

#endif /* TASTR_AST_CHARACTER_TYPE_H */
