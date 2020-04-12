#ifndef IN_CONDITION_H
#define IN_CONDITION_H

#include "BinaryCondition.h"

using namespace std;

class InCondition : public BinaryCondition {
    public:
        bool calculate(vector<TableField> fields, vector<DataType*> row);
};

#endif