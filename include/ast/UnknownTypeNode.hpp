#ifndef TASTR_AST_UNKNOWN_TYPE_NODE_HPP
#define TASTR_AST_UNKNOWN_TYPE_NODE_HPP

#include "ast/KeywordNode.hpp"
#include "ast/TypeNode.hpp"

namespace tastr::ast {

class UnknownTypeNode final: public TypeNode {
  public:
    explicit UnknownTypeNode(const KeywordNode& keyword)
        : TypeNode(), keyword_(keyword) {
    }

    ~UnknownTypeNode() = default;

    UnknownTypeNode(const UnknownTypeNode& node)
        : TypeNode(node), keyword_(node.keyword_) {
    }

    UnknownTypeNode(UnknownTypeNode&& node)
        : TypeNode(std::move(node)), keyword_(std::move(node.keyword_)) {
    }

    UnknownTypeNode& operator=(const UnknownTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        keyword_ = node.keyword_;
        return *this;
    }

    UnknownTypeNode& operator=(UnknownTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        keyword_ = std::move(node.keyword_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<UnknownTypeNode> clone() const {
        return std::unique_ptr<UnknownTypeNode>(this->clone_impl());
    }

    bool is_unknown_type_node() const override final {
        return true;
    }

    const KeywordNode& get_keyword() const {
        return keyword_;
    }

  private:
    virtual UnknownTypeNode* clone_impl() const override final {
        return new UnknownTypeNode(*this);
    };

    KeywordNode keyword_;
};

using UnknownTypeNodePtr = UnknownTypeNode*;
using UnknownTypeNodeUPtr = std::unique_ptr<UnknownTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_UNKNOWN_TYPE_NODE_HPP */
