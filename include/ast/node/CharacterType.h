#ifndef R_TYPE_AST_NODE_CHARACTER_TYPE_H
#define R_TYPE_AST_NODE_CHARACTER_TYPE_H

#include "ScalarType.h"

namespace rtype::ast::node {

class CharacterType: public ScalarType {
  public:
    CharacterType(): ScalarType() {
    }

    ~CharacterType() {
    }

    void accept(rtype::ast::visitor::Visitor& visitor) const override;
};

using CharacterTypePtr = CharacterType*;
using CharacterTypeUPtr = std::unique_ptr<CharacterType>;

} // namespace rtype::ast::node

#endif /* R_TYPE_AST_NODE_CHARACTER_TYPE_H */
