#ifndef R_TYPE_AST_NODE_TAGGED_TYPE_H
#define R_TYPE_AST_NODE_TAGGED_TYPE_H

#include "ast/node/Node.h"
#include "ast/node/Type.h"

#include <memory>
#include <string>

namespace rtype::ast::node {

class TaggedType final: public Node {
  public:
    explicit TaggedType(const std::string& tag, std::unique_ptr<Type> type)
        : Node(), tag_(tag), type_(std::move(type)) {
    }

    ~TaggedType() {
    }

    void accept(rtype::ast::visitor::Visitor& visitor) const override final;

    const std::string& get_tag() const {
        return tag_;
    }

    const rtype::ast::node::Type& get_type() const {
        return *type_.get();
    }

  private:
    std::string tag_;
    std::unique_ptr<Type> type_;
};

using TaggedTypePtr = TaggedType*;
using TaggedTypeUPtr = std::unique_ptr<TaggedType>;

} // namespace rtype::ast::node

#endif /* R_TYPE_AST_NODE_TAGGED_TYPE_H */
