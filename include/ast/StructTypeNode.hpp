#ifndef TASTR_AST_STRUCT_TYPE_NODE_HPP
#define TASTR_AST_STRUCT_TYPE_NODE_HPP

#include "ast/Bracket.hpp"
#include "ast/TypeNode.hpp"

namespace tastr::ast {

class StructTypeNode final
    : public TypeNode
    , public Bracketed {
  public:
    explicit StructTypeNode(OperatorNodeUPtr opening_bracket,
                            OperatorNodeUPtr closing_bracket,
                            NodeUPtr elements)
        : TypeNode()
        , Bracketed(std::move(opening_bracket), std::move(closing_bracket))
        , elements_(std::move(elements)) {
    }

    ~StructTypeNode() = default;

    StructTypeNode(const StructTypeNode& node)
        : TypeNode(node), Bracketed(node), elements_(node.elements_->clone()) {
    }

    StructTypeNode(StructTypeNode&& node)
        : TypeNode(std::move(node))
        , Bracketed(std::move(node))
        , elements_(std::move(node.elements_)) {
    }

    StructTypeNode& operator=(const StructTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        Bracketed::operator=(node);
        elements_ = node.elements_->clone();
        return *this;
    }

    StructTypeNode& operator=(StructTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        Bracketed::operator=(std::move(node));
        elements_ = std::move(node.elements_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<StructTypeNode> clone() const {
        return std::unique_ptr<StructTypeNode>(this->clone_impl());
    }

    bool is_struct_type_node() const override final {
        return true;
    }

    Node& get_elements() const {
        return *elements_.get();
    }

  private:
    virtual StructTypeNode* clone_impl() const override final {
        return new StructTypeNode(*this);
    }

    NodeUPtr elements_;
};

using StructTypeNodePtr = StructTypeNode*;
using StructTypeNodeUPtr = std::unique_ptr<StructTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_STRUCT_TYPE_NODE_HPP */
