#ifndef TASTR_AST_TAGGED_TYPE_H
#define TASTR_AST_TAGGED_TYPE_H

#include "ast/IdentifierNode.h"
#include "ast/Node.h"
#include "ast/TypeNode.h"

#include <memory>
#include <string>

namespace tastr::ast {

class TaggedTypeNode final: public Node {
  public:
    explicit TaggedTypeNode(std::unique_ptr<IdentifierNode> identifier,
                            std::unique_ptr<TypeNode> type)
        : Node(), identifier_(std::move(identifier)), type_(std::move(type)) {
    }

    TaggedTypeNode(const TaggedTypeNode& node)
        : identifier_(node.get_identifier().clone())
        , type_(node.get_type().clone()) {
    }

    ~TaggedTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<TaggedTypeNode> clone() const {
        return std::unique_ptr<TaggedTypeNode>(this->clone_impl());
    }

    const tastr::ast::IdentifierNode& get_identifier() const {
        return *identifier_.get();
    }

    const tastr::ast::TypeNode& get_type() const {
        return *type_.get();
    }

    bool is_tagged_type_node() const override final {
        return true;
    }

  private:
    virtual TaggedTypeNode* clone_impl() const override final {
        return new TaggedTypeNode(*this);
    }

    std::unique_ptr<IdentifierNode> identifier_;
    std::unique_ptr<TypeNode> type_;
};

using TaggedTypeNodePtr = TaggedTypeNode*;
using TaggedTypeNodeUPtr = std::unique_ptr<TaggedTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_TAGGED_TYPE_H */
