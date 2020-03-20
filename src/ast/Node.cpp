#include "ast/Node.hpp"

std::ostream& operator<<(std::ostream& os, const tastr::ast::Node::Kind& kind) {
    os << to_string(kind);
    return os;
}

std::string to_string(const tastr::ast::Node::Kind& kind) {
    switch (kind) {
    case tastr::ast::Node::Kind::AnyType:
        return "AnyTypeNode";
        break;

    case tastr::ast::Node::Kind::BytecodeType:
        return "BytecodeTypeNode";
        break;

    case tastr::ast::Node::Kind::CharacterAScalarType:
        return "CharacterAScalarTypeNode";
        break;

    case tastr::ast::Node::Kind::CommaSeparator:
        return "CommaSeparatorNode";
        break;

    case tastr::ast::Node::Kind::ComplexAScalarType:
        return "ComplexAScalarTypeNode";
        break;

    case tastr::ast::Node::Kind::DoubleAScalarType:
        return "DoubleAScalarTypeNode";
        break;

    case tastr::ast::Node::Kind::Empty:
        return "EmptyNode";
        break;

    case tastr::ast::Node::Kind::EnvironmentType:
        return "EnvironmentTypeNode";
        break;

    case tastr::ast::Node::Kind::Eof:
        return "EofNode";
        break;

    case tastr::ast::Node::Kind::ExpressionType:
        return "ExpressionTypeNode";
        break;

    case tastr::ast::Node::Kind::ExternalPointerType:
        return "ExternalPointerTypeNode";
        break;

    case tastr::ast::Node::Kind::FunctionType:
        return "FunctionTypeNode";
        break;

    case tastr::ast::Node::Kind::GroupType:
        return "GroupTypeNode";
        break;

    case tastr::ast::Node::Kind::Identifier:
        return "IdentifierNode";
        break;

    case tastr::ast::Node::Kind::IntegerAScalarType:
        return "IntegerAScalarTypeNode";
        break;

    case tastr::ast::Node::Kind::Keyword:
        return "KeywordNode";
        break;

    case tastr::ast::Node::Kind::LanguageType:
        return "LanguageTypeNode";
        break;

    case tastr::ast::Node::Kind::ListType:
        return "ListTypeNode";
        break;

    case tastr::ast::Node::Kind::LogicalAScalarType:
        return "LogicalAScalarTypeNode";
        break;

    case tastr::ast::Node::Kind::NAScalarType:
        return "NAScalarTypeNode";
        break;

    case tastr::ast::Node::Kind::NullableType:
        return "NullableTypeNode";
        break;

    case tastr::ast::Node::Kind::NullType:
        return "NullTypeNode";
        break;

    case tastr::ast::Node::Kind::Operator:
        return "OperatorNode";
        break;

    case tastr::ast::Node::Kind::PairlistType:
        return "PairlistTypeNode";
        break;

    case tastr::ast::Node::Kind::Parameter:
        return "ParameterNode";
        break;

    case tastr::ast::Node::Kind::RawAScalarType:
        return "RawAScalarTypeNode";
        break;

    case tastr::ast::Node::Kind::S4Type:
        return "S4TypeNode";
        break;

    case tastr::ast::Node::Kind::Separator:
        return "SeparatorNode";
        break;

    case tastr::ast::Node::Kind::StructType:
        return "StructTypeNode";
        break;

    case tastr::ast::Node::Kind::SymbolType:
        return "SymbolTypeNode";
        break;

    case tastr::ast::Node::Kind::TagTypePair:
        return "TagTypePairNode";
        break;

    case tastr::ast::Node::Kind::Terminator:
        return "TerminatorNode";
        break;

    case tastr::ast::Node::Kind::TopLevel:
        return "TopLevelNode";
        break;

    case tastr::ast::Node::Kind::TupleType:
        return "TupleTypeNode";
        break;

    case tastr::ast::Node::Kind::TypeDeclaration:
        return "TypeDeclarationNode";
        break;

    case tastr::ast::Node::Kind::UnionType:
        return "UnionTypeNode";
        break;

    case tastr::ast::Node::Kind::UnknownType:
        return "UnknownTypeNode";
        break;

    case tastr::ast::Node::Kind::VarargType:
        return "VarargTypeNode";
        break;

    case tastr::ast::Node::Kind::VectorType:
        return "VectorTypeNode";
        break;

    case tastr::ast::Node::Kind::WeakReferenceType:
        return "WeakReferenceTypeNode";
        break;
    }
    return "UNDEFINED";
}
