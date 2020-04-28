#ifndef TASTR_AST_BYTECODE_TYPE_NODE_HPP
#define TASTR_AST_BYTECODE_TYPE_NODE_HPP

#include "ast/KeywordNode.hpp"
#include "ast/TypeNode.hpp"

namespace tastr {
namespace ast {

class BytecodeTypeNode final: public TypeNode {
  public:
    explicit BytecodeTypeNode(KeywordNodeUPtr keyword)
        : TypeNode(), keyword_(std::move(keyword)) {
    }

    ~BytecodeTypeNode() = default;

    BytecodeTypeNode(const BytecodeTypeNode& node)
        : TypeNode(node), keyword_(node.keyword_->clone()) {
    }

    BytecodeTypeNode(BytecodeTypeNode&& node)
        : TypeNode(std::move(node)), keyword_(std::move(node.keyword_)) {
    }

    BytecodeTypeNode& operator=(const BytecodeTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        keyword_ = node.keyword_->clone();
        return *this;
    }

    BytecodeTypeNode& operator=(BytecodeTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        keyword_ = std::move(node.keyword_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<BytecodeTypeNode> clone() const {
        return std::unique_ptr<BytecodeTypeNode>(this->clone_impl());
    }

    Kind get_kind() const override final {
        return kind_;
    }

    const KeywordNode& get_keyword() const {
        return *keyword_.get();
    }

  private:
    virtual BytecodeTypeNode* clone_impl() const override final {
        return new BytecodeTypeNode(*this);
    }

    KeywordNodeUPtr keyword_;

    static const Kind kind_;
};

using BytecodeTypeNodePtr = BytecodeTypeNode*;
using BytecodeTypeNodeUPtr = std::unique_ptr<BytecodeTypeNode>;

} // namespace ast
} // namespace tastr

#endif /* TASTR_AST_BYTECODE_TYPE_NODE_HPP */
