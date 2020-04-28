#ifndef TASTR_AST_ANY_TYPE_NODE_HPP
#define TASTR_AST_ANY_TYPE_NODE_HPP

#include "ast/KeywordNode.hpp"
#include "ast/TypeNode.hpp"

namespace tastr {
namespace ast {

class AnyTypeNode final: public TypeNode {
  public:
    explicit AnyTypeNode(KeywordNodeUPtr keyword)
        : TypeNode(), keyword_(std::move(keyword)) {
    }

    ~AnyTypeNode() = default;

    AnyTypeNode(const AnyTypeNode& node)
        : TypeNode(node), keyword_(node.keyword_->clone()) {
    }

    AnyTypeNode(AnyTypeNode&& node)
        : TypeNode(std::move(node)), keyword_(std::move(node.keyword_)) {
    }

    AnyTypeNode& operator=(const AnyTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        keyword_ = node.keyword_->clone();
        return *this;
    }

    AnyTypeNode& operator=(AnyTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        keyword_ = std::move(node.keyword_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<AnyTypeNode> clone() const {
        return std::unique_ptr<AnyTypeNode>(this->clone_impl());
    }

    Kind get_kind() const override final {
        return kind_;
    }

    const KeywordNode& get_keyword() const {
        return *keyword_.get();
    }

  private:
    virtual AnyTypeNode* clone_impl() const override final {
        return new AnyTypeNode(*this);
    };

    KeywordNodeUPtr keyword_;

    static const Kind kind_;
};

using AnyTypeNodePtr = AnyTypeNode*;
using AnyTypeNodeUPtr = std::unique_ptr<AnyTypeNode>;

} // namespace ast
} // namespace tastr

#endif /* TASTR_AST_ANY_TYPE_NODE_HPP */
