#ifndef TASTR_AST_TAG_TYPE_PAIR_NODE_HPP
#define TASTR_AST_TAG_TYPE_PAIR_NODE_HPP

#include "ast/IdentifierNode.hpp"
#include "ast/Node.hpp"
#include "ast/SeparatorNode.hpp"
#include "ast/TypeNode.hpp"

#include <memory>
#include <string>

namespace tastr {
namespace ast {

class TagTypePairNode final: public Node {
  public:
    explicit TagTypePairNode(std::unique_ptr<IdentifierNode> identifier,
                             std::unique_ptr<TypeNode> type,
                             std::unique_ptr<SeparatorNode> separator)
        : Node()
        , identifier_(std::move(identifier))
        , type_(std::move(type))
        , separator_(std::move(separator)) {
    }

    ~TagTypePairNode() = default;

    TagTypePairNode(const TagTypePairNode& node)
        : Node(node)
        , identifier_(node.identifier_->clone())
        , type_(node.type_->clone())
        , separator_(node.separator_->clone()) {
    }

    TagTypePairNode(TagTypePairNode&& node)
        : Node(std::move(node))
        , identifier_(std::move(node.identifier_))
        , type_(std::move(node.type_))
        , separator_(std::move(node.separator_)) {
    }

    TagTypePairNode& operator=(const TagTypePairNode& node) {
        if (&node == this) {
            return *this;
        }
        Node::operator=(node);
        identifier_ = node.identifier_->clone();
        type_ = node.type_->clone();
        separator_ = node.separator_->clone();
        return *this;
    }

    TagTypePairNode& operator=(TagTypePairNode&& node) {
        Node::operator=(std::move(node));
        identifier_ = std::move(node.identifier_);
        type_ = std::move(node.type_);
        separator_ = std::move(node.separator_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<TagTypePairNode> clone() const {
        return std::unique_ptr<TagTypePairNode>(this->clone_impl());
    }

    Kind get_kind() const override final {
        return kind_;
    }

    const tastr::ast::IdentifierNode& get_identifier() const {
        return *identifier_.get();
    }

    const tastr::ast::TypeNode& get_type() const {
        return *type_.get();
    }

    const tastr::ast::SeparatorNode& get_separator() const {
        return *separator_.get();
    }

  private:
    virtual TagTypePairNode* clone_impl() const override final {
        return new TagTypePairNode(*this);
    }

    std::unique_ptr<IdentifierNode> identifier_;
    std::unique_ptr<TypeNode> type_;
    std::unique_ptr<SeparatorNode> separator_;

    static const Kind kind_;
};

using TagTypePairNodePtr = TagTypePairNode*;
using TagTypePairNodeUPtr = std::unique_ptr<TagTypePairNode>;

} // namespace ast
} // namespace tastr

#endif /* TASTR_AST_TAG_TYPE_PAIR_NODE_HPP */
