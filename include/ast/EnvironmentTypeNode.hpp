#ifndef TASTR_AST_ENVIRONMENT_TYPE_NODE_HPP
#define TASTR_AST_ENVIRONMENT_TYPE_NODE_HPP

#include "ast/KeywordNode.hpp"
#include "ast/TypeNode.hpp"

namespace tastr {
namespace ast {

class EnvironmentTypeNode final: public TypeNode {
  public:
    explicit EnvironmentTypeNode(KeywordNodeUPtr keyword)
        : TypeNode(), keyword_(std::move(keyword)) {
    }

    ~EnvironmentTypeNode() = default;

    EnvironmentTypeNode(const EnvironmentTypeNode& node)
        : TypeNode(node), keyword_(node.keyword_->clone()) {
    }

    EnvironmentTypeNode(EnvironmentTypeNode&& node)
        : TypeNode(std::move(node)), keyword_(std::move(node.keyword_)) {
    }

    EnvironmentTypeNode& operator=(const EnvironmentTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        keyword_ = node.keyword_->clone();
        return *this;
    }

    EnvironmentTypeNode& operator=(EnvironmentTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        keyword_ = std::move(node.keyword_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<EnvironmentTypeNode> clone() const {
        return std::unique_ptr<EnvironmentTypeNode>(this->clone_impl());
    }

    Kind get_kind() const override final {
        return kind_;
    }

    const KeywordNode& get_keyword() const {
        return *keyword_.get();
    }

  private:
    virtual EnvironmentTypeNode* clone_impl() const override final {
        return new EnvironmentTypeNode(*this);
    }

    KeywordNodeUPtr keyword_;

    static const Kind kind_;
};

using EnvironmentTypeNodePtr = EnvironmentTypeNode*;
using EnvironmentTypeNodeUPtr = std::unique_ptr<EnvironmentTypeNode>;

} // namespace ast
} // namespace tastr

#endif /* TASTR_AST_ENVIRONMENT_TYPE_NODE_HPP */
