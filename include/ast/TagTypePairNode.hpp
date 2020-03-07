#ifndef TASTR_AST_TAG_TYPE_PAIR_NODE_HPP
#define TASTR_AST_TAG_TYPE_PAIR_NODE_HPP

#include "ast/IdentifierNode.hpp"
#include "ast/Node.hpp"
#include "ast/TypeNode.hpp"
#include "ast/Separator.hpp"

#include <memory>
#include <string>

namespace tastr::ast {

class TagTypePairNode final
    : public Node
    , public Separator {
  public:
    explicit TagTypePairNode(std::unique_ptr<IdentifierNode> identifier,
                             std::unique_ptr<TypeNode> type,
                             const std::string& separator)
        : Node()
        , Separator(separator)
        , identifier_(std::move(identifier))
        , type_(std::move(type)) {
    }

    ~TagTypePairNode() = default;

    TagTypePairNode(const TagTypePairNode& node)
        : Node(node)
        , Separator(node)
        , identifier_(node.identifier_->clone())
        , type_(node.type_->clone()) {
    }

    TagTypePairNode(TagTypePairNode&& node)
        : Node(std::move(node))
        , Separator(std::move(node))
        , identifier_(std::move(node.identifier_))
        , type_(std::move(node.type_)) {
    }

    TagTypePairNode& operator=(const TagTypePairNode& node) {
        if (&node == this) {
            return *this;
        }
        Node::operator=(node);
        Separator::operator=(node);
        identifier_ = node.identifier_->clone();
        type_ = node.type_->clone();
        return *this;
    }

    TagTypePairNode& operator=(TagTypePairNode&& node) {
        Node::operator=(std::move(node));
        Separator::operator=(std::move(node));
        identifier_ = std::move(node.identifier_);
        type_ = std::move(node.type_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<TagTypePairNode> clone() const {
        return std::unique_ptr<TagTypePairNode>(this->clone_impl());
    }

    const tastr::ast::IdentifierNode& get_identifier() const {
        return *identifier_.get();
    }

    const tastr::ast::TypeNode& get_type() const {
        return *type_.get();
    }

    bool is_tag_type_pair_node() const override final {
        return true;
    }

  private:
    virtual TagTypePairNode* clone_impl() const override final {
        return new TagTypePairNode(*this);
    }

    std::unique_ptr<IdentifierNode> identifier_;
    std::unique_ptr<TypeNode> type_;
};

using TagTypePairNodePtr = TagTypePairNode*;
using TagTypePairNodeUPtr = std::unique_ptr<TagTypePairNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_TAG_TYPE_PAIR_NODE_HPP */
