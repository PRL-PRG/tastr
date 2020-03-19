#ifndef TASTR_AST_STRUCT_TYPE_NODE_HPP
#define TASTR_AST_STRUCT_TYPE_NODE_HPP

#include "ast/KeywordNode.hpp"
#include "ast/ParameterNode.hpp"
#include "ast/TypeNode.hpp"

namespace tastr::ast {

class StructTypeNode final: public TypeNode {
  public:
    explicit StructTypeNode(KeywordNodeUPtr keyword,
                            ParameterNodeUPtr parameters)
        : TypeNode()
        , keyword_(std::move(keyword))
        , parameters_(std::move(parameters)) {
    }

    ~StructTypeNode() = default;

    StructTypeNode(const StructTypeNode& node)
        : TypeNode(node)
        , keyword_(node.keyword_->clone())
        , parameters_(node.parameters_->clone()) {
    }

    StructTypeNode(StructTypeNode&& node)
        : TypeNode(std::move(node))
        , keyword_(std::move(node.keyword_))
        , parameters_(std::move(node.parameters_)) {
    }

    StructTypeNode& operator=(const StructTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        keyword_ = node.keyword_->clone();
        parameters_ = node.parameters_->clone();
        return *this;
    }

    StructTypeNode& operator=(StructTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        keyword_ = std::move(node.keyword_);
        parameters_ = std::move(node.parameters_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<StructTypeNode> clone() const {
        return std::unique_ptr<StructTypeNode>(this->clone_impl());
    }

    Kind get_kind() const override final {
        return kind_;
    }

    KeywordNode& get_keyword() const {
        return *keyword_.get();
    }

    ParameterNode& get_parameters() const {
        return *parameters_.get();
    }

  private:
    virtual StructTypeNode* clone_impl() const override final {
        return new StructTypeNode(*this);
    };

    KeywordNodeUPtr keyword_;
    ParameterNodeUPtr parameters_;

    static const Kind kind_;
};

using StructTypeNodePtr = StructTypeNode*;
using StructTypeNodeUPtr = std::unique_ptr<StructTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_STRUCT_TYPE_NODE_HPP */
