#ifndef TASTR_AST_RAW_SCALAR_TYPE_NODE_HPP
#define TASTR_AST_RAW_SCALAR_TYPE_NODE_HPP

#include "AScalarTypeNode.hpp"

namespace tastr::ast {

class RawAScalarTypeNode final: public AScalarTypeNode {
  public:
    explicit RawAScalarTypeNode(KeywordNodeUPtr keyword)
        : AScalarTypeNode(std::move(keyword)) {
    }

    ~RawAScalarTypeNode() = default;

    RawAScalarTypeNode(const RawAScalarTypeNode& node): AScalarTypeNode(node) {
    }

    RawAScalarTypeNode(RawAScalarTypeNode&& node)
        : AScalarTypeNode(std::move(node)) {
    }

    RawAScalarTypeNode& operator=(const RawAScalarTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        AScalarTypeNode::operator=(node);
        return *this;
    }

    RawAScalarTypeNode& operator=(RawAScalarTypeNode&& node) {
        AScalarTypeNode::operator=(std::move(node));
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<RawAScalarTypeNode> clone() const {
        return std::unique_ptr<RawAScalarTypeNode>(this->clone_impl());
    }

    Kind get_kind() const override final {
        return kind_;
    }

  private:
    virtual RawAScalarTypeNode* clone_impl() const override final {
        return new RawAScalarTypeNode(*this);
    }

    static const Kind kind_;
};

using RawAScalarTypeNodePtr = RawAScalarTypeNode*;
using RawAScalarTypeNodeUPtr = std::unique_ptr<RawAScalarTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_RAW_SCALAR_TYPE_NODE_HPP */
