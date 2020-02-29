#ifndef R_TYPE_AST_NODE_TAGGED_TYPE_H
#define R_TYPE_AST_NODE_TAGGED_TYPE_H

#include "ast/node/Identifier.h"
#include "ast/node/Node.h"
#include "ast/node/Type.h"

#include <memory>
#include <string>

namespace rtype::ast::node {

class TaggedType final: public Node {
  public:
    explicit TaggedType(std::unique_ptr<Identifier> identifier,
                        std::unique_ptr<Type> type)
        : Node(), identifier_(std::move(identifier)), type_(std::move(type)) {
    }

    ~TaggedType() {
    }

    void accept(rtype::ast::visitor::Visitor& visitor) const override final;

    const rtype::ast::node::Identifier& get_identifier() const {
        return *identifier_.get();
    }

    const rtype::ast::node::Type& get_type() const {
        return *type_.get();
    }

  private:
    std::unique_ptr<Identifier> identifier_;
    std::unique_ptr<Type> type_;
};

using TaggedTypePtr = TaggedType*;
using TaggedTypeUPtr = std::unique_ptr<TaggedType>;

} // namespace rtype::ast::node

#endif /* R_TYPE_AST_NODE_TAGGED_TYPE_H */
