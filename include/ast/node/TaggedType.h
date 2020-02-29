#ifndef TASTR_AST_NODE_TAGGED_TYPE_H
#define TASTR_AST_NODE_TAGGED_TYPE_H

#include "ast/node/Identifier.h"
#include "ast/node/Node.h"
#include "ast/node/Type.h"

#include <memory>
#include <string>

namespace tastr::ast::node {

class TaggedType final: public Node {
  public:
    explicit TaggedType(std::unique_ptr<Identifier> identifier,
                        std::unique_ptr<Type> type)
        : Node(), identifier_(std::move(identifier)), type_(std::move(type)) {
    }

    ~TaggedType() {
    }

    void accept(tastr::ast::visitor::Visitor& visitor) const override final;

    const tastr::ast::node::Identifier& get_identifier() const {
        return *identifier_.get();
    }

    const tastr::ast::node::Type& get_type() const {
        return *type_.get();
    }

  private:
    std::unique_ptr<Identifier> identifier_;
    std::unique_ptr<Type> type_;
};

using TaggedTypePtr = TaggedType*;
using TaggedTypeUPtr = std::unique_ptr<TaggedType>;

} // namespace tastr::ast::node

#endif /* TASTR_AST_NODE_TAGGED_TYPE_H */
