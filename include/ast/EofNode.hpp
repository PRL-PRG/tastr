#ifndef TASTR_AST_EOF_NODE_HPP
#define TASTR_AST_EOF_NODE_HPP

#include "ast/Node.hpp"

#include <string>

namespace tastr::ast {

class EofNode final: public Node {
  public:
    EofNode(): Node() {
    }

    ~EofNode() = default;

    EofNode(const EofNode& node): Node(node) {
    }

    EofNode(EofNode&& node): Node(std::move(node)) {
    }

    EofNode& operator=(const EofNode& node) {
        if (&node == this) {
            return *this;
        }
        Node::operator=(node);
        return *this;
    }

    EofNode& operator=(EofNode&& node) {
        Node::operator=(std::move(node));
        return *this;
    }

    std::unique_ptr<EofNode> clone() const {
        return std::unique_ptr<EofNode>(this->clone_impl());
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    bool is_eof_node() const override final {
        return true;
    }

  private:
    virtual EofNode* clone_impl() const override final {
        return new EofNode(*this);
    }
};

using EofNodePtr = EofNode*;
using EofNodeUPtr = std::unique_ptr<EofNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_EOF_NODE_HPP */
