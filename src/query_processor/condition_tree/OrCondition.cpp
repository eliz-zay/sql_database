#pragma once

#include "OrCondition.h"

#include "../../engine/TableField.cpp"
#include "../../engine/DataType.cpp"

#include <string>

bool OrCondition::calculate(vector<TableField> fields, vector<DataType*> row) {
    for (BaseCondition* operand: operands) {
        if (operand->calculate(fields, row) == true) {
            return true^isNegated;
        }
    }
    return false^isNegated;
}

string OrCondition::toString(int nestLevel) {
    string message;
    
    if (this->NegatableCondition::isNegated || operands.size() > 1) {
        message += string(nestLevel - 1,'\t');
    }
    
    if (this->NegatableCondition::isNegated) {
        message += "NOT ";
    }
    
    
    if (operands.size() > 1) {
        message += "OR Condition {\n";
        
        for (BaseCondition* it: operands) {
            message += it->toString(nestLevel + 1);
        }
        
        message += string(nestLevel - 1,'\t');
        message += "}";
        message += "\n";
    } else {
        if (this->NegatableCondition::isNegated) {
            message += "{\n\t";
            message += operands[0]->toString(nestLevel);
            message += string(nestLevel - 1,'\t');
            message += "}\n";
        } else {
            message += operands[0]->toString(nestLevel);
        }

        
    }
    
    return message;
}
