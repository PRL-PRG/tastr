#ifndef TASTR_AST_LOGICAL_SCALAR_TYPE_NODE_HPP
#define TASTR_AST_LOGICAL_SCALAR_TYPE_NODE_HPP

#include "AScalarTypeNode.hpp"

namespace tastr {
namespace ast {

class LogicalAScalarTypeNode final: public AScalarTypeNode {
  public:
    explicit LogicalAScalarTypeNode(KeywordNodeUPtr keyword)
        : AScalarTypeNode(std::move(keyword)) {
    }

    ~LogicalAScalarTypeNode() = default;

    LogicalAScalarTypeNode(const LogicalAScalarTypeNode& node)
        : AScalarTypeNode(node) {
    }

    LogicalAScalarTypeNode(LogicalAScalarTypeNode&& node)
        : AScalarTypeNode(std::move(node)) {
    }

    LogicalAScalarTypeNode& operator=(const LogicalAScalarTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        AScalarTypeNode::operator=(node);
        return *this;
    }

    LogicalAScalarTypeNode& operator=(LogicalAScalarTypeNode&& node) {
        AScalarTypeNode::operator=(std::move(node));
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<LogicalAScalarTypeNode> clone() const {
        return std::unique_ptr<LogicalAScalarTypeNode>(this->clone_impl());
    }

    Kind get_kind() const override final {
        return kind_;
    }

  private:
    virtual LogicalAScalarTypeNode* clone_impl() const override final {
        return new LogicalAScalarTypeNode(*this);
    };

    static const Kind kind_;
};

using LogicalAScalarTypeNodePtr = LogicalAScalarTypeNode*;
using LogicalAScalarTypeNodeUPtr = std::unique_ptr<LogicalAScalarTypeNode>;

} // namespace ast
} // namespace tastr

#endif /* TASTR_AST_LOGICAL_SCALAR_TYPE_NODE_HPP */
