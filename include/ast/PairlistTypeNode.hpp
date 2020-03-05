#ifndef TASTR_AST_PAIRLIST_TYPE_NODE_H
#define TASTR_AST_PAIRLIST_TYPE_NODE_H

#include "TypeNode.hpp"

namespace tastr::ast {

class PairlistTypeNode final: public TypeNode {
  public:
    explicit PairlistTypeNode(const std::string& identifier)
        : TypeNode(), identifier_(identifier) {
    }

    ~PairlistTypeNode() = default;

    PairlistTypeNode(const PairlistTypeNode& node)
        : TypeNode(node), identifier_(node.identifier_) {
    }

    PairlistTypeNode(PairlistTypeNode&& node)
        : TypeNode(std::move(node)), identifier_(std::move(node.identifier_)) {
    }

    PairlistTypeNode& operator=(const PairlistTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        identifier_ = node.identifier_;
        return *this;
    }

    PairlistTypeNode& operator=(PairlistTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        identifier_ = std::move(node.identifier_);
        return *this;
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<PairlistTypeNode> clone() const {
        return std::unique_ptr<PairlistTypeNode>(this->clone_impl());
    }

    bool is_pairlist_type_node() const override final {
        return true;
    }

    const std::string& get_identifier() const {
        return identifier_;
    }

  private:
    virtual PairlistTypeNode* clone_impl() const override final {
        return new PairlistTypeNode(*this);
    };

    std::string identifier_;
};

using PairlistTypeNodePtr = PairlistTypeNode*;
using PairlistTypeNodeUPtr = std::unique_ptr<PairlistTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_PAIRLIST_TYPE_NODE_H */
