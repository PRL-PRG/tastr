#ifndef R_TYPE_AST_NODE_NAMED_TYPE_SEQUENCE_H
#define R_TYPE_AST_NODE_NAMED_TYPE_SEQUENCE_H

#include "Type.h"

#include <memory>
#include <string>

namespace rtype::ast::node {

class NamedTypeSequence {
  public:
    NamedTypeSequence() {
    }

    explicit NamedTypeSequence(const std::string& name,
                               std::unique_ptr<Type> type) {
    }

    void push_back(const std::string& name, std::unique_ptr<Type> type) {
    }

    ~NamedTypeSequence() {
    }

  private:
};

} // namespace rtype::ast::node

#endif /* R_TYPE_AST_NODE_NAMED_TYPE_SEQUENCE_H */
